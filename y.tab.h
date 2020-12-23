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
    FUNC = 260,
    BEGIN1 = 261,
    WRITE = 262,
    WRITELN = 263,
    READ = 264,
    READLN = 265,
    ASSIGN = 266,
    WHILE = 267,
    DO = 268,
    DONE = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ENDIF = 273,
    PLUS = 274,
    MINUS = 275,
    TIMES = 276,
    DIVIDE = 277,
    POWER = 278,
    INF = 279,
    INF_EQ = 280,
    SUP = 281,
    SUP_EQ = 282,
    EQ = 283,
    INF_SUP = 284,
    EQUAL = 285,
    TRUE = 286,
    FALSE = 287,
    OR = 288,
    AND = 289,
    NOT = 290,
    XOR = 291,
    PARENTHESE_DROITE = 292,
    PARENTHESE_GAUCHE = 293,
    END = 294,
    RETURN = 295,
    IDENT = 296,
    VAR = 297,
    ARRAY1 = 298,
    COMA = 299,
    SPC = 300,
    WHITE = 301,
    AFFECT = 302,
    INT = 303,
    CHAR = 304,
    REAL = 305,
    BOOL = 306,
    CTE = 307,
    NEG = 308
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define LEPROGRAM 259
#define FUNC 260
#define BEGIN1 261
#define WRITE 262
#define WRITELN 263
#define READ 264
#define READLN 265
#define ASSIGN 266
#define WHILE 267
#define DO 268
#define DONE 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ENDIF 273
#define PLUS 274
#define MINUS 275
#define TIMES 276
#define DIVIDE 277
#define POWER 278
#define INF 279
#define INF_EQ 280
#define SUP 281
#define SUP_EQ 282
#define EQ 283
#define INF_SUP 284
#define EQUAL 285
#define TRUE 286
#define FALSE 287
#define OR 288
#define AND 289
#define NOT 290
#define XOR 291
#define PARENTHESE_DROITE 292
#define PARENTHESE_GAUCHE 293
#define END 294
#define RETURN 295
#define IDENT 296
#define VAR 297
#define ARRAY1 298
#define COMA 299
#define SPC 300
#define WHITE 301
#define AFFECT 302
#define INT 303
#define CHAR 304
#define REAL 305
#define BOOL 306
#define CTE 307
#define NEG 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "ar.y"

    int ival;
    char* sstring;
    struct ident_list* list;

#line 169 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
