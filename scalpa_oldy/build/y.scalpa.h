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
    INT = 258,
    STENCIL = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    RETURN = 264,
    PRINTI = 265,
    ASSIGN = 266,
    PLUS = 267,
    MINUS = 268,
    MULT = 269,
    DIVI = 270,
    INC = 271,
    DEC = 272,
    END = 273,
    TRUE = 274,
    FALSE = 275,
    OR = 276,
    AND = 277,
    NOT = 278,
    CONSTANT = 279,
    RELOP = 280,
    IDENTIFIER = 281,
    LOWER_THAN_ELSE = 282
  };
#endif
/* Tokens.  */
#define INT 258
#define STENCIL 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define RETURN 264
#define PRINTI 265
#define ASSIGN 266
#define PLUS 267
#define MINUS 268
#define MULT 269
#define DIVI 270
#define INC 271
#define DEC 272
#define END 273
#define TRUE 274
#define FALSE 275
#define OR 276
#define AND 277
#define NOT 278
#define CONSTANT 279
#define RELOP 280
#define IDENTIFIER 281
#define LOWER_THAN_ELSE 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "yacc/scalpa.y"

  /** @brief Used for identifiers */
  char* string;
  /** @brief Used for numbers and relops (==, !=, <= ...) */
  int value;
  /** @struct bool_node_
   * @brief Attributes of a condition rule
   * @member truelist   quads to completed with true destination
   * @member falselist  quads to completed with false destination
   * @member top        first quad of the condition
   * usefull when there is not in a condition and list are reverted
   */
  struct bool_node_ {
      struct quad_list_* truelist;
      struct quad_list_* falselist;
      struct quad_* top; // Usefull when lists are revert
  } condData;
  /** @struct statement_node_
   * @brief Attributes of a statement
   * @member head   The link list to the first quad of the statement
   * @member next   The list of quads that need to be completed with the next statement's head
   */
  struct statement_node_ {
    struct quad_list_* head;
    struct quad_list_* next;
  } statementData;
  /** @struct expr_node_
   * @brief Attributes of an expression
   * @member ql     The link list to the first quad of the expression
   * @member ptr    The symbol pointer to the resulting symbol of the expr
   */
  struct expr_node_ {
     struct quad_list_* ql;
     struct symbol_* ptr;
  } exprData;

#line 148 "build/y.scalpa.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_Y_SCALPA_H_INCLUDED  */
