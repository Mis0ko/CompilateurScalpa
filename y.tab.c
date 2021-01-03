/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

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
#include <getopt.h>

#include "include/function.h"
#include "include/mipssy.h"
#include "include/array.h"

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


#line 99 "y.tab.c"

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
    XOR = 285,                     /* XOR  */
    NOT = 286,                     /* NOT  */
    SBEGIN = 287,                  /* SBEGIN  */
    SEND = 288,                    /* SEND  */
    WRITE = 289,                   /* WRITE  */
    READ = 290,                    /* READ  */
    SFUNCTION = 291,               /* SFUNCTION  */
    REF = 292,                     /* REF  */
    IF = 293,                      /* IF  */
    THEN = 294,                    /* THEN  */
    ELSE = 295,                    /* ELSE  */
    WHILE = 296,                   /* WHILE  */
    DO = 297,                      /* DO  */
    RETURN = 298,                  /* RETURN  */
    LOWER_THAN_ELSE = 299,         /* LOWER_THAN_ELSE  */
    NEG = 300                      /* NEG  */
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
#line 29 "ar.y"

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

#line 259 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_SARRAY = 5,                     /* SARRAY  */
  YYSYMBOL_SOF = 6,                        /* SOF  */
  YYSYMBOL_INTRV_SEP = 7,                  /* INTRV_SEP  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_UNIT = 11,                      /* UNIT  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_PLUS = 14,                      /* PLUS  */
  YYSYMBOL_AFFECT = 15,                    /* AFFECT  */
  YYSYMBOL_TIMES = 16,                     /* TIMES  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 18,                    /* DIVIDE  */
  YYSYMBOL_POWER = 19,                     /* POWER  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_INF = 22,                       /* INF  */
  YYSYMBOL_INFEQ = 23,                     /* INFEQ  */
  YYSYMBOL_SUP = 24,                       /* SUP  */
  YYSYMBOL_SUPEQ = 25,                     /* SUPEQ  */
  YYSYMBOL_DIFF = 26,                      /* DIFF  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_XOR = 30,                       /* XOR  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_SBEGIN = 32,                    /* SBEGIN  */
  YYSYMBOL_SEND = 33,                      /* SEND  */
  YYSYMBOL_WRITE = 34,                     /* WRITE  */
  YYSYMBOL_READ = 35,                      /* READ  */
  YYSYMBOL_SFUNCTION = 36,                 /* SFUNCTION  */
  YYSYMBOL_REF = 37,                       /* REF  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_THEN = 39,                      /* THEN  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_DO = 42,                        /* DO  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_LOWER_THAN_ELSE = 44,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_NEG = 45,                       /* NEG  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_vardecllist = 55,               /* vardecllist  */
  YYSYMBOL_varsdecl = 56,                  /* varsdecl  */
  YYSYMBOL_identlist = 57,                 /* identlist  */
  YYSYMBOL_typename = 58,                  /* typename  */
  YYSYMBOL_arraytype = 59,                 /* arraytype  */
  YYSYMBOL_rangelist = 60,                 /* rangelist  */
  YYSYMBOL_lvalue = 61,                    /* lvalue  */
  YYSYMBOL_exprlist = 62,                  /* exprlist  */
  YYSYMBOL_atomictype = 63,                /* atomictype  */
  YYSYMBOL_fundecllist = 64,               /* fundecllist  */
  YYSYMBOL_fundecl = 65,                   /* fundecl  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_parlist = 67,                   /* parlist  */
  YYSYMBOL_par = 68,                       /* par  */
  YYSYMBOL_instr = 69,                     /* instr  */
  YYSYMBOL_sequence = 70,                  /* sequence  */
  YYSYMBOL_semcol = 71,                    /* semcol  */
  YYSYMBOL_Elist = 72,                     /* Elist  */
  YYSYMBOL_E = 73,                         /* E  */
  YYSYMBOL_cond = 74,                      /* cond  */
  YYSYMBOL_opb = 75,                       /* opb  */
  YYSYMBOL_oprel = 76,                     /* oprel  */
  YYSYMBOL_M = 77,                         /* M  */
  YYSYMBOL_tag = 78                        /* tag  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    92,    93,    94,    96,    97,    99,   100,
     104,   107,   109,   110,   113,   118,   119,   123,   124,   125,
     128,   129,   133,   132,   146,   147,   148,   151,   160,   169,
     178,   186,   192,   201,   209,   215,   221,   222,   228,   235,
     246,   260,   261,   264,   264,   266,   280,   295,   296,   299,
     300,   301,   302,   303,   304,   317,   331,   349,   364,   370,
     376,   381,   386,   396,   403,   412,   413,   414,   415,   416,
     419,   420,   421,   422,   423,   424,   426,   430
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "VAR",
  "SARRAY", "SOF", "INTRV_SEP", "ID", "STR", "NUM", "UNIT", "BOOL", "INT",
  "PLUS", "AFFECT", "TIMES", "MINUS", "DIVIDE", "POWER", "TRUE", "FALSE",
  "INF", "INFEQ", "SUP", "SUPEQ", "DIFF", "EQ", "AND", "OR", "XOR", "NOT",
  "SBEGIN", "SEND", "WRITE", "READ", "SFUNCTION", "REF", "IF", "THEN",
  "ELSE", "WHILE", "DO", "RETURN", "LOWER_THAN_ELSE", "NEG", "';'", "':'",
  "','", "'['", "']'", "'('", "')'", "$accept", "program", "vardecllist",
  "varsdecl", "identlist", "typename", "arraytype", "rangelist", "lvalue",
  "exprlist", "atomictype", "fundecllist", "fundecl", "$@1", "parlist",
  "par", "instr", "sequence", "semcol", "Elist", "E", "cond", "opb",
  "oprel", "M", "tag", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    58,    44,    91,
      93,    40,    41
};
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
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
static const yytype_int8 yydefact[] =
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
static const yytype_int8 yystos[] =
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
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: PROGRAM ID vardecllist tag fundecllist M instr  */
#line 89 "ar.y"
                                                        {complete((yyvsp[-3].lpos), (yyvsp[-1].actualquad));}
#line 1424 "y.tab.c"
    break;

  case 3: /* vardecllist: varsdecl  */
#line 92 "ar.y"
                      {}
#line 1430 "y.tab.c"
    break;

  case 4: /* vardecllist: varsdecl ';' vardecllist  */
#line 93 "ar.y"
                                       {}
#line 1436 "y.tab.c"
    break;

  case 5: /* vardecllist: %empty  */
#line 94 "ar.y"
                          {}
#line 1442 "y.tab.c"
    break;

  case 6: /* varsdecl: VAR identlist ':' typename  */
#line 96 "ar.y"
                                     {create_symblist("var",(yyvsp[-2].list), (yyvsp[0].strval));}
#line 1448 "y.tab.c"
    break;

  case 7: /* varsdecl: VAR identlist ':' arraytype  */
#line 97 "ar.y"
                                      {create_symblist_array("array",(yyvsp[-2].list), "int", (yyvsp[0].dim_list));}
#line 1454 "y.tab.c"
    break;

  case 8: /* identlist: ID  */
#line 99 "ar.y"
                              {(yyval.list) = create_identlist((yyvsp[0].strval));}
#line 1460 "y.tab.c"
    break;

  case 9: /* identlist: identlist ',' ID  */
#line 100 "ar.y"
                              {(yyval.list) = add_to_identlist((yyvsp[-2].list), (yyvsp[0].strval));}
#line 1466 "y.tab.c"
    break;

  case 10: /* typename: atomictype  */
#line 104 "ar.y"
                       { (yyval.strval) = (yyvsp[0].strval); }
#line 1472 "y.tab.c"
    break;

  case 11: /* arraytype: SARRAY '[' rangelist ']' SOF atomictype  */
