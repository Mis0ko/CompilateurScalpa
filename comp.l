%option nounput
%option noyywrap
%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
%}

identifier [a-zA-Z_]+[0-9a-zA-Z_]*
number     [1-9][0-9]*

%%
"program"    {return PROGRAM;}
"int"   	 { return INT;}
"unit"       { return UNIT; }
"bool"       { return BOOL; }
"var" 		 { return VAR;}
{identifier} { yylval.strval = strdup(yytext); return ID; }
{number}     { yylval.intval = atoi(yytext); return NUM; }
[();:,]       { return yytext[0]; }
\n           { }
[\t ]        { }
.            { printf("Caractere inconnu: %s", yytext);}
%%
// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
