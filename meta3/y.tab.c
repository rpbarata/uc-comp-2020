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
#line 1 "uccompiler.y"

  #include "ast.h"
  #include "structs.h"
  int yylex(void);
  void yyerror (char *s);
  extern int line;
  extern int yyleng;
  extern int column;
  extern char* yytext;
  extern int flag;
  extern int errorFlag;
  Node node1;
  Node node2;


#line 86 "y.tab.c"

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
    CHAR = 258,
    ELSE = 259,
    WHILE = 260,
    IF = 261,
    INT = 262,
    SHORT = 263,
    DOUBLE = 264,
    RETURN = 265,
    VOID = 266,
    BITWISEAND = 267,
    BITWISEOR = 268,
    BITWISEXOR = 269,
    AND = 270,
    ASSIGN = 271,
    MUL = 272,
    COMMA = 273,
    DIV = 274,
    EQ = 275,
    GE = 276,
    GT = 277,
    LBRACE = 278,
    LE = 279,
    LPAR = 280,
    LT = 281,
    MINUS = 282,
    MOD = 283,
    NE = 284,
    NOT = 285,
    OR = 286,
    PLUS = 287,
    RBRACE = 288,
    RPAR = 289,
    SEMI = 290,
    RESERVED = 291,
    REALLIT = 292,
    INTLIT = 293,
    CHRLIT = 294,
    ID = 295,
    NOELSE = 296
  };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define REALLIT 292
#define INTLIT 293
#define CHRLIT 294
#define ID 295
#define NOELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "uccompiler.y"

  char *value;
  Node node;

