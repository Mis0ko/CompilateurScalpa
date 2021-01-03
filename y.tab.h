/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    VAR = 259,                     /* VAR  */
    SARRAY = 260,                  /* SARRAY  */
    SOF = 261,                     /* SOF  */
    INTRV_SEP = 262,               /* INTRV_SEP  */
    ID = 263,                      /* ID  */
    STR = 264,                     /* STR  */
    NUM = 265,                     /* NUM  */
    UNIT = 266,                    /* UNIT  */
    BOOL = 267,                    /* BOOL  */
    INT = 268,                     /* INT  */
    PLUS = 269,                    /* PLUS  */
    AFFECT = 270,                  /* AFFECT  */
    TIMES = 271,                   /* TIMES  */
    MINUS = 272,                   /* MINUS  */
    DIVIDE = 273,                  /* DIVIDE  */
    POWER = 274,                   /* POWER  */
    TRUE = 275,                    /* TRUE  */
    FALSE = 276,                   /* FALSE  */
    INF = 277,                     /* INF  */
    INFEQ = 278,                   /* INFEQ  */
    SUP = 279,                     /* SUP  */
    SUPEQ = 280,                   /* SUPEQ  */
    DIFF = 281,                    /* DIFF  */
    EQ = 282,                      /* EQ  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    NOT = 285,                     /* NOT  */
    SBEGIN = 286,                  /* SBEGIN  */
    SEND = 287,                    /* SEND  */
    WRITE = 288,                   /* WRITE  */
    READ = 289,                    /* READ  */
    SFUNCTION = 290,               /* SFUNCTION  */
    REF = 291,                     /* REF  */
    IF = 292,                      /* IF  */
    THEN = 293,                    /* THEN  */
    ELSE = 294,                    /* ELSE  */
    WHILE = 295,                   /* WHILE  */
    DO = 296,                      /* DO  */
    RETURN = 297,                  /* RETURN  */
    THEN_SIMPLE = 298,             /* THEN_SIMPLE  */
    NEG = 299                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROGRAM 258
#define VAR 259
#define SARRAY 260
#define SOF 261
#define INTRV_SEP 262
#define ID 263
#define STR 264
#define NUM 265
#define UNIT 266
#define BOOL 267
#define INT 268
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
#define NOT 285
#define SBEGIN 286
#define SEND 287
#define WRITE 288
#define READ 289
#define SFUNCTION 290
#define REF 291
#define IF 292
#define THEN 293
#define ELSE 294
#define WHILE 295
#define DO 296
#define RETURN 297
#define THEN_SIMPLE 298
#define NEG 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "scalpa.y"

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
	struct typelist *typelist;
	struct dim_list* dim_list;
	struct array_call *array_call;
	struct index_list *index_list;

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
