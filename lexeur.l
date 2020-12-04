%option nounput
%option noyywrap
%{
	   /* Analyseur Lexical : conversion du texte en entrée
		 en une liste de symboles (tokens). */

		 /*
		 Commande pour compiler et exec le fichier.

		 flex lexeur.l
		 gcc -lfl lex.yy.c -o lexeur_exec
		 ./lexeur_exec < bidon.txt

		 */

	   #include <stdio.h>
     #include <stdlib.h>
		 struct P_token;
		 #define SIZE_HASH_TABLE 1000
		 #define TOK_SIZE 100

		 typedef struct P_token{
		   int indice;
		   char* tok_chaine;	// chaine récuperer par l'analyseur syntaxique
		   char* var_name;	//NULL si pas une variable
		   struct P_token* next_doublon;	// si plusieurs memes valeurs de nb_hachage
		 }P_token;



		 P_token token_tab[SIZE_HASH_TABLE];

		 /*
		 fonction de hachage basique (somme des caractères ASCII)
		 A changer pour de meilleurs perf plus tard
		 */
		 void hachage(char *chaine){
			    int i = 0, nombreHache = 0;
			    for (i = 0 ; chaine[i] != '\0' ; i++)
			        nombreHache += chaine[i];
			    nombreHache %= SIZE_HASH_TABLE;
					printf("%s : %i\n", chaine, nombreHache);
			}


			/*
			function to compare char from a token
			*/
			int cmp_tok_chaine(char* c1, char* c2){
				return strncmp(c1, c2, TOK_SIZE);
			}

			/*
			compare 2 tokens base on all their arguments
			When we use this function we consider that
			the index / hash number is the same.
			*/
			int cmp_tok(P_token* tok1, P_token* tok2)
			{
				if(!cmp_tok_chaine(tok1->tok_chaine, tok2->tok_chaine)){
						if((tok1->var_name != NULL) && (tok2->var_name != NULL)
						&& !cmp_tok_chaine(tok1->var_name, tok2->var_name)){
							return 1;
						}
				}
				return 0;
			}

			/*
			function that check if a token is in the hash table.
			It use the hash number from the structure tok
			and compare to the token in the hash table, and loop
			for all the token that pocess the same hash number

			not tested yet
			*/

			int search_token(P_token* tok){
				P_token* tok_table = &token_tab[tok->indice];
				if(tok_table != NULL){
					while(tok_table != NULL){
						if(cmp_tok(tok, tok_table))
						{
							printf("token present");
							return 1;
						}
						tok_table = tok_table->next_doublon;
					}
				}
				return 0;
			}


			void print_token(P_token* tok)
			{
				printf("	%i	|	%s	", tok->indice, tok-> tok_chaine);
				if(tok->tok_chaine != NULL)
					printf("|	%s	|\n", tok->var_name);
				else
					printf("\n");
			}

			void print_tab()
			{
				 printf("index   |   chaine\n");
				 for(int i =0; i < SIZE_HASH_TABLE ; i++){
					 print_token(&token_tab[i]);
					 if(token_tab[i].next_doublon != NULL)
					 {
						 P_token* tok_parcour = token_tab[i].next_doublon;
						 while(token_tab[i].next_doublon != NULL){
							 print_token(tok_parcour);
						 }
					 }
				 }
			}

%}

%%

("program")   		hachage("program");
("var")   				hachage("var");
("int")   				hachage("int");
("array")   			hachage("array");
("function")   		hachage("function");
("begin")   			hachage("begin");
("end")   				hachage("end");
("return")   			hachage("return");
("write")   			hachage("write");
("writeln")   		hachage("writeln");
("read")   				hachage("read");
("readln")   			hachage("readln");
("if")   					hachage("if");
("then")   				hachage("then");
("else")   				hachage("else");
("while")  		  	hachage("while");
("float")   			hachage("float");
%%

int main(void){
  yylex();
	print_tab();
  return 0;
}
