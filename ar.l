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
"+"          { return PLUS; }
"*"          { return TIMES; }
"-"          { return MINUS; }
"/"          { return DIVIDE; }
"^"          { return POWER; }
":="         { return AFFECT; }
{identifier} { yylval.strval = strdup(yytext); return ID; }
{number}     { yylval.intval = atoi(yytext); return NUM; }
\n           { return yytext[0]; }
[\t ]        { }
[()]         { return yytext[0]; }
.            { printf("[Lex] Unknown character: %s\n", yytext); }

%%

// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
