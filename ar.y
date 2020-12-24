%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "quad.h"
	extern quad globalcode[100];
	extern int nextquad;
	extern int ntp;

	void yyerror(char*);
	int yylex();
	void lex_free();
%}

%union {
	char *strval;
	int intval;
	struct quadop* exprval;
	struct {
		struct lpos* true;
		struct lpos* false;
	} tf;
	struct lpos* lpos;
	int actualquad;
}


%token <intval> PLUS AFFECT TIMES MINUS DIVIDE POWER TRUE FALSE
%token <intval> INF INFEQ SUP SUPEQ DIFF EQ
%token <intval> AND OR XOR NOT
%token <strval> ID
%token <intval> NUM
%token IF THEN ELSE ENDIF WHILE DO DONE RETURN
%type <intval> opb oprel
%type <exprval> E
%type <tf> cond
%type <actualquad> M
%type <lpos> instr tag
%left INF INFEQ SUP SUPEQ DIFF EQ
%left PLUS MINUS OR XOR
%left TIMES DIVIDE AND
%right POWER
%left NEG NOT

%start 	axiom
%%
axiom : instr '\n'
		{
			printf("Match !!!\n");
			return 0;
		}

instr : ID AFFECT E //ID correspond a lvalue sans les listes
	  {
	 	  quad q = quad_make(Q_AFFECT, $3, NULL, quadop_name($1));
	 	  gencode(q);
	  }
	  | IF cond THEN M instr ENDIF
	  {
		  complete($2.true,$4);
		  $$ = concat($2.false,crelist(nextquad));
	  }
	  | IF cond THEN M instr tag ELSE M instr ENDIF
	  {
		  complete($2.true, $4);
		  complete($2.false, $8);
		  $$ = concat($5, $6);
		  $$ = concat($$, crelist(nextquad));
		  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		  gencode(q);
	  }
	  | WHILE M cond DO M instr DONE
  	  {
	  		complete($3.true, $5);
  			complete($6, $2);
			quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst($2));
			gencode(q);
  			$$ = $3.false;
      }
	  | RETURN E
	  {
		  quad q = quad_make(Q_RET,NULL,NULL,$2);
		  gencode(q);
	  }
	  | RETURN
	  {
		  quad q = quad_make(Q_RET,NULL,NULL,NULL);
		  gencode(q);
	  }
	  ;

E : ID { $$ = quadop_name($1);}
  | NUM { $$ = quadop_cst($1);}
  | '(' E ')' { $$ = $2;}
  | E opb E
  {
  	  quadop* t = new_temp();
  	  quad q = quad_make($2, $1, $3, t);
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
  ;

cond : cond OR M cond
{
	$$.true = concat ($1.true, $4.true);
	complete($1.false, $3);
	$$.false = $4.false;
}
| cond AND M cond
{
	$$.false = concat ($1.false, $4.false);
	complete($1.true, $3);
	$$.true = $4.true;
}
| NOT cond
{
	$$.true = $2.false;
	$$.false = $2.true;
}
| '(' cond ')'
{
	$$.true = $2.true;
	$$.false = $2.false;
}
| E oprel E
{
	$$.true = crelist(nextquad);
	quad q = quad_make($2,$1,$3,NULL);
	gencode (q); // if ($1 rel $3)     goto ?
	$$.false = crelist(nextquad);
	quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	gencode(q2);
}
| TRUE
{
	$$.true = crelist(nextquad);
	quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	gencode(q2);
	$$.false = NULL;
}
| FALSE
{
	$$.false = crelist(nextquad);
	quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	gencode(q2);
	$$.true = NULL;
}
;

opb : PLUS { $$ = Q_PLUS; }
	| MINUS { $$ = Q_MINUS; }
	| TIMES { $$ = Q_TIMES; }
	| DIVIDE { $$ = Q_DIVIDE; }
	| POWER { $$ = Q_POWER; }
	;

oprel :	INF { $$ = Q_INF; }
	  | INFEQ { $$ = Q_INFEQ; }
	  | SUP { $$ = Q_SUP; }
	  | SUPEQ { $$ = Q_SUPEQ; }
	  | EQ { $$ = Q_EQ; }
	  | DIFF { $$ = Q_DIFF; }

M : { $$ = nextquad; }
  ;

tag:
  {
	  $$ = crelist(nextquad);
	  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	  gencode(q);
  }
;


%%
void yyerror (char *s) {
	fprintf(stderr, "[Yacc] error: %s\n", s);
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
