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

		 #define SIZE_HASH_TABLE 1000
		 typedef struct {
			 int indice;
			 char* symb_chaine;	// chaine récuperer par l'analyseur syntaxique
			 char* variable;	//NULL si pas une variable
			 P_token* next_doublon;	// si plusieurs memes valeurs de nb_hachage
		 } P_token;

		 P_token** token_tab;


		 void hachage(char *chaine){
			    int i = 0, nombreHache = 0;
			    for (i = 0 ; chaine[i] != '\0' ; i++)
			        nombreHache += chaine[i];
			    nombreHache %= SIZE_HASH_TABLE;
					printf("%s : %i\n", chaine, nombreHache);
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
("read")   				hachage("read");
("if")   					hachage("if");
("then")   				hachage("then");
("else")   				hachage("else");
("while")  		  	hachage("while");
("float")   			hachage("float");
%%

int main(void){
  yylex();
  return 0;
}
