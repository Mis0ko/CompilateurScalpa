%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DINT 0
#define DBOOL 1
#define DUNIT 2

typedef struct ident_list
{
    char*       name;           // name
    struct ident_list* next;
} ident_list ;

ident_list* create_identlist(char* ident)
{
    ident_list* my_list = malloc(sizeof(ident_list));
    //strncpy(my_list->name, ident, strlen(ident));
    my_list->name = ident;
    my_list->next = NULL;
    return my_list;
}

ident_list* add_to_identlist(ident_list* old_list, char* ident)
{
    ident_list* new_ident = malloc(sizeof(ident_list));
    //strncpy(new_ident->name, ident, strlen(ident));
    new_ident->name = ident;
    new_ident->next = NULL;
    ident_list* loop_ident = old_list;
    while(loop_ident->next != NULL)
        loop_ident = loop_ident->next;
    loop_ident->next = new_ident;
    return old_list;
}

typedef struct P_symb{
	char *id;
	int type;
} P_symb;

P_symb symbtab[100];
int idx =0;

void create_symb(int typename, char* id)
{
	symbtab[idx].id = malloc(100);
	sprintf(symbtab[idx].id,"%s", id);
	symbtab[idx].type = typename;
	idx++;
}

ident_list* create_symblist(ident_list* list, int typename)
{
    ident_list* list_parcour = list;
    while(list_parcour != NULL){
        create_symb(typename,  list_parcour->name);
        list_parcour = list_parcour->next;
    }
    return list;
}


void yyerror(char*);
int yylex();
void lex_free();


%}

%union {
	char *strval;
	int intval;
	struct P_symb *psymb;
	struct ident_list* list;
}

%token PROGRAM  VAR
%token <strval> ID
%token <intval> NUM UNIT BOOL INT
%type <intval> atomictype typename
%type <psymb> vardecllist varsdecl
%type <list> identlist

%start program
%%


/* Grammaire à complémenté au fur et à mesure de l'implémentation */
program: PROGRAM ID {ident_list *list = create_identlist($2); create_symblist(list, DUNIT);} vardecllist
        ;

vardecllist: varsdecl {$$ = $1;}
            | varsdecl ';' vardecllist
            ;

varsdecl: VAR identlist ':' typename {create_symblist($2, $4);}
        ;

identlist: ID                 {$$ = create_identlist($1);}
         | identlist ',' ID   {$$ = add_to_identlist($1, $3);}
         ;

typename: atomictype ';'   {$$ = $1;}

atomictype: UNIT  {$$ = DUNIT;}
          | BOOL  {$$ = DBOOL;}
          | INT   {$$ = DINT;}
          ;

/*
instr : lvalue AFFECT expr
	  | return expr /*{ gencode("j $ra"); }*/
/*	  | return /*{ gencode("j $ra"); }*/
/*	  |	begin sequence end { $$ = $2; }
	  | begin end
	  ;

sequence : sequence ';' M instr /*{ complete($1, $3); $$ = $4; }*/
/*		 | instr ';' { $$ = $1; }
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

M : {}*/

%%
void yyerror (char *s) {
	fprintf(stderr, "[Yacc] error: %s\n", s);
}

void print_tab()
{
	for (int i = 0 ; i<idx ;i++)
		printf("%s %i\n", symbtab[i].id, symbtab[i].type);
}

int main() {
	printf("Enter your code:\n");
	yyparse();
	printf("-----------------\nSymbol table:\n");
	printf("-----------------\nQuad list:\n");
	print_tab();

	// Be clean.
	lex_free();
	return 0;
}