#line 107 "ar.y"
                                                    { (yyval.dim_list) = (yyvsp[-3].dim_list); print_dims((yyvsp[-3].dim_list)); }
#line 1478 "y.tab.c"
    break;

  case 12: /* rangelist: NUM INTRV_SEP NUM  */
#line 109 "ar.y"
                              { (yyval.dim_list) = add_dim((yyvsp[-2].intval), (yyvsp[0].intval)); }
#line 1484 "y.tab.c"
    break;

  case 13: /* rangelist: NUM INTRV_SEP NUM ',' rangelist  */
#line 110 "ar.y"
                                                   { (yyval.dim_list) = add_dims((yyvsp[0].dim_list), (yyvsp[-4].intval), (yyvsp[-2].intval));}
#line 1490 "y.tab.c"
    break;

  case 14: /* lvalue: ID '[' exprlist ']'  */
#line 113 "ar.y"
                             { (yyval.array_call) = array_call_info((yyvsp[-3].strval), (yyvsp[-1].index_list)); check_indx((yyvsp[-3].strval), (yyvsp[-1].index_list));
		//printf("%s %s %d\n", $$->tab_name, $$->tab_element , $$->head_array->un.index_int); //print the most right index
		//printf("%d\n", $$->head_array->next_indxlist->un.index_int);
		}
#line 1499 "y.tab.c"
    break;

  case 15: /* exprlist: E  */
#line 118 "ar.y"
                                        { (yyval.index_list) = solo_index((yyvsp[0].exprval)); }
#line 1505 "y.tab.c"
    break;

  case 16: /* exprlist: exprlist ',' E  */
#line 119 "ar.y"
                                   { (yyval.index_list) = all_indexs((yyvsp[-2].index_list), (yyvsp[0].exprval)); }
#line 1511 "y.tab.c"
    break;

  case 17: /* atomictype: UNIT  */
#line 123 "ar.y"
                  {(yyval.strval) = "unit";}
#line 1517 "y.tab.c"
    break;

  case 18: /* atomictype: BOOL  */
#line 124 "ar.y"
                  {(yyval.strval) = "bool";}
#line 1523 "y.tab.c"
    break;

  case 19: /* atomictype: INT  */
#line 125 "ar.y"
                  {(yyval.strval) = "int";}
#line 1529 "y.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 133 "ar.y"
                {
			create_symblist("function",create_identlist((yyvsp[-5].strval)), (yyvsp[0].strval));
			add_typelist_to_symb((yyvsp[-5].strval), (yyvsp[-3].typelist));
			quad q = quad_make(Q_FBEGIN, quadop_cst(len_param((yyvsp[-3].typelist))), NULL, quadop_name((yyvsp[-5].strval)));
			gencode(q);
		}
#line 1540 "y.tab.c"
    break;

  case 23: /* fundecl: SFUNCTION ID '(' parlist ')' ':' atomictype $@1 vardecllist instr  */
#line 140 "ar.y"
                {
			quad q = quad_make(Q_FEND, NULL, NULL, quadop_name((yyvsp[-8].strval)));
			gencode(q);
		}
#line 1549 "y.tab.c"
    break;

  case 24: /* parlist: par  */
#line 146 "ar.y"
              {(yyval.typelist) = (yyvsp[0].typelist);}
#line 1555 "y.tab.c"
    break;

  case 25: /* parlist: par ',' parlist  */
#line 147 "ar.y"
                                  { (yyval.typelist) = add_to_typelist((yyvsp[-2].typelist), (yyvsp[0].typelist));}
#line 1561 "y.tab.c"
    break;

  case 26: /* parlist: %empty  */
#line 148 "ar.y"
                  { (yyval.typelist) = NULL;}
#line 1567 "y.tab.c"
    break;

  case 27: /* par: ID ':' typename  */
#line 152 "ar.y"
        {
		create_symblist("param",create_identlist((yyvsp[-2].strval)), (yyvsp[0].strval));
		(yyval.typelist) = create_typelist((yyvsp[-2].strval), (yyvsp[0].strval));
	}
