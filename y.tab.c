/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/function.h"
#include "include/mipssy.h"
#include <getopt.h>

struct option longopts[] = {
   { "out",     required_argument, 0,  'o'  },
   { "help",    no_argument,       0,  'h'  },
   { "version", no_argument,       0,  'v'  },
   { "tos",     no_argument,       0,  't'  },
   { NULL, 0, NULL, 0 }
};

extern quad globalcode[100];
extern int nextquad;
extern int ntp;

void yyerror(char*);
int yylex();
void lex_free();

//********* Declarationde tableau ********
void check_indx(char *tab_id, struct index_list *index_list) {
	struct dim_list *dim_tab = lookfor_dims(tab_id);
	if (dim_tab == NULL) {
		printf("failed finding dims\n");
		exit(EXIT_FAILURE);
	}
	int min_dim, max_dim;
	min_dim = dim_tab->min_dim;
	max_dim = dim_tab->max_dim;
	if (index_list->type == INDX_CST) {
		// printf("%d %d %d\n",min_dim, index_list->un.index_int, max_dim);
		if (index_list->un.index_int > max_dim ||
			index_list->un.index_int < min_dim) {
			printf("error index isn't valid");
			exit(EXIT_FAILURE);
		}
	}
	if (index_list->next_indxlist != NULL) {
		dim_tab = dim_tab->next;
		min_dim = dim_tab->min_dim;
		max_dim = dim_tab->max_dim;
		if (index_list->next_indxlist->type == INDX_CST) {
			// printf("%d %d %d\n",min_dim,
			// index_list->next_indxlist->un.index_int, max_dim);
			if (index_list->next_indxlist->un.index_int > max_dim ||
				index_list->next_indxlist->un.index_int < min_dim) {
				printf("error index isn't valid");
				exit(1);
			}
		}
	}
}

struct array_call *array_call_info(char *tab_id,
								   struct index_list *index_list) {
	char *tabid_tabindx = malloc(100);
	sprintf(tabid_tabindx, "%s%s", tab_id, index_list->tab);

	struct array_call *arraycall = malloc(sizeof(array_call));
	arraycall->tab_name = strdup(tab_id);
	arraycall->tab_element = strdup(tabid_tabindx);
	arraycall->head_array = index_list;

	return arraycall;
}

struct index_list *all_indexs(struct index_list *indx, quadop *index) {
	struct index_list *indxlist = malloc(sizeof(index_list));
	char *expr_list = malloc(100);
	if (index->type == QO_CST) {
		sprintf(expr_list, "%s[%d]", indx->tab, index->u.cst);
		indxlist->un.index_int = index->u.cst;
		indxlist->type = INDX_CST;
	} else {
		sprintf(expr_list, "%s[%s]", indx->tab, index->u.name);
		indxlist->un.index_name = strdup(index->u.name);
		indxlist->type = INDX_NAME;
	}
	indxlist->tab = strdup(expr_list);

	indxlist->next_indxlist = indx;
	return indxlist;
}
struct index_list *solo_index(quadop *index) {
	struct index_list *indxlist = malloc(sizeof(index_list));
	char *expr = malloc(100);
	if (index->type == QO_CST) {
		sprintf(expr, "[%d]", index->u.cst);
		indxlist->un.index_int = index->u.cst;
		indxlist->type = INDX_CST;
	} else {
		sprintf(expr, "[%s]", index->u.name);
		indxlist->un.index_name = strdup(index->u.name);
		indxlist->type = INDX_NAME;
	}
	indxlist->tab = strdup(expr);

	indxlist->next_indxlist = NULL;
	return indxlist;
}

//*********ADDITION********* Added dans token_tab.h

dim_list *add_dim(int dim_inf, int dim_sup) {
	dim_list *st_dimension = malloc(sizeof(dim_list));
	st_dimension->min_dim = dim_inf;
	st_dimension->max_dim = dim_sup;
	st_dimension->next = NULL;
	return st_dimension;
}

