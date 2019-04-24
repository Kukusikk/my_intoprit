/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "my_bis.y"

#include <iostream>
#include "C:\cygwin64\home\Kukusik\tree.h"

#define YYDEBUG 1
extern FILE * yyin;
extern std::map<std::string, Function*>tab_f;//������� �������
int yylex(void);      //�������� ��� ������� �� ������������ �����������, ����������� ������� ������������ �� l �����
void yyerror(const char *);
//int for_main(void);
const char* for_er[5] = {"heve not ;", "net 2 ckobki","net 2 operada","lishnii posle predlogenia","net kluchevogo slova"};//������ ��� ����� ������
int line1;
int line2;
int line3;
int line4;

/* Line 371 of yacc.c  */
#line 85 "my_bis.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "my_bis.tab.h".  */
#ifndef YY_YY_MY_BIS_TAB_H_INCLUDED
# define YY_YY_MY_BIS_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TRUE = 258,
     FALSE = 259,
     CONSTANT = 260,
     FUNCTION = 261,
     VECTOR = 262,
     MATRIX = 263,
     INT = 264,
     T_BOOL = 265,
     ZAPAT = 266,
     IN1 = 267,
     OUT1 = 268,
     TZAP = 269,
     IN2 = 270,
     OUT2 = 271,
     IN3 = 272,
     OUT3 = 273,
     FOR = 274,
     BEGI = 275,
     END = 276,
     IF = 277,
     NAPRAVLEN_RIT = 278,
     NAPRAVLEN_LEFT = 279,
     WALL = 280,
     EXIT = 281,
     MOOV = 282,
     DVOET = 283,
     CONTIN_PREDLOG = 284,
     ENDLINE = 285,
     SDVIG_PRAV = 286,
     SDVIG_LEV = 287,
     SUMM = 288,
     TRAN = 289,
     AND = 290,
     MINUS = 291,
     PLUS = 292,
     SRAVN_P = 293,
     SRAVN_L = 294,
     RAVN = 295,
     OR = 296,
     YMN_E = 297,
     YMN_M = 298,
     NOT = 299,
     NUMBER = 300,
     NAME = 301
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 28 "my_bis.y"

int num;
char* str;
//������ ����� ����� �� ��������������� ������ 
class expression* exp;
class spis_predlog* sp;
class vec* varr;
class predlog* predl;
class matr* mm;


