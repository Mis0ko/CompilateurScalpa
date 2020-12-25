%option nounput
%option noyywrap
%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"


	char buffer[200];
	void output(char* msg)
	{
		printf("Analyseur lexical:\t%s\n", msg);
	}
%}

identifier [a-zA-Z_]+[0-9a-zA-Z_]*
number     [1-9][0-9]*

%%

"program"   			{output("program");return PROGRAM ;}

"var"   				{output("var");return VAR;}
"int"   				{output("int");return INT;}
"bool"  				{output("bool");return BOOL;}
"char"  				{output("char");return CHAR;}
"real"  				{output("real");return REAL;}
"uint"          {output("unit");return UNIT; }

"begin"   			{output("begin");return SBEGIN;}
"end"   				{output("end");return SEND;}

"+"          { return PLUS; }
"*"          { return TIMES; }
"-"          { return MINUS; }
"/"          { return DIVIDE; }
"^"          { return POWER; }
":="         { return AFFECT; }
"<"          { return INF; }
">"          { return SUP; }
"<="         { return INFEQ; }
">="         { return SUPEQ; }
"<>"         { return DIFF; }
"="          { return EQ; }
"true"       { return TRUE; }
"false"      { return FALSE; }
"and"        { return AND; }
"or"         { return OR; }
"xor"        { return XOR; }
"not"        { return NOT; }
"if"         { return IF; }
"then"       { return THEN; }
"else"       { return ELSE; }
"endif"      { return ENDIF; }
"while"      { return WHILE; }
"done"       { return DONE; }
"do"         { return DO; }
"return"	 { return RETURN; }
"write"		 { return WRITE; }
"read"		 { return READ; }

{identifier} {yylval.strval = strdup(yytext);output(yylval.strval); return ID;}
{number}     { yylval.intval = atoi(yytext);output(yytext); return NUM;}
"0" 		 { yylval.intval = atoi(yytext); return NUM; }

[();:,]       {return yytext[0]; }
\n           { }
[\t ]        { }
.            { printf("Caractere inconnu: %s", yytext);}
%%
// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
