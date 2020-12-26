/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BUILD_Y_SCALPA_H_INCLUDED
# define YY_YY_BUILD_Y_SCALPA_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    VAR = 259,
    DECL = 260,
    COMMA = 261,
    BEGINPROG = 262,
    ENDPROG = 263,
    INT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    FOR = 268,
    RETURN = 269,
    PRINTI = 270,
    ASSIGN = 271,
    PLUS = 272,
    MINUS = 273,
    MULT = 274,
    DIVI = 275,
    END = 276,
    TRUE = 277,
    FALSE = 278,
    OR = 279,
    AND = 280,
    NOT = 281,
    CONSTANT = 282,
    RELOP = 283,
    IDENTIFIER = 284
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define VAR 259
#define DECL 260
#define COMMA 261
#define BEGINPROG 262
#define ENDPROG 263
#define INT 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define RETURN 269
#define PRINTI 270
#define ASSIGN 271
#define PLUS 272
#define MINUS 273
#define MULT 274
#define DIVI 275
#define END 276
#define TRUE 277
#define FALSE 278
#define OR 279
#define AND 280
#define NOT 281
#define CONSTANT 282
#define RELOP 283
#define IDENTIFIER 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "yacc/scalpa.y"

  // for identifiers 
  char* string;
  // for numbers and relops (==, !=, <= ...) 
  int value;
  // head : a link to the first quad of the statement
  // next : list of quad that needs to be completed
  struct statement_node_ {
    struct quad_list_* head;
    struct quad_list_* next;
  } statementData;
  // head : link to the first quad
  // ptr : the resulting symbol 
  struct expr_node_ {
     struct quad_list_* ql;
     struct symbol_* ptr;
  } exprData;

#line 134 "build/y.scalpa.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_Y_SCALPA_H_INCLUDED  */
