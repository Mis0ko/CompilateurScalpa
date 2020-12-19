%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char *msg) {
  fprintf(stderr, "%s\n",msg);
}
int yylex();
int yylex_destroy();



typedef struct ident_list
{
    const char*       name;           // name
    struct ident_list* next;
} ident_list ;


ident_list* create_identlist(char* ident)
{
    ident_list* my_list = malloc(sizeof(ident_list));
    strncpy(my_list->name, ident, strlen(ident));
    my_list->next = NULL;
    return my_list;
}

ident_list* add_to_identlist(ident_list* old_list, char* ident)
{
    ident_list* new_ident = malloc(sizeof(ident_list));
    strncpy(new_ident->name, ident, strlen(ident));
    new_ident->next = NULL;
    ident_list* loop_ident = old_list;
    while(loop_ident->next != NULL)
        loop_ident = loop_ident->next;
    loop_ident->next = new_ident;
    return old_list;
}

%}



%token  NUMBER
%token  PLUS MINUS TIMES DIVIDE POWER
%token  INF INF_EQ SUP SUP_EQ EQ INF_SUP
%token  AND OR XOR
%token  NEG NOT
%token  PARENTHESE_DROITE PARENTHESE_GAUCHE
%token  END




%token IDENT










/* priorité des opérations de bases*/
%left   PLUS MINUS
%left   TIMES DIVIDE
%left   NEG
%right  POWER



%start program
%%





/* Grammaire à complémenté au fur et à mesure de l'implémentation */
program: program IDENT vardecllist instr
        ;

vardecllist:
            | varsdecl {$$ = $1;}
            | varsdecl ; vardcllist
            ;

varsdecl: var identlist : typename {$$=create_symb($1, $2, $4);}
        ;

identlist:    ident                 {$$ = create_identlist($1);}
            | ident COMA identlist  {$$ = add_to_identlist($3, $1);}
            ;

typename: atomictype;   {$$ = $1;}

atomictype:   unit  {$$ = $1;}
            | bool  {$$ = $1;}
            | int   {$$ = $1;}
            ;


instr: lvalue := expr 
        ;

lvalue: ident
        ;

exprlist:   expr 
            | expr COMA exprlist 
            ;

expr: cte 
    | (expr) 
    | expr opb expr 
    | opu expr ;

opb : PLUS {$$ = $1} 
    | MOINS {$$ = $1} 
    | TIMES {$$ = $1} 
    | DIVISE {$$ = $1} 
    | POWER {$$ = $1} 
    | INF {$$ = $1} 
    | INF_EQ {$$ = $1} 
    | SUP {$$ = $1} 
    | SUP_EQ {$$ = $1} 
    | EQ {$$ = $1} 
    | INF_SUP {$$ = $1} 
    | AND {$$ = $1} 
    | OR {$$ = $1} 
    | XOR {$$ = $1} 

opu : NEG {$$ = $1}   
    | NOT {$$ = $1}


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

