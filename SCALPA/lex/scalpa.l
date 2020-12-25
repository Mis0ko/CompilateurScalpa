%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.scalpa.h"
  #include "quad.h"
%}
%option nounput
%option noinput

blank      [\t\b\v\n\f ]*
identifier [a-zA-Z_][0-9a-zA-Z_]*
number     (0|[1-9][0-9]*)
comment    "//".*$

%%

{blank}                 {}
{comment}               {}

"program"				{ return (PROGRAM); }
"var"					{ return (VAR); }
":"						{ return (DECL);}
","						{ return COMMA;}
"begin"					{ return BEGINPROG;}
"end"					{ return ENDPROG;}
":="					{ return ASSIGN;}

"if"                    { return(IF); }
"else"                  { return(ELSE); }

"for"                   { return(FOR); }
"while"                 { return(WHILE); }

"=="                    { yylval.value = QUAD_RELOP_EQ;     return RELOP; }
"!="                    { yylval.value = QUAD_RELOP_NEQ;    return RELOP; }
"<="                    { yylval.value = QUAD_RELOP_LTE;    return RELOP; }
">="                    { yylval.value = QUAD_RELOP_GTE;    return RELOP; }
">"                     { yylval.value = QUAD_RELOP_GT;     return RELOP; }
"<"                     { yylval.value = QUAD_RELOP_LT;     return RELOP; }

"&&"                    { return AND; }
"||"                    { return OR; }
"!"                     { return NOT; }

"true"                  { return TRUE; }
"false"                 { return FALSE; }

"int"                   { return(INT); }

"printi"                { return PRINTI; }
"return"                { return(RETURN); }


"+"                     { return(PLUS); }
"-"                     { return(MINUS); }
"*"                     { return(MULT); }
"/"                     { return(DIVI); }
";"                     { return(END); }
[()]                    { return yytext[0]; }
[{}]                    { return yytext[0]; }

{number}                { yylval.value = atoi(yytext); return CONSTANT; }
{identifier}            { yylval.string = strdup(yytext); return IDENTIFIER; }


.                       { printf("Caractere inconnu: %s\n", yytext); }

%%

// Free the memory allocated for Lex
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}