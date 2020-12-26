/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/token_tab.h"
#include "include/fct_utilitaires.h"
#include "include/quad.h"
extern quad globalcode[1000];
extern int nextquad;
extern int ntp;

  symbol st = NULL;     // The symbol table
  
void yyerror(char*);
int yylex();
void lex_free();


int quad_compt;

void translatemips(quad q, FILE* os) {
	if(q.type==Q_AFFECT){
		return ;
	}
	quad_compt++;
	fprintf(os, "\nLABEL_Q_%d:\n", quad_compt);
	switch (q.type) {
		case Q_PLUS:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "    lw $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "    lw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "    lw $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "    lw $t1, VAR_%s_\n", q.op2->u.name);
			// Addition operation
			fprintf(os, "    add $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "    sw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_MINUS:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "    lw $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "    lw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "    lw $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "    lw $t1, VAR_%s_\n", q.op2->u.name);
			// Substraction operation
			fprintf(os, "    sub $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "    sw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_DIVIDE:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "    lw $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "    lw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "    lw $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "    lw $t1, VAR_%s_\n", q.op2->u.name);
			// Signed Division operation
			fprintf(os, "    div $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "    mflo $t2\n");
			// Storing the result
			fprintf(os, "    sw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_TIMES:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "    lw $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "    lw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "    lw $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "    lw $t1, VAR_%s_\n", q.op2->u.name);
			// Signed Multioperation
			fprintf(os, "    mult $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "    mflo $t2\n");
			// Storing the result
			fprintf(os, "    sw $t2, VAR_%s_\n", q.res->u.name);
			break;			
	}
}

void tomips(quad* globalcode, symbol st, FILE* os) {
	fprintf(os, ".data\n");

	while (st != NULL) {
		{
			fprintf(os, "VAR_%s_:\t.word %d\n", st->name, st->value);
		}
		st = st->next;
	}
	fprintf(os, ".text\n");
	fprintf(os, "main:\n");
	quad_compt = 0;
	for (int i = 0; i < nextquad; i++) {
		translatemips(globalcode[i], os);
	}
}




#line 185 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 339 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   163,   163,   166,   167,   173,   174,   176,   178,   179,
     180,   182,   188,   189,   190,   193,   196,   205,   215,   218,
     219,   220,   221,   222,   225,   235,   240,   249,   260,   265,
     270,   271,   272,   277,   284,   285,   286,   290,   291,   292,
     293,   300,   309,   315,   321,   326,   331,   340,   347,   356,
     357,   358,   359,   360,   363,   364,   365,   366,   367,   368,
     370,   374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "PROGRAM", "VAR", "ID", "NUM",
  "UNIT", "BOOL", "INT", "CHAR", "REAL", "PLUS", "AFFECT", "TIMES",
  "MINUS", "DIVIDE", "POWER", "TRUE", "FALSE", "INF", "INFEQ", "SUP",
  "SUPEQ", "DIFF", "EQ", "AND", "OR", "XOR", "NOT", "SBEGIN", "SEND",
  "WRITE", "READ", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "DONE",
  "RETURN", "SFUNCTION", "NEG", "';'", "'('", "')'", "':'", "','",
  "$accept", "program", "commentary", "funcdecllist", "fundecl", "parlist",
  "par", "vardecllist", "varsdecl", "identlist", "typename", "atomictype",
  "instr", "sequence", "E", "cond", "opb", "oprel", "M", "tag", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    59,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,   -56,     4,     3,   -56,    11,    25,    29,    14,   -35,
     -56,   -33,    50,    36,    17,    25,   118,    52,    26,    59,
       5,     7,    70,    13,   -56,     7,   -56,    14,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,    71,     7,   -56,
      34,    42,   -56,   -56,     7,     7,    68,   -56,   -56,   -56,
      13,    13,    99,    18,    13,    68,   -56,    32,    40,    39,
      68,    57,   -56,   -56,    48,   -56,   -56,   -56,   -56,   -56,
       7,   -56,    85,    21,   -56,   -56,   -56,   -56,   -56,   -56,
       7,   -56,   -56,   -56,    -6,   118,    44,    71,    36,   -56,
      68,   -56,    68,    13,    13,    36,   -56,   -56,   118,   -56,
     -56,   -56,    63,    56,    36,    25,   -56,    60,   -56,    36,
     -56,   -56,    36,    66,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     3,     0,     0,     1,     0,    14,     0,     5,    12,
      16,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    29,     2,     5,    13,    19,
      20,    21,    23,    22,    15,    18,    17,     8,     0,    31,
      36,     0,    37,    38,     0,     0,    33,    32,    47,    48,
       0,     0,     0,     0,     0,    28,     6,     0,     0,     9,
      24,    60,    30,    41,     0,    49,    51,    50,    52,    53,
       0,    44,     0,     0,    54,    55,    56,    57,    59,    58,
       0,    60,    60,    60,     0,     0,     0,     8,     0,    39,
      40,    45,    46,     0,     0,     0,    60,    11,     0,    10,
      34,    43,    42,    61,     0,    14,    25,     0,    27,     0,
      60,     7,     0,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,    78,   -56,    31,   -56,   -12,   -56,   -56,
      28,    33,   -13,    45,   -20,   -42,   -56,   -56,   -55,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    14,    58,    59,     8,     9,    11,
      34,    35,    40,    41,    52,    53,    70,    80,    54,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    46,     1,    28,     4,    55,    88,     5,    71,    73,
      15,    19,    84,    42,    43,    16,    17,     6,    60,    42,
      43,    81,    82,    44,    63,    64,    93,    94,    95,    44,
       7,    72,    48,    49,    96,    10,    20,    39,    21,    22,
      23,   104,    19,    50,    24,    81,    82,    25,    81,    82,
      90,   101,   102,    45,    83,   112,    18,    12,    36,    51,
      92,    65,    27,    66,    67,    68,    69,    20,    91,    21,
      22,    23,    37,    38,    62,    24,    47,    57,    25,    61,
      85,    65,   103,    66,    67,    68,    69,    86,    87,   -35,
      81,   108,    98,   109,   106,    89,   111,   110,    65,   113,
      66,    67,    68,    69,   114,    56,    74,    75,    76,    77,
      78,    79,    65,    97,    66,    67,    68,    69,    99,     0,
      74,    75,    76,    77,    78,    79,    29,    30,    31,    32,
      33,   105,    89,   100
};

static const yytype_int8 yycheck[] =
{
      13,    21,     3,    15,     0,    25,    61,     4,    50,    51,
      45,     6,    54,     6,     7,    48,    49,     6,    38,     6,
       7,    27,    28,    16,    44,    45,    81,    82,    83,    16,
       5,    51,    19,    20,    40,     6,    31,    32,    33,    34,
      35,    96,     6,    30,    39,    27,    28,    42,    27,    28,
      70,    93,    94,    46,    36,   110,     6,    43,     6,    46,
      80,    13,    45,    15,    16,    17,    18,    31,    47,    33,
      34,    35,    46,    14,    32,    39,     6,     6,    42,    45,
      48,    13,    95,    15,    16,    17,    18,    47,    49,    32,
      27,   104,    48,   105,    38,    47,   109,    37,    13,   112,
      15,    16,    17,    18,    38,    27,    21,    22,    23,    24,
      25,    26,    13,    85,    15,    16,    17,    18,    87,    -1,
      21,    22,    23,    24,    25,    26,     8,     9,    10,    11,
      12,    98,    47,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,    52,     0,     4,     6,     5,    57,    58,
       6,    59,    43,    53,    54,    45,    48,    49,     6,     6,
      31,    33,    34,    35,    39,    42,    62,    45,    57,     8,
       9,    10,    11,    12,    60,    61,     6,    46,    14,    32,
      62,    63,     6,     7,    16,    46,    64,     6,    19,    20,
      30,    46,    64,    65,    68,    64,    53,     6,    55,    56,
      64,    45,    32,    64,    64,    13,    15,    16,    17,    18,
      66,    65,    64,    65,    21,    22,    23,    24,    25,    26,
      67,    27,    28,    36,    65,    48,    47,    49,    68,    47,
      64,    47,    64,    68,    68,    68,    40,    60,    48,    55,
      63,    65,    65,    62,    68,    61,    38,    69,    62,    57,
      37,    62,    68,    62,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      55,    56,    57,    57,    57,    58,    59,    59,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     0,     0,     3,     9,     0,     1,
       3,     3,     1,     3,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     6,    10,     6,     2,     1,
       3,     2,     2,     2,     4,     2,     1,     1,     1,     3,
       3,     2,     4,     4,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 166 "ar.y"
                    {}
#line 1595 "y.tab.c"
    break;

  case 4:
#line 167 "ar.y"
                          {}
#line 1601 "y.tab.c"
    break;

  case 5:
#line 173 "ar.y"
              {}
#line 1607 "y.tab.c"
    break;

  case 6:
#line 174 "ar.y"
                                                   {}
#line 1613 "y.tab.c"
    break;

  case 8:
#line 178 "ar.y"
          {}
#line 1619 "y.tab.c"
    break;

  case 12:
#line 188 "ar.y"
                      {}
#line 1625 "y.tab.c"
    break;

  case 13:
#line 189 "ar.y"
                                       {}
#line 1631 "y.tab.c"
    break;

  case 14:
#line 190 "ar.y"
                          {}
#line 1637 "y.tab.c"
    break;

  case 15:
#line 193 "ar.y"
                                     {//create_symblist("var",$2, $4);
}
#line 1644 "y.tab.c"
    break;

  case 16:
#line 196 "ar.y"
               {
				symbol s = symbol_find(st, (yyvsp[0].strval));
				if (s != NULL) {
					fprintf(stderr, "The variable %s already exists.\n", (yyvsp[0].strval));
					YYABORT;
				}
				s = symbol_new(&st, (yyvsp[0].strval));
				//$$ = create_identlist($1);
			}
#line 1658 "y.tab.c"
    break;

  case 17:
#line 205 "ar.y"
                                           {
				symbol s = symbol_find(st, (yyvsp[0].strval));
				if (s != NULL) {
					fprintf(stderr, "The variable %s already exists.\n", (yyvsp[0].strval));
					YYABORT;
				}
				s = symbol_new(&st, (yyvsp[0].strval));
				//$$ = add_to_identlist($1, $3);
			}
#line 1672 "y.tab.c"
    break;

  case 18:
#line 215 "ar.y"
                       {(yyval.strval) = (yyvsp[0].strval);}
#line 1678 "y.tab.c"
    break;

  case 19:
#line 218 "ar.y"
                  {(yyval.strval) = "unit";}
#line 1684 "y.tab.c"
    break;

  case 20:
#line 219 "ar.y"
                  {(yyval.strval) = "bool";}
#line 1690 "y.tab.c"
    break;

  case 21:
#line 220 "ar.y"
                  {(yyval.strval) = "int";}
#line 1696 "y.tab.c"
    break;

  case 22:
#line 221 "ar.y"
                  {(yyval.strval) = "real";}
#line 1702 "y.tab.c"
    break;

  case 23:
#line 222 "ar.y"
                          {(yyval.strval) = "char";}
#line 1708 "y.tab.c"
    break;

  case 24:
#line 226 "ar.y"
          {
		  symbol s = symbol_find(st, (yyvsp[-2].strval));
       	 	if(s == NULL){
            fprintf(stderr, "The variable %s isn't declared.\n", (yyvsp[-2].strval));
            YYABORT;
        	}
	 	  quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, quadop_name((yyvsp[-2].strval)));
	 	  gencode(q);
	  }
#line 1722 "y.tab.c"
    break;

  case 25:
#line 236 "ar.y"
          {
		  complete((yyvsp[-4].tf).true,(yyvsp[-2].actualquad));
		  (yyval.lpos) = concat((yyvsp[-4].tf).false,crelist(nextquad));
	  }
#line 1731 "y.tab.c"
    break;

  case 26:
#line 241 "ar.y"
          {
		  complete((yyvsp[-8].tf).true, (yyvsp[-6].actualquad));
		  complete((yyvsp[-8].tf).false, (yyvsp[-2].actualquad));
		  (yyval.lpos) = concat((yyvsp[-5].lpos), (yyvsp[-4].lpos));
		  (yyval.lpos) = concat((yyval.lpos), crelist(nextquad));
		  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		  gencode(q);
	  }
#line 1744 "y.tab.c"
    break;

  case 27:
#line 250 "ar.y"
          {
		  	printf("1");
	  		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
			printf("2");
			complete((yyvsp[0].lpos), (yyvsp[-4].actualquad));
			printf("3");
			quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst((yyvsp[-4].actualquad)));
			gencode(q);
			(yyval.lpos) = (yyvsp[-3].tf).false;
    }
#line 1759 "y.tab.c"
    break;

  case 28:
#line 261 "ar.y"
          {
		  quad q = quad_make(Q_RET,NULL,NULL,(yyvsp[0].exprval));
		  gencode(q);
	  }
#line 1768 "y.tab.c"
    break;

  case 29:
#line 266 "ar.y"
          {
		  quad q = quad_make(Q_RET,NULL,NULL,NULL);
		  gencode(q);
	  }
#line 1777 "y.tab.c"
    break;

  case 30:
#line 270 "ar.y"
                                 { (yyval.lpos) = (yyvsp[-1].lpos); }
#line 1783 "y.tab.c"
    break;

  case 31:
#line 271 "ar.y"
                         { }
#line 1789 "y.tab.c"
    break;

  case 32:
#line 273 "ar.y"
          {
		  quad q = quad_make(Q_READ, NULL, NULL, quadop_name((yyvsp[0].strval)));
		  gencode(q);
	  }
#line 1798 "y.tab.c"
    break;

  case 33:
#line 278 "ar.y"
          {
		  quad q = quad_make(Q_WRITE, NULL, NULL, (yyvsp[0].exprval));
		  gencode(q);
	  }
#line 1807 "y.tab.c"
    break;

  case 34:
#line 284 "ar.y"
                                { complete((yyvsp[-3].lpos), (yyvsp[-1].actualquad)); (yyval.lpos) = (yyvsp[0].lpos); }
#line 1813 "y.tab.c"
    break;

  case 35:
#line 285 "ar.y"
                             { (yyval.lpos) = (yyvsp[-1].lpos); }
#line 1819 "y.tab.c"
    break;

  case 36:
#line 286 "ar.y"
                         { (yyval.lpos) = (yyvsp[0].lpos); }
#line 1825 "y.tab.c"
    break;

  case 37:
#line 290 "ar.y"
       { (yyval.exprval) = quadop_name((yyvsp[0].strval));}
#line 1831 "y.tab.c"
    break;

  case 38:
#line 291 "ar.y"
      { (yyval.exprval) = quadop_cst((yyvsp[0].intval));}
#line 1837 "y.tab.c"
    break;

  case 39:
#line 292 "ar.y"
            { (yyval.exprval) = (yyvsp[-1].exprval);}
#line 1843 "y.tab.c"
    break;

  case 40:
#line 294 "ar.y"
{
	  quadop* t = new_temp();
	  quad q = quad_make((yyvsp[-1].intval), (yyvsp[-2].exprval), (yyvsp[0].exprval), t);
	  gencode(q);
	  (yyval.exprval) = t;
}
#line 1854 "y.tab.c"
    break;

  case 41:
#line 301 "ar.y"
{
	quadop* t = new_temp();
	quad q = quad_make(Q_NEG, (yyvsp[0].exprval), NULL, t);
	gencode(q);
	(yyval.exprval) = t;
}
#line 1865 "y.tab.c"
    break;

  case 42:
#line 310 "ar.y"
        {
		(yyval.tf).true = concat ((yyvsp[-3].tf).true, (yyvsp[0].tf).true);
		complete((yyvsp[-3].tf).false, (yyvsp[-1].actualquad));
		(yyval.tf).false = (yyvsp[0].tf).false;
	}
#line 1875 "y.tab.c"
    break;

  case 43:
#line 316 "ar.y"
        {
		(yyval.tf).false = concat ((yyvsp[-3].tf).false, (yyvsp[0].tf).false);
		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
		(yyval.tf).true = (yyvsp[0].tf).true;
	}
#line 1885 "y.tab.c"
    break;

  case 44:
#line 322 "ar.y"
        {
		(yyval.tf).true = (yyvsp[0].tf).false;
		(yyval.tf).false = (yyvsp[0].tf).true;
	}
#line 1894 "y.tab.c"
    break;

  case 45:
#line 327 "ar.y"
        {
		(yyval.tf).true = (yyvsp[-1].tf).true;
		(yyval.tf).false = (yyvsp[-1].tf).false;
	}
#line 1903 "y.tab.c"
    break;

  case 46:
#line 332 "ar.y"
        {
		(yyval.tf).true = crelist(nextquad);
		quad q = quad_make((yyvsp[-1].intval),(yyvsp[-2].exprval),(yyvsp[0].exprval),NULL);
		gencode (q); // if ($1 rel $3)     goto ?
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
	}
#line 1916 "y.tab.c"
    break;

  case 47:
#line 341 "ar.y"
        {
		(yyval.tf).true = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).false = NULL;
	}
#line 1927 "y.tab.c"
    break;

  case 48:
#line 348 "ar.y"
        {
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).true = NULL;
	}
