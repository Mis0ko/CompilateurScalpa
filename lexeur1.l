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
identifier [a-zA-Z_]+[0-9a-zA-Z_]*
number     [1-9][0-9]*

%%
"program"    {return PROGRAM;}
"var"  		 {return VAR;}
"int"   	 { yylval.string = strdup(yytext);return INT;}
"unit"       { yylval.string = strdup(yytext);return UNIT; }
"bool"       { yylval.string = strdup(yytext);return BOOL; }
"array"      {return ARRAY;}
"function"   {return FUNCTION;}
"begin"   	 {return BEGIN;}
"end"   	 {return END;}
"return"   	 {return RETURN;}
"write"    	 {return WRITE;}
"writeln"    {return WRITELN;}
"read"     	 {return READ;}
"readln"     {return READLN;}
"if"         { return IF; }
"while"      { return WHILE; }
"done"       { return DONE; }
"do"         { return DO; }
"then"       { return THEN; }
"else"       { return ELSE; }
"endif"      { return ENDIF; }
"true"       { return TRUE; }
"false"      { return FALSE; }
{identifier} { yylval.string = strdup(yytext); return ID; }
{number}     { yylval.value = atoi(yytext); return NUM; }
[()+*]       { return yytext[0]; }
\n           { return yytext[0]; }
[\t ]        { }
","			 { return COMA; }
";"			 { return SEMICOL;}
.            { printf("Caractere inconnu: %s", yytext);}

%%
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}

int main(void){
  yylex();
  //print_tab();
  return 0;
}
