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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    SARRAY = 260,
    SOF = 261,
    ID = 262,
    STR = 263,
    NUM = 264,
    UNIT = 265,
    BOOL = 266,
    INT = 267,
    INTRV_SEP = 268,
    PLUS = 269,
    AFFECT = 270,
    TIMES = 271,
    MINUS = 272,
    DIVIDE = 273,
    POWER = 274,
    TRUE = 275,
    FALSE = 276,
    INF = 277,
    INFEQ = 278,
    SUP = 279,
    SUPEQ = 280,
    DIFF = 281,
    EQ = 282,
    AND = 283,
    OR = 284,
    XOR = 285,
    NOT = 286,
    SBEGIN = 287,
    SEND = 288,
    WRITE = 289,
    READ = 290,
    IF = 291,
    THEN = 292,
    ELSE = 293,
    ENDIF = 294,
    WHILE = 295,
    DO = 296,
    DONE = 297,
    RETURN = 298,
    NEG = 299
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define VAR 259
#define SARRAY 260
#define SOF 261
#define ID 262
#define STR 263
#define NUM 264
#define UNIT 265
#define BOOL 266
#define INT 267
#define INTRV_SEP 268
#define PLUS 269
#define AFFECT 270
#define TIMES 271
#define MINUS 272
#define DIVIDE 273
#define POWER 274
#define TRUE 275
#define FALSE 276
#define INF 277
#define INFEQ 278
#define SUP 279
#define SUPEQ 280
#define DIFF 281
#define EQ 282
#define AND 283
#define OR 284
#define XOR 285
#define NOT 286
#define SBEGIN 287
#define SEND 288
#define WRITE 289
#define READ 290
#define IF 291
#define THEN 292
#define ELSE 293
#define ENDIF 294
#define WHILE 295
#define DO 296
#define DONE 297
#define RETURN 298
#define NEG 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "ar.y"

	char *strval;
	int intval;
	struct P_symb **psymb;
	struct ident_list* list;
	struct quadop* exprval;
	struct {
		struct lpos* false;
		struct lpos* true;
	} tf;
	struct lpos* lpos;
	int actualquad;
	struct dim_list* dim_list;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
