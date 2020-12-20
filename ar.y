%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	char temp[8][3] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"};
	typedef struct quadop{
		enum { QO_CST, QO_NAME } type;
		union { int cst; char *name ; } u;
	} quadop ;


	quadop* quadop_cst(int val)
	{
		quadop *res = malloc(sizeof(quadop));
		res->type = QO_CST;
		res->u.cst = val;
		return res;
	}

	quadop* quadop_name(char *str)
	{
		quadop *res = malloc(sizeof(quadop));
		res->type = QO_NAME;
		res->u.name = str;
		return res;
	}

	enum quad_type { Q_PLUS, Q_TIMES, Q_MINUS, Q_DIVIDE, Q_NEG, Q_POWER, Q_AFFECT} quad_type ;

	typedef struct quad {
		enum quad_type type;
		quadop* op1, *op2, *res;
	} quad;

	quad quad_make(enum quad_type t, quadop* o1, quadop* o2, quadop* r)
	{
		quad res;
		res.type = t;
		res.op1 = o1;
		res.op2 = o2;
		res.res = r;
		return res;
	}

	quad globalcode[100];
	int nextquad =0;

	void gencode(quad q)
	{
		globalcode[nextquad] = q;
		nextquad++;
	}

	int ntp=0;
	quadop *new_temp()
	{
		quadop* tp = quadop_name(temp[ntp]);
		ntp++;
		return tp;
	}

	void yyerror(char*);
	int yylex();
	void lex_free();
%}

%union {
	char *strval;
	int intval;
	struct quadop* exprval;
}


%token PLUS AFFECT TIMES MINUS DIVIDE POWER
%token <strval> ID
%token <intval> NUM

%type <exprval> E

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER
%%
axiom : S '\n'
		{
			printf("Match !!!\n");
			return 0;
		}

S : ID AFFECT E
 {
	  quad q = quad_make(Q_AFFECT, $3, NULL, quadop_name($1));
	  gencode(q);
 }
 ;

E : ID { $$ = quadop_name($1);}
  | NUM { $$ = quadop_cst($1);}
  | '(' E ')' { $$ = $2;}
  | E PLUS E
  {
	  quadop* t = new_temp();
	  quad q = quad_make(Q_PLUS, $1, $3, t);
	  gencode(q);
	  $$ = t;
  }
  | E TIMES E
  {
	  quadop* t = new_temp();
	  quad q = quad_make(Q_TIMES, $1, $3, t);
	  gencode(q);
	  $$ = t;
  }
  | E MINUS E
  {
	quadop* t = new_temp();
	quad q = quad_make(Q_MINUS, $1, $3, t);
	gencode(q);
	$$ = t;
  }
  | E DIVIDE E
  {
	  quadop* t = new_temp();
	  quad q = quad_make(Q_DIVIDE, $1, $3, t);
	  gencode(q);
	  $$ = t;
  }
  | MINUS E %prec NEG
  {
	  quadop* t = new_temp();
	  quad q = quad_make(Q_NEG, $2, NULL, t);
	  gencode(q);
	  $$ = t;
  }
  | E POWER E
  {
	quadop* t = new_temp();
	quad q = quad_make(Q_POWER, $1, $3, t);
	gencode(q);
	$$ = t;
  }

  ;
%%

void yyerror (char *s) {
	fprintf(stderr, "[Yacc] error: %s\n", s);
}

void affiche(quad q)
{
	switch(q.type)
	{
		case Q_PLUS:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d + ", q.op1->u.cst);
			else
				printf("%s + ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_TIMES:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d * ", q.op1->u.cst);
			else
				printf("%s * ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_POWER:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d^", q.op1->u.cst);
			else
				printf("%s^", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_MINUS:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d - ", q.op1->u.cst);
			else
				printf("%s - ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_DIVIDE:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d / ", q.op1->u.cst);
			else
				printf("%s / ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_NEG:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("-%d\n", q.op1->u.cst);
			else
				printf("-%s\n", q.op1->u.name);
			break;

		case Q_AFFECT:
			if (q.op1->type == QO_NAME)
				printf("%s = %s\n", q.res->u.name, q.op1->u.name);
			else
				printf("%s = %d\n", q.res->u.name, q.op1->u.cst);
			break;
		default:
			printf("pas compris\n");
	}
}

int main() {
	printf("Enter your code:\n");
	yyparse();
	printf("-----------------\nSymbol table:\n");
	printf("-----------------\nQuad list:\n");
	for (int i=0; i<nextquad; i++) {
		affiche(globalcode[i]);
	}

	// Be clean.
	lex_free();
	return 0;
}
