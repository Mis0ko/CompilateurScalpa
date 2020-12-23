%option nounput
%option noyywrap
%{
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
	#include "y.tab.h"


	char buffer[200];
	void output(const char* msg)
	{
		printf("Analyseur lexical: %s\n", msg);
	}



%}
letter [a-zA-Z]
figure [0-9]
ident {letter}({letter}|{figure})*
nb {figure}+
white    [ \t\n]+


%%
("program")   			{output("key word ");return LEPROGRAM ;}
("var")   				{output("key word : var");return VAR;}
("int")   				{output("key word : int"); return INT;}
("bool")   				{output("key word : int"); return BOOL;}
("char")   				{output("key word : int"); return CHAR;}
("real")   				{output("key word : int"); return REAL;}
("array")   			{output("key word : array"); return ARRAY1;}
("function")   			{output("key word : function");return FUNC;}
("begin")   			{output("key word : begin");return BEGIN1;}
("end")   				{output("key word : end");return END;}
("return")   			{output("key word : return");return RETURN;}
("write")   			{output("key word : write");return WRITE;}
("writeln")   			{output("key word : writeln");return WRITELN;}
("read")   				{output("key word : read");return READ;}
("readln")   			{output("key word : readln");return READLN;}
("if")   				{output("key word : if");return IF;}
("then")   				{output("key word : then");return THEN;}
("else")   				{output("key word : else");return ELSE;}
("while")  		  		{output("key word : while");return WHILE;}


{nb} 								{sprintf(buffer, "NB: %s (nb carac : %d)", yytext, yyleng); output(buffer);return NUMBER;}
{ident} 								{sprintf(buffer, "ID: %s (nb carac : %d)", yytext, yyleng);output(buffer);return IDENT;}
.						{sprintf(buffer, "other %s (nb carac : %d)", yytext, yyleng);output(buffer);}
%%
