%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token_tab.h"

#include "y.tab.h"

void yyerror(char *msg) {
  fprintf(stderr, "%s\n",msg);
}
int yylex();
int yylex_destroy();





%}
%union{
    int ival;
    char* sstring;
    struct ident_list* list;
}


%token  NUMBER LEPROGRAM FUNC BEGIN1 WRITE WRITELN READ READLN
%token  ASSIGN WHILE DO DONE IF THEN ELSE ENDIF
%token  PLUS MINUS TIMES DIVIDE POWER
%token  INF INF_EQ SUP SUP_EQ EQ INF_SUP
%token  EQUAL TRUE FALSE OR AND NOT XOR
%token  PARENTHESE_DROITE PARENTHESE_GAUCHE
%token  END RETURN




%token <sstring>IDENT VAR ARRAY1
%token COMA
%token AFFECT

%token INT CHAR REAL BOOL CTE






/* priorité des opérations de bases*/
%left   PLUS MINUS
%left   TIMES DIVIDE
%left   NEG
%right  POWER



/*type des non terminaux pour compiler, pas définitif(notamment vardecllist*/
%type <list> vardecllist
%type <list> varsdecl
%type <sstring> atomictype
%type <sstring> typename
%type <list> identlist
/* %type <sstring> opu
%type <sstring> opb */
%start program
%%





/* Grammaire à complémenté au fur et à mesure de l'implémentation */
program: LEPROGRAM IDENT vardecllist {printf("programme lance");}//instr
        ;

vardecllist: varsdecl {$$ = $1;}
            /* | varsdecl ; vardcllist  faut faire une fonction de concaténation de liste*/
            ;

varsdecl: VAR identlist ':' typename {$$=create_symblist($1, $2, $4);}
        ;

identlist:    IDENT                 {$$ = create_identlist($1);}
            | IDENT COMA identlist  {$$ = add_to_identlist($3, $1);}
            ;

typename: atomictype {$$ = $1;}
        ;


atomictype:   INT  {$$ = "int";}
            | REAL  {$$ = "real";}
            | BOOL   {$$ = "bool";}
            | CHAR  {$$ = "char";}
            ;


/* instr: lvalue AFFECT expr
        ;

lvalue: IDENT
        ;

exprlist:   expr
            /*| expr COMA exprlist  idem on voit plus tard*/
            //;
/*
expr: CTE
    | PARENTHESE_GAUCHE expr PARENTHESE_DROITE
    | expr opb expr
    | opu expr ; */

/* opb : PLUS {$$ = $1}
    | MINUS {$$ = $1}
    | TIMES {$$ = $1}
    | DIVIDE {$$ = $1}
    | POWER {$$ = $1}
    | INF {$$ = $1}
    | INF_EQ {$$ = $1}
    | SUP {$$ = $1}
    | SUP_EQ {$$ = $1}
    | EQ {$$ = $1}
    | INF_SUP {$$ = $1}
    | AND {$$ = $1}
    | OR {$$ = $1}
    | XOR {$$ = $1}  */

/* opu : NEG {$$ = $1}
    | NOT {$$ = $1}
 */

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