#line 1938 "y.tab.c"
    break;

  case 49:
#line 356 "ar.y"
           { (yyval.intval) = Q_PLUS; }
#line 1944 "y.tab.c"
    break;

  case 50:
#line 357 "ar.y"
                { (yyval.intval) = Q_MINUS; }
#line 1950 "y.tab.c"
    break;

  case 51:
#line 358 "ar.y"
                { (yyval.intval) = Q_TIMES; }
#line 1956 "y.tab.c"
    break;

  case 52:
#line 359 "ar.y"
                 { (yyval.intval) = Q_DIVIDE; }
#line 1962 "y.tab.c"
    break;

  case 53:
#line 360 "ar.y"
                { (yyval.intval) = Q_POWER; }
#line 1968 "y.tab.c"
    break;

  case 54:
#line 363 "ar.y"
            { (yyval.intval) = Q_INF; }
#line 1974 "y.tab.c"
    break;

  case 55:
#line 364 "ar.y"
                  { (yyval.intval) = Q_INFEQ; }
#line 1980 "y.tab.c"
    break;

  case 56:
#line 365 "ar.y"
                { (yyval.intval) = Q_SUP; }
#line 1986 "y.tab.c"
    break;

  case 57:
#line 366 "ar.y"
                  { (yyval.intval) = Q_SUPEQ; }