#line 225 "y.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    39,    43,    44,    45,    49,    50,    54,
      58,    59,    63,    64,    65,    66,    70,    74,    78,    79,
      83,    84,    88,    98,   102,   106,   107,   111,   112,   113,
     114,   115,   119,   120,   124,   125,   126,   127,   132,   133,
     138,   142,   145,   146,   150,   151,   155,   156,   160,   161,
     165,   166,   170,   171,   175,   176,   180,   181,   185,   186,
     190,   191,   195,   196,   197,   201,   202,   203,   204,   205,
     209,   210,   211,   215,   216,   217,   218,   222,   223,   224,
     225,   229,   230,   233,   234,   235,   236,   240,   241,   242,
     243,   244,   245
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "RESERVED", "REALLIT", "INTLIT", "CHRLIT",
  "ID", "NOELSE", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionsAndDeclarationsMandatory",
  "FunctionsAndDeclarationsZeroOrMore", "FunctionDefinition",
  "FunctionBody", "DeclarationsAndStatements", "FunctionDeclaration",
  "FunctionDeclarator", "ParameterList", "ParameterDeclaration",
  "Declaration", "DeclaratorList", "DeclaratorZeroOrMore", "TypeSpec",
  "Declarator", "Statement", "StatementZeroOrMore", "StatementOrError",
  "Expr", "ExprA", "ExprB", "ExprC", "ExprD", "ExprE", "ExprF", "ExprG",
  "ExprH", "ExprI", "ExprJ", "ExprK", "ExprL", "ExprM", "ExprN", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     127,     7,  -103,  -103,  -103,  -103,  -103,    24,  -103,    87,
    -103,  -103,  -103,    -9,  -103,  -103,    87,  -103,    12,   -16,
      11,    35,  -103,   211,   272,    74,  -103,  -103,  -103,    15,
    -103,   131,   211,   211,   211,  -103,  -103,  -103,    41,  -103,
    -103,    10,    55,    59,    72,    77,    -4,   105,    29,    48,
    -103,  -103,  -103,    -1,  -103,    53,    75,    78,   171,   154,
    -103,  -103,   114,  -103,    15,  -103,    -5,    86,  -103,    71,
       0,  -103,  -103,  -103,    20,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   272,  -103,  -103,   211,   211,  -103,    -3,
      -6,  -103,  -103,   194,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    76,  -103,  -103,     2,  -103,  -103,    55,    59,    72,
      77,    -4,   105,   105,    29,    29,    29,    29,    48,    48,
    -103,  -103,  -103,  -103,     4,     5,  -103,  -103,  -103,    73,
    -103,  -103,  -103,   211,  -103,   234,   234,  -103,  -103,   112,
     234,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    27,    28,    30,    31,    29,     0,     2,     0,
       4,     5,     6,     0,    23,     1,     0,     3,    33,     0,
       0,    26,     7,     0,     0,     0,    16,     9,    22,     0,
      24,     0,     0,     0,     0,    90,    88,    89,    87,    32,
      48,    50,    52,    54,    56,    58,    60,    62,    65,    70,
      73,    77,    83,     0,    18,    21,     0,     0,     0,     0,
      11,    34,     0,    15,     0,    14,     0,    33,    25,     0,
       0,    79,    80,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    20,     0,     0,    43,     0,
       0,    36,    46,     0,    45,    10,    13,    12,    35,    92,
      91,     0,    84,    81,     0,    49,    51,    53,    55,    57,
      59,    61,    63,    64,    69,    67,    68,    66,    72,    71,
      74,    75,    76,    19,     0,     0,    42,    38,    47,     0,
      37,    44,    86,     0,    85,     0,     0,    82,    41,    40,
       0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,   118,   117,  -103,  -103,  -103,  -103,  -103,
    -103,    47,   -13,   113,  -103,   -22,  -103,   -11,  -103,  -102,
     -23,   -65,  -103,    66,    67,    69,    70,    81,   -14,    88,
       3,   -28,  -103,  -103,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,    16,    17,    10,    27,    62,    11,    19,
      53,    54,    12,    20,    30,    13,    21,   102,   103,   104,
      66,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   114,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   141,    55,    64,    71,    72,    73,    25,    70,   113,
     115,   116,    63,    75,    65,    75,    82,    93,    75,    26,
     143,   111,    75,    75,    15,    83,    76,   137,    23,   138,
     108,    18,   136,    94,   110,    99,   144,    24,   145,   146,
      64,    77,    14,   148,   149,    31,    28,    32,   151,   106,
      33,   107,    34,    29,   112,    67,    88,    35,    36,    37,
      38,    89,   130,   131,   132,    90,    74,    91,   122,   123,
      78,    55,    79,   134,   135,     1,    92,     2,   147,    56,
      57,     3,     4,     5,    58,     6,    80,    -8,     1,    81,
       2,   128,   129,    95,     3,     4,     5,    59,     6,    31,
      96,    32,    23,    97,    33,   109,    34,    60,   138,    61,
     142,    35,    36,    37,    38,     1,   150,     2,     9,    56,
      57,     3,     4,     5,    58,     6,    84,    85,     1,    86,
       2,    87,    69,    22,     3,     4,     5,    59,     6,    31,
     133,    32,    68,   117,    33,   118,    34,   105,   119,    61,
     120,    35,    36,    37,    38,   100,    31,     0,    32,    56,
      57,    33,   121,    34,    58,     0,     0,     0,    35,    36,
      37,    38,   124,   125,   126,   127,     0,    59,     0,    31,
       0,    32,     0,     0,    33,     0,    34,   101,     0,    61,
       0,    35,    36,    37,    38,   139,    31,     0,    32,    56,
      57,    33,     0,    34,    58,     0,    98,     0,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    59,     0,    31,
       0,    32,     0,     0,    33,     0,    34,   140,     0,    61,
       0,    35,    36,    37,    38,   139,    31,     0,    32,    56,
      57,    33,     0,    34,    58,     0,     0,     0,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    59,     0,    31,
       0,    32,     0,     0,    33,     0,    34,     0,     0,    61,
       0,    35,    36,    37,    38,     2,     0,     0,     0,     3,
       4,     5,     0,     6
};

