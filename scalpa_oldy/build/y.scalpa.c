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
#line 1 "yacc/scalpa.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "symbol.h"
  #include "quad.h"
  #include "mips.h"

  void lex_free();      // Free the memory used by lex
  void yyerror(char*);  // Just to handle custom message
  symbol st = NULL;     // The symbol table
  quad_list qt = NULL;  // The main quad list

  extern FILE *yyin;    // The input file
  extern int yylex();   
  extern int yyparse();
  
  /**
   * @brief Update the given expr_node
   * Sets the given symbol.
   * Sets the given quad list if haven't been set yet. Usefull to keep track of the first quad
   * of the expression.
   * @param The node
   * @param The symbol
   * @param The quad list containing the quad
   * @return The updated node
   */
  struct expr_node_ update_expr_node(struct expr_node_, symbol, quad_list);

#line 100 "build/y.scalpa.c"

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

#line 243 "build/y.scalpa.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_Y_SCALPA_H_INCLUDED  */



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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


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
      28,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   113,   134,   144,   149,   154,   159,   164,
     170,   192,   226,   252,   258,   266,   281,   302,   320,   333,
     341,   349,   357,   365,   381,   397,   413,   429,   437,   445,
     450,   461,   470,   478,   496,   506,   516,   531,   547,   554
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STENCIL", "IF", "ELSE", "WHILE",
  "FOR", "RETURN", "PRINTI", "ASSIGN", "PLUS", "MINUS", "MULT", "DIVI",
  "INC", "DEC", "END", "TRUE", "FALSE", "OR", "AND", "NOT", "CONSTANT",
  "RELOP", "IDENTIFIER", "LOWER_THAN_ELSE", "'('", "')'", "'{'", "'}'",
  "$accept", "axiom", "statement_list", "statement", "braced_statement",
  "declare_statement", "assign_statement", "expr_statement", "expr",
  "link", "condition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    40,    41,
     123,   125
};
# endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,   -16,    10,    14,    36,   140,   140,    -2,    45,   -21,
       6,   140,    60,    69,   104,   -21,   -21,   -21,   -21,   -21,
     111,    -7,   123,   123,   140,   -11,    35,    35,   -21,   -21,
     140,   -21,   -21,    18,   -21,    82,   -21,   -21,   140,   140,
     140,   140,   -21,   140,   -21,   -21,   -21,   123,   123,    43,
     -13,    19,    67,   147,   -21,   -21,    35,    35,   -21,   -21,
     157,   -21,     0,    30,   140,   123,   123,   104,   104,    56,
     -21,   -21,   -21,    88,    53,   -21,    72,   -21,   -21,   -21,
     104,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      30,     0,     0,     0,     2,     4,     8,     6,     5,     7,
       0,     0,     0,     0,     0,    30,    20,    22,    23,    24,
       0,    25,    26,     0,    13,     0,     1,     3,     0,     0,
       0,     0,    18,     0,    15,    34,    35,     0,     0,     0,
       0,     0,     0,     0,    29,    14,    19,    21,    27,    28,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    16,    39,    33,    36,    37,    10,    12,     9,    32,
       0,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,    71,   -14,   -21,   -21,   -21,   -21,    -4,   -21,
     -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    80,
      50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    26,    27,    51,    43,    31,    32,    33,    65,    66,
      21,    44,    38,    39,    40,    41,    67,    30,    49,    49,
      52,    37,    31,    32,    28,    64,    53,    61,    63,    54,
      38,    39,    40,    41,    56,    57,    58,    59,    22,    60,
      65,    66,    23,    49,    62,    74,    75,    54,    68,    40,
      41,    65,    66,    76,    77,    38,    39,    40,    41,    72,
      73,    49,    49,     1,    24,     2,    81,     3,    64,    36,
       4,    29,     5,     6,    78,    66,     7,     8,    79,    38,
      39,    40,    41,    35,     9,     1,    10,     2,    11,     3,
      12,    34,     4,     0,     5,     6,    69,     0,     7,     8,
      38,    39,    40,    41,     0,     0,     9,     1,    10,     2,
      11,     3,    12,    55,     4,     0,     5,     6,     0,     0,
       7,     8,     0,    38,    39,    40,    41,     0,     9,    42,
      10,     0,    11,     0,    12,     5,     6,     0,     0,     7,
       8,     0,    45,    46,     0,     0,    47,     9,     0,    25,
       0,    48,     5,     6,     0,     0,     7,     8,     0,    38,
      39,    40,    41,     0,     9,    70,    25,     0,    11,    38,
      39,    40,    41,     0,     0,    71
};

static const yytype_int8 yycheck[] =
{
      14,     5,     6,    23,    11,    16,    17,    11,    21,    22,
      26,    18,    12,    13,    14,    15,    29,    11,    22,    23,
      24,    35,    16,    17,    26,    25,    30,    47,    48,    29,
      12,    13,    14,    15,    38,    39,    40,    41,    28,    43,
      21,    22,    28,    47,    48,    65,    66,    29,    29,    14,
      15,    21,    22,    67,    68,    12,    13,    14,    15,    29,
      64,    65,    66,     3,    28,     5,    80,     7,    25,     0,
      10,    26,    12,    13,    18,    22,    16,    17,     6,    12,
      13,    14,    15,    12,    24,     3,    26,     5,    28,     7,
      30,    31,    10,    -1,    12,    13,    29,    -1,    16,    17,
      12,    13,    14,    15,    -1,    -1,    24,     3,    26,     5,
      28,     7,    30,    31,    10,    -1,    12,    13,    -1,    -1,
      16,    17,    -1,    12,    13,    14,    15,    -1,    24,    18,
      26,    -1,    28,    -1,    30,    12,    13,    -1,    -1,    16,
      17,    -1,    19,    20,    -1,    -1,    23,    24,    -1,    26,
      -1,    28,    12,    13,    -1,    -1,    16,    17,    -1,    12,
      13,    14,    15,    -1,    24,    18,    26,    -1,    28,    12,
      13,    14,    15,    -1,    -1,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,    10,    12,    13,    16,    17,    24,
      26,    28,    30,    33,    34,    35,    36,    37,    38,    39,
      40,    26,    28,    28,    28,    26,    40,    40,    26,    26,
      11,    16,    17,    40,    31,    34,     0,    35,    12,    13,
      14,    15,    18,    11,    18,    19,    20,    23,    28,    40,
      42,    42,    40,    40,    29,    31,    40,    40,    40,    40,
      40,    42,    40,    42,    25,    21,    22,    29,    29,    29,
      18,    18,    29,    40,    42,    42,    35,    35,    18,     6,
      41,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    36,    37,    37,    38,    39,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    41,    42,    42,    42,    42,    42,    42,    42
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     5,
       5,     8,     5,     2,     3,     3,     5,     4,     2,     3,
       2,     3,     2,     2,     2,     2,     2,     3,     3,     3,
       1,     1,     0,     3,     1,     1,     3,     3,     2,     3
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
  case 2:
#line 106 "yacc/scalpa.y"
    {
        quad_list_free((yyvsp[0].statementData).next, false);
        // End of the program, next won't be completed 
    }
#line 1488 "build/y.scalpa.c"
    break;

  case 3:
#line 114 "yacc/scalpa.y"
    {
        // Complete previous quads with new statement's head quad
        if((yyvsp[0].statementData).head != NULL)
        {
            quad_list_complete((yyval.statementData).next, (yyvsp[0].statementData).head->q);
            // free list
            quad_list_free((yyval.statementData).next, false); 
            // Each list is a new allocated one, so we need to free it
            // Heriting
            (yyval.statementData).next = (yyvsp[0].statementData).next;
        }
        else
        {
            // If next line isnt an instruction (int a;)
            quad_list ql = quad_list_concat((yyval.statementData).next, (yyvsp[0].statementData).next);
            quad_list_free((yyval.statementData).next, false);
            (yyval.statementData).next = ql;
        }
    }
#line 1512 "build/y.scalpa.c"
    break;

  case 4:
#line 135 "yacc/scalpa.y"
    {
        // Heriting
        // First statement of the program
        (yyval.statementData).next = (yyvsp[0].statementData).next;
        (yyval.statementData).head = (yyvsp[0].statementData).head;
    }
#line 1523 "build/y.scalpa.c"
    break;

  case 5:
#line 145 "yacc/scalpa.y"
    {
        (yyval.statementData) = (yyvsp[0].statementData);
    }
#line 1531 "build/y.scalpa.c"
    break;

  case 6:
#line 150 "yacc/scalpa.y"
    {
        (yyval.statementData) = (yyvsp[0].statementData);
    }
#line 1539 "build/y.scalpa.c"
    break;

  case 7:
#line 155 "yacc/scalpa.y"
    {
        (yyval.statementData) = (yyvsp[0].statementData);
    }
#line 1547 "build/y.scalpa.c"
    break;

  case 8:
#line 160 "yacc/scalpa.y"
    {
        (yyval.statementData) = (yyvsp[0].statementData);
    }
#line 1555 "build/y.scalpa.c"
    break;

  case 9:
#line 165 "yacc/scalpa.y"
    {
        (yyval.statementData).next = NULL;
        (yyval.statementData).head = quad_add(&qt, quad_printi_gen((yyvsp[-2].exprData).ptr));
    }
#line 1564 "build/y.scalpa.c"
    break;

  case 10:
#line 171 "yacc/scalpa.y"
    {
        (yyval.statementData).next = NULL;
        if((yyvsp[0].statementData).head == NULL || (yyvsp[0].statementData).head->q == NULL)
        {
            fprintf(stderr, "ERROR: Empty statement is not allowed inside an if block.\n");
            YYABORT;
        }
        // True goto will go to statement's head
        quad_list_complete((yyvsp[-2].condData).truelist, (yyvsp[0].statementData).head->q);

        // Create the list of quads that need to be completed with the next statement
        // or END if there isn't any
        (yyval.statementData).next = quad_list_concat((yyvsp[-2].condData).falselist, (yyvsp[0].statementData).next);
        // We need the top quad list element, but from the global list
        (yyval.statementData).head = quad_list_find(qt, (yyvsp[-2].condData).top->id);
        // Free true list and false list but not the quads
        quad_list_free((yyvsp[-2].condData).truelist, false);
        quad_list_free((yyvsp[-2].condData).falselist, false);
        quad_list_free((yyvsp[0].statementData).next, false);
    }
#line 1589 "build/y.scalpa.c"
    break;

  case 11:
#line 193 "yacc/scalpa.y"
    {
        // link generated a goto thant quit the if statement instead of 
        // executing the if and the else
        (yyval.statementData).next = NULL;
        if((yyvsp[-3].statementData).head == NULL || (yyvsp[-3].statementData).head->q == NULL)
        {
            fprintf(stderr, "ERROR: Empty statement is not allowed inside an if block.\n");
            YYABORT;
        }
        if((yyvsp[0].statementData).head == NULL || (yyvsp[0].statementData).head->q == NULL)
        {
            fprintf(stderr, "ERROR: Empty statement is not allowed inside an else block.\n");
            YYABORT;
        }
        // Where to go when true
        quad_list_complete((yyvsp[-5].condData).truelist, (yyvsp[-3].statementData).head->q);
        // Where to go when false
        quad_list_complete((yyvsp[-5].condData).falselist, (yyvsp[0].statementData).head->q);

        quad_list qll = NULL;
        qll = quad_list_concat((yyvsp[-3].statementData).next, (yyvsp[0].statementData).next);
        (yyval.statementData).next = quad_list_concat(qll, (yyvsp[0].statementData).next);
        (yyval.statementData).next = quad_list_append(&((yyval.statementData).next), (yyvsp[-1].statementData).head->q);
        quad_list_free(qll, false);
        // We need the top quad list element, but from the global list
        (yyval.statementData).head = quad_list_find(qt, (yyvsp[-5].condData).top->id);
        // Free true list and false list but not the quads
        quad_list_free((yyvsp[-5].condData).truelist, false);
        quad_list_free((yyvsp[-5].condData).falselist, false);
        quad_list_free((yyvsp[-3].statementData).next, false);
        quad_list_free((yyvsp[0].statementData).next, false);
    }
#line 1626 "build/y.scalpa.c"
    break;

  case 12:
#line 227 "yacc/scalpa.y"
    {
        (yyval.statementData).next = NULL;
        if((yyvsp[0].statementData).head == NULL || (yyvsp[0].statementData).head->q == NULL)
        {
            fprintf(stderr, "ERROR: Empty statement is not allowed inside a while block.\n");
            YYABORT;
        }
        quad_list_complete((yyvsp[-2].condData).truelist, (yyvsp[0].statementData).head->q);
        (yyval.statementData).next = (yyvsp[-2].condData).falselist;

        // End while
        // Go to the condition test 
        quad qgo = quad_goto_gen();
        qgo->dest = (yyvsp[-2].condData).top;
        quad_add(&qt, qgo);

        // Top while
        (yyval.statementData).head = quad_list_find(qt, (yyvsp[-2].condData).top->id);
        quad_list_complete((yyvsp[0].statementData).next, (yyvsp[-2].condData).top);
        quad_list_free((yyvsp[-2].condData).truelist, false);
        quad_list_free((yyvsp[0].statementData).next, false);
    }
#line 1653 "build/y.scalpa.c"
    break;

  case 13:
#line 253 "yacc/scalpa.y"
    {
        (yyval.statementData).head = NULL;
        (yyval.statementData).next = NULL;
    }
#line 1662 "build/y.scalpa.c"
    break;

  case 14:
#line 259 "yacc/scalpa.y"
    {
        (yyval.statementData).head = (yyvsp[-1].statementData).head;
        (yyval.statementData).next = (yyvsp[-1].statementData).next;
    }
#line 1671 "build/y.scalpa.c"
    break;

  case 15:
#line 267 "yacc/scalpa.y"
    {
        // New integer
        symbol s = symbol_find(st, (yyvsp[-1].string));
        if(s != NULL)
        {
            fprintf(stderr, "The variable %s already exists.\n", (yyvsp[-1].string));
            YYABORT;
        }
        s = symbol_new(&st, (yyvsp[-1].string));
        (yyval.statementData).head = NULL;
        (yyval.statementData).next = NULL;
        free((yyvsp[-1].string));
    }
#line 1689 "build/y.scalpa.c"
    break;

  case 16:
#line 282 "yacc/scalpa.y"
    {
        // New integer with initialization
        symbol s = symbol_find(st, (yyvsp[-3].string));
        if(s != NULL)
        {
            fprintf(stderr, "The variable %s already exists.\n", s->name);
            YYABORT;
        }
        s = symbol_new(&st, (yyvsp[-3].string));

        quad_list ql = quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, (yyvsp[-1].exprData).ptr));
        (yyvsp[-1].exprData) = update_expr_node((yyvsp[-1].exprData), s, ql);

        (yyval.statementData).next = NULL;
        (yyval.statementData).head = (yyvsp[-1].exprData).ql;
        free((yyvsp[-3].string));
    }