/* Line 387 of yacc.c  */
#line 186 "my_bis.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MY_BIS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 227 "my_bis.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    18,    22,    26,
      29,    32,    35,    38,    41,    49,    57,    64,    66,    68,
      72,    76,    89,   102,   115,   128,   141,   154,   170,   186,
     202,   218,   234,   250,   266,   277,   281,   285,   289,   293,
     295,   297,   299,   301,   305,   309,   313,   317,   321,   325,
     332,   339,   346,   349,   352,   356,   360,   363,   366,   370,
     374,   378,   382,   387,   392,   397,   401,   405,   409,   416,
     421,   426,   433,   437,   441,   444,   447,   451,   455,   459,
     462,   465,   469,   470,   472,   476,   480,   482,   486,   490,
     493,   496,   500,   504,   508,   512,   516,   520,   525,   530,
     535,   539,   543,   547,   552,   557,   562,   564,   568,   572,
     576,   578,   582,   586
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    -1,    49,    50,    -1,
      57,    14,    30,    -1,    57,     1,    30,    -1,    56,    14,
      30,    -1,    56,     1,    30,    -1,    55,    30,    -1,    52,
      30,    -1,    53,    30,    -1,    54,    30,    -1,    51,    30,
      -1,    64,    40,    40,    58,    15,    64,    16,    -1,    58,
      40,    40,    58,    15,    64,    16,    -1,    58,    40,    27,
      15,    58,    16,    -1,    23,    -1,    24,    -1,    58,    40,
      25,    -1,    58,    40,    26,    -1,    22,    58,    20,    17,
      22,    18,    30,    49,    21,    17,    22,    18,    -1,    22,
      58,    20,    17,    22,    30,     1,    49,    21,    17,    22,
      18,    -1,    22,    58,    20,    17,    22,    18,    30,    49,
      21,    17,    22,     1,    -1,    22,    58,    20,    17,    22,
      18,    30,    49,    21,    17,     1,    18,    -1,    22,    58,
       1,    17,    22,    18,    30,    49,    21,    17,    22,    18,
      -1,     1,    58,    20,    17,    22,    18,    30,    49,    21,
      17,    22,    18,    -1,    19,    63,    40,    58,    28,    58,
      20,    17,    19,    18,    49,    21,    17,    19,    18,    -1,
       1,    63,    40,    58,    28,    58,    20,    17,    19,    18,
      49,    21,    17,    19,    18,    -1,    19,    63,    40,    58,
      28,    58,     1,    17,    19,    18,    49,    21,    17,    19,
      18,    -1,    19,    63,    40,    58,    28,    58,    20,    17,
       1,    18,    49,    21,    17,    19,    18,    -1,    19,    63,
      40,    58,    28,    58,    20,    17,    19,    18,    49,    21,
      17,     1,    18,    -1,    19,    63,    40,    58,    28,    58,
      20,    17,    19,     1,    49,    21,    17,    19,    18,    -1,
      19,    63,    40,    58,    28,    58,    20,    17,    19,    18,
      49,    21,    17,    19,     1,    -1,    62,    40,     6,    46,
      60,    30,    20,    30,    49,    21,    -1,    58,    40,    58,
      -1,    63,    40,    58,    -1,    63,    40,    65,    -1,    63,
      40,    67,    -1,    45,    -1,     4,    -1,     3,    -1,    46,
      -1,    58,    37,    58,    -1,    58,    37,     1,    -1,    58,
      36,     1,    -1,     1,    37,    58,    -1,     1,    36,    58,
      -1,    58,    36,    58,    -1,    58,    15,    58,    11,    58,
      16,    -1,    58,    15,    58,    11,     1,    16,    -1,    58,
      15,     1,    11,    58,    16,    -1,    58,    32,    -1,    58,
      31,    -1,    58,    38,    58,    -1,    58,    39,    58,    -1,
       1,    32,    -1,     1,    31,    -1,     1,    38,    58,    -1,
       1,    39,    58,    -1,    58,    38,     1,    -1,    58,    39,
       1,    -1,    33,    15,    58,    16,    -1,    33,    15,    58,
       1,    -1,    33,    15,     1,    16,    -1,    58,    42,    58,
      -1,     1,    42,    58,    -1,    58,    42,     1,    -1,    58,
      15,    58,    11,    28,    16,    -1,    58,    17,    58,    18,
      -1,    58,    15,    58,     1,    -1,    58,    15,    28,    11,
      58,    16,    -1,     1,    43,    58,    -1,    58,    43,     1,
      -1,     1,    34,    -1,    44,     1,    -1,     1,    35,    58,
      -1,    58,    35,     1,    -1,    58,    43,    58,    -1,    58,
      34,    -1,    44,    58,    -1,    58,    35,    58,    -1,    -1,
      57,    -1,    59,    11,    57,    -1,    15,    59,    16,    -1,
      63,    -1,    61,    11,    63,    -1,    15,    61,    16,    -1,
       9,    46,    -1,    10,    46,    -1,     5,     9,    46,    -1,
       5,    10,    46,    -1,     5,     1,    46,    -1,     7,     9,
      46,    -1,     7,    10,    46,    -1,     7,     1,    46,    -1,
       5,     7,     9,    46,    -1,     5,     7,    10,    46,    -1,
       5,     7,     1,    46,    -1,     8,     9,    46,    -1,     8,
       1,    46,    -1,     8,    10,    46,    -1,     5,     9,     8,
      46,    -1,     5,    10,     8,    46,    -1,     5,     1,     8,
      46,    -1,    58,    -1,    64,    11,    58,    -1,    12,    64,
      13,    -1,    12,    64,     1,    -1,    65,    -1,    66,    11,
      65,    -1,    12,    66,    13,    -1,    12,    66,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    58,    66,    67,    68,    69,    70,
      72,    74,    76,    77,    82,    83,    86,    87,    88,    89,
      90,    94,    95,    96,    97,    98,   100,   102,   103,   104,
     105,   106,   107,   108,   112,   116,   119,   120,   121,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   153,   154,   155,   157,   158,   159,   160,   161,
     162,   163,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   177,   178,   180,   182,   183,   184,   187,   189,
     190,   191,   192,   193,   195,   196,   197,   199,   200,   201,
     202,   203,   205,   206,   207,   208,   218,   220,   223,   224,
     228,   230,   233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "CONSTANT", "FUNCTION",
  "VECTOR", "MATRIX", "INT", "T_BOOL", "ZAPAT", "IN1", "OUT1", "TZAP",
  "IN2", "OUT2", "IN3", "OUT3", "FOR", "BEGI", "END", "IF",
  "NAPRAVLEN_RIT", "NAPRAVLEN_LEFT", "WALL", "EXIT", "MOOV", "DVOET",
  "CONTIN_PREDLOG", "ENDLINE", "SDVIG_PRAV", "SDVIG_LEV", "SUMM", "TRAN",
  "AND", "MINUS", "PLUS", "SRAVN_P", "SRAVN_L", "RAVN", "OR", "YMN_E",
  "YMN_M", "NOT", "NUMBER", "NAME", "$accept", "programm", "Predlog_s",
  "Predlog", "Funcion_v", "Robot_predlog", "If_predlog", "For_predlog",
  "Funcion", "Virag_predlog", "Obav_predlog", "Ar_virag", "Parametr_s",
  "Parametr_s2", "Peremen_s", "Peremen_s2", "Peremen", "Ar_virag_forv",
  "Ar_forv2", "Ar_virag_form", "Ar_virag_form2", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    60,    61,    61,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     7,     7,     6,     1,     1,     3,
       3,    12,    12,    12,    12,    12,    12,    15,    15,    15,
      15,    15,    15,    15,    10,     3,     3,     3,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     2,     2,     3,     3,     2,     2,     3,     3,
       3,     3,     4,     4,     4,     3,     3,     3,     6,     4,
       4,     6,     3,     3,     2,     2,     3,     3,     3,     2,
       2,     3,     0,     1,     3,     3,     1,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       3,     3,     3,     4,     4,     4,     1,     3,     3,     3,
       1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    41,    40,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    39,    42,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,    57,    56,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,     0,    86,     0,
       0,     0,    75,    80,     1,     4,    13,    10,    11,    12,
       9,     0,     0,     0,     0,     0,     0,    53,    52,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    47,    46,    58,    59,    66,    72,     0,
       0,     0,    93,     0,     0,     0,     0,    91,     0,    92,
      96,    94,    95,   101,   100,   102,     0,    88,     0,     0,
       0,     0,     0,     8,     7,     6,     5,     0,     0,     0,
       0,    77,    81,    45,    48,    44,    43,    60,    54,    61,
      55,    19,    20,     0,     0,    35,    67,    65,    73,    78,
       0,     0,    36,    37,    38,   107,     0,     0,     0,   105,
      99,    97,    98,   103,   104,    87,     0,     0,     0,    64,
      63,    62,     0,     0,    70,     0,    69,     0,     0,     0,
       0,   106,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
     109,   108,   113,     0,   112,     0,     0,     0,     0,     0,
       0,     0,    51,    71,    50,    68,    49,    16,     0,     0,
      83,     0,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    85,     0,    14,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    25,    24,    23,    21,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      32,    31,    33,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   221,   199,    57,    29,    30,    31,   153,   184,
     154
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -185
static const yytype_int16 yypact[] =
{
     600,   224,  -185,  -185,   161,    64,   182,   -29,   -16,   290,
     290,   163,  -185,  -185,    51,   592,  -185,  -185,    46,   101,
    -185,    42,    48,    49,    61,    65,     6,     9,   855,    54,
      63,    -6,   926,  -185,  -185,  -185,   163,   163,   163,   163,
     163,   163,   163,   868,    73,     1,   189,     8,    21,    83,
      86,    91,   102,   103,   108,  -185,  -185,    77,  -185,   115,
     736,   617,   926,    97,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,   128,   133,   135,   139,    24,   163,  -185,  -185,  -185,
     625,   631,   639,   648,   653,    18,   686,   700,   168,    95,
     163,   136,   100,   100,   100,   100,   100,    97,    97,   162,
     163,   132,  -185,   140,   157,   158,   160,  -185,   165,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,   290,  -185,   163,   164,
     195,   675,   768,  -185,  -185,  -185,  -185,   826,   174,   781,
     897,   926,   100,   926,   100,   926,   100,   926,   100,   926,
     100,  -185,  -185,   198,   163,  1065,   926,    97,   926,    97,
     171,   149,  1065,  -185,  -185,  1065,   163,   197,   910,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,   939,   199,   204,  -185,
    -185,  -185,   163,   163,  -185,   156,  -185,   163,  1094,   205,
     163,  1065,   120,  -185,   125,  1107,   218,   163,   163,   219,
      41,   968,   981,  1124,   222,  1010,  1023,    24,   290,   209,
    -185,  -185,  -185,   228,  -185,    24,   216,  1052,   813,   223,
     234,   251,  -185,  -185,  -185,  -185,  -185,  -185,   723,    81,
    -185,   111,   245,  -185,   119,   600,   237,   255,   259,   600,
     600,   600,  -185,   290,  -185,   252,  -185,   270,   262,   264,
       5,   303,   336,   369,  -185,   600,   267,   268,   269,   272,
      17,   271,   279,   284,   402,   280,   600,   600,   600,   600,
     600,   283,    31,   287,  -185,   299,   435,   468,   501,   534,
     567,   301,   302,    32,   305,  -185,   304,   311,   312,   313,
     314,  -185,  -185,  -185,  -185,  -185,   315,   316,   319,   323,
       7,   332,   334,   335,   338,   343,    59,  -185,  -185,  -185,
    -185,  -185,  -185,  -185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,   -15,   -19,  -185,  -185,  -185,  -185,  -185,  -185,
    -184,     0,  -185,  -185,  -185,  -185,     3,  -149,  -148,  -185,
    -185
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
      65,    43,   182,   183,    44,    90,   249,    71,   295,   101,
      73,    60,    58,    59,   220,    63,   106,    55,   259,    32,
      72,     2,     3,    74,   250,   127,   296,     2,     3,   108,
      56,   182,   272,   283,    91,   260,    92,    93,    94,    95,
      96,    97,    98,   141,   142,   143,    64,   102,   219,   244,
     284,    14,   128,   273,   107,   223,   224,    14,   144,   210,
     302,   122,    15,    16,    17,    49,    61,   109,    15,    16,
      17,   211,    66,    50,    51,   129,   130,   303,    67,    68,
     132,   134,   136,   138,   140,   145,   147,   149,   116,   152,
     155,    69,    90,   117,    88,    70,    32,   232,     2,     3,
     158,    -2,     1,    89,     2,     3,     4,   151,     5,     6,
       7,     8,    75,   100,    76,    75,     9,    76,   166,   165,
      10,   200,   233,    11,    12,    13,   202,   234,    14,   110,
      90,    90,   111,   201,    14,   236,   203,   112,   204,    15,
      16,    17,    86,    87,   178,    15,    16,    17,   113,   114,
      32,   181,     2,     3,   115,   118,   185,   193,   123,     2,
       3,   180,    45,   124,    32,   125,     2,     3,    46,   126,
      47,    48,   191,   192,   150,   195,   156,   196,   159,   157,
     181,   167,    14,    52,   194,   173,   160,   207,   208,    14,
     103,    53,    54,    15,    16,    17,    14,   218,   104,   105,
      15,    16,    17,   161,   162,   218,   163,    15,    16,    17,
     237,   164,   168,   177,   241,   242,   243,   179,    65,   186,
     198,   189,    65,    65,    65,    32,   190,     2,     3,     4,
     254,     5,     6,     7,     8,    65,   206,   209,   215,   222,
     180,   266,   267,   268,   269,   270,   225,    65,    65,    65,
      65,    65,   231,   229,   238,    33,    34,    14,    35,    36,
      37,    38,    39,    40,   230,   235,    41,    42,    15,    16,
      17,     1,   239,     2,     3,     4,   240,     5,     6,     7,
       8,   247,   245,   248,   255,     9,   256,   257,   261,    10,
     258,   246,    11,    12,    13,     4,   262,     5,     6,     7,
       8,   263,   265,    14,     1,   271,     2,     3,     4,   274,
       5,     6,     7,     8,    15,    16,    17,   275,     9,   281,
     282,   286,    10,   285,   251,    11,    12,    13,   287,   288,
     289,   290,     0,     0,   291,   292,    14,     1,   293,     2,
       3,     4,   294,     5,     6,     7,     8,    15,    16,    17,
     297,     9,   298,   299,     0,    10,   300,   252,    11,    12,
      13,   301,     0,     0,     0,     0,     0,     0,     0,    14,
       1,     0,     2,     3,     4,     0,     5,     6,     7,     8,
      15,    16,    17,     0,     9,     0,     0,     0,    10,     0,
     253,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     1,     0,     2,     3,     4,     0,     5,
       6,     7,     8,    15,    16,    17,     0,     9,     0,     0,
       0,    10,     0,   264,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     1,     0,     2,     3,
       4,     0,     5,     6,     7,     8,    15,    16,    17,     0,
       9,     0,     0,     0,    10,     0,   276,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     1,
       0,     2,     3,     4,     0,     5,     6,     7,     8,    15,
      16,    17,     0,     9,     0,     0,     0,    10,     0,   277,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     1,     0,     2,     3,     4,     0,     5,     6,
       7,     8,    15,    16,    17,     0,     9,     0,     0,     0,
      10,     0,   278,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     1,     0,     2,     3,     4,
       0,     5,     6,     7,     8,    15,    16,    17,     0,     9,
       0,     0,     0,    10,     0,   279,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     1,     0,
       2,     3,     4,     0,     5,     6,     7,     8,    15,    16,
      17,     0,     9,     0,     0,     0,    10,     0,   280,    11,
      12,    13,     0,    62,     0,     2,     3,     0,     0,     0,
      14,     1,     0,     2,     3,     4,     0,     5,     6,     7,
       8,    15,    16,    17,     0,     9,     0,     0,   121,    10,
       2,     3,    11,    12,    13,    14,   131,     0,     2,     3,
       0,     0,   133,    14,     2,     3,    15,    16,    17,     0,
     135,     0,     2,     3,    15,    16,    17,     0,     0,   137,
      14,     2,     3,     0,   139,     0,     2,     3,    14,     0,
       0,    15,    16,    17,    14,     0,     0,     0,     0,    15,
      16,    17,    14,     0,     0,    15,    16,    17,     0,     0,
       0,    14,     0,    15,    16,    17,    14,   146,     0,     2,
       3,   169,    15,    16,    17,     0,     0,    15,    16,    17,
       0,   148,     0,     2,     3,     0,    33,    34,     0,    35,
      36,    37,    38,    39,    40,     0,     0,    41,    42,    14,
       0,     0,     0,     0,   174,     0,     0,     0,     0,     0,
      15,    16,    17,    14,   175,     0,     0,   119,    75,  -106,
      76,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,    75,     0,    76,    77,    78,   120,    79,    80,    81,
      82,    83,    84,     0,     0,    86,    87,    77,    78,   170,
      79,    80,    81,    82,    83,    84,     0,     0,    86,    87,
       0,     0,   174,    75,   171,    76,     0,     0,     0,     0,
       0,     0,   175,     0,     0,     0,    75,     0,    76,    77,
      78,     0,    79,    80,    81,    82,    83,    84,     0,     0,
      86,    87,    77,    78,   227,    79,    80,    81,    82,    83,
      84,     0,     0,    86,    87,     0,     0,     0,    75,     0,
      76,     0,     0,   228,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    84,     0,     0,    86,    87,    33,    34,     0,
      35,    36,    37,    38,    39,    40,     0,     0,    41,    42,
      75,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,    76,    77,    78,    99,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,    77,
      78,     0,    79,    80,    81,    82,    83,    84,     0,     0,
      86,    87,    75,     0,    76,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,     0,   187,    86,
      87,    77,    78,     0,    79,    80,    81,    82,    83,    84,
       0,     0,    86,    87,    75,     0,    76,    33,    34,     0,
      35,    36,    37,    38,    39,    40,     0,   188,    41,    42,
      77,    78,     0,    79,    80,    81,    82,    83,    84,     0,
       0,    86,    87,    75,   212,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,   213,    76,    77,
      78,     0,    79,    80,    81,    82,    83,    84,     0,     0,
      86,    87,    77,    78,     0,    79,    80,    81,    82,    83,
      84,     0,     0,    86,    87,    75,   216,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,   217,
      76,    77,    78,     0,    79,    80,    81,    82,    83,    84,
       0,     0,    86,    87,    77,    78,     0,    79,    80,    81,
      82,    83,    84,     0,     0,    86,    87,    75,     0,    76,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    76,    77,    78,     0,    79,    80,    81,    82,
      83,    84,     0,     0,    86,    87,    77,    78,     0,    79,
      80,    81,    82,    83,    84,     0,     0,    86,    87,   197,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,    76,    77,    78,     0,    79,    80,
      81,    82,    83,    84,     0,     0,    86,    87,    77,    78,
     214,    79,    80,    81,    82,    83,    84,     0,     0,    86,
      87,     0,     0,     0,     0,    33,    34,     0,    35,    36,
      37,    38,    39,    40,     0,     0,    41,    42
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      19,     1,   151,   151,     1,    11,     1,     1,     1,     8,
       1,    11,     9,    10,   198,    15,     8,    46,     1,     1,
      14,     3,     4,    14,    19,     1,    19,     3,     4,     8,
      46,   180,     1,     1,    40,    18,    36,    37,    38,    39,
      40,    41,    42,    25,    26,    27,     0,    46,   197,   233,
      18,    33,    28,    22,    46,   203,   205,    33,    40,    18,
       1,    61,    44,    45,    46,     1,    15,    46,    44,    45,
      46,    30,    30,     9,    10,    75,    76,    18,    30,    30,
      80,    81,    82,    83,    84,    85,    86,    87,    11,    89,
      90,    30,    11,    16,    40,    30,     1,    16,     3,     4,
     100,     0,     1,    40,     3,     4,     5,    12,     7,     8,
       9,    10,    15,    40,    17,    15,    15,    17,   118,   116,
      19,     1,    11,    22,    23,    24,     1,    16,    33,    46,
      11,    11,    46,    13,    33,    16,    11,    46,    13,    44,
      45,    46,    42,    43,   144,    44,    45,    46,    46,    46,
       1,   151,     3,     4,    46,    40,   156,     1,    30,     3,
       4,    12,     1,    30,     1,    30,     3,     4,     7,    30,
       9,    10,   172,   173,     6,   175,    40,   177,    46,    17,
     180,    17,    33,     1,    28,    11,    46,   187,   188,    33,
       1,     9,    10,    44,    45,    46,    33,   197,     9,    10,
      44,    45,    46,    46,    46,   205,    46,    44,    45,    46,
     225,    46,    17,    15,   229,   230,   231,    46,   237,    22,
      15,    22,   241,   242,   243,     1,    22,     3,     4,     5,
     245,     7,     8,     9,    10,   254,    18,    18,    16,    30,
      12,   256,   257,   258,   259,   260,    30,   266,   267,   268,
     269,   270,     1,    30,    17,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    30,    20,    42,    43,    44,    45,
      46,     1,    17,     3,     4,     5,    17,     7,     8,     9,
      10,    19,    30,    19,    17,    15,    18,    18,    17,    19,
      18,    21,    22,    23,    24,     5,    17,     7,     8,     9,
      10,    17,    22,    33,     1,    22,     3,     4,     5,    22,
       7,     8,     9,    10,    44,    45,    46,    18,    15,    18,
      18,    17,    19,    18,    21,    22,    23,    24,    17,    17,
      17,    17,    -1,    -1,    19,    19,    33,     1,    19,     3,
       4,     5,    19,     7,     8,     9,    10,    44,    45,    46,
      18,    15,    18,    18,    -1,    19,    18,    21,    22,    23,
      24,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      44,    45,    46,    -1,    15,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    44,    45,    46,    -1,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    44,    45,    46,    -1,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    44,
      45,    46,    -1,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    44,    45,    46,    -1,    15,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    44,    45,    46,    -1,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    44,    45,
      46,    -1,    15,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    24,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,
      33,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    44,    45,    46,    -1,    15,    -1,    -1,     1,    19,
       3,     4,    22,    23,    24,    33,     1,    -1,     3,     4,
      -1,    -1,     1,    33,     3,     4,    44,    45,    46,    -1,
       1,    -1,     3,     4,    44,    45,    46,    -1,    -1,     1,
      33,     3,     4,    -1,     1,    -1,     3,     4,    33,    -1,
      -1,    44,    45,    46,    33,    -1,    -1,    -1,    -1,    44,
      45,    46,    33,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    33,    -1,    44,    45,    46,    33,     1,    -1,     3,
       4,    16,    44,    45,    46,    -1,    -1,    44,    45,    46,
      -1,     1,    -1,     3,     4,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    33,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    33,    11,    -1,    -1,     1,    15,    16,
      17,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    15,    -1,    17,    31,    32,    20,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    43,    31,    32,     1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      -1,    -1,     1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    17,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    43,    31,    32,     1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    -1,    -1,    -1,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    43,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    31,    32,    20,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    43,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    -1,    28,    42,
      43,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    43,    15,    -1,    17,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    -1,    28,    42,    43,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    43,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    43,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    43,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    43,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43,    31,    32,
      16,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     7,     8,     9,    10,    15,
      19,    22,    23,    24,    33,    44,    45,    46,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    62,
      63,    64,     1,    31,    32,    34,    35,    36,    37,    38,
      39,    42,    43,    58,    63,     1,     7,     9,    10,     1,
       9,    10,     1,     9,    10,    46,    46,    61,    63,    63,
      58,    15,     1,    58,     0,    50,    30,    30,    30,    30,
      30,     1,    14,     1,    14,    15,    17,    31,    32,    34,
      35,    36,    37,    38,    39,    40,    42,    43,    40,    40,
      11,    40,    58,    58,    58,    58,    58,    58,    58,    20,
      40,     8,    46,     1,     9,    10,     8,    46,     8,    46,
      46,    46,    46,    46,    46,    46,    11,    16,    40,     1,
      20,     1,    58,    30,    30,    30,    30,     1,    28,    58,
      58,     1,    58,     1,    58,     1,    58,     1,    58,     1,
      58,    25,    26,    27,    40,    58,     1,    58,     1,    58,
       6,    12,    58,    65,    67,    58,    40,    17,    58,    46,
      46,    46,    46,    46,    46,    63,    58,    17,    17,    16,
       1,    16,    11,    11,     1,    11,    18,    15,    58,    46,
      12,    58,    64,    65,    66,    58,    22,    28,    28,    22,
      22,    58,    58,     1,    28,    58,    58,    15,    15,    60,
       1,    13,     1,    11,    13,    15,    18,    58,    58,    18,
      18,    30,    16,    16,    16,    16,    16,    16,    58,    64,
      57,    59,    30,    65,    64,    30,    20,     1,    20,    30,
      30,     1,    16,    11,    16,    20,    16,    49,    17,    17,
      17,    49,    49,    49,    57,    30,    21,    19,    19,     1,
      19,    21,    21,    21,    49,    17,    18,    18,    18,     1,
      18,    17,    17,    17,    21,    22,    49,    49,    49,    49,
      49,    22,     1,    22,    22,    18,    21,    21,    21,    21,
      21,    18,    18,     1,    18,    18,    17,    17,    17,    17,
      17,    19,    19,    19,    19,     1,    19,    18,    18,    18,
      18,    18,     1,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 53 "my_bis.y"
    { go_pr22((yyvsp[(1) - (1)].sp));exit(0);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 56 "my_bis.y"
    {(yyval.sp)=new spis_predlog;(yyval.sp)->add((yyvsp[(1) - (1)].predl));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 58 "my_bis.y"
    {(yyval.sp)->add((yyvsp[(2) - (2)].predl));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 66 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (3)].predl);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 67 "my_bis.y"
    { line1 = (yylsp[(2) - (3)]).first_line;  line2 = (yylsp[(2) - (3)]).first_column; line3 = (yylsp[(2) - (3)]).last_line; line4 = (yylsp[(2) - (3)]).last_column;yyerror("heve not ;"); yyerrok;}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 68 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (3)].predl);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 69 "my_bis.y"
    { line1 = (yylsp[(2) - (3)]).first_line;  line2 = (yylsp[(2) - (3)]).first_column; line3 = (yylsp[(2) - (3)]).last_line; line4 = (yylsp[(2) - (3)]).last_column; yyerror("heve not ;"); yyerrok;}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 70 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (2)].predl);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 72 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (2)].predl);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 74 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (2)].predl);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 76 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (2)].predl);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 77 "my_bis.y"
    {(yyval.predl)=(yyvsp[(1) - (2)].predl);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 82 "my_bis.y"
    {(yyval.predl)=new  predlog(funct_v,(yyvsp[(1) - (7)].varr),(yyvsp[(4) - (7)].exp)->name,(yyvsp[(6) - (7)].varr));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 83 "my_bis.y"
    {(yyval.predl)=new  predlog(funct_v,(yyvsp[(1) - (7)].exp),(yyvsp[(4) - (7)].exp)->name,(yyvsp[(6) - (7)].varr));}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 86 "my_bis.y"
    {(yyval.predl)=new predlog(robot,mOOV,(yyvsp[(1) - (6)].exp),(yyvsp[(5) - (6)].exp));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 87 "my_bis.y"
    {(yyval.predl)=new predlog(robot,nAPRAVLEN_RIT);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 88 "my_bis.y"
    {(yyval.predl)=new predlog(robot,nAPRAVLEN_LEFT);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 89 "my_bis.y"
    {(yyval.predl)=new predlog(robot,wALL,(yyvsp[(1) - (3)].exp));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 90 "my_bis.y"
    {(yyval.predl)=new predlog(robot,eXIT,(yyvsp[(1) - (3)].exp));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 94 "my_bis.y"
    {(yyval.predl)=new predlog(if_,(yyvsp[(2) - (12)].exp),(yyvsp[(8) - (12)].sp));}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 95 "my_bis.y"
    {line1 = (yylsp[(7) - (12)]).first_line;  line2 = (yylsp[(7) - (12)]).first_column; line3 = (yylsp[(7) - (12)]).last_line; line4 = (yylsp[(7) - (12)]).last_column; yyerror("net 2 ckobki "); yyerrok;}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 96 "my_bis.y"
    { line1 = (yylsp[(12) - (12)]).first_line;  line2 = (yylsp[(12) - (12)]).first_column; line3 = (yylsp[(12) - (12)]).last_line; line4 = (yylsp[(12) - (12)]).last_column; yyerror("net 2 ckobki "); yyerrok;}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 97 "my_bis.y"
    { line1 = (yylsp[(11) - (12)]).first_line;  line2 = (yylsp[(11) - (12)]).first_column; line3 = (yylsp[(11) - (12)]).last_line; line4 = (yylsp[(11) - (12)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 98 "my_bis.y"
    {line1 = (yylsp[(3) - (12)]).first_line;  line2 = (yylsp[(3) - (12)]).first_column; line3 = (yylsp[(3) - (12)]).last_line; line4 = (yylsp[(3) - (12)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 100 "my_bis.y"
    { line1 = (yylsp[(1) - (12)]).first_line;  line2 = (yylsp[(1) - (12)]).first_column; line3 = (yylsp[(1) - (12)]).last_line;line4 = (yylsp[(1) - (12)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 102 "my_bis.y"
    {(yyval.predl)=new predlog(for_,(yyvsp[(2) - (15)].exp),(yyvsp[(4) - (15)].exp),(yyvsp[(6) - (15)].exp),(yyvsp[(11) - (15)].sp));}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 103 "my_bis.y"
    { line1 = (yylsp[(1) - (15)]).first_line;  line2 = (yylsp[(1) - (15)]).first_column; line3 = (yylsp[(1) - (15)]).last_line;line4 = (yylsp[(1) - (15)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 104 "my_bis.y"
    { line1 = (yylsp[(7) - (15)]).first_line;  line2 = (yylsp[(7) - (15)]).first_column; line3 = (yylsp[(7) - (15)]).last_line;line4 = (yylsp[(7) - (15)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 105 "my_bis.y"
    { line1 = (yylsp[(9) - (15)]).first_line;  line2 = (yylsp[(9) - (15)]).first_column; line3 = (yylsp[(9) - (15)]).last_line;line4 = (yylsp[(9) - (15)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 106 "my_bis.y"
    { line1 = (yylsp[(14) - (15)]).first_line;  line2 = (yylsp[(14) - (15)]).first_column; line3 = (yylsp[(14) - (15)]).last_line;line4 = (yylsp[(14) - (15)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 107 "my_bis.y"
    {line1 = (yylsp[(10) - (15)]).first_line;  line2 = (yylsp[(10) - (15)]).first_column; line3 = (yylsp[(10) - (15)]).last_line;line4 = (yylsp[(10) - (15)]).last_column; yyerror("net 2 ckobki "); yyerrok;}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 108 "my_bis.y"
    { line1 = (yylsp[(15) - (15)]).first_line;  line2 = (yylsp[(15) - (15)]).first_column; line3 = (yylsp[(15) - (15)]).last_line;line4 = (yylsp[(15) - (15)]).last_column; yyerror("net 2 ckobki "); yyerrok;}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 112 "my_bis.y"
    {(yyval.predl)=new  predlog(funct,(yyvsp[(1) - (10)].varr),(yyvsp[(4) - (10)].str),(yyvsp[(5) - (10)].sp),(yyvsp[(9) - (10)].sp));}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 116 "my_bis.y"
    {(yyval.predl)= new  predlog(viragen,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 119 "my_bis.y"
    {(yyval.predl)=new predlog(obyav,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),chislo);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 120 "my_bis.y"
    {(yyval.predl)=new predlog(obyav,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].varr),vetor);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 121 "my_bis.y"
    {(yyval.predl)=new predlog(obyav,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].mm),matriz);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 128 "my_bis.y"
    { (yyval.exp) = new expression(constant,int_,chislo,(yyvsp[(1) - (1)].num));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 129 "my_bis.y"
    { (yyval.exp) = new expression(constant,bool_,chislo,0);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 130 "my_bis.y"
    { (yyval.exp) = new expression(constant,bool_,chislo,1);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 131 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (1)].str),peremen);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 132 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),plus,operat,2);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 133 "my_bis.y"
    {line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 134 "my_bis.y"
    {line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 135 "my_bis.y"
    { line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 136 "my_bis.y"
    {line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 137 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),minus,operat,2);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 138 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (6)].exp),(yyvsp[(3) - (6)].exp),(yyvsp[(5) - (6)].exp),koordin,operat,3);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 139 "my_bis.y"
    { line1 = (yylsp[(5) - (6)]).first_line;  line2 = (yylsp[(5) - (6)]).first_column; line3 = (yylsp[(5) - (6)]).last_line;line4 = (yylsp[(5) - (6)]).last_column; yyerror("net 3 operada"); yyerrok;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 140 "my_bis.y"
    { line1 = (yylsp[(3) - (6)]).first_line;  line2 = (yylsp[(3) - (6)]).first_column; line3 = (yylsp[(3) - (6)]).last_line;line4 = (yylsp[(3) - (6)]).last_column;yyerror("net 2 operada"); yyerrok;}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 141 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (2)].exp),sd_l,operat,1);}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 142 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (2)].exp),sd_p,operat,1);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 143 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),sravn_p,operat,2);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 144 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),sravn_l,operat,2);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 145 "my_bis.y"
    { line1 = (yylsp[(1) - (2)]).first_line;  line2 = (yylsp[(1) - (2)]).first_column; line3 = (yylsp[(1) - (2)]).last_line;line4 = (yylsp[(1) - (2)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 146 "my_bis.y"
    {line1 = (yylsp[(1) - (2)]).first_line;  line2 = (yylsp[(1) - (2)]).first_column; line3 = (yylsp[(1) - (2)]).last_line;line4 = (yylsp[(1) - (2)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 147 "my_bis.y"
    { line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 148 "my_bis.y"
    { line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 149 "my_bis.y"
    {line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 150 "my_bis.y"
    { line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column;yyerror("net 2 operada"); yyerrok;}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 153 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(3) - (4)].exp),sum,operat,1);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 154 "my_bis.y"
    {  line1 = (yylsp[(4) - (4)]).first_line;  line2 = (yylsp[(4) - (4)]).first_column; line3 = (yylsp[(4) - (4)]).last_line;line4 = (yylsp[(4) - (4)]).last_column; yyerror("net 2 ckobki"); yyerrok;}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 155 "my_bis.y"
    { line1 = (yylsp[(3) - (4)]).first_line;  line2 = (yylsp[(3) - (4)]).first_column; line3 = (yylsp[(3) - (4)]).last_line;line4 = (yylsp[(3) - (4)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 157 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),ymn,operat,2);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 158 "my_bis.y"
    {line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 159 "my_bis.y"
    { line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 160 "my_bis.y"
    {(yyval.exp)=new expression((yyvsp[(1) - (6)].exp),(yyvsp[(3) - (6)].exp),vector_stolb,operat,2);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 161 "my_bis.y"
    {(yyval.exp)=new expression((yyvsp[(1) - (4)].exp),(yyvsp[(3) - (4)].exp),matr_matr,operat,2);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 162 "my_bis.y"
    { line1 = (yylsp[(4) - (4)]).first_line;  line2 = (yylsp[(4) - (4)]).first_column; line3 = (yylsp[(4) - (4)]).last_line;line4 = (yylsp[(4) - (4)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 163 "my_bis.y"
    {(yyval.exp)=new expression((yyvsp[(1) - (6)].exp),(yyvsp[(5) - (6)].exp),vector_strok,operat,2);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 165 "my_bis.y"
    { line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 166 "my_bis.y"
    { line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 operada"); yyerrok;}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 167 "my_bis.y"
    { line1 = (yylsp[(1) - (2)]).first_line;  line2 = (yylsp[(1) - (2)]).first_column; line3 = (yylsp[(1) - (2)]).last_line;line4 = (yylsp[(1) - (2)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 168 "my_bis.y"
    { line1 = (yylsp[(2) - (2)]).first_line;  line2 = (yylsp[(2) - (2)]).first_column; line3 = (yylsp[(2) - (2)]).last_line;line4 = (yylsp[(2) - (2)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 169 "my_bis.y"
    { line1 = (yylsp[(1) - (3)]).first_line;  line2 = (yylsp[(1) - (3)]).first_column; line3 = (yylsp[(1) - (3)]).last_line;line4 = (yylsp[(1) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 170 "my_bis.y"
    {  line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 1 operada"); yyerrok;}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 171 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),ymm,operat,2);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 172 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (2)].exp),tran,operat,1);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 173 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(2) - (2)].exp),not_,operat,1);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 174 "my_bis.y"
    { (yyval.exp) = new expression((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp),and_,operat,2);}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 177 "my_bis.y"
    {(yyval.sp)=new spis_predlog;}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 178 "my_bis.y"
    {(yyval.sp)->add((yyvsp[(1) - (1)].predl));}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 180 "my_bis.y"
    {(yyval.sp)->add((yyvsp[(3) - (3)].predl));}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 182 "my_bis.y"
    {(yyval.sp)=(yyvsp[(2) - (3)].sp);}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 183 "my_bis.y"
    {(yyval.varr)=new vec;(yyval.varr)->add((yyvsp[(1) - (1)].exp));}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 184 "my_bis.y"
    {(yyval.varr)->add((yyvsp[(3) - (3)].exp));}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 187 "my_bis.y"
    {(yyval.varr)=(yyvsp[(2) - (3)].varr);}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 189 "my_bis.y"
    {(yyval.exp)=new expression(0,int_,(yyvsp[(2) - (2)].str),peremen,chislo);}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 190 "my_bis.y"
    {(yyval.exp)=new expression(0,bool_,(yyvsp[(2) - (2)].str),peremen,chislo);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 191 "my_bis.y"
    {(yyval.exp)=new expression(1,int_,(yyvsp[(3) - (3)].str),peremen,chislo);}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 192 "my_bis.y"
    {(yyval.exp)=new expression(1,bool_,(yyvsp[(3) - (3)].str),peremen,chislo);}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 193 "my_bis.y"
    {  line1 = (yylsp[(2) - (3)]).first_line;  line2 = (yylsp[(2) - (3)]).first_column; line3 = (yylsp[(2) - (3)]).last_line;line4 = (yylsp[(2) - (3)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 195 "my_bis.y"
    {(yyval.exp)=new expression(0,int_v,(yyvsp[(3) - (3)].str),peremen,vetor);}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 196 "my_bis.y"
    {(yyval.exp)=new expression(0,bool_v,(yyvsp[(3) - (3)].str),peremen,vetor);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 197 "my_bis.y"
    { line1 = (yylsp[(2) - (3)]).first_line;  line2 = (yylsp[(2) - (3)]).first_column; line3 = (yylsp[(2) - (3)]).last_line;line4 = (yylsp[(2) - (3)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 199 "my_bis.y"
    {(yyval.exp)=new expression(1,int_v,(yyvsp[(4) - (4)].str),peremen,vetor);}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 200 "my_bis.y"
    {(yyval.exp)=new expression(1,int_v,(yyvsp[(4) - (4)].str),peremen,vetor);}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 201 "my_bis.y"
    {  line1 = (yylsp[(2) - (4)]).first_line;  line2 = (yylsp[(2) - (4)]).first_column; line3 = (yylsp[(2) - (4)]).last_line;line4 = (yylsp[(2) - (4)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 202 "my_bis.y"
    {(yyval.exp)=new expression(0,int_m,(yyvsp[(3) - (3)].str),peremen,matriz);}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 203 "my_bis.y"
    { line1 = (yylsp[(2) - (3)]).first_line;  line2 = (yylsp[(2) - (3)]).first_column; line3 = (yylsp[(2) - (3)]).last_line;line4 = (yylsp[(2) - (3)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 205 "my_bis.y"
    {(yyval.exp)=new expression(0,bool_m,(yyvsp[(3) - (3)].str),peremen,matriz);}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 206 "my_bis.y"
    {(yyval.exp)=new expression(1,int_m,(yyvsp[(4) - (4)].str),peremen,matriz);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 207 "my_bis.y"
    {(yyval.exp)=new expression(1,bool_m,(yyvsp[(4) - (4)].str),peremen,matriz);}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 208 "my_bis.y"
    { line1 = (yylsp[(2) - (4)]).first_line;  line2 = (yylsp[(2) - (4)]).first_column; line3 = (yylsp[(2) - (4)]).last_line;line4 = (yylsp[(2) - (4)]).last_column; yyerror("net kluchevogo slova"); yyerrok;}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 218 "my_bis.y"
    {(yyval.varr)=new vec;(yyval.varr)->add((yyvsp[(1) - (1)].exp));}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 220 "my_bis.y"
    {(yyval.varr)->add((yyvsp[(3) - (3)].exp)) ;}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 223 "my_bis.y"
    {(yyval.varr)=(yyvsp[(2) - (3)].varr);}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 224 "my_bis.y"
    { line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 ckobki"); yyerrok;}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 228 "my_bis.y"
    {(yyval.mm)=new matr;(yyval.mm)->add((yyvsp[(1) - (1)].varr));}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 230 "my_bis.y"
    {(yyval.mm)->add((yyvsp[(3) - (3)].varr));}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 233 "my_bis.y"
    {(yyval.mm)=(yyvsp[(2) - (3)].mm);}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 234 "my_bis.y"
    { line1 = (yylsp[(3) - (3)]).first_line;  line2 = (yylsp[(3) - (3)]).first_column; line3 = (yylsp[(3) - (3)]).last_line;line4 = (yylsp[(3) - (3)]).last_column; yyerror("net 2 ckobki"); yyerrok;}
    break;


/* Line 1792 of yacc.c  */
#line 2637 "my_bis.tab.cpp"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 239 "my_bis.y"


int main(void)
{
yydebug=1;
int dd;
	//printf("It works!\n");
	//yyparse();
	std::cout<<"play game?if no to vvedite 0----------->>>>>>>>>>";
	std::cin>>dd;
	if(dd){
	std::cout<<"THE GAME HAS BEGUN"<<std::endl;
	go_play_game();
	yyin = fopen("C:\\Users\\Kukusik\\Desktop\\bdz\\2_63\\game_prog.txt", "r");
	if(yyin==NULL){
	std::cout<<"file ne open";
	return 0;}
	yyparse();
	}
	else{
	yyin = fopen("C:\\cygwin64\\home\\Kukusik\\prog.txt", "r");
	if(yyin==NULL){
	std::cout<<"file ne open";
	return 0;}

	yyparse();
	fclose(yyin);}
	return 0;
}


void yyerror(const char *ppp)
{const char *l=ppp;
printf("l:%d c:%d - l:%d c: %d\n---------------->",line1,line2,line3,line4);

	printf("%s\n",ppp);
	
}