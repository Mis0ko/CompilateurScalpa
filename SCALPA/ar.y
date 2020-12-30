%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/token_tab.h"
#include "include/fct_utilitaires.h"
extern quad globalcode[100];
extern int nextquad;
extern int ntp;

void yyerror(char*);
int yylex();
void lex_free();


int quad_compt;
int number_strings;
void translatemips(quad q, FILE* os) {


	fprintf(os, "\nLABEL_%d:\n", quad_compt);
	quad_compt++;	
	if( q.type == Q_DIFF || q.type == Q_EQ || q.type == Q_SUP || q.type == Q_SUPEQ || q.type == Q_INF || q.type == Q_INFEQ || q.type == Q_PLUS || q.type == Q_MINUS || q.type == Q_TIMES || q.type == Q_DIVIDE) {
		// Loading in register depending on type
		if (q.op1->type == QO_CST)
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		if (q.op2->type == QO_CST)
			fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
		else
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);
		switch(q.type)	{
			case Q_EQ :
				// Branch in case it's not eq => bne
				fprintf(os, "\t\tbne $t1, $t2, LABEL_%d\n", q.res->u.cst);
				break;
			case Q_DIFF :
				// Branch in case it's equal => beq
				fprintf(os, "\t\tbeq $t1, $t2, LABEL_%d\n", q.res->u.cst);	
				break;					
			case Q_SUP :
				// Branch in case it's not sup = less or eq => ble
				fprintf(os, "\t\tble $t1, $t2, LABEL_%d\n", q.res->u.cst);	
				break;
			case Q_SUPEQ :
				// Branch in case it's not supeq = less => blt
				fprintf(os, "\t\tblt $t1, $t2, LABEL_%d\n", q.res->u.cst);
				break;
			case Q_INF :
				// Branch in case it's not inf= greater or eq=> bge
				fprintf(os, "\t\tbge $t1, $t2, LABEL_%d\n", q.res->u.cst);	
				break;
			case Q_INFEQ :
				// Branch in case it's not infeq= greater => bgt
				fprintf(os, "\t\tbgt $t1, $t2, LABEL_%d\n", q.res->u.cst);
				break;
			case Q_MINUS:
				// Substraction operation
				fprintf(os, "\t\tsub $t2, $t0, $t1\n");
				// Storing the result
				fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
				break;
			case Q_PLUS:
				fprintf(os, "\t\tadd $t2, $t0, $t1\n");
				// Storing the result
				fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
				break;								
			case Q_TIMES:
				// Signed Multioperation
				fprintf(os, "\t\tmult $t0, $t1\n");
				// 32 most significant bits of multiplication to $t2
				fprintf(os, "\t\tmflo $t2\n");
				// Storing the result
				fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);			
				break;			
			case Q_DIVIDE:
				// Signed Division operation
				fprintf(os, "\t\tdiv $t0, $t1\n");
				// 32 most significant bits of multiplication to $t2
				fprintf(os, "\t\tmflo $t2\n");
				// Storing the result
				fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
				break;						
			default :
				break;			
		}	
	}	
	switch (q.type) {
		case Q_GOTO:
			if(q.res->u.cst==-1)
				fprintf(os, "\t\tj LABEL_END\n");
			else	
				fprintf(os, "\t\tj LABEL_%d\n", q.res->u.cst);
			break;
		case Q_WRITE:
			if (q.res->type == QO_STR){
				number_strings++;
				fprintf(os, "\t\tla $a0, STR_%d\n",number_strings); // TO COMPLETE
				fprintf(os, "\t\tli $v0, 4\n");
				fprintf(os, "\t\tsyscall\n");
				break;
			}
			if (q.res->type == QO_CST)
				// Load integer to print
				fprintf(os, "\t\tli $a0, %d\n", q.res->u.cst);
			else if(q.res->type == QO_NAME)
				// Load variable to print
				fprintf(os, "\t\tlw $a0, VAR_%s_\n", q.res->u.name);
			// system call code for print_int				
			fprintf(os, "\t\tli $v0, 1\n");
			fprintf(os, "\t\tsyscall\n");
			break;
		case Q_READ:
			if (q.res->type == QO_CST)
				// Load integer to print
				fprintf(os, "\t\tli $t0, %d\n", q.res->u.cst);
			else
				// Load variable to print
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.res->u.name);
			// system call code for read_int				
			fprintf(os, "\t\tli $v0, 5\n");
			fprintf(os, "\t\tsyscall\n");	
			// Moving the integer input to another register (is it necessary?)
			fprintf(os, "\t\tmove $t0, $v0\n");
			// save in var
			fprintf(os, "\t\tsw $t0, VAR_%s_\n", q.res->u.name);
			break;
		case Q_AFFECT:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
			// Storing the value in the register in a variable	
			fprintf(os, "\t\tsw $t0, VAR_%s_\n", q.res->u.name);
			break;	
		case Q_XOR:
			if (q.op1->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);	
			// XOR operation
			fprintf(os, "\t\txor $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);	
			break;
		case Q_AND:
			if (q.op1->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);	
			// AND operation
			fprintf(os, "\t\tand $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);	
			break;
		case Q_OR:
			if (q.op1->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);	
			// OR operation
			fprintf(os, "\t\tor $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);	
			break;
		case Q_NOT:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				// Load Integer in case of a cst
				fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
			else
				// Load a word in case of a var
				fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
			// NOT operation	
			fprintf(os, "\t\tnot $t1, $t0\n");
			// Storing the value in the register in a variable	
			fprintf(os, "\t\tsw $t1, VAR_%s_\n", q.res->u.name);
			break;	
		case Q_RET:
			// return from function call
			fprintf(os, "\t\tjr $ra");
			break;			
		default :
			break;

	}
}

void tomips(quad* globalcode, FILE* os) {
	fprintf(os, "#\tSCALPA Project\n#\tOutput test code in MIPS\n#\t\n\n\n\n");
	fprintf(os, ".data\n");
	fprintf(os, "# In the section .data we establish data components such as \n");
	fprintf(os, "# variables or strings to be displayed on the console. \n\n");
	// Should be changed to Mich's table
	// Loop on table and show vars

	// ASCIIZ write "string"

	int number_str=0;
	for (int i = 0; i < nextquad; i++) {
		if(globalcode[i].type == Q_WRITE && globalcode[i].res->type==QO_STR ){
			number_str++;
			fprintf(os,"STR_%d:\t.asciiz\t \"%s\" \n", number_str, globalcode[i].res->u.str);  
		}
	}
	fprintf(os, "\n\n.text\n");
	fprintf(os, "# In the section .text we put our executable code \n");
	//fprintf(os, "main:\n");
	quad_compt = 0;
	for (int i = 0; i < nextquad; i++) {
		translatemips(globalcode[i], os);
	}
	fprintf(os, "\nLABEL_END:\n");
	// Exit code
	fprintf(os, "\t\tli $v0, 10\n");
	fprintf(os, "\t\tsyscall\n");	
}

%}