dim_list *add_dims(dim_list *old_list, int dim_inf, int dim_sup) {
	dim_list *loop_dim = old_list;
	while (loop_dim->next != NULL) loop_dim = loop_dim->next;
	loop_dim->next = add_dim(dim_inf, dim_sup);
	return old_list;
}

void print_dims(dim_list *dims_list) {
	dim_list *loop_dim = dims_list;
	while (loop_dim->next != NULL) {
		printf("dim : %d %d \n", loop_dim->min_dim, loop_dim->max_dim);
		loop_dim = loop_dim->next;
	}
	printf("dim : %d %d \n", loop_dim->min_dim, loop_dim->max_dim);
}
//************************

#line 201 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    INTRV_SEP = 262,
    ID = 263,
    STR = 264,
    NUM = 265,
    UNIT = 266,
    BOOL = 267,
    INT = 268,
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
    SFUNCTION = 291,
    REF = 292,
    IF = 293,
    THEN = 294,
    ELSE = 295,
    WHILE = 296,
    DO = 297,
    RETURN = 298,
    LOWER_THAN_ELSE = 299,
    NEG = 300
  };
#endif
/* Tokens.  */
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
#define XOR 285
#define NOT 286
#define SBEGIN 287
#define SEND 288
#define WRITE 289
#define READ 290
#define SFUNCTION 291
#define REF 292
#define IF 293
#define THEN 294
#define ELSE 295
#define WHILE 296
#define DO 297
#define RETURN 298
#define LOWER_THAN_ELSE 299
#define NEG 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 136 "ar.y" /* yacc.c:355  */

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
	struct array_call *array_call; //ADDITION
	struct index_list *index_list; //ADDITION	

