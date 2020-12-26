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
    COMMENT = 258,
    PROGRAM = 259,
    VAR = 260,
    ID = 261,
    NUM = 262,
    UNIT = 263,
    BOOL = 264,
    INT = 265,
    CHAR = 266,
    REAL = 267,
    PLUS = 268,
    AFFECT = 269,
    TIMES = 270,
    MINUS = 271,
    DIVIDE = 272,
    POWER = 273,
    TRUE = 274,
    FALSE = 275,
    INF = 276,
    INFEQ = 277,
    SUP = 278,
    SUPEQ = 279,
    DIFF = 280,
    EQ = 281,
    AND = 282,
    OR = 283,
    XOR = 284,
    NOT = 285,
    SBEGIN = 286,
    SEND = 287,
    WRITE = 288,
    READ = 289,
    IF = 290,
    THEN = 291,
    ELSE = 292,
    ENDIF = 293,
    WHILE = 294,
    DO = 295,
    DONE = 296,
    RETURN = 297,
    SFUNCTION = 298,
    NEG = 299
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define PROGRAM 259
#define VAR 260
#define ID 261
#define NUM 262
#define UNIT 263
#define BOOL 264
#define INT 265
#define CHAR 266
#define REAL 267
#define PLUS 268
#define AFFECT 269
#define TIMES 270
#define MINUS 271
#define DIVIDE 272
#define POWER 273
#define TRUE 274
#define FALSE 275
#define INF 276
#define INFEQ 277
#define SUP 278
#define SUPEQ 279
#define DIFF 280
#define EQ 281
#define AND 282
#define OR 283
#define XOR 284
#define NOT 285
#define SBEGIN 286
#define SEND 287
#define WRITE 288
#define READ 289
#define IF 290
#define THEN 291
#define ELSE 292
#define ENDIF 293
#define WHILE 294
#define DO 295
#define DONE 296
#define RETURN 297
#define SFUNCTION 298
#define NEG 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 116 "ar.y"

	char *strval;
	int intval;
	struct P_symb **psymb;
	struct ident_list* list;
	struct quadop* exprval;
	struct {
		struct lpos* true;
		struct lpos* false;
	} tf;
	struct lpos* lpos;
	int actualquad;

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
