%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "include/function.h"
#include "include/mipssy.h"
#include "include/array.h"

struct option longopts[] = {
   { "out",     required_argument, 0,  'o'  },
   { "help",    no_argument,       0,  'h'  },
   { "version", no_argument,       0,  'v'  },
   { "tos",     no_argument,       0,  't'  },
   { NULL, 0, NULL, 0 }
};

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
	struct P_symb **psymb;
	struct ident_list* list;
	struct quadop* exprval;
	struct {
		struct lpos* false;
		struct lpos* true;
	} tf;
	struct lpos* lpos;
	int actualquad;
	struct typelist *typelist;
	struct dim_list* dim_list;
	struct array_call *array_call;
	struct index_list *index_list;
}

%token PROGRAM  VAR SARRAY SOF INTRV_SEP
%token <strval> ID STR
%token <intval> NUM UNIT BOOL INT

%token <intval> PLUS AFFECT TIMES MINUS DIVIDE POWER TRUE FALSE
%token <intval> INF INFEQ SUP SUPEQ DIFF EQ
%token <intval> AND OR NOT

%token SBEGIN SEND WRITE READ SFUNCTION REF
%token IF THEN ELSE WHILE DO RETURN


%type <list> identlist
%type <strval> atomictype typename
%type <intval> opb oprel
%type <exprval> E
%type <tf> cond
%type <actualquad> M
%type <lpos> instr tag sequence
%type <typelist> par parlist Elist


%type <dim_list> rangelist arraytype //ADDITION
%type <index_list> exprlist
%type <array_call> lvalue

%nonassoc THEN_SIMPLE
%nonassoc ELSE

%left RETURN
%left INF INFEQ SUP SUPEQ DIFF EQ
%right AFFECT
%left PLUS MINUS OR
%left TIMES DIVIDE AND
%right POWER
%left NEG NOT
%left ID


%start program
%%
program: PROGRAM ID vardecllist tag fundecllist M instr {complete($4, $6);}
        ;

vardecllist: varsdecl {}
            | varsdecl ';' vardecllist {}
			| {} //element vide
            ;
varsdecl: VAR identlist ':' typename {create_symblist("var",$2, $4);}
        | VAR identlist ':' arraytype {create_symblist_array("array",$2, "int", $4);} //ADDITION
        ;
identlist: ID                 {$$ = create_identlist($1);}
         | identlist ',' ID   {$$ = add_to_identlist($1, $3);}
         ;

typename: atomictype   { $$ = $1; }
		;

arraytype : SARRAY '[' rangelist ']' SOF atomictype { $$ = $3; print_dims($3); };

rangelist : NUM INTRV_SEP NUM { $$ = add_dim($1, $3); }
		|  NUM INTRV_SEP NUM ',' rangelist { $$ = add_dims($5, $1, $3);}
		;

lvalue : ID '[' exprlist ']' { $$ = array_call_info($1, $3); check_indx($1, $3);
		//printf("%s %s %d\n", $$->tab_name, $$->tab_element , $$->head_array->un.index_int); //print the most right index
		//printf("%d\n", $$->head_array->next_indxlist->un.index_int);
		}

exprlist : E 				{ $$ = solo_index($1); }
		 | exprlist ',' E  { $$ = all_indexs($1, $3); } ;

//**************************************************************

atomictype: UNIT  {$$ = "unit";}
          | BOOL  {$$ = "bool";}
          | INT   {$$ = "int";}
          ;

fundecllist : fundecl ';' fundecllist
			|
			;

fundecl : SFUNCTION ID '(' parlist ')' ':' atomictype
		{
			create_symblist("function",create_identlist($2), $7);
			add_typelist_to_symb($2, $4);
			quad q = quad_make(Q_FBEGIN, quadop_cst(len_param($4)), NULL, quadop_name($2));
			gencode(q);
		}
		vardecllist instr
		{
			quad q = quad_make(Q_FEND, NULL, NULL, quadop_name($2));
			gencode(q);
		}
		;

parlist : par {$$ = $1;}
		| par ',' parlist { $$ = add_to_typelist($1, $3);}
		| { $$ = NULL;}
		;

par : ID ':' typename
	{
		create_symblist("param",create_identlist($1), $3);
		$$ = create_typelist($1, $3);
	}
	;