#line 1576 "y.tab.c"
    break;

  case 28: /* instr: lvalue AFFECT E  */
#line 160 "ar.y"
                                {
			quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, quadop_array((yyvsp[-2].array_call)));
			//printf("%d %d %s %s",$1->i, $1->j, $1->tab_element,$1->tab_name);
			//printf("%s",q.res->u.name);
			gencode(q);
			(yyval.lpos) = crelist(nextquad);
			printf("fin affectation tableau\n");
		}
#line 1589 "y.tab.c"
    break;

  case 29: /* instr: ID AFFECT E  */
#line 170 "ar.y"
          {
		  chk_symb_declared((yyvsp[-2].strval));
		  chk_symb_type((yyvsp[-2].strval),(yyvsp[0].exprval));
		  affect_symb((yyvsp[-2].strval), (yyvsp[0].exprval));
	 	  quad q = quad_make(Q_AFFECT, (yyvsp[0].exprval), NULL, quadop_name((yyvsp[-2].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1602 "y.tab.c"
    break;

  case 30: /* instr: ID AFFECT cond  */
#line 179 "ar.y"
          {
		  chk_symb_declared((yyvsp[-2].strval));
		  chk_symb_type((yyvsp[-2].strval),NULL);
		  quad q = quad_make(Q_AFFECT, reify((yyvsp[0].tf).true, (yyvsp[0].tf).false), NULL, quadop_name((yyvsp[-2].strval)));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1614 "y.tab.c"
    break;

  case 31: /* instr: IF cond THEN M instr  */
#line 187 "ar.y"
          {
		  (yyval.lpos) = NULL;
		  complete((yyvsp[-3].tf).true,(yyvsp[-1].actualquad));
		  (yyval.lpos) = concat((yyvsp[-3].tf).false,(yyvsp[0].lpos));
	  }
#line 1624 "y.tab.c"
    break;

  case 32: /* instr: IF cond THEN M instr ELSE tag M instr  */
#line 193 "ar.y"
          {
		  complete((yyvsp[-7].tf).true, (yyvsp[-5].actualquad));
		  complete((yyvsp[-7].tf).false, (yyvsp[-1].actualquad));
		  (yyval.lpos) = concat((yyvsp[-4].lpos), (yyvsp[-2].lpos));
		  (yyval.lpos) = concat((yyval.lpos), crelist(nextquad));
		  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		  gencode(q);
	  }
#line 1637 "y.tab.c"
    break;

  case 33: /* instr: WHILE M cond DO M instr  */
#line 202 "ar.y"
          {
	  		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
			complete((yyvsp[0].lpos), (yyvsp[-4].actualquad));
			quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst((yyvsp[-4].actualquad)));
			gencode(q);
			(yyval.lpos) = (yyvsp[-3].tf).false;
    }
#line 1649 "y.tab.c"
    break;

  case 34: /* instr: RETURN E  */
#line 210 "ar.y"
          {
		  quad q = quad_make(Q_RET,NULL,NULL,(yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1659 "y.tab.c"
    break;

  case 35: /* instr: RETURN  */
#line 216 "ar.y"
          {
		  quad q = quad_make(Q_RET,NULL,NULL,NULL);
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1669 "y.tab.c"
    break;

  case 36: /* instr: SBEGIN sequence SEND  */
#line 221 "ar.y"
                                 {(yyval.lpos) = (yyvsp[-1].lpos);}
#line 1675 "y.tab.c"
    break;

  case 37: /* instr: READ E  */
#line 223 "ar.y"
          {
		  quad q = quad_make(Q_READ, NULL, NULL, (yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);
	  }
#line 1685 "y.tab.c"
    break;

  case 38: /* instr: WRITE E  */
#line 229 "ar.y"
          {
		  quad q = quad_make(Q_WRITE, NULL, NULL, (yyvsp[0].exprval));
		  gencode(q);
		  (yyval.lpos) = crelist(nextquad);

	  }
#line 1696 "y.tab.c"
    break;

  case 39: /* instr: ID '(' Elist ')'  */
#line 236 "ar.y"
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
#line 1711 "y.tab.c"
    break;

  case 40: /* instr: ID '(' ')'  */
#line 247 "ar.y"
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
#line 1726 "y.tab.c"
    break;

  case 41: /* sequence: sequence semcol M instr semcol  */
#line 260 "ar.y"
                                          {complete((yyvsp[-4].lpos), (yyvsp[-2].actualquad));(yyval.lpos) = (yyvsp[-1].lpos);}
#line 1732 "y.tab.c"
    break;

  case 42: /* sequence: instr semcol  */
#line 261 "ar.y"
                                { (yyval.lpos) = (yyvsp[-1].lpos);}
#line 1738 "y.tab.c"
    break;

  case 45: /* Elist: E  */
#line 267 "ar.y"
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
#line 1756 "y.tab.c"
    break;

  case 46: /* Elist: E ',' Elist  */
#line 281 "ar.y"
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
#line 1775 "y.tab.c"
    break;

  case 47: /* Elist: cond ',' Elist  */
#line 295 "ar.y"
                           {(yyval.typelist) = add_to_typelist(create_typelist((reify((yyvsp[-2].tf).true, (yyvsp[-2].tf).false))->u.name, "bool"), (yyvsp[0].typelist));}
#line 1781 "y.tab.c"
    break;

  case 48: /* Elist: cond  */
#line 296 "ar.y"
                 {(yyval.typelist) = create_typelist(reify((yyvsp[0].tf).true, (yyvsp[0].tf).false)->u.name, "bool");}
#line 1787 "y.tab.c"
    break;

  case 49: /* E: ID  */
#line 299 "ar.y"
       { chk_symb_declared((yyvsp[0].strval)); (yyval.exprval) = quadop_name((yyvsp[0].strval));}
#line 1793 "y.tab.c"
    break;

  case 50: /* E: lvalue  */
#line 300 "ar.y"
         { (yyval.exprval) = quadop_array((yyvsp[0].array_call));}
#line 1799 "y.tab.c"
    break;

  case 51: /* E: NUM  */
#line 301 "ar.y"
      {	(yyval.exprval) = quadop_cst((yyvsp[0].intval));}
#line 1805 "y.tab.c"
    break;

  case 52: /* E: STR  */
#line 302 "ar.y"
      { (yyval.exprval) = quadop_str((yyvsp[0].strval));}
#line 1811 "y.tab.c"
    break;

  case 53: /* E: '(' E ')'  */
#line 303 "ar.y"
            { (yyval.exprval) = (yyvsp[-1].exprval);}
#line 1817 "y.tab.c"
    break;

  case 54: /* E: ID '(' Elist ')'  */
#line 305 "ar.y"
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
#line 1834 "y.tab.c"
    break;

  case 55: /* E: ID '(' ')'  */
#line 318 "ar.y"
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
#line 1852 "y.tab.c"
    break;

  case 56: /* E: E opb E  */
#line 332 "ar.y"
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
#line 1874 "y.tab.c"
    break;

  case 57: /* E: MINUS E  */
#line 350 "ar.y"
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
#line 1891 "y.tab.c"
    break;

  case 58: /* cond: cond OR M cond  */
#line 365 "ar.y"
        {
		(yyval.tf).true = concat ((yyvsp[-3].tf).true, (yyvsp[0].tf).true);
		complete((yyvsp[-3].tf).false, (yyvsp[-1].actualquad));
		(yyval.tf).false = (yyvsp[0].tf).false;
	}
#line 1901 "y.tab.c"
    break;

  case 59: /* cond: cond AND M cond  */
#line 371 "ar.y"
        {
		(yyval.tf).false = concat ((yyvsp[-3].tf).false, (yyvsp[0].tf).false);
		complete((yyvsp[-3].tf).true, (yyvsp[-1].actualquad));
		(yyval.tf).true = (yyvsp[0].tf).true;
	}
#line 1911 "y.tab.c"
    break;

  case 60: /* cond: NOT cond  */
#line 377 "ar.y"
        {
		(yyval.tf).true = (yyvsp[0].tf).false;
		(yyval.tf).false = (yyvsp[0].tf).true;
	}
#line 1920 "y.tab.c"
    break;

  case 61: /* cond: '(' cond ')'  */
#line 382 "ar.y"
        {
		(yyval.tf).true = (yyvsp[-1].tf).true;
		(yyval.tf).false = (yyvsp[-1].tf).false;
	}
#line 1929 "y.tab.c"
    break;

  case 62: /* cond: E oprel E  */
#line 387 "ar.y"
        {
		chk_symb_typeE((yyvsp[-2].exprval), (yyvsp[0].exprval));
		(yyval.tf).true = crelist(nextquad);
		quad q = quad_make((yyvsp[-1].intval),(yyvsp[-2].exprval),(yyvsp[0].exprval),NULL);
		gencode (q); // if ($1 rel $3)     goto ?
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
	}
#line 1943 "y.tab.c"
    break;

  case 63: /* cond: TRUE  */
#line 397 "ar.y"
        {
		(yyval.tf).true = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).false = NULL;
	}
#line 1954 "y.tab.c"
    break;

  case 64: /* cond: FALSE  */
#line 404 "ar.y"
        {
		(yyval.tf).false = crelist(nextquad);
		quad q2 = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
		gencode(q2);
		(yyval.tf).true = NULL;
	}
#line 1965 "y.tab.c"
    break;

  case 65: /* opb: PLUS  */
#line 412 "ar.y"
           { (yyval.intval) = Q_PLUS; }
#line 1971 "y.tab.c"
    break;

  case 66: /* opb: MINUS  */
#line 413 "ar.y"
                { (yyval.intval) = Q_MINUS; }
#line 1977 "y.tab.c"
    break;

  case 67: /* opb: TIMES  */
#line 414 "ar.y"
                { (yyval.intval) = Q_TIMES; }
#line 1983 "y.tab.c"
    break;

  case 68: /* opb: DIVIDE  */
#line 415 "ar.y"
                 { (yyval.intval) = Q_DIVIDE; }
#line 1989 "y.tab.c"
    break;

  case 69: /* opb: POWER  */
#line 416 "ar.y"
                { (yyval.intval) = Q_POWER; }
#line 1995 "y.tab.c"
    break;

  case 70: /* oprel: INF  */
#line 419 "ar.y"
            { (yyval.intval) = Q_INF; }
#line 2001 "y.tab.c"
    break;

  case 71: /* oprel: INFEQ  */
#line 420 "ar.y"
                  { (yyval.intval) = Q_INFEQ; }
#line 2007 "y.tab.c"
    break;

  case 72: /* oprel: SUP  */
#line 421 "ar.y"
                { (yyval.intval) = Q_SUP; }
#line 2013 "y.tab.c"
    break;

  case 73: /* oprel: SUPEQ  */
#line 422 "ar.y"
                  { (yyval.intval) = Q_SUPEQ; }
#line 2019 "y.tab.c"
    break;

  case 74: /* oprel: EQ  */
#line 423 "ar.y"
               { (yyval.intval) = Q_EQ; }
#line 2025 "y.tab.c"
    break;

  case 75: /* oprel: DIFF  */
#line 424 "ar.y"
                 { (yyval.intval) = Q_DIFF; }
#line 2031 "y.tab.c"
    break;

  case 76: /* M: %empty  */
#line 426 "ar.y"
    { (yyval.actualquad) = nextquad;}
#line 2037 "y.tab.c"
    break;

  case 77: /* tag: %empty  */
#line 430 "ar.y"
{
	  (yyval.lpos) = crelist(nextquad);
	  quad q = quad_make(Q_GOTO,NULL,NULL,quadop_cst(-1));
	  gencode(q);
}
#line 2047 "y.tab.c"
    break;


#line 2051 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 437 "ar.y"

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