%union {
	char *strval;
	int intval;
	struct P_symb **psymb;
	struct ident_list* list;
	struct quadop* exprval;
	struct {
		struct lpos* false;
		struct lpos* true;
	} tf;
	struct lpos* lpos;
	int actualquad;
}

%token PROGRAM  VAR
%token <strval> ID STR
%token <intval> NUM UNIT BOOL INT

%token <intval> PLUS AFFECT TIMES MINUS DIVIDE POWER TRUE FALSE
%token <intval> INF INFEQ SUP SUPEQ DIFF EQ
%token <intval> AND OR XOR NOT

%token SBEGIN SEND WRITE READ
%token IF THEN ELSE WHILE DO RETURN


%type <list> identlist
%type <strval> atomictype typename
%type <intval> opb oprel
%type <exprval> E
%type <tf> cond
%type <actualquad> M
%type <lpos> instr tag sequence

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%left RETURN
%left INF INFEQ SUP SUPEQ DIFF EQ
%right AFFECT
%left PLUS MINUS OR XOR
%left TIMES DIVIDE AND
%right POWER
%left NEG NOT
%left ID


%start program
%%


/* Grammaire à complémenté au fur et à mesure de l'implémentation */
program: PROGRAM ID vardecllist instr
        ;

vardecllist: varsdecl {}
            | varsdecl ';' vardecllist {}
			| {} //element vide
            ;