#line 349 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 366 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   199,   200,   201,   203,   204,   206,   207,
     211,   214,   216,   217,   220,   225,   226,   230,   231,   232,
     235,   236,   240,   239,   253,   254,   255,   258,   267,   276,
     285,   293,   299,   308,   316,   322,   328,   329,   335,   342,
     353,   367,   368,   371,   371,   373,   387,   402,   403,   406,
     407,   408,   409,   410,   411,   424,   438,   456,   471,   477,
     483,   488,   493,   503,   510,   519,   520,   521,   522,   523,
     526,   527,   528,   529,   530,   531,   533,   537
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "SARRAY", "SOF",
  "INTRV_SEP", "ID", "STR", "NUM", "UNIT", "BOOL", "INT", "PLUS", "AFFECT",
  "TIMES", "MINUS", "DIVIDE", "POWER", "TRUE", "FALSE", "INF", "INFEQ",
  "SUP", "SUPEQ", "DIFF", "EQ", "AND", "OR", "XOR", "NOT", "SBEGIN",
  "SEND", "WRITE", "READ", "SFUNCTION", "REF", "IF", "THEN", "ELSE",
  "WHILE", "DO", "RETURN", "LOWER_THAN_ELSE", "NEG", "';'", "':'", "','",
  "'['", "']'", "'('", "')'", "$accept", "program", "vardecllist",
  "varsdecl", "identlist", "typename", "arraytype", "rangelist", "lvalue",
  "exprlist", "atomictype", "fundecllist", "fundecl", "$@1", "parlist",
  "par", "instr", "sequence", "semcol", "Elist", "E", "cond", "opb",
  "oprel", "M", "tag", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    58,    44,    91,
      93,    40,    41
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     5,    22,    14,   -57,    23,   -57,   -10,   -57,   -20,
      10,    14,    75,    43,    47,   -57,    19,   -57,    20,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,    59,   123,    10,    69,
      86,   -12,   123,    58,    58,    39,   -57,    58,   104,   -57,
     -57,   115,    73,    82,    81,    88,    39,    58,    33,    89,
     -16,   -35,   -57,   -57,    58,    58,   -57,   186,   186,   -57,
     -57,    39,    39,   172,    79,    39,   186,    58,   130,   136,
     101,   100,    86,   172,    54,    28,   186,   -57,   107,   158,
      29,   -57,   -57,   -57,   -57,   117,   -57,    87,   -57,   -57,
     -57,   -57,   -57,    58,   -57,   127,    -8,   -57,   -57,   -57,
     -57,   -57,   -57,    58,   -57,   -57,   -57,   -19,   186,   108,
     101,   -57,   101,   -57,    58,   -57,   -57,    39,    39,   123,
     -57,   110,   -57,   -57,   -57,   186,    39,    39,   123,   -57,
      69,   -57,   -57,   186,   -57,   -57,    89,   -57,   -57,   132,
     125,   123,   -57,    14,   -57,   -57,   -57,   123,   -57,   -57,
     123,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     1,     0,    77,     3,     8,     0,
      21,     5,     0,     0,     0,    76,     0,     4,     0,    17,
      18,    19,     6,     7,    10,     9,     0,     0,    21,     0,
      26,     0,     0,     0,     0,     0,    76,    35,     0,     2,
      20,     0,     0,     0,     0,    24,     0,     0,     0,    44,
      44,    49,    52,    51,     0,     0,    50,    38,    37,    63,
      64,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,    26,    29,    30,     0,    15,    40,     0,    45,
      48,    43,    42,    36,    76,     0,    57,     0,    65,    67,
      66,    68,    69,     0,    60,     0,     0,    70,    71,    72,
      73,    75,    74,     0,    76,    76,    76,     0,    28,    12,
       0,    27,     0,    25,     0,    14,    39,     0,     0,     0,
      55,     0,    53,    56,    61,    62,     0,     0,     0,    76,
       0,    11,    22,    16,    46,    47,    44,    54,    59,    58,
      31,     0,    13,     5,    41,    77,    33,     0,    76,    23,
       0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -11,   -57,   -57,    93,   -57,    37,   -26,   -57,
      18,   142,   -57,   -57,    99,   -57,   -30,   -57,   -45,   -56,
     -22,   -27,   -57,   -57,   -32,    42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,     9,    22,    23,    42,    56,    75,
      24,    15,    16,   143,    44,    45,    39,    50,    82,    78,
      63,    80,    93,   103,    27,    10
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    38,    49,    46,    65,    84,    38,     1,    64,   104,
     105,    57,    58,     3,    47,    66,    85,    83,     5,    74,
     104,   105,     4,   129,    73,    76,    79,    12,    13,   121,
      81,     8,    86,    87,    94,    96,    11,    47,   107,    48,
      95,    51,    52,    53,   124,   108,    14,    51,    52,    53,
      54,    25,   119,    59,    60,    26,    54,   104,   105,    59,
      60,   134,   135,    79,    61,    28,    51,    52,    53,    29,
      61,   123,   126,   127,   128,    54,   114,   118,   115,    41,
      18,   125,   104,   105,    62,    77,    19,    20,    21,   136,
      62,   144,   133,    38,    43,    79,    79,   141,   140,   138,
     139,    88,    38,    89,    90,    91,    92,   104,   105,    55,
      30,   146,    19,    20,    21,    38,   150,   149,   106,    67,
     151,    38,    68,    69,    38,    51,    52,    53,   131,    70,
     132,    31,   147,    71,    54,    81,    72,    59,    60,   122,
     109,    88,   110,    89,    90,    91,    92,   112,    61,    97,
      98,    99,   100,   101,   102,    32,   130,    33,    34,   116,
     104,    35,   137,   111,    36,   145,    37,   142,    62,   120,
      40,   113,    88,     0,    89,    90,    91,    92,     0,   122,
      97,    98,    99,   100,   101,   102,    88,   148,    89,    90,
      91,    92,     0,     0,    97,    98,    99,   100,   101,   102,
      88,     0,    89,    90,    91,    92,   117
};