instr :
		lvalue AFFECT E {
			quad q = quad_make(Q_AFFECT, $3, NULL, quadop_array($1));
			//printf("%d %d %s %s",$1->i, $1->j, $1->tab_element,$1->tab_name);
			//printf("%s",q.res->u.name);
			gencode(q);
			$$ = crelist(nextquad);
			printf("fin affectation tableau\n");
		}

	  | ID AFFECT E
	  {
		  chk_symb_declared($1);
		  chk_symb_type($1,$3);
		  affect_symb($1, $3);
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
	  | IF cond THEN M instr %prec THEN_SIMPLE
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
	  | SBEGIN sequence SEND {$$ = $2;}
	  | READ E
	  {
		  quad q = quad_make(Q_READ, NULL, NULL, $2);
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | WRITE E
	  {
		  quad q = quad_make(Q_WRITE, NULL, NULL, $2);
		  gencode(q);
		  $$ = crelist(nextquad);

	  }
	  | ID '(' Elist ')'
	  {
		  chk_symb_declared($1);
		  chk_symb_fct($1);
		  typelist* l = get_typelist($1);
		  cmp_typelist($3, l);
		  int len = gencode_param($3);
		  quad q = quad_make(Q_CALL, quadop_cst(len), NULL, quadop_name($1));
		  gencode(q);
		  $$ = crelist(nextquad);
	  }
	  | ID '(' ')'
	  {
		  chk_symb_declared($1);
		  chk_symb_fct($1);
		  typelist* l = get_typelist($1);
		  cmp_typelist(NULL, l);
		  int len = gencode_param(NULL);
		  quad q = quad_make(Q_CALL, quadop_cst(len), NULL, quadop_name($1));
		  gencode(q);
		  $$ = crelist(nextquad);
	  }

	  ;

sequence : sequence semcol M instr semcol {complete($1, $3);$$ = $4;}
		 | instr semcol { $$ = $1;}
		 ;

semcol : ';' | ;

Elist : E
	  {
		  if ($1->type == QO_CST) // on doit creer une variable temp pour stocker la constante
		  {
			  quadop *t = new_temp();
			  quad q = quad_make(Q_AFFECT, $1, NULL, t);
			  gencode(q);
			  create_symblist("var", create_identlist(t->u.name), "int");
			  char *s = get_symb_type_A_char(t->u.name);
			  $$ = create_typelist(t->u.name, s);
		  }
		  else
			  $$ = create_typelist($1->u.name, get_symb_type_A_char($1->u.name));
	  }
	  | E ',' Elist
	  {
		  if ($1->type == QO_CST)
		  {
			  quadop *t = new_temp();
			  quad q = quad_make(Q_AFFECT, $1, NULL, t);
			  gencode(q);
			  create_symblist("var", create_identlist(t->u.name), "int");
			  char *s = get_symb_type_A_char(t->u.name);
				  $$ = add_to_typelist(create_typelist(t->u.name, get_symb_type_A_char(t->u.name)), $3);
		  }
		  else
			  $$ = add_to_typelist(create_typelist($1->u.name, get_symb_type_A_char($1->u.name)), $3);

	  }
	  | cond ',' Elist {$$ = add_to_typelist(create_typelist((reify($1.true, $1.false))->u.name, "bool"), $3);}
	  | cond {$$ = create_typelist(reify($1.true, $1.false)->u.name, "bool");}
	  ;

E : ID { chk_symb_declared($1); $$ = quadop_name($1);}
| lvalue { $$ = quadop_array($1);}
| NUM {	$$ = quadop_cst($1);}
| STR { $$ = quadop_str($1);}
| '(' E ')' { $$ = $2;}
| ID '(' Elist ')'
{
	chk_symb_declared($1);
	chk_symb_fct($1);
	typelist* l = get_typelist($1);
	cmp_typelist($3, l);
	int len = gencode_param($3);
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), get_symb_type_A_char($1));
	quad q = quad_make(Q_CALL_AFFECT, quadop_name($1),quadop_cst(len), t);
	gencode(q);
	$$ = t;
}
| ID '(' ')'
{
	chk_symb_declared($1);
	chk_symb_fct($1);
	typelist* l = get_typelist($1);
	cmp_typelist(NULL, l);
	int len = gencode_param(NULL);
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), get_symb_type_A_char($1));
	quad q = quad_make(Q_CALL_AFFECT, quadop_name($1),quadop_cst(len), t);
	gencode(q);
	$$ = t;

}
| E %prec ID opb E //%prec ID pour regler conflits avec opb
{
	  if ($1->type == QO_STR || $3->type == QO_STR)
	  {
		  yyerror("erreur de type");
		  exit(1);
	  }
	  quadop* t = new_temp();
	  create_symblist("var", create_identlist(t->u.name), "int");
	  quad q = quad_make($2, $1, $3, t);

	  quadop* t_val = malloc(sizeof(quadop));
	  CHK_MALLOC(t_val);
	  affect_opb($1, $2, $3, t_val);
	  affect_symb(t->u.name, t_val);

	  gencode(q);
	  $$ = t;
}
| MINUS E %prec NEG
{
	if ($2->type == QO_STR)
	{
		yyerror("erreur de type");
		exit(1);
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
		gencode (q);
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

	int c;
	char *filename = NULL;

	while ((c = getopt_long(argc, argv, "o:htv", longopts, NULL)) != -1)
	{
		switch(c)
		{
			case 'v':
				printf("Les membres du groupe sont :\n\t-Céline Ly\n\t-Yassine Lambarki\n\t-Michael Hofmann\n\t-Simon Willer\n");
				break;
			case 'o':
				filename = optarg;
				break;
			case ':':
				fprintf(stderr, "%s: option `-%c' requires an argument\n",argv[0], optopt);
				break;
			case 'h':
				printf("option -version -o -tos\n");
				break;
			case 't':
				printf("-----------------\nSymbol table:\n-----------------\n");
				print_tab();
				printf("-----------------\nSymbol integer:\n-----------------\n");
				print_intvar_name();
				printf("-----------------\nQuad List:\n-----------------\n");
				for (int i=0; i<nextquad; i++) {
					printf("%i ", i);
					affiche(globalcode[i]);
				}
				break;
			case '?':
			default:
				fprintf(stderr, "%s: option `-%c' is invalid: ignored\n",argv[0], optopt);
		        break;
		}
	}

	FILE * out = stdout;

	if(filename == NULL)
		out = fopen("out.asm", "w");
	else
		out = fopen(filename, "w");

	if(!out) {
		fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
	}

	mips_code(globalcode, nextquad, out);
	fclose(out);


	// Be clean.===> Ofc As always
	lex_free();
	free_quad();
	free_symbtab();
	return 0;
}