varsdecl: VAR identlist ':' typename {create_symblist("var",$2, $4);}
        ;

identlist: ID                 {$$ = create_identlist($1);}
         | identlist ',' ID   {$$ = add_to_identlist($1, $3);}
         ;

typename: atomictype   {$$ = $1;}

atomictype: UNIT  {$$ = "unit";}
          | BOOL  {$$ = "bool";}
          | INT   {$$ = "int";}
          ;

instr : ID AFFECT E //ID correspond a lvalue sans les listes
	  {
		  chk_symb_declared($1);
		  chk_symb_type($1,$3);
	 	  quad q = quad_make(Q_AFFECT, $3, NULL, quadop_name($1));
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | ID AFFECT cond
	  {
		  chk_symb_declared($1);
		  chk_symb_type($1,NULL);
		  quad q = quad_make(Q_AFFECT, reify($3.true, $3.false), NULL, quadop_name($1));
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | IF cond THEN M instr %prec LOWER_THAN_ELSE
	  {
		  $$ = NULL;
		  complete($2.true,$4);
		  $$ = concat($2.false,$5);
	  }
	  | IF cond THEN M instr ELSE tag M instr
	  {
		  complete($2.true, $4);
		  complete($2.false, $8);
		  $$ = concat($5, $7);
		  $$ = concat($$, crelist(nextquad));
		  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		  gencode(q);
	  }
	  | WHILE M cond DO M instr 
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
		  $$ = crelist(nextquad);
	  }
	  | RETURN
	  {
		  quad q = quad_make(Q_RET,NULL,NULL,NULL);
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | SBEGIN sequence SEND semcol{$$ = $2;}
	  | SBEGIN SEND  { }
	  | READ ID //lvalue a l'origine, a changer apres les tableaux
	  {
		  quad q = quad_make(Q_READ, NULL, NULL, quadop_name($2));
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | WRITE E
	  {
		  quad q = quad_make(Q_WRITE, NULL, NULL, $2);
		  gencode(q);
		  $$ = crelist(nextquad);

	  }
	  ;

sequence : sequence semcol M instr semcol {complete($1, $3);$$ = $4;}
		 | instr semcol { $$ = $1;}
		 ;

semcol : ';' | ;

E : ID { chk_symb_declared($1); $$ = quadop_name($1);}
| NUM {	$$ = quadop_cst($1);}
| STR { $$ = quadop_str($1);}
| '(' E ')' { $$ = $2;}
| E %prec ID opb E //%prec ID pour regler conflits avec opb
{
	  if ($1->type == QO_STR || $3->type == QO_STR)
	  {
		  yyerror("erreur de type");
		  return 1;
	  }
	  quadop* t = new_temp();
	  create_symblist("var", create_identlist(t->u.name), "int");
	  quad q = quad_make($2, $1, $3, t);
	  gencode(q);
	  $$ = t;
}
| MINUS E %prec NEG
{
	if ($2->type == QO_STR)
	{
		yyerror("erreur de type");
		return 1;
	}
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), "int");
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
		chk_symb_typeE($1, $3);
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

M : { $$ = nextquad;}
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


int main(int argc, char** argv) {
	init_symb_tab();
	printf("Enter your code:\n");

	yyparse();
	printf("-----------------\nSymbol table:\n-----------------\n");
	print_tab();
	printf("Quad list:\n");
	for (int i=0; i<nextquad; i++) {
		printf("%i ", i);
		affiche(globalcode[i]);
	}
	FILE * out = stdout;

    if(argc == 3)
        out = fopen(argv[2], "w");
    else
        out = fopen("out.asm", "w");

    if(!out) {
        fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
        return -2;
    }

    tomips(globalcode, out); 
    fclose(out);
	
	// Be clean.===> Ofc As always
	lex_free();
	return 0;
}

/*
*	Test fonctionnel : creation de variable:
*
*	Ce test contient tout type de symbole afin de recouvrir la totalité
*	des cas : symboles doublons d'indice de hachage mais symb différent,
*	test avec symbole doublon (et donc refus d'ajouter dans la table),
*	ajout symbole classique.
*
*	./ar < file_test/test_declaration_var
*/