static const yytype_int16 yycheck[] =
{
      11,    27,    32,    15,    36,    50,    32,     3,    35,    28,
      29,    33,    34,     8,    49,    37,    51,    33,     4,    46,
      28,    29,     0,    42,    46,    47,    48,    47,    48,    85,
      46,     8,    54,    55,    61,    62,    46,    49,    65,    51,
      62,     8,     9,    10,    52,    67,    36,     8,     9,    10,
      17,     8,    84,    20,    21,     8,    17,    28,    29,    20,
      21,   117,   118,    85,    31,    46,     8,     9,    10,    49,
      31,    93,   104,   105,   106,    17,    48,    48,    50,    10,
       5,   103,    28,    29,    51,    52,    11,    12,    13,   119,
      51,   136,   114,   119,     8,   117,   118,   129,   128,   126,
     127,    14,   128,    16,    17,    18,    19,    28,    29,    51,
      51,   141,    11,    12,    13,   141,   148,   147,    39,    15,
     150,   147,     7,    50,   150,     8,     9,    10,   110,    47,
     112,     8,   143,    52,    17,    46,    48,    20,    21,    52,
      10,    14,     6,    16,    17,    18,    19,    47,    31,    22,
      23,    24,    25,    26,    27,    32,    48,    34,    35,    52,
      28,    38,    52,    70,    41,    40,    43,   130,    51,    52,
      28,    72,    14,    -1,    16,    17,    18,    19,    -1,    52,
      22,    23,    24,    25,    26,    27,    14,   145,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      14,    -1,    16,    17,    18,    19,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,     8,     0,     4,    55,    56,     8,    57,
      78,    46,    47,    48,    36,    64,    65,    55,     5,    11,
      12,    13,    58,    59,    63,     8,     8,    77,    46,    49,
      51,     8,    32,    34,    35,    38,    41,    43,    61,    69,
      64,    10,    60,     8,    67,    68,    15,    49,    51,    69,
      70,     8,     9,    10,    17,    51,    61,    73,    73,    20,
      21,    31,    51,    73,    74,    77,    73,    15,     7,    50,
      47,    52,    48,    73,    74,    62,    73,    52,    72,    73,
      74,    46,    71,    33,    71,    51,    73,    73,    14,    16,
      17,    18,    19,    75,    74,    73,    74,    22,    23,    24,
      25,    26,    27,    76,    28,    29,    39,    74,    73,    10,
       6,    58,    47,    67,    48,    50,    52,    48,    48,    77,
      52,    72,    52,    73,    52,    73,    77,    77,    77,    42,
      48,    63,    63,    73,    72,    72,    69,    52,    74,    74,
      69,    77,    60,    66,    71,    40,    69,    55,    78,    69,
      77,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    62,    62,    63,    63,    63,
      64,    64,    66,    65,    67,    67,    67,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     1,     3,     0,     4,     4,     1,     3,
       1,     6,     3,     5,     4,     1,     3,     1,     1,     1,
       3,     0,     0,    10,     1,     3,     0,     3,     3,     3,
       3,     5,     9,     6,     2,     1,     3,     2,     2,     4,
       3,     5,     2,     1,     0,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     4,     3,     3,     2,     4,     4,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 196 "ar.y" /* yacc.c:1646  */
    {complete((yyvsp[-3].lpos), (yyvsp[-1].actualquad));}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 199 "ar.y" /* yacc.c:1646  */
    {}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 200 "ar.y" /* yacc.c:1646  */
    {}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 201 "ar.y" /* yacc.c:1646  */
    {}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 203 "ar.y" /* yacc.c:1646  */
    {create_symblist("var",(yyvsp[-2].list), (yyvsp[0].strval));}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 204 "ar.y" /* yacc.c:1646  */
    {create_symblist_array("array",(yyvsp[-2].list), "int", (yyvsp[0].dim_list));}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "ar.y" /* yacc.c:1646  */
    {(yyval.list) = create_identlist((yyvsp[0].strval));}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "ar.y" /* yacc.c:1646  */
    {(yyval.list) = add_to_identlist((yyvsp[-2].list), (yyvsp[0].strval));}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "ar.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "ar.y" /* yacc.c:1646  */
    { (yyval.dim_list) = (yyvsp[-3].dim_list); print_dims((yyvsp[-3].dim_list)); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 216 "ar.y" /* yacc.c:1646  */
    { (yyval.dim_list) = add_dim((yyvsp[-2].intval), (yyvsp[0].intval)); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "ar.y" /* yacc.c:1646  */
    { (yyval.dim_list) = add_dims((yyvsp[0].dim_list), (yyvsp[-4].intval), (yyvsp[-2].intval));}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 220 "ar.y" /* yacc.c:1646  */
    { (yyval.array_call) = array_call_info((yyvsp[-3].strval), (yyvsp[-1].index_list)); check_indx((yyvsp[-3].strval), (yyvsp[-1].index_list));
		//printf("%s %s %d\n", $$->tab_name, $$->tab_element , $$->head_array->un.index_int); //print the most right index 
		//printf("%d\n", $$->head_array->next_indxlist->un.index_int);
		}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 225 "ar.y" /* yacc.c:1646  */
    { (yyval.index_list) = solo_index((yyvsp[0].exprval)); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 226 "ar.y" /* yacc.c:1646  */
    { (yyval.index_list) = all_indexs((yyvsp[-2].index_list), (yyvsp[0].exprval)); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 230 "ar.y" /* yacc.c:1646  */
    {(yyval.strval) = "unit";}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "ar.y" /* yacc.c:1646  */
    {(yyval.strval) = "bool";}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 232 "ar.y" /* yacc.c:1646  */
    {(yyval.strval) = "int";}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "ar.y" /* yacc.c:1646  */
    {
			create_symblist("function",create_identlist((yyvsp[-5].strval)), (yyvsp[0].strval));
			add_typelist_to_symb((yyvsp[-5].strval), (yyvsp[-3].typelist));
			quad q = quad_make(Q_FBEGIN, quadop_cst(len_param((yyvsp[-3].typelist))), NULL, quadop_name((yyvsp[-5].strval)));
			gencode(q);
		}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "ar.y" /* yacc.c:1646  */
    {
			quad q = quad_make(Q_FEND, NULL, NULL, quadop_name((yyvsp[-8].strval)));
			gencode(q);
		}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "ar.y" /* yacc.c:1646  */
    {(yyval.typelist) = (yyvsp[0].typelist);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 254 "ar.y" /* yacc.c:1646  */
    { (yyval.typelist) = add_to_typelist((yyvsp[-2].typelist), (yyvsp[0].typelist));}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "ar.y" /* yacc.c:1646  */
    { (yyval.typelist) = NULL;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 259 "ar.y" /* yacc.c:1646  */
    {
		create_symblist("param",create_identlist((yyvsp[-2].strval)), (yyvsp[0].strval));
		(yyval.typelist) = create_typelist((yyvsp[-2].strval), (yyvsp[0].strval));
	}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 267 "ar.y" /* yacc.c:1646  */
    {
			quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, quadop_array((yyvsp[-2].array_call)));
			//printf("%d %d %s %s",$1->i, $1->j, $1->tab_element,$1->tab_name);
			//printf("%s",q.res->u.name);
			gencode(q);
			(yyval.lpos) = crelist(nextquad);
			printf("fin affectation tableau\n");
		}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 277 "ar.y" /* yacc.c:1646  */
    {
		  chk_symb_declared((yyvsp[-2].strval));
		  chk_symb_type((yyvsp[-2].strval),(yyvsp[0].exprval));
		  affect_symb((yyvsp[-2].strval), (yyvsp[0].exprval));
	 	  quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, quadop_name((yyvsp[-2].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 286 "ar.y" /* yacc.c:1646  */
    {
		  chk_symb_declared((yyvsp[-2].strval));
		  chk_symb_type((yyvsp[-2].strval),NULL);
		  quad q = quad_make(Q_AFFECT, reify((yyvsp[0].tf).true, (yyvsp[0].tf).false), NULL, quadop_name((yyvsp[-2].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "ar.y" /* yacc.c:1646  */
    {
		  (yyval.lpos) = NULL;
		  complete((yyvsp[-3].tf).true,(yyvsp[-1].actualquad));
		  (yyval.lpos) = concat((yyvsp[-3].tf).false,(yyvsp[0].lpos));
	  }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "ar.y" /* yacc.c:1646  */
    {
		  complete((yyvsp[-7].tf).true, (yyvsp[-5].actualquad));
		  complete((yyvsp[-7].tf).false, (yyvsp[-1].actualquad));
		  (yyval.lpos) = concat((yyvsp[-4].lpos), (yyvsp[-2].lpos));
		  (yyval.lpos) = concat((yyval.lpos), crelist(nextquad));
		  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		  gencode(q);
	  }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 309 "ar.y" /* yacc.c:1646  */
    {
	  		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
			complete((yyvsp[0].lpos), (yyvsp[-4].actualquad));
			quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst((yyvsp[-4].actualquad)));
			gencode(q);
			(yyval.lpos) = (yyvsp[-3].tf).false;
    }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 317 "ar.y" /* yacc.c:1646  */
    {
		  quad q = quad_make(Q_RET,NULL,NULL,(yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "ar.y" /* yacc.c:1646  */
    {
		  quad q = quad_make(Q_RET,NULL,NULL,NULL);
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 328 "ar.y" /* yacc.c:1646  */
    {(yyval.lpos) = (yyvsp[-1].lpos);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 330 "ar.y" /* yacc.c:1646  */
    {
		  quad q = quad_make(Q_READ, NULL, NULL, (yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "ar.y" /* yacc.c:1646  */
    {
		  quad q = quad_make(Q_WRITE, NULL, NULL, (yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);

	  }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 343 "ar.y" /* yacc.c:1646  */
    {
		  chk_symb_declared((yyvsp[-3].strval));
		  chk_symb_fct((yyvsp[-3].strval));
		  typelist* l = get_typelist((yyvsp[-3].strval));
		  cmp_typelist((yyvsp[-1].typelist), l);
		  int len = gencode_param((yyvsp[-1].typelist));
		  quad q = quad_make(Q_CALL, quadop_cst(len), NULL, quadop_name((yyvsp[-3].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 354 "ar.y" /* yacc.c:1646  */
    {
		  chk_symb_declared((yyvsp[-2].strval));
		  chk_symb_fct((yyvsp[-2].strval));
		  typelist* l = get_typelist((yyvsp[-2].strval));
		  cmp_typelist(NULL, l);
		  int len = gencode_param(NULL);
		  quad q = quad_make(Q_CALL, quadop_cst(len), NULL, quadop_name((yyvsp[-2].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "ar.y" /* yacc.c:1646  */
    {complete((yyvsp[-4].lpos), (yyvsp[-2].actualquad));(yyval.lpos) = (yyvsp[-1].lpos);}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 368 "ar.y" /* yacc.c:1646  */
    { (yyval.lpos) = (yyvsp[-1].lpos);}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 374 "ar.y" /* yacc.c:1646  */
    {
		  if ((yyvsp[0].exprval)->type == QO_CST) // on doit creer une variable temp pour stocker la constante
		  {
			  quadop *t = new_temp();
			  quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, t);
			  gencode(q);
			  create_symblist("var", create_identlist(t->u.name), "int");
			  char *s = get_symb_type_A_char(t->u.name);
			  (yyval.typelist) = create_typelist(t->u.name, s);
		  }
		  else
			  (yyval.typelist) = create_typelist((yyvsp[0].exprval)->u.name, get_symb_type_A_char((yyvsp[0].exprval)->u.name));
	  }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 388 "ar.y" /* yacc.c:1646  */
    {
		  if ((yyvsp[-2].exprval)->type == QO_CST)
		  {
			  quadop *t = new_temp();
			  quad q = quad_make(Q_AFFECT, (yyvsp[-2].exprval), NULL, t);
			  gencode(q);
			  create_symblist("var", create_identlist(t->u.name), "int");
			  char *s = get_symb_type_A_char(t->u.name);
				  (yyval.typelist) = add_to_typelist(create_typelist(t->u.name, get_symb_type_A_char(t->u.name)), (yyvsp[0].typelist));
		  }
		  else
			  (yyval.typelist) = add_to_typelist(create_typelist((yyvsp[-2].exprval)->u.name, get_symb_type_A_char((yyvsp[-2].exprval)->u.name)), (yyvsp[0].typelist));

	  }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 402 "ar.y" /* yacc.c:1646  */
    {(yyval.typelist) = add_to_typelist(create_typelist((reify((yyvsp[-2].tf).true, (yyvsp[-2].tf).false))->u.name, "bool"), (yyvsp[0].typelist));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 403 "ar.y" /* yacc.c:1646  */
    {(yyval.typelist) = create_typelist(reify((yyvsp[0].tf).true, (yyvsp[0].tf).false)->u.name, "bool");}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 406 "ar.y" /* yacc.c:1646  */
    { chk_symb_declared((yyvsp[0].strval)); (yyval.exprval) = quadop_name((yyvsp[0].strval));}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 407 "ar.y" /* yacc.c:1646  */
    { (yyval.exprval) = quadop_array((yyvsp[0].array_call));}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 408 "ar.y" /* yacc.c:1646  */
    {	(yyval.exprval) = quadop_cst((yyvsp[0].intval));}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 409 "ar.y" /* yacc.c:1646  */
    { (yyval.exprval) = quadop_str((yyvsp[0].strval));}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 410 "ar.y" /* yacc.c:1646  */
    { (yyval.exprval) = (yyvsp[-1].exprval);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 412 "ar.y" /* yacc.c:1646  */
    {
	chk_symb_declared((yyvsp[-3].strval));
	chk_symb_fct((yyvsp[-3].strval));
	typelist* l = get_typelist((yyvsp[-3].strval));
	cmp_typelist((yyvsp[-1].typelist), l);
	int len = gencode_param((yyvsp[-1].typelist));
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), get_symb_type_A_char((yyvsp[-3].strval)));
	quad q = quad_make(Q_CALL_AFFECT, quadop_name((yyvsp[-3].strval)),quadop_cst(len), t);
	gencode(q);
	(yyval.exprval) = t;
}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 425 "ar.y" /* yacc.c:1646  */
    {
	chk_symb_declared((yyvsp[-2].strval));
	chk_symb_fct((yyvsp[-2].strval));
	typelist* l = get_typelist((yyvsp[-2].strval));
	cmp_typelist(NULL, l);
	int len = gencode_param(NULL);
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), get_symb_type_A_char((yyvsp[-2].strval)));
	quad q = quad_make(Q_CALL_AFFECT, quadop_name((yyvsp[-2].strval)),quadop_cst(len), t);
	gencode(q);
	(yyval.exprval) = t;

}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 439 "ar.y" /* yacc.c:1646  */
    {
	  if ((yyvsp[-2].exprval)->type == QO_STR || (yyvsp[0].exprval)->type == QO_STR)
	  {
		  yyerror("erreur de type");
		  return 1;
	  }
	  quadop* t = new_temp();
	  create_symblist("var", create_identlist(t->u.name), "int");
	  quad q = quad_make((yyvsp[-1].intval), (yyvsp[-2].exprval), (yyvsp[0].exprval), t);

	  quadop* t_val = malloc(sizeof(quadop)); //faut free ça plus tard
	  affect_opb((yyvsp[-2].exprval), (yyvsp[-1].intval), (yyvsp[0].exprval), t_val);
	  affect_symb(t->u.name, t_val);

	  gencode(q);
	  (yyval.exprval) = t;
}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 457 "ar.y" /* yacc.c:1646  */
    {
	if ((yyvsp[0].exprval)->type == QO_STR)
	{
		yyerror("erreur de type");
		return 1;
	}
	quadop* t = new_temp();
	create_symblist("var", create_identlist(t->u.name), "int");
	quad q = quad_make(Q_NEG, (yyvsp[0].exprval), NULL, t);
	gencode(q);
	(yyval.exprval) = t;
}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 472 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).true = concat ((yyvsp[-3].tf).true, (yyvsp[0].tf).true);
		complete((yyvsp[-3].tf).false, (yyvsp[-1].actualquad));
		(yyval.tf).false = (yyvsp[0].tf).false;
	}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 478 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).false = concat ((yyvsp[-3].tf).false, (yyvsp[0].tf).false);
		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
		(yyval.tf).true = (yyvsp[0].tf).true;
	}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 484 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).true = (yyvsp[0].tf).false;
		(yyval.tf).false = (yyvsp[0].tf).true;
	}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 489 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).true = (yyvsp[-1].tf).true;
		(yyval.tf).false = (yyvsp[-1].tf).false;
	}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 494 "ar.y" /* yacc.c:1646  */
    {
		chk_symb_typeE((yyvsp[-2].exprval), (yyvsp[0].exprval));
		(yyval.tf).true = crelist(nextquad);
		quad q = quad_make((yyvsp[-1].intval),(yyvsp[-2].exprval),(yyvsp[0].exprval),NULL);
		gencode (q); // if ($1 rel $3)     goto ?
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
	}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 504 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).true = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).false = NULL;
	}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 511 "ar.y" /* yacc.c:1646  */
    {
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).true = NULL;
	}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 519 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_PLUS; }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 520 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_MINUS; }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 521 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_TIMES; }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 522 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_DIVIDE; }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 523 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_POWER; }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 526 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_INF; }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 527 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_INFEQ; }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 528 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_SUP; }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 529 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_SUPEQ; }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 530 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_EQ; }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 531 "ar.y" /* yacc.c:1646  */
    { (yyval.intval) = Q_DIFF; }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 533 "ar.y" /* yacc.c:1646  */
    { (yyval.actualquad) = nextquad;}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 537 "ar.y" /* yacc.c:1646  */
    {
	  (yyval.lpos) = crelist(nextquad);
	  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	  gencode(q);
}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2187 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 544 "ar.y" /* yacc.c:1906  */

void yyerror (char *s) {
	fprintf(stderr, "[Yacc] error: %s\n", s);
}


int main(int argc, char** argv) {
	init_symb_tab();
	printf("Enter your code:\n");

	yyparse();

	int c;
	char *filename = NULL;

	while ((c = getopt_long(argc, argv, "o:htv", longopts, NULL)) != -1)
	{
		switch(c)
		{
			case 'v':
				printf("Les membres du groupe sont :\n\t-Céline Ly\n\t-Yassine Lambarki\n\t-Michael Hofmann\n\t-Simon Willer\n");
				break;
			case 'o':
				filename = optarg;
				break;
			case ':':
				fprintf(stderr, "%s: option `-%c' requires an argument\n",argv[0], optopt);
				break;
			case 'h':
				printf("option -version -o -tos\n");
				break;
			case 't':
				printf("-----------------\nSymbol table:\n-----------------\n");
				print_tab();
				printf("-----------------\nSymbol integer:\n-----------------\n");
				print_intvar_name();
				printf("-----------------\nQuad List:\n-----------------\n");
				for (int i=0; i<nextquad; i++) {
					printf("%i ", i);
					affiche(globalcode[i]);
				}
				break;
			case '?':
			default:
				fprintf(stderr, "%s: option `-%c' is invalid: ignored\n",argv[0], optopt);
		        break;
		}
	}

	FILE * out = stdout;

	if(filename == NULL)
		out = fopen("out.asm", "w");
	else
		out = fopen(filename, "w");

	if(!out) {
		fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
	}

	mips_code(globalcode, nextquad, out);
	fclose(out);


	// Be clean.===> Ofc As always
	lex_free();
	//free_quad();
	//free_symbtab();
	return 0;
}

/***
*	Test fonctionnel : creation de variable:
*
*	Ce test contient tout type de symbole afin de recouvrir la totalité
*	des cas : symboles doublons d'indice de hachage mais symb différent,
*	test avec symbole doublon (et donc refus d'ajouter dans la table),
*	ajout symbole classique.
*
*	./ar < file_test/test_declaration_var
*
*
*	Test fonctionnel pour ajouter des affectation d'entiers sur
*	des variables dans la table des symboles
*
*	./ar < file_test/test_affect_variable
****/


/***
 * Truc ultra important! on va considéré que dans une même portée
 * On peut trouver qu'une seule varibale de même nom et type.
 * On se servira de scope pour faire la diff avec 2 variables
 *  de même nom et types quand on aura fait les fonctions
 * ça permet d'implémenter vite et simplement, faudra modifier la fonction
 * en dessous avec la prise ne compte de scope je le fais
 * pas encore ça a pas d'intérêt mais à pas oublier.
 * ***/
