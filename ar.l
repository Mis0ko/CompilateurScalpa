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

("program")   			{output("program");return PROGRAM ;}

"var"   				{output("var");return VAR;}
"int"   				{output("int");return INT;}
"bool"  				{output("int");return BOOL;}
"char"  				{output("int");return CHAR;}
"real"  				{output("int");return REAL;}
"unit"          {output("uint");return UNIT; }

"begin"   			{output("begin");return PBEGIN;}
"end"   				{output("end");return PEND;}


{identifier} {yylval.strval = strdup(yytext);output(yylval.strval); return ID;}
{number}     { yylval.intval = atoi(yytext);output(yytext); return NUM;}
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
