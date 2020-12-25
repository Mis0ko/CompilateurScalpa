%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "symbol.h"
  #include "quad.h"
  #include "mips.h"

  void lex_free();      // Free the memory used by lex
  void yyerror(char*);  // Just to handle custom message
  
  symbol st = NULL;     // The symbol table
  quad_list qt = NULL;  // The quad list

  extern FILE *yyin;    // The input file
  extern int yylex();   
  extern int yyparse();
  
  
  struct expr_node_ update_expr_node(struct expr_node_, symbol, quad_list);
%}

%union {
  // for identifiers 
  char* string;
  // for numbers and relops (==, !=, <= ...) 
  int value;
  // head : a link to the first quad of the statement
  // next : list of quad that needs to be completed
  struct statement_node_ {
    struct quad_list_* head;
    struct quad_list_* next;
  } statementData;
  // head : link to the first quad
  // ptr : the resulting symbol 
  struct expr_node_ {
     struct quad_list_* ql;
     struct symbol_* ptr;
  } exprData;
}

%token PROGRAM VAR DECL COMMA BEGINPROG ENDPROG
%token INT
%token IF ELSE WHILE FOR RETURN PRINTI
%token ASSIGN PLUS MINUS MULT DIVI END 
%token TRUE FALSE OR AND NOT

%token <value> CONSTANT RELOP
%token <string> IDENTIFIER

//%type <condData> condition
%type <statementData>
  statement
  statement_list
  expr_statement
  assign_statement
  declare_statement

%type <exprData> expr


%left OR
%left AND
%left NOT
%right ASSIGN
%left PLUS MINUS
%left MULT DIVI


%start axiom

%%

axiom:
    PROGRAM IDENTIFIER BEGINPROG statement_list ENDPROG {
	printf("Match !!!\n");
	quad_list_free($4.next, false);
	// End of the program, next won't be completed
}

// Un programme est une suite de statement
statement_list:

    statement_list statement {
		fprintf(stderr, "statement_list statement\n");
		// Complete previous quads with new statement's head quad
		if ($2.head != NULL) {
			quad_list_complete($$.next, $2.head->q);
			// free list
			quad_list_free($$.next, false);
			// Each list is a new allocated one, so we need to free it
			// Heriting
			$$.next = $2.next;
		} else {
			// If next line isnt an instruction (int a;)
			quad_list ql = quad_list_concat($$.next, $2.next);
			quad_list_free($$.next, false);
			$$.next = ql;
		}
	}
    | statement {
		fprintf(stderr, "statement\n");
		// First
		$$.next = $1.next;
		$$.head = $1.head;
	}

// Un statement est soit une affectation une déclaration une expression lebodyd'une fonction (ne pas oublier statement vide)
statement:
   	assign_statement { $$ = $1; }
	| declare_statement { $$ = $1; }
	| expr_statement { $$ = $1; }

// Déclaration 
declare_statement:
	// int a;
	// INT IDENTIFIER END
	// var i : int ;
	VAR IDENTIFIER DECL INT END {
		// New integer
		fprintf(stderr, "int identifier ;\n");
		// Look for id in sym table
		symbol s = symbol_find(st, $2);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $2);
			YYABORT;
		}
		s = symbol_new(&st, $2);
		$$.head = NULL;
		$$.next = NULL;
		free($2);
	}
	| VAR IDENTIFIER COMMA IDENTIFIER DECL INT END {
		// New integer
		fprintf(stderr, "int identifier ;\n");
		// Look for id in sym table
		symbol s = symbol_find(st, $2);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $2);
			YYABORT;
		}
		s = symbol_new(&st, $2);
		// Look for id in sym table
		s = symbol_find(st, $4);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $4);
			YYABORT;
		}
		s = symbol_new(&st, $4);

		$$.head = NULL;
		$$.next = NULL;
		free($2);
		free($4);
	}
	| VAR IDENTIFIER COMMA IDENTIFIER COMMA IDENTIFIER DECL INT END {
		// New integer
		fprintf(stderr, "int identifier ;\n");
		// Look for id in sym table
		symbol s = symbol_find(st, $2);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $2);
			YYABORT;
		}
		s = symbol_new(&st, $2);
		// Look for id in sym table
		s = symbol_find(st, $4);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $4);
			YYABORT;
		}
		s = symbol_new(&st, $4);
		// Look for id in sym table
		s = symbol_find(st, $6);
		if (s != NULL) {
			fprintf(stderr, "The variable %s already exists.\n", $6);
			YYABORT;
		}
		s = symbol_new(&st, $6);
		$$.head = NULL;
		$$.next = NULL;
		free($2);
		free($4);
		free($6);
	}

