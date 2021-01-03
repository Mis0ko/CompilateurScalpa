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
number     [-]?[1-9][0-9]*|"0"
comment    "(*"((\*+[^(*])|([^*]))*\**"*)"
string     ["]([^"]|\\(.|\n))*["]

%%

"program"   			{output("program");return PROGRAM ;}

"var"   				{output("var");return VAR;}
"int"   				{output("int");return INT;}
"bool"  				{output("bool");return BOOL;}
"unit"          	{output("unit");return UNIT; }

"array"          	{output("array");return SARRAY; }
"of"          	{output("of");return SOF; }
".."		 {return INTRV_SEP;}

"begin"   			{output("begin");return SBEGIN;}
"end"   				{output("end");return SEND;}

"+"          { output(yytext);return PLUS; }
"*"          { output(yytext);return TIMES; }
"-"          { output(yytext);return MINUS; }
"/"          { output(yytext);return DIVIDE; }
"^"          { output(yytext);return POWER; }
":="         { output(yytext);return AFFECT; }
"<"          { output(yytext);return INF; }
">"          { output(yytext);return SUP; }
"<="         { output(yytext);return INFEQ; }
">="         { output(yytext);return SUPEQ; }
"<>"         { output(yytext);return DIFF; }
"="          { output(yytext);return EQ; }
"true"       { return TRUE; }
"false"      { return FALSE; }
"and"        { return AND; }
"or"         { return OR; }
"not"        { output(yytext);return NOT; }
"if"         { output(yytext);return IF; }
"then"       { output(yytext);return THEN; }
"else"       { output(yytext);return ELSE; }
"while"      { output(yytext);return WHILE; }
"do"         { output(yytext);return DO; }
"return"	 { output(yytext);return RETURN; }
"write"		 { output(yytext);return WRITE; }
"read"		 { output(yytext);return READ; }
"function"   { output(yytext);return SFUNCTION; }
{identifier} { yylval.strval = strdup(yytext);output(yylval.strval); return ID;}
{number}     { yylval.intval = atoi(yytext);output(yytext); return NUM;}
{string}     {
				yylval.strval = malloc(yyleng -1);
				memcpy(yylval.strval, yytext + 1, yyleng - 2);
				yylval.strval[yyleng - 2] = 0;
				output(yylval.strval); return STR;
			 }
{comment}    { printf("%s\n", yytext);}
[();:,]      { output(yytext);return yytext[0]; }
"["			 { output(yytext); return yytext[0];}
"]"			 { output(yytext); return yytext[0];}
\n           { }
[\t ]        { }
.            { printf("Caractere inconnu: %s", yytext);}
%%
// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
