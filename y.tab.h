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
    NUMBER = 258,
    LEPROGRAM = 259,
    ASSIGN = 260,
    WHILE = 261,
    DO = 262,
    DONE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIVIDE = 271,
    POWER = 272,
    INF = 273,
    INF_EQ = 274,
    SUP = 275,
    SUP_EQ = 276,
    EQ = 277,
    INF_SUP = 278,
    EQUAL = 279,
    TRUE = 280,
    FALSE = 281,
    OR = 282,
    AND = 283,
    NOT = 284,
    XOR = 285,
    PARENTHESE_DROITE = 286,
    PARENTHESE_GAUCHE = 287,
    END = 288,
    IDENT = 289,
    VAR = 290,
    COMA = 291,
    AFFECT = 292,
    INT = 293,
    CHAR = 294,
    REAL = 295,
    BOOL = 296,
    CTE = 297,
    NEG = 298
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define LEPROGRAM 259
#define ASSIGN 260
#define WHILE 261
#define DO 262
#define DONE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define PLUS 268
#define MINUS 269
#define TIMES 270
#define DIVIDE 271
#define POWER 272
#define INF 273
#define INF_EQ 274
#define SUP 275
#define SUP_EQ 276
#define EQ 277
#define INF_SUP 278
#define EQUAL 279
#define TRUE 280
#define FALSE 281
#define OR 282
#define AND 283
#define NOT 284
#define XOR 285
#define PARENTHESE_DROITE 286
#define PARENTHESE_GAUCHE 287
#define END 288
#define IDENT 289
#define VAR 290
#define COMA 291
#define AFFECT 292
#define INT 293
#define CHAR 294
#define REAL 295
#define BOOL 296
#define CTE 297
#define NEG 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "ar.y"

    int ival;
    char* sstring;
    ident_list* list;

#line 149 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
