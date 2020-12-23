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
white   [ \t\n]+
spc [ \t]


%%
("program")   			{output("key word : \tprogram");return LEPROGRAM ;}
("var")   				{output("key word : \tvar");return VAR;}
("int")   				{output("key word : \tint"); return INT;}
("bool")   				{output("key word : \tint"); return BOOL;}
("char")   				{output("key word : \tint"); return CHAR;}
("real")   				{output("key word : \tint"); return REAL;}
("array")   			{output("key word : \tarray"); return ARRAY1;}
("function")   			{output("key word : \tfunction");return FUNC;}
("begin")   			{output("key word : \tbegin");return BEGIN1;}
("end")   				{output("key word : \tend");return END;}
("return")   			{output("key word : \treturn");return RETURN;}
("write")   			{output("key word : \twrite");return WRITE;}
("writeln")   			{output("key word : \twriteln");return WRITELN;}
("read")   				{output("key word : \tread");return READ;}
("readln")   			{output("key word : \treadln");return READLN;}
("if")   				{output("key word : \tif");return IF;}
("then")   				{output("key word : \tthen");return THEN;}
("else")   				{output("key word : \telse");return ELSE;}
("while")  		  		{output("key word : \twhile");return WHILE;}


{nb} 								{sprintf(buffer, "NB: %s (nb carac : %d)", yytext, yyleng); output(buffer);return NUMBER;}
{ident} 								{sprintf(buffer, "ID: %s (nb carac : %d)", yytext, yyleng);output(buffer);return IDENT;}
{spc}							{output("key elem : \tspace"); return SPC;}
{white}							{output("key elem : \tretour white"); return WHITE;}
","								{output("key elem : \t ya une virgule");return COMA;}
"("								{output("key elem : \tparenthese gauche");return PARENTHESE_GAUCHE;}
")"								{output("key elem: \tparenthese droite");return PARENTHESE_DROITE;}

.						{sprintf(buffer, "other %s (nb carac : %d)", yytext, yyleng);output(buffer);}
%%