#line 1711 "build/y.scalpa.c"
    break;

  case 17:
#line 303 "yacc/scalpa.y"
    {
        // a = something
        symbol s = symbol_find(st, (yyvsp[-3].string));
        if(s == NULL){
            fprintf(stderr, "The variable %s isn't declared.\n", (yyvsp[-3].string));
            YYABORT;
        }
        quad_list ql = quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, (yyvsp[-1].exprData).ptr));
        (yyvsp[-1].exprData) = update_expr_node((yyvsp[-1].exprData), s, ql);

        (yyval.statementData).next = NULL;
        (yyval.statementData).head = (yyvsp[-1].exprData).ql;
        free((yyvsp[-3].string));
    }
#line 1730 "build/y.scalpa.c"
    break;

  case 18:
#line 321 "yacc/scalpa.y"
    {
        (yyval.statementData).next = NULL;
        if((yyvsp[-1].exprData).ql == NULL || (yyvsp[-1].exprData).ql->q == NULL)
        {
            fprintf(stderr, "ERROR: No instruction generated for the expression.\n");
            YYABORT;
        }
        (yyval.statementData).head = (yyvsp[-1].exprData).ql;
    }
#line 1744 "build/y.scalpa.c"
    break;

  case 19:
#line 334 "yacc/scalpa.y"
    { 
        (yyval.exprData) = (yyvsp[0].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_PLUS, s, (yyvsp[-2].exprData).ptr, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1755 "build/y.scalpa.c"
    break;

  case 20:
#line 342 "yacc/scalpa.y"
    {
        (yyval.exprData) = (yyvsp[0].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_unary_gen(QUAD_UOP_PLUS, s, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1766 "build/y.scalpa.c"
    break;

  case 21:
#line 350 "yacc/scalpa.y"
    {
        (yyval.exprData) = (yyvsp[-2].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_MINUS, s, (yyvsp[-2].exprData).ptr, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1777 "build/y.scalpa.c"
    break;

  case 22:
#line 358 "yacc/scalpa.y"
    {
        (yyval.exprData) = (yyvsp[0].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_unary_gen(QUAD_UOP_MINUS, s, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1788 "build/y.scalpa.c"
    break;

  case 23:
#line 366 "yacc/scalpa.y"
    {
        symbol s = symbol_must_find(st, (yyvsp[0].string)); // Will yell if null
        if(s == NULL)
        {
            YYABORT;
        }
        symbol one = symbol_new_const(&st, 1);
        symbol add = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_PLUS, add, s, one));
        quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, add));
        (yyval.exprData).ql = ql;
        (yyval.exprData).ptr = s;
        free((yyvsp[0].string));
    }
#line 1807 "build/y.scalpa.c"
    break;

  case 24:
#line 382 "yacc/scalpa.y"
    {
        symbol s = symbol_must_find(st, (yyvsp[0].string));
        if(s == NULL)
        {
            YYABORT;
        }
        symbol one = symbol_new_const(&st, 1);
        symbol sub = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_MINUS, sub, s, one));
        quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, sub));
        (yyval.exprData).ql = ql;
        (yyval.exprData).ptr = s;
        free((yyvsp[0].string));
    }
#line 1826 "build/y.scalpa.c"
    break;

  case 25:
#line 398 "yacc/scalpa.y"
    {
        symbol s = symbol_must_find(st, (yyvsp[-1].string));
        if(s == NULL)
        {
            YYABORT;
        }
        symbol one = symbol_new_const(&st, 1);
        symbol add = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_PLUS, add, s, one));
        quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, add));
        (yyval.exprData).ql = ql;
        (yyval.exprData).ptr = s;
        free((yyvsp[-1].string));
    }