static const yytype_int16 yycheck[] =
{
      23,   103,    24,    25,    32,    33,    34,    23,    31,    74,
      75,    76,    25,    18,    25,    18,    20,    18,    18,    35,
      18,     1,    18,    18,     0,    29,    16,    33,    16,    35,
      35,    40,    35,    34,    34,    58,    34,    25,    34,    34,
      62,    31,    35,   145,   146,    25,    35,    27,   150,    62,
      30,    62,    32,    18,    34,    40,    27,    37,    38,    39,
      40,    32,    90,    91,    92,    17,    25,    19,    82,    83,
      15,    93,    13,    96,    97,     1,    28,     3,   143,     5,
       6,     7,     8,     9,    10,    11,    14,     0,     1,    12,
       3,    88,    89,    40,     7,     8,     9,    23,    11,    25,
      25,    27,    16,    25,    30,    34,    32,    33,    35,    35,
      34,    37,    38,    39,    40,     1,     4,     3,     0,     5,
       6,     7,     8,     9,    10,    11,    21,    22,     1,    24,
       3,    26,     1,    16,     7,     8,     9,    23,    11,    25,
      93,    27,    29,    77,    30,    78,    32,    33,    79,    35,
      80,    37,    38,    39,    40,     1,    25,    -1,    27,     5,
       6,    30,    81,    32,    10,    -1,    -1,    -1,    37,    38,
      39,    40,    84,    85,    86,    87,    -1,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,     1,    25,    -1,    27,     5,
       6,    30,    -1,    32,    10,    -1,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,     1,    25,    -1,    27,     5,
       6,    30,    -1,    32,    10,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,    35,
      -1,    37,    38,    39,    40,     3,    -1,    -1,    -1,     7,
       8,     9,    -1,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    44,    45,
      47,    50,    54,    57,    35,     0,    45,    46,    40,    51,
      55,    58,    46,    16,    25,    23,    35,    48,    35,    18,
      56,    25,    27,    30,    32,    37,    38,    39,    40,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    75,    76,    52,    53,    57,     5,     6,    10,    23,
      33,    35,    49,    54,    57,    59,    62,    40,    55,     1,
      62,    73,    73,    73,    25,    18,    16,    31,    15,    13,
      14,    12,    20,    29,    21,    22,    24,    26,    27,    32,
      17,    19,    28,    18,    34,    40,    25,    25,    35,    62,
       1,    33,    59,    60,    61,    33,    54,    59,    35,    34,
      34,     1,    34,    63,    74,    63,    63,    65,    66,    67,
      68,    69,    70,    70,    71,    71,    71,    71,    72,    72,
      73,    73,    73,    53,    62,    62,    35,    33,    35,     1,
      33,    61,    34,    18,    34,    34,    34,    63,    61,    61,
       4,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    49,    49,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    71,    72,    72,    72,    72,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     0,     3,
       3,     2,     2,     2,     1,     1,     3,     4,     1,     3,
       2,     1,     3,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     3,     1,     1,     2,     2,     3,     3,     7,
       5,     5,     3,     2,     2,     1,     1,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     1,     3,     1,     3,     4,     4,     1,     1,     1,
       1,     3,     3
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
#line 35 "uccompiler.y"
                              {treeRoot = createNode(Program, NULL); addChild(treeRoot, (yyvsp[0].node));}
#line 1541 "y.tab.c"
    break;

  case 3:
#line 39 "uccompiler.y"
                                                                          {(yyval.node) = addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1547 "y.tab.c"
    break;

  case 4:
#line 43 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1553 "y.tab.c"
    break;

  case 5:
#line 44 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1559 "y.tab.c"
    break;

  case 6:
#line 45 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1565 "y.tab.c"
    break;

  case 7:
#line 49 "uccompiler.y"
                                                                          {(yyval.node) = addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1571 "y.tab.c"
    break;

  case 8:
#line 50 "uccompiler.y"
                                                                          {(yyval.node) = NULL;}
#line 1577 "y.tab.c"
    break;

  case 9:
#line 54 "uccompiler.y"
                                              {(yyval.node) = createNode(FuncDefinition, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[-1].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1583 "y.tab.c"
    break;

  case 10:
#line 58 "uccompiler.y"
                                            {(yyval.node) = createNode(FuncBody, NULL); addChild((yyval.node), (yyvsp[-1].node));}
#line 1589 "y.tab.c"
    break;

  case 11:
#line 59 "uccompiler.y"
                                            {(yyval.node) = createNode(FuncBody, NULL);}
#line 1595 "y.tab.c"
    break;

  case 12:
#line 63 "uccompiler.y"
                                          {(yyval.node) = addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1601 "y.tab.c"
    break;

  case 13:
#line 64 "uccompiler.y"
                                          {(yyval.node) = addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1607 "y.tab.c"
    break;

  case 14:
#line 65 "uccompiler.y"
                                          {(yyval.node) = (yyvsp[0].node);}
#line 1613 "y.tab.c"
    break;

  case 15:
#line 66 "uccompiler.y"
                                          {(yyval.node) = (yyvsp[0].node);}
#line 1619 "y.tab.c"
    break;

  case 16:
#line 70 "uccompiler.y"
                                      {(yyval.node) = createNode(FuncDeclaration, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1625 "y.tab.c"
    break;

  case 17:
#line 74 "uccompiler.y"
                                {(yyval.node) = createNode(Id, (yyvsp[-3].value)); node1 = createNode(ParamList, NULL); addBrother((yyval.node), node1); addChild(node1, (yyvsp[-1].node));}
#line 1631 "y.tab.c"
    break;

  case 18:
#line 78 "uccompiler.y"
                                              {(yyval.node) = (yyvsp[0].node);}
#line 1637 "y.tab.c"
    break;

  case 19:
#line 79 "uccompiler.y"
                                              {(yyval.node) = addBrother((yyval.node), (yyvsp[0].node));}
#line 1643 "y.tab.c"
    break;

  case 20:
#line 83 "uccompiler.y"
                {(yyval.node) = createNode(ParamDeclaration, NULL); addChild((yyval.node), (yyvsp[-1].node)); addBrother((yyvsp[-1].node), createNode(Id, (yyvsp[0].value)));}
#line 1649 "y.tab.c"
    break;

  case 21:
#line 84 "uccompiler.y"
                {(yyval.node) = createNode(ParamDeclaration, NULL); addChild((yyval.node), (yyvsp[0].node));}
#line 1655 "y.tab.c"
    break;

  case 22:
#line 88 "uccompiler.y"
                                  {addBrother((yyvsp[-2].node), (yyvsp[-1].node)->child);
                                   (yyvsp[-1].node)->child = (yyvsp[-2].node);
                                   node1 = (yyvsp[-1].node)->brother;
                                   while(node1 != NULL){
                                      node2 = createNode((yyvsp[-2].node)->label, NULL);
                                      addBrother(node2, node1->child);
                                      node1->child = node2;
                                      node1 = node1->brother;
                                   }
                                   (yyval.node) = (yyvsp[-1].node);}
#line 1670 "y.tab.c"
    break;

  case 23:
#line 98 "uccompiler.y"
                                  {(yyval.node) = createNode(Null, NULL);}
#line 1676 "y.tab.c"
    break;

  case 24:
#line 102 "uccompiler.y"
                                    {(yyval.node) = createNode(Declaration, NULL); addChild((yyval.node), (yyvsp[-1].node)); addBrother((yyval.node), (yyvsp[0].node));}
#line 1682 "y.tab.c"
    break;

  case 25:
#line 106 "uccompiler.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1688 "y.tab.c"
    break;

  case 26:
#line 107 "uccompiler.y"
                          {(yyval.node) = NULL;}
#line 1694 "y.tab.c"
    break;

  case 27:
#line 111 "uccompiler.y"
            {(yyval.node) = createNode(Char, NULL);}
#line 1700 "y.tab.c"
    break;

  case 28:
#line 112 "uccompiler.y"
            {(yyval.node) = createNode(Int, NULL);}
#line 1706 "y.tab.c"
    break;

  case 29:
#line 113 "uccompiler.y"
            {(yyval.node) = createNode(Void, NULL);}
#line 1712 "y.tab.c"
    break;

  case 30:
#line 114 "uccompiler.y"
            {(yyval.node) = createNode(Short, NULL);}
#line 1718 "y.tab.c"
    break;

  case 31:
#line 115 "uccompiler.y"
            {(yyval.node) = createNode(Double, NULL);}
#line 1724 "y.tab.c"
    break;

  case 32:
#line 119 "uccompiler.y"
                    {(yyval.node) = createNode(Id, (yyvsp[-2].value)); addBrother((yyval.node), (yyvsp[0].node));}
#line 1730 "y.tab.c"
    break;

  case 33:
#line 120 "uccompiler.y"
                    {(yyval.node) = createNode(Id, (yyvsp[0].value));}
#line 1736 "y.tab.c"
    break;

  case 34:
#line 124 "uccompiler.y"
                                                              {(yyval.node) = NULL;}
#line 1742 "y.tab.c"
    break;

  case 35:
#line 125 "uccompiler.y"
                                                              {(yyval.node) = (yyvsp[-1].node);}
#line 1748 "y.tab.c"
    break;

  case 36:
#line 126 "uccompiler.y"
                                                              {(yyval.node) = NULL;}
#line 1754 "y.tab.c"
    break;

  case 37:
#line 127 "uccompiler.y"
                                                              {if((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->brother != NULL){
                                                                (yyval.node) = createNode(StatList, NULL);
                                                                addChild((yyval.node), (yyvsp[-1].node));
                                                               }
                                                               else (yyval.node) = (yyvsp[-1].node);}
#line 1764 "y.tab.c"
    break;

  case 38:
#line 132 "uccompiler.y"
                                                              {(yyval.node) = createNode(Null, NULL);}
#line 1770 "y.tab.c"
    break;

  case 39:
#line 133 "uccompiler.y"
                                                              {(yyval.node) = createNode(If, NULL); addChild((yyval.node), (yyvsp[-4].node));
                                                               if ((yyvsp[-2].node) == NULL) addBrother((yyvsp[-4].node), createNode(Null, NULL));
                                                               else addBrother((yyvsp[-4].node), (yyvsp[-2].node));
                                                               if ((yyvsp[0].node) == NULL) addBrother((yyvsp[-4].node), createNode(Null, NULL));
                                                               else addBrother((yyvsp[-4].node), (yyvsp[0].node));}
#line 1780 "y.tab.c"
    break;

  case 40:
#line 138 "uccompiler.y"
                                                               {(yyval.node) = createNode(If, NULL); addChild((yyval.node), (yyvsp[-2].node));
                                                                if ((yyvsp[0].node) == NULL) addBrother((yyvsp[-2].node), createNode(Null, NULL));
                                                                else addBrother((yyvsp[-2].node), (yyvsp[0].node));
                                                                addBrother((yyvsp[-2].node), createNode(Null, NULL));}
#line 1789 "y.tab.c"
    break;

  case 41:
#line 142 "uccompiler.y"
                                                               {(yyval.node) = createNode(While, NULL); addChild((yyval.node), (yyvsp[-2].node));
                                                                if ((yyvsp[0].node) == NULL) addBrother((yyvsp[-2].node), createNode(Null, NULL));
                                                                else addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1797 "y.tab.c"
    break;

  case 42:
#line 145 "uccompiler.y"
                                                               {(yyval.node) = createNode(Return, NULL); addChild((yyval.node), (yyvsp[-1].node));}
#line 1803 "y.tab.c"
    break;

  case 43:
#line 146 "uccompiler.y"
                                                               {(yyval.node) = createNode(Return, NULL); addChild((yyval.node), createNode(Null, NULL));}
#line 1809 "y.tab.c"
    break;

  case 44:
#line 150 "uccompiler.y"
                                          {(yyval.node) = addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1815 "y.tab.c"
    break;

  case 45:
#line 151 "uccompiler.y"
                                          {(yyval.node) = (yyvsp[0].node);}
#line 1821 "y.tab.c"
    break;

  case 46:
#line 155 "uccompiler.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1827 "y.tab.c"
    break;

  case 47:
#line 156 "uccompiler.y"
                {(yyval.node) = createNode(Null, NULL);}
#line 1833 "y.tab.c"
    break;

  case 48:
#line 160 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1839 "y.tab.c"
    break;

  case 49:
#line 161 "uccompiler.y"
                        {(yyval.node) = createNode(Comma, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1845 "y.tab.c"
    break;

  case 50:
#line 165 "uccompiler.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1851 "y.tab.c"
    break;

  case 51:
#line 166 "uccompiler.y"
                          {(yyval.node) = createNode(Store, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1857 "y.tab.c"
    break;

  case 52:
#line 170 "uccompiler.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1863 "y.tab.c"
    break;

  case 53:
#line 171 "uccompiler.y"
                      {(yyval.node) = createNode(Or, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1869 "y.tab.c"
    break;

  case 54:
#line 175 "uccompiler.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1875 "y.tab.c"
    break;

  case 55:
#line 176 "uccompiler.y"
                      {(yyval.node) = createNode(And, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1881 "y.tab.c"
    break;

  case 56:
#line 180 "uccompiler.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1887 "y.tab.c"
    break;

  case 57:
#line 181 "uccompiler.y"
                            {(yyval.node) = createNode(BitWiseOr, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1893 "y.tab.c"
    break;

  case 58:
#line 185 "uccompiler.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 1899 "y.tab.c"
    break;

  case 59:
#line 186 "uccompiler.y"
                              {(yyval.node) = createNode(BitWiseXor, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1905 "y.tab.c"
    break;

  case 60:
#line 190 "uccompiler.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 1911 "y.tab.c"
    break;

  case 61:
#line 191 "uccompiler.y"
                              {(yyval.node) = createNode(BitWiseAnd, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1917 "y.tab.c"
    break;

  case 62:
#line 195 "uccompiler.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1923 "y.tab.c"
    break;

  case 63:
#line 196 "uccompiler.y"
                      {(yyval.node) = createNode(Eq, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1929 "y.tab.c"
    break;

  case 64:
#line 197 "uccompiler.y"
                      {(yyval.node) = createNode(Ne, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1935 "y.tab.c"
    break;

  case 65:
#line 201 "uccompiler.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1941 "y.tab.c"
    break;

  case 66:
#line 202 "uccompiler.y"
                      {(yyval.node) = createNode(Lt, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1947 "y.tab.c"
    break;

  case 67:
#line 203 "uccompiler.y"
                      {(yyval.node) = createNode(Gt, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1953 "y.tab.c"
    break;

  case 68:
#line 204 "uccompiler.y"
                      {(yyval.node) = createNode(Le, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1959 "y.tab.c"
    break;

  case 69:
#line 205 "uccompiler.y"
                      {(yyval.node) = createNode(Ge, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1965 "y.tab.c"
    break;

  case 70:
#line 209 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1971 "y.tab.c"
    break;

  case 71:
#line 210 "uccompiler.y"
                        {(yyval.node) = createNode(Add, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1977 "y.tab.c"
    break;

  case 72:
#line 211 "uccompiler.y"
                        {(yyval.node) = createNode(Sub, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1983 "y.tab.c"
    break;

  case 73:
#line 215 "uccompiler.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1989 "y.tab.c"
    break;

  case 74:
#line 216 "uccompiler.y"
                      {(yyval.node) = createNode(Mul, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1995 "y.tab.c"
    break;

  case 75:
#line 217 "uccompiler.y"
                      {(yyval.node) = createNode(Div, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2001 "y.tab.c"
    break;

  case 76:
#line 218 "uccompiler.y"
                      {(yyval.node) = createNode(Mod, NULL); addChild((yyval.node), (yyvsp[-2].node)); addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2007 "y.tab.c"
    break;

  case 77:
#line 222 "uccompiler.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2013 "y.tab.c"
    break;

  case 78:
#line 223 "uccompiler.y"
                  {(yyval.node) = createNode(Plus, NULL); addChild((yyval.node), (yyvsp[0].node));}
#line 2019 "y.tab.c"
    break;

  case 79:
#line 224 "uccompiler.y"
                  {(yyval.node) = createNode(Minus, NULL); addChild((yyval.node), (yyvsp[0].node));}
#line 2025 "y.tab.c"
    break;

  case 80:
#line 225 "uccompiler.y"
                  {(yyval.node) = createNode(Not, NULL); addChild((yyval.node), (yyvsp[0].node));}
#line 2031 "y.tab.c"
    break;

  case 81:
#line 229 "uccompiler.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2037 "y.tab.c"
    break;

  case 82:
#line 230 "uccompiler.y"
                        {(yyval.node) = addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2043 "y.tab.c"
    break;

  case 83:
#line 233 "uccompiler.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 2049 "y.tab.c"
    break;

  case 84:
#line 234 "uccompiler.y"
                          {(yyval.node) = createNode(Call, NULL); addChild((yyval.node), createNode(Id, (yyvsp[-2].value)));}
#line 2055 "y.tab.c"
    break;

  case 85:
#line 235 "uccompiler.y"
                          {(yyval.node) = createNode(Call, NULL); node1 = createNode(Id, (yyvsp[-3].value)); addChild((yyval.node), node1); addBrother(node1, (yyvsp[-1].node));}
#line 2061 "y.tab.c"
    break;

  case 86:
#line 236 "uccompiler.y"
                          {(yyval.node) = createNode(Null, NULL); free((yyvsp[-3].value));}
#line 2067 "y.tab.c"
    break;

  case 87:
#line 240 "uccompiler.y"
                      {(yyval.node) = createNode(Id, (yyvsp[0].value));}
#line 2073 "y.tab.c"
    break;

  case 88:
#line 241 "uccompiler.y"
                      {(yyval.node) = createNode(IntLit, (yyvsp[0].value));}
#line 2079 "y.tab.c"
    break;

  case 89:
#line 242 "uccompiler.y"
                      {(yyval.node) = createNode(ChrLit, (yyvsp[0].value));}
#line 2085 "y.tab.c"
    break;

  case 90:
#line 243 "uccompiler.y"
                      {(yyval.node) = createNode(RealLit, (yyvsp[0].value));}
#line 2091 "y.tab.c"
    break;

  case 91:
#line 244 "uccompiler.y"
                      {(yyval.node) = (yyvsp[-1].node);}
#line 2097 "y.tab.c"
    break;

  case 92:
#line 245 "uccompiler.y"
                      {(yyval.node) = createNode(Null, NULL);}
#line 2103 "y.tab.c"
    break;


#line 2107 "y.tab.c"

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
#line 247 "uccompiler.y"


void yyerror (char *s) {
  if(flag > 6) printf("Line %d, col %d: %s: %s\n", line, column-(int)yyleng, s, yytext);
  errorFlag = 1;
}