#line 1992 "y.tab.c"
    break;

  case 58:
#line 367 "ar.y"
               { (yyval.intval) = Q_EQ; }
#line 1998 "y.tab.c"
    break;

  case 59:
#line 368 "ar.y"
                 { (yyval.intval) = Q_DIFF; }
#line 2004 "y.tab.c"
    break;

  case 60:
#line 370 "ar.y"
    { (yyval.actualquad) = nextquad; }
#line 2010 "y.tab.c"
    break;

  case 61:
#line 374 "ar.y"
{
	  (yyval.lpos) = crelist(nextquad);
	  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	  gencode(q);
}
#line 2020 "y.tab.c"
    break;


#line 2024 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 381 "ar.y"

void yyerror (char *s) {
	fprintf(stderr, "[Yacc] error: %s\n", s);
}


int main(int argc, char** argv) {
	init_symb_tab();
	printf("Enter your code:\n");

	yyparse();
	printf("-----------------\nSymbol table:\n-----------------\n");
	//print_tab();
	printf("Quad list:\n");
	for (int i=0; i<nextquad; i++) {
		affiche(globalcode[i]);
	}
	symbol_list_print(st);
	FILE * out = stdout;

    if(argc == 3)

        out = fopen(argv[2], "w");
    else
        out = fopen("out.asm", "w");

    if(!out) {
        fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
        return -2;
    }

    tomips(globalcode, st,out); // donner out ici
    fclose(out);

    symbol_free_memory(st);
	// Be clean.===> Ofc As always
	lex_free();
	return 0;
}

/*
*	Test fonctionnel : creation de variable:
*
*	Ce test contient tout type de symbole afin de recouvrir la totalité
*	des cas : symboles doublons d'indice de hachage mais symb différent,
*	test avec symbole doublon (et donc refus d'ajouter dans la table),
*	ajout symbole classique.
*
*	./ar < file_test/test_declaration_var
*/
