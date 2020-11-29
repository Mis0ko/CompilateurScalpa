%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	typedef struct quafrup {
		char* instruction;
		int   cible;
	} quadrup;

	quadrup QUAD[100];
	int nextquad = 0;

	typedef struct lpos {
		int position;
		struct lpos* suivant;
	} lpos;

	lpos* crelist(int position) {
		lpos* new = malloc(sizeof(lpos));
		new->position = position;
		new->suivant = NULL;
		return new;
	}

	lpos* concat(lpos* l1, lpos* l2) {
		lpos* res;
		if (l1 != NULL) res = l1;
		else if (l2 != NULL) res = l2;
		else res = NULL;
		if (l1 != NULL) {
			while (l1->suivant!=NULL)
				l1 = l1->suivant;
		l1->suivant = l2;
		}
		return res;
	}

	void complete(lpos* liste, int cible) {
		if (liste == NULL)
			return;
		QUAD[liste->position].cible = cible;
		while (liste->suivant != NULL) {
			liste = liste->suivant;
			QUAD[liste->position].cible = cible;
		}
	}

  void gencode(char* code) {
    QUAD[nextquad].instruction=code;
    QUAD[nextquad].cible=0;
    nextquad++;
  }

  void yyerror(char*);
  int yylex();
  void lex_free();
%}

%union {
	struct {
		struct lpos* true;
		struct lpos* false;
	} tf;
	struct lpos* lpos;
	int quad;
}

%token ASSIGN WHILE DO DONE IF THEN ELSE ENDIF
%token EQUAL TRUE FALSE OR AND NOT
%token ID
%token NUM
%token bidon bidon2

%type <tf> condition
%type <quad> M
%type <lpos> statement_list statement tag

%left OR
%left AND
%left NOT

%%

axiom:
	statement_list '\n'
	{
		printf("Match !!!\n");
		return 0;
	}

	statement_list:
		statement_list M statement {
			complete($1,$2);
			$$ = $3;
		}
		| statement { $$ = $1; }
;

statement:
    /* ID ASSIGN expression */
	bidon {
		gencode("instruction bidon");
	}
	| bidon2 {
		gencode("instruction bidon2");
	}

	| WHILE condition DO statement_list DONE
	{ ;
    }
	| IF condition THEN M statement_list ENDIF {
		complete($2.true,$4);
		$$ = concat($2.false,crelist(nextquad));
		gencode("goto");
	}
	| IF condition THEN M statement_list tag ELSE M statement_list ENDIF {
		complete($2.true, $4);
		complete($2.false, $8);
		$$ = concat($5, $6);
		$$ = concat($$, crelist(nextquad));
		gencode("goto");
	}
	;

M : { $$ = nextquad; }
  ;

condition:
/*    ID EQUAL NUM
    {
    }
  | */
	TRUE
	{
		$$.true = crelist(nextquad);
		gencode("goto");
		$$.false = NULL;
	}
	| FALSE
	{
		$$.false = crelist(nextquad);
		gencode("goto");
		$$.true = NULL;
	}
	| condition OR M condition
	{
		$$.true = concat($1.true, $4.true);
		complete($1.false, $3);
		$$.false = $4.false;
	}
	| condition AND M condition
	{
		$$.false = concat($1.false, $4.false);
		complete($1.true, $3);
		$$.true = $4.true;
	}
	| NOT condition
	{
		$$.true = $2.false;
		$$.false = $2.true;
	}
	| '(' condition ')'
	{
		$$.true = $2.true;
		$$.false = $2.false;
	}
	;

/* expression:
    ID
    {
    }
  | NUM
    {
    }
  ; */


  tag:
      {
  		$$ = crelist(nextquad);
  		gencode("goto");
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
		printf("%i %s",i, QUAD[i].instruction);
		if (QUAD[i].cible != 0)
			printf(" %d\n",QUAD[i].cible);
		else
			printf("\n");
	}

	// Be clean.
	lex_free();
	return 0;
}