#line 1845 "build/y.scalpa.c"
    break;

  case 26:
#line 414 "yacc/scalpa.y"
    {
        symbol s = symbol_must_find(st, (yyvsp[-1].string));
        if(s == NULL)
        {
            YYABORT;
        }
        symbol one = symbol_new_const(&st, 1);
        symbol sub = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_MINUS, sub, s, one));
        quad_add(&qt, quad_unary_gen(QUAD_UOP_ASSIGN, s, sub));
        (yyval.exprData).ql = ql;
        (yyval.exprData).ptr = s;
        free((yyvsp[-1].string));
    }
#line 1864 "build/y.scalpa.c"
    break;

  case 27:
#line 430 "yacc/scalpa.y"
    {
        (yyval.exprData) = (yyvsp[0].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_MULT, s, (yyvsp[-2].exprData).ptr, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1875 "build/y.scalpa.c"
    break;

  case 28:
#line 438 "yacc/scalpa.y"
    { 
        (yyval.exprData) = (yyvsp[0].exprData);
        symbol s = symbol_new_temp(&st);
        quad_list ql = quad_add(&qt, quad_gen(QUAD_OP_DIVI, s, (yyvsp[-2].exprData).ptr, (yyvsp[0].exprData).ptr));
        (yyval.exprData) = update_expr_node((yyval.exprData), s, ql);
    }
#line 1886 "build/y.scalpa.c"
    break;

  case 29:
#line 446 "yacc/scalpa.y"
    {
        (yyval.exprData) = (yyvsp[-1].exprData);
    }
#line 1894 "build/y.scalpa.c"
    break;

  case 30:
#line 451 "yacc/scalpa.y"
    { 
        symbol s = symbol_must_find(st, (yyvsp[0].string));
        if(s == NULL)
        {
            YYABORT;
        }
        (yyval.exprData) = update_expr_node((yyval.exprData), s, NULL);
        free((yyvsp[0].string));
    }
#line 1908 "build/y.scalpa.c"
    break;

  case 31:
#line 462 "yacc/scalpa.y"
    {
        (yyval.exprData) = update_expr_node((yyval.exprData), 
                        symbol_new_const(&st, (yyvsp[0].value)),
                        NULL
                        );
    }
#line 1919 "build/y.scalpa.c"
    break;

  case 32:
#line 470 "yacc/scalpa.y"
  {
        quad qgo = quad_goto_gen();
        (yyval.statementData).head = quad_add(&qt, qgo);
        (yyval.statementData).next = NULL;
  }
#line 1929 "build/y.scalpa.c"
    break;

  case 33:
#line 479 "yacc/scalpa.y"
    {
        (yyval.condData).truelist = NULL;
        (yyval.condData).falselist= NULL;
        quad qif = quad_ifgoto_gen((yyvsp[-2].exprData).ptr, (yyvsp[-1].value), (yyvsp[0].exprData).ptr);
        quad qgo = quad_goto_gen();
        if((yyvsp[-2].exprData).ql != NULL && (yyvsp[-2].exprData).ql->q != NULL)
            (yyval.condData).top = (yyvsp[-2].exprData).ql->q;
        else if((yyvsp[0].exprData).ql != NULL && (yyvsp[0].exprData).ql->q != NULL)
            (yyval.condData).top = (yyvsp[0].exprData).ql->q;
        else
            (yyval.condData).top = qif;
        quad_add(&qt, qif); 
        quad_add(&((yyval.condData).truelist), qif);
        quad_add(&qt, qgo);
        quad_add(&((yyval.condData).falselist), qgo);
    }
#line 1950 "build/y.scalpa.c"
    break;

  case 34:
#line 497 "yacc/scalpa.y"
    {
        (yyval.condData).truelist = NULL;
        (yyval.condData).falselist= NULL;
        quad qgo = quad_goto_gen();
        (yyval.condData).top = qgo;
        quad_add(&qt, qgo);
        quad_add(&((yyval.condData).truelist), qgo);
    }
#line 1963 "build/y.scalpa.c"
    break;

  case 35:
#line 507 "yacc/scalpa.y"
    {
        (yyval.condData).truelist = NULL;
        (yyval.condData).falselist= NULL;
        quad qgo = quad_goto_gen();
        (yyval.condData).top = qgo;
        quad_add(&qt, qgo); 
        quad_add(&((yyval.condData).falselist), qgo);
    }
#line 1976 "build/y.scalpa.c"
    break;

  case 36:
#line 517 "yacc/scalpa.y"
    {
        (yyval.condData).truelist = NULL;
        (yyval.condData).falselist = NULL;
        (yyval.condData).top = (yyvsp[-2].condData).top;

        quad_list_complete((yyvsp[-2].condData).falselist, (yyvsp[0].condData).top);

        (yyval.condData).falselist = (yyvsp[0].condData).falselist;
        (yyval.condData).truelist = quad_list_concat((yyvsp[-2].condData).truelist, (yyvsp[0].condData).truelist);
        quad_list_free((yyvsp[-2].condData).falselist, false);
        quad_list_free((yyvsp[-2].condData).truelist, false);
        quad_list_free((yyvsp[0].condData).truelist, false);
    }
#line 1994 "build/y.scalpa.c"
    break;

  case 37:
#line 532 "yacc/scalpa.y"
    {
        (yyval.condData).truelist = NULL;
        (yyval.condData).falselist = NULL;
        (yyval.condData).top = (yyvsp[-2].condData).top;

        quad_list_complete((yyvsp[-2].condData).truelist, (yyvsp[0].condData).top);

        (yyval.condData).falselist = quad_list_concat((yyvsp[-2].condData).falselist, (yyvsp[0].condData).falselist);
        (yyval.condData).truelist = (yyvsp[0].condData).truelist;

        quad_list_free((yyvsp[-2].condData).falselist, false);
        quad_list_free((yyvsp[-2].condData).truelist, false);
        quad_list_free((yyvsp[0].condData).falselist, false);
    }
#line 2013 "build/y.scalpa.c"
    break;

  case 38:
#line 548 "yacc/scalpa.y"
    {
      (yyval.condData).top = (yyvsp[0].condData).top;
      (yyval.condData).truelist = (yyvsp[0].condData).falselist;
      (yyval.condData).falselist = (yyvsp[0].condData).truelist;
    }
#line 2023 "build/y.scalpa.c"
    break;

  case 39:
#line 555 "yacc/scalpa.y"
    {
      (yyval.condData).truelist = (yyvsp[-1].condData).truelist;
      (yyval.condData).falselist = (yyvsp[-1].condData).falselist;
      (yyval.condData).top = (yyvsp[-1].condData).top;
    }
#line 2033 "build/y.scalpa.c"
    break;


#line 2037 "build/y.scalpa.c"

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
#line 561 "yacc/scalpa.y"

  
void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error: %s\n", s);
}

struct expr_node_ update_expr_node(struct expr_node_ node, symbol s, quad_list q)
{
    node.ptr = s;

    if(q == NULL)
        node.ql = 0; // First init
    else if(node.ql == NULL && q!= NULL)
        node.ql = q;

    return node;
}

int main(int argc, const char** argv) {
    int status = 0;

    // Args check
    if(argc == 1)
    {
        fprintf(stdout, "Usage: %s [input [output]]\n", argv[0]);
        fprintf(stdout, "Reading from standard input.\n");
        fprintf(stdout, "Output will be saved to out.asm.\n");
        status = yyparse(); // Default parsing
    }
    else if(argc >= 2)
    {
        fprintf(stdout, "Reading from %s.\n", argv[1]);
        if(argc == 3)
            fprintf(stdout, "Output will be saved to %s.\n", argv[2]);
        else
            fprintf(stdout, "Output will be saved to out.asm.\n");


        FILE *fi = fopen(argv[1], "r");
        if (!fi) {
            fprintf(stderr, "ERROR: Unable to input the given file %s.\n", argv[1]);
            return -1;
        }
        yyin = fi;
        do
        {
            status = yyparse(); // Parsing from a file
        } while(!feof(yyin) && status == 0);
        fclose(fi);
    }

    // Set uncompleted branches to end (exit)
    int rmQuad = 0;
    rmQuad = quad_list_clean_gotos(qt);
    // Debug
    symbol_list_print(st);
    quad_list_print(qt);
    printf("Cleaned %d quad(s) with undefined branch\n", rmQuad);

    // Mips generation
    FILE * out = stdout;

    if(argc == 3)
        out = fopen(argv[2], "w");
    else
        out = fopen("out.asm", "w");

    if(!out) {
        fprintf(stderr, "ERROR: Unable to open the output file for writing.\n");
        return -2;
    }

    toMips(st,qt, out); // donner out ici
    fclose(out);

    // End, cleanup
    printf("Cleaning...");
    quad_list_free(qt, true);
    symbol_free_memory(st);
    lex_free();
    printf("OK\n");
    printf("YACC Exit code: %d\n", status);

    return status;
}