// Affectation
assign_statement:
	IDENTIFIER ASSIGN expr END {
		// a = something
		fprintf(stderr, "id = EXPRESSION ;\n");
		symbol s = symbol_find(st, $1);
		if (s == NULL) {
			fprintf(stderr, "The variable %s isn't declared.\n", $1);
			YYABORT;
		}
		quad_list ql =
			quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, $3.ptr));
		$3 = update_expr_node($3, s, ql);

		$$.next = NULL;
		$$.head = $3.ql;
		free($1);
	}

expr_statement:
	// EXPR ;
    expr END {
		fprintf(stderr, "expression ;\n");
		$$.next = NULL;
		if ($1.ql == NULL || $1.ql->q == NULL) {
			fprintf(stderr,
					"ERROR: No instruction generated for the expression.\n");
			YYABORT;
		}
		$$.head = $1.ql;
	}

expr:
	IDENTIFIER {
		fprintf(stderr, "identifier\n");
		symbol s = symbol_must_find(st, $1);
		if (s == NULL) {
			YYABORT;
		}
		$$ = update_expr_node($$, s, NULL);
		free($1);
	}

	| CONSTANT {
		fprintf(stderr, "constant\n");
		$$ = update_expr_node($$, symbol_new_const(&st, $1), NULL);
	}

	| '(' expr ')' { $$ = $2; }

	| expr PLUS expr {
		fprintf(stderr, "expr plus expr\n");
		$$ = $3;
		// Create a temporary symbol
		symbol s = symbol_new_temp(&st);
		// Generate and add the quad (+, temporary_symbol, expr1, expr2) to the
		// quad table
		quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_PLUS, s, $1.ptr, $3.ptr));
		// Return the expression's info : its symbols & its quad list
		$$ = update_expr_node($$, s, ql);
	}

	| expr MINUS expr {
		$$ = $1;
		symbol s = symbol_new_temp(&st);
		quad_list ql =
			quad_add(&qt, quad_gen(QUAD_OP_MINUS, s, $1.ptr, $3.ptr));
		$$ = update_expr_node($$, s, ql);
	}

	| expr MULT expr {
		$$ = $3;
		symbol s = symbol_new_temp(&st);
		quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_MULT, s, $1.ptr, $3.ptr));
		$$ = update_expr_node($$, s, ql);
	}

	| expr DIVI expr {
		$$ = $3;
		symbol s = symbol_new_temp(&st);
		quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_DIVI, s, $1.ptr, $3.ptr));
		$$ = update_expr_node($$, s, ql);
	}
%%
  
void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error: %s\n", s);
}

struct expr_node_ update_expr_node(struct expr_node_ node, symbol s, quad_list q){
    node.ptr = s;
	// First initialization
    if(q == NULL)
        node.ql = 0;
    else if(node.ql == NULL && q!= NULL)
        node.ql = q;

    return node;
}

int main(int argc, const char** argv) {
    int status = 0;

    // Args check
    if(argc == 1)
    {
        fprintf(stdout, "Usage: %s [input [output]]\n", argv[0]);
        fprintf(stdout, "Reading from standard input.\n");
        fprintf(stdout, "Output will be saved to out.asm.\n");
		printf("********************************\n");
		printf("********VERBAL HISTORY**********\n");
		printf("********************************\n");
        status = yyparse(); // Default parsing
    }
	
    // Set uncompleted branches to end (exit)
    int rmQuad = 0;
    rmQuad = quad_list_clean_gotos(qt);
    // Debug
    symbol_list_print(st);
    quad_list_print(qt);

    printf("Cleaned %d quad(s) with undefined branch\n", rmQuad);
	
    // Mips
    FILE * out = stdout;
    if(argc == 3)
        out = fopen(argv[2], "w");
    else
        out = fopen("out.asm", "w");
    if(!out) {
        fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
        return -2;
    }

	// Print mips code
    toMips(st,qt, out); 
    fclose(out);

    // End, 
    printf("Cleaning...");
    quad_list_free(qt, true);
    symbol_free_memory(st);
    lex_free();
    printf("OK\n");
    printf("YACC Exit code: %d\n", status);

    return status;
}
