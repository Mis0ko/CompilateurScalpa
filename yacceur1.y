%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "token_tab.c"


void yyerror(char *msg) {
  fprintf(stderr, "%s\n",msg);
}
int yylex();
int yylex_destroy();


%}

%union {
	char *strval;
	int intval;
}

%token PROGRAM VAR ARRAY FUNCTION BEGIN END RETURN WRITE READ
%token <strval> ID UNIT BOOL INT
%token <intval> NUM
%type <strval> atomictype lvalue //a changer pour lvalue apres
%start program
%%


/* Grammaire à complémenté au fur et à mesure de l'implémentation */
program: PROGRAM ID vardecllist instr
        ;

vardecllist:
            | varsdecl {$$ = $1;}
            | varsdecl ';' vardcllist
            ;

varsdecl: VAR identlist ':' typename {create_symblist($1, $2, $4);}
        ;

identlist:    ID                 {$$ = create_identlist($1);}
            | ID ',' identlist   {$$ = add_to_identlist($3, $1);}
            ;

typename: atomictype ';'   {$$ = $1;}

atomictype: UNIT  {$$ = $1;}
          | BOOL  {$$ = $1;}
          | INT   {$$ = $1;}
          ;


instr : lvalue := expr // L = sequence et S = instr
	  | return expr { gencode("j $ra"); }
	  | return { gencode("j $ra"); }
	  |	begin sequence end { $$ = $2; }
	  | begin end
	  ;

sequence : sequence ';' M instr { complete($1, $3); $$ = $4; }
		 | instr ';' { $$ = $1; }
		 | instr { $$ = $1; }
		 ;

lvalue: ID { $$ = $1; }//a completer pour la suite
      ;

exprlist: expr
        | expr ',' exprlist
        ;

expr: NUM
    | '(' expr ')'
	| ID
	;


%%

int main(void)
{
      printf("Made by group blabla\n");
      printf("you can run the example file with\n");
      printf("./ex3 << example_test\n");
      yyparse();
      //yylex_destroy();
      return 0;
}
