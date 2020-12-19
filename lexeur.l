%option nounput
%option noyywrap
%{
	extern int yylval;
	/* Analyseur Lexical : conversion du texte en entrée
	en une liste de symboles (tokens). */

	/*
	Commande pour compiler et exec le fichier.

	flex lexeur.l
	gcc -lfl lex.yy.c -o lexeur_exec
	./lexeur_exec < test_analyseur_syntaxique.txt 


	les trucs à rajouter plus tard:

	faut gérer les minuscules et majusculesp our les mots clés
	genre 
	begin ==> [bB][eE]..... etc


	*/

	#include <stdio.h>
    #include <stdlib.h>



	void yyerror(char *msg) {
  		fprintf(stderr, "%s\n",msg);
	}



%}
letter [a-zA-Z]
figure [0-9]
id {letter}({letter}|{figure})*
nb {figure}+
white    [ \t\n]+



%%
("program")   			{output("key word : program");}
("var")   				{output("key word : var");}
("int")   				{output("key word : int");}
("array")   			{output("key word : array");}
("function")   			{output("key word : function");}
("begin")   			{output("key word : begin");}
("end")   				{output("key word : end");}
("return")   			{output("key word : return");}
("write")   			{output("key word : write");}
("writeln")   			{output("key word : writeln");}
("read")   				{output("key word : read");}
("readln")   			{output("key word : readln");}
("if")   				{output("key word : if");}
("then")   				{output("key word : then");}
("else")   				{output("key word : else");}
("while")  		  		{output("key word : while");}
("float")   			{output("key word : float");}


{nb} 								{sprintf(buffer, "NB: %s (nb carac : %d)", yytext, yyleng); output(buffer);}
{id} 								{sprintf(buffer, "ID: %s (nb carac : %d)", yytext, yyleng);output(buffer);}
"<"|"<="|">="|">"|"=="|"not" 		{sprintf(buffer, "OP_COMP: %s (nb carac : %d)", yytext, yyleng);output(buffer);}
\+|-|or 							{sprintf(buffer, "OP_ADD: %s (nb carac : %d)", yytext, yyleng);output(buffer);}
= 									{sprintf(buffer, "OP_AFF: %s (nb carac : %d)", yytext, yyleng);output(buffer);}
\*|\/|div|mod|and 		{			sprintf(buffer, "OP_MULT: %s (nb carac : %d)", yytext, yyleng);output(buffer);}


{white}  {}


.						{sprintf(buffer, "other %s (nb carac : %d)", yytext, yyleng);output(buffer);}
%%

int main(void){
  yylex();
  //print_tab();
  return 0;
}