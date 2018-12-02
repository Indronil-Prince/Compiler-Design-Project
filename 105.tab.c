
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "105.y"

	#include<stdio.h>
	#include <string.h>
	#include <math.h>
	int sym[26], store[26], p;
	int forswitchcase=5;
	int forifelse = 1,str_flagd=0,val_flagd=0;
	int fvalue, val_flag=0, str_flag=0, val_prior=0, str_prior=0, prior=0;
	int switchstack[100], check[100], check2[100], checkstr[100], ll=0, l=0, flag=1, val, i, j, count=0;
	char switchstackstr[100][100], finsidestr[100];
	char str[100];
	char multichar[100][100];
	int m=0, multi_flag=0, ind=0, t=1, single=0, multi=0;
	int cnt;
  	
	int yyerror(char* );
    int yylex();
	
	void clear_str(){
		for(i=0;str[i]!='\0';i++)
		str[i]='\0';
	}
	
	void clear_multichar(int cnt)
	{
		for(p=0; multichar[cnt-1][p]!='\0'; p++) 
		multichar[cnt-1][p] = '\0';
	}
	
	void re_dec(int cnt)
	{
		for(i=0; i<cnt-1; i++)  //when cnt > 1
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				printf("variable '%s' is redeclared\n",multichar[i]);
				t=0;
				clear_multichar(cnt);
				cnt--;
			}
		}
	}
	
	int un_dec()
	{	
		multi_flag=0;
		for(i=0; i<cnt-1; i++)
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				multi_flag = 1;
			}
		}

		if(!multi_flag)
		{
			printf("variable '%s' undeclared!\n",multichar[cnt-1]);
			
			clear_multichar(cnt);
			cnt=cnt-1;
			return 1;
		}
		
		return 0;
	}

	int check_index(int cnt){
		for(i=0; i<cnt-1; i++)
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				return i;
			}
		}
	}
	
	void print_single(int str_flag, int val_flag, int str_prior, int val_prior){
		if(str_flag && val_flag && str_prior < val_prior)
		{
			printf("Printing statement : %s\n",finsidestr);
			printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
		}
		else if(str_flag && val_flag && str_prior > val_prior)
		{
			printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
			printf("Printing statement : %s\n",finsidestr);
		}
		else{
			if(val_flag)printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
			if(str_flag)printf("Printing statement : %s\n",finsidestr);
		}
	}
	
	void print_multi(int str_flag, int val_flag, int str_prior, int val_prior){
		if(str_flag && val_flag && str_prior < val_prior)
		{
			printf("Printing statement : %s\n",finsidestr);
			printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
		}
		else if(str_flag && val_flag && str_prior > val_prior)
		{
			printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
			printf("Printing statement : %s\n",finsidestr);
		}
		else{
			if(val_flag) printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
			if(str_flag) printf("Printing statement : %s\n",finsidestr);
		}
	}
	


/* Line 189 of yacc.c  */
#line 186 "105.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     AA = 259,
     LL = 260,
     FOR = 261,
     VAR = 262,
     VAR1 = 263,
     COLON = 264,
     BREAK = 265,
     DEFAULT = 266,
     CASE = 267,
     THEN = 268,
     IF = 269,
     ELSE = 270,
     SWITCH = 271,
     MAIN = 272,
     RET = 273,
     INT = 274,
     STR = 275,
     FLOAT = 276,
     CHAR = 277,
     LP = 278,
     RP = 279,
     LB = 280,
     RB = 281,
     CM = 282,
     SM = 283,
     PRNT = 284,
     PLUS = 285,
     MINUS = 286,
     MULT = 287,
     DIV = 288,
     POW = 289,
     ASSIGN = 290,
     GT = 291,
     LT = 292,
     GE = 293,
     LE = 294,
     EE = 295,
     IFX = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 269 "105.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    11,    14,    17,    20,    24,    26,
      28,    30,    34,    36,    38,    40,    44,    48,    58,    68,
      78,    88,    93,   110,   127,   144,   161,   169,   171,   174,
     176,   179,   188,   197,   203,   209,   211,   213,   215,   217,
     219,   220,   223,   226,   230,   234,   238,   240,   243,   248,
     253,   255,   257,   260,   264,   268,   272,   274,   276,   280,
     284,   286,   290,   294,   296,   300,   302,   304,   308
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    17,    23,    24,    25,    44,    26,    -1,
      -1,    44,    57,    -1,    44,    45,    -1,    44,    49,    -1,
      46,    47,    28,    -1,    19,    -1,    21,    -1,    22,    -1,
      48,    27,    47,    -1,    48,    -1,     7,    -1,     8,    -1,
       8,    35,     3,    -1,     7,    35,     3,    -1,    14,     7,
      54,     3,    13,     9,    25,    55,    26,    -1,    14,     7,
      54,     7,    13,     9,    25,    55,    26,    -1,    14,     8,
      54,     3,    13,     9,    25,    55,    26,    -1,    14,     8,
      54,     7,    13,     9,    25,    55,    26,    -1,    15,    25,
      55,    26,    -1,     6,    23,     7,    35,     3,    27,     7,
      39,     3,    27,     7,     4,    24,    25,    55,    26,    -1,
       6,    23,     7,    35,     3,    27,     7,    38,     3,    27,
       7,     5,    24,    25,    55,    26,    -1,     6,    23,     8,
      35,     3,    27,     8,    39,     3,    27,     8,     4,    24,
      25,    55,    26,    -1,     6,    23,     8,    35,     3,    27,
       8,    38,     3,    27,     8,     5,    24,    25,    55,    26,
      -1,    16,    23,     7,    24,    25,    50,    26,    -1,    51,
      -1,    51,    53,    -1,    52,    -1,    52,    51,    -1,    12,
       3,     9,    29,     7,    28,    10,    28,    -1,    12,     3,
       9,    29,    20,    28,    10,    28,    -1,    11,     9,    29,
       7,    28,    -1,    11,     9,    29,    20,    28,    -1,    36,
      -1,    37,    -1,    40,    -1,    39,    -1,    38,    -1,    -1,
      49,    55,    -1,    56,    55,    -1,    29,     7,    28,    -1,
      29,     8,    28,    -1,    29,    20,    28,    -1,    28,    -1,
      60,    28,    -1,     7,    35,    60,    28,    -1,     8,    35,
      60,    28,    -1,    58,    -1,    59,    -1,    59,    58,    -1,
      29,    20,    28,    -1,    29,     7,    28,    -1,    29,     8,
      28,    -1,     7,    -1,     8,    -1,    60,    30,    61,    -1,
      60,    31,    61,    -1,    61,    -1,    61,    32,    62,    -1,
      61,    33,    62,    -1,    62,    -1,    62,    34,    63,    -1,
      63,    -1,    64,    -1,    23,    60,    24,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   131,   132,   133,   134,   137,   140,   140,
     140,   142,   142,   144,   153,   168,   195,   203,   222,   242,
     268,   291,   298,   317,   336,   358,   380,   408,   408,   410,
     410,   412,   419,   432,   437,   452,   452,   452,   452,   452,
     454,   454,   454,   456,   462,   475,   483,   484,   485,   490,
     505,   508,   508,   510,   514,   517,   523,   524,   525,   526,
     527,   530,   531,   542,   545,   546,   549,   550,   553
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "AA", "LL", "FOR", "VAR", "VAR1",
  "COLON", "BREAK", "DEFAULT", "CASE", "THEN", "IF", "ELSE", "SWITCH",
  "MAIN", "RET", "INT", "STR", "FLOAT", "CHAR", "LP", "RP", "LB", "RB",
  "CM", "SM", "PRNT", "PLUS", "MINUS", "MULT", "DIV", "POW", "ASSIGN",
  "GT", "LT", "GE", "LE", "EE", "IFX", "$accept", "program", "cstatement",
  "cdeclaration", "TYPE", "varlist", "vassign", "structure", "sblock",
  "caselist", "casestatement", "defaultstatement", "operator",
  "finsidelist", "finside", "statement", "printlist", "printone", "expr",
  "term", "power", "factor", "digit", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     2,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     3,     9,     9,     9,
       9,     4,    16,    16,    16,    16,     7,     1,     2,     1,
       2,     8,     8,     5,     5,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     3,     3,     1,     2,     4,     4,
       1,     1,     2,     3,     3,     3,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,    68,     0,
      56,    57,     0,     0,     0,     8,     9,    10,     0,     2,
      46,     0,     5,     0,     6,     4,    50,    51,     0,    60,
      63,    65,    66,     0,     0,     0,     0,     0,    40,     0,
      56,    57,     0,     0,     0,     0,    13,    14,     0,    12,
      52,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    39,    38,    37,     0,     0,     0,    40,
       0,    40,     0,    67,    54,    55,    53,     0,     0,     7,
       0,    58,    59,    61,    62,    64,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,    41,    21,    42,
       0,    16,    15,    11,     0,     0,     0,     0,     0,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    29,     0,     0,    40,    40,    40,    40,
       0,    26,     0,    28,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    40,    40,    40,    40,     0,     0,     0,
       0,    23,    22,    25,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    22,    23,    48,    49,    69,   121,   122,
     123,   133,    66,    70,    71,    25,    26,    27,    28,    29,
      30,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
       1,    17,    68,    48,   -70,    22,   -70,    -2,   -70,    53,
      46,    51,     3,    64,    67,   -70,   -70,   -70,     0,   -70,
     -70,     8,   -70,    31,   -70,   -70,   -70,    62,    39,    23,
      60,   -70,   -70,    56,     0,     0,    14,    14,    16,    85,
     -70,   -70,    13,    65,    69,    70,    61,    66,    71,    73,
     -70,   -70,     6,     6,     6,     6,     6,    72,    74,    43,
      47,   -70,   -70,   -70,   -70,   -70,    58,    59,    26,    16,
      76,    16,    79,   -70,   -70,   -70,   -70,    92,   101,   -70,
      31,    23,    23,    60,    60,   -70,   102,   103,   -70,   -70,
      95,    97,    98,    99,    90,    91,    93,   -70,   -70,   -70,
      88,   -70,   -70,   -70,    96,   100,   111,   113,   115,   116,
     -70,   -70,   -70,   114,   121,   122,   104,   106,   107,   108,
     131,   109,   125,   114,    41,    44,    16,    16,    16,    16,
     128,   -70,   129,   -70,   -70,   136,   137,   138,   139,   117,
     118,   119,   120,   123,   124,   127,   130,   132,   133,   -70,
     -70,   -70,   -70,    28,    29,   140,   141,   142,   143,   134,
     135,   144,   145,   150,   152,   153,   157,   154,   155,   -70,
     -70,   146,   147,   151,   156,   148,   149,   158,   159,   160,
     161,   -70,   -70,    16,    16,    16,    16,   162,   163,   164,
     165,   -70,   -70,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,    86,   -70,   167,   -70,    45,
     -70,   -70,   112,   -69,   -70,   -70,   166,   -70,     7,    32,
      33,   126,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      97,     8,    99,     8,     9,    10,    11,    40,    41,     8,
      36,    37,    12,    13,    14,    43,    44,    15,     1,    16,
      17,    18,     9,    18,    19,    42,    20,    21,    45,    18,
      12,    13,    14,    94,    95,   159,   161,    73,    46,    47,
       3,    59,    60,    52,    53,    68,    96,     6,   160,   162,
      61,    62,    63,    64,    65,    54,    55,   139,   140,   141,
     142,    90,    92,    57,    58,    91,    93,    51,     4,    52,
      53,    88,     5,    52,    53,    89,    33,    52,    53,   135,
     136,    34,   137,   138,    81,    82,    35,    83,    84,    38,
      39,    21,    72,    74,    56,   101,    77,    75,    76,    79,
      80,    78,    98,   100,   102,   104,   105,    86,   106,    87,
     107,   108,   109,   113,   187,   188,   189,   190,   110,   111,
     116,   112,   117,   114,   118,   119,   120,   115,   124,   126,
     125,   127,   128,   129,   130,   131,   132,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   163,   164,    67,
     165,   166,   153,   154,   155,   171,   172,   156,   173,   157,
     158,   174,   167,   168,   175,   176,   103,     0,   134,     0,
     177,   178,   169,   170,    24,   179,   181,   182,     0,     0,
     180,     0,    85,   183,   184,   185,   186,     0,   191,   192,
     193,   194,     0,    50
};

static const yytype_int16 yycheck[] =
{
      69,     3,    71,     3,     6,     7,     8,     7,     8,     3,
       7,     8,    14,    15,    16,     7,     8,    19,    17,    21,
      22,    23,     6,    23,    26,    18,    28,    29,    20,    23,
      14,    15,    16,     7,     8,     7,     7,    24,     7,     8,
      23,    34,    35,    30,    31,    29,    20,    25,    20,    20,
      36,    37,    38,    39,    40,    32,    33,   126,   127,   128,
     129,     3,     3,     7,     8,     7,     7,    28,     0,    30,
      31,    28,    24,    30,    31,    28,    23,    30,    31,    38,
      39,    35,    38,    39,    52,    53,    35,    54,    55,    25,
      23,    29,     7,    28,    34,     3,    35,    28,    28,    28,
      27,    35,    26,    24,     3,     3,     3,    35,    13,    35,
      13,    13,    13,    25,   183,   184,   185,   186,    28,    28,
       9,    28,     9,    27,     9,     9,    12,    27,     7,    25,
       8,    25,    25,    25,     3,    26,    11,     9,     9,     3,
       3,     3,     3,    26,    26,    26,    26,     7,     7,    37,
       8,     8,    29,    29,    27,     5,     4,    27,     5,    27,
      27,     4,    28,    28,    10,    10,    80,    -1,   123,    -1,
      24,    24,    28,    28,     7,    24,    28,    28,    -1,    -1,
      24,    -1,    56,    25,    25,    25,    25,    -1,    26,    26,
      26,    26,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    43,    23,     0,    24,    25,    44,     3,     6,
       7,     8,    14,    15,    16,    19,    21,    22,    23,    26,
      28,    29,    45,    46,    49,    57,    58,    59,    60,    61,
      62,    63,    64,    23,    35,    35,     7,     8,    25,    23,
       7,     8,    60,     7,     8,    20,     7,     8,    47,    48,
      58,    28,    30,    31,    32,    33,    34,     7,     8,    60,
      60,    36,    37,    38,    39,    40,    54,    54,    29,    49,
      55,    56,     7,    24,    28,    28,    28,    35,    35,    28,
      27,    61,    61,    62,    62,    63,    35,    35,    28,    28,
       3,     7,     3,     7,     7,     8,    20,    55,    26,    55,
      24,     3,     3,    47,     3,     3,    13,    13,    13,    13,
      28,    28,    28,    25,    27,    27,     9,     9,     9,     9,
      12,    50,    51,    52,     7,     8,    25,    25,    25,    25,
       3,    26,    11,    53,    51,    38,    39,    38,    39,    55,
      55,    55,    55,     9,     9,     3,     3,     3,     3,    26,
      26,    26,    26,    29,    29,    27,    27,    27,    27,     7,
      20,     7,    20,     7,     7,     8,     8,    28,    28,    28,
      28,     5,     4,     5,     4,    10,    10,    24,    24,    24,
      24,    28,    28,    25,    25,    25,    25,    55,    55,    55,
      55,    26,    26,    26,    26
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 128 "105.y"
    { printf("\nSuccessfully compiled!!!\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 137 "105.y"
    { printf("valid declaration\n\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "105.y"
    {
										if(store[(yyvsp[(1) - (1)])] == 1) printf("variable '%c' redeclared!!!\n",(yyvsp[(1) - (1)])+'a');
										else
										{
											store[(yyvsp[(1) - (1)])]=1;
											printf("%c declared!\n",(yyvsp[(1) - (1)])+'a');
										}	
									;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 153 "105.y"
    {	
										int v = 1;
										for(i=0; i<cnt-1; i++)
										{	
											if(!strcmp(multichar[cnt-1],multichar[i]))
											{
												printf("variable '%s' redeclared!!!\n",multichar[i]);
												clear_multichar(cnt);
												cnt--;
												v=0;
											}
										}
										if(v)printf("%s declared!\n",multichar[cnt-1]);
									;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 168 "105.y"
    {
										t=1;
										
										if(cnt<2)             //when cnt == 1
										{
											char c = (char) (yyvsp[(3) - (3)]);
											multichar[cnt-1][99]=c;
											int i = (int) c;
											
										}
										
										re_dec(cnt);
								
										if(t&&cnt>1)
										{
										
											char c = (char) (yyvsp[(3) - (3)]);
											multichar[cnt-1][99]=c;
											int i = (int) c;
										
										}
									
										if(t)printf("%s = %d declared & assigned!\n",multichar[cnt-1],multichar[cnt-1][99]);
										
									;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 195 "105.y"
    { 	
										if(store[(yyvsp[(1) - (3)])] == 1) printf("variable '%c' redeclared!!!\n",(yyvsp[(1) - (3)])+'a');
										else store[(yyvsp[(1) - (3)])]=1;
										sym[(yyvsp[(1) - (3)])] = (yyvsp[(3) - (3)]); 
										printf("%c = %d declared & assigned!\n",(yyvsp[(1) - (3)])+'a',(yyvsp[(3) - (3)]));
									;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 203 "105.y"
    {	
													if(store[(yyvsp[(2) - (9)])]!=1)printf("Undeclared character : %c\n",(yyvsp[(2) - (9)])+'a');
													printf("\nIf Block\n");
													if( sym[(yyvsp[(2) - (9)])] > (yyvsp[(4) - (9)]))
													{
														printf("Condition True!\n");
																		
														if(single)print_single(str_flag,val_flag,str_prior,val_prior);
														if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
														forifelse = 0;
													}
													else
													{
														printf("Your 'IF' condition is false!\n");
													}
														single=multi=0;
									  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 222 "105.y"
    {	
													if(store[(yyvsp[(2) - (9)])]!=1)printf("Undeclared character : %c\n",(yyvsp[(2) - (9)])+'a');
													if(store[(yyvsp[(4) - (9)])]!=1)printf("Undeclared character : %c\n",(yyvsp[(4) - (9)])+'a');
													printf("\nIf Block\n");
													if( sym[(yyvsp[(2) - (9)])] > sym[(yyvsp[(4) - (9)])])
													{
														printf("Condition True!\n");
																		
														if(single)print_single(str_flag,val_flag,str_prior,val_prior);
														if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
														forifelse = 0;
													}
													else
													{
														printf("Your 'IF' condition is false!\n");
													}
														single=multi=0;
									  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 242 "105.y"
    {
																
																	un_dec();
																	ind = check_index(cnt);
																	printf("\nIf Block\n");
																	if( multichar[ind][99] > (yyvsp[(4) - (9)]))
																	{
																		printf("Condition True!\n");
																		
																		if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																		if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
																		forifelse = 0;
																	}
																	else
																	{
																		printf("Your 'IF' condition is false!\n");
																	}
																	single=multi=0;
																	
																	printf("Deleting %s\n",multichar[cnt-1]);
																	clear_multichar(cnt);
																	cnt--;
																
																;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 268 "105.y"
    {
																
																	un_dec();
																	ind = check_index(cnt);
																	printf("\nIf Block\n");
																	if( multichar[ind][99] > sym[(yyvsp[(4) - (9)])])
																	{
																		printf("IF condition True!\n");
																		
																		if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																		if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
																		forifelse = 0;
																	}
																	else
																	{
																		printf("IF condition false!\n");
																	}
																	single=multi=0;
																	clear_multichar(cnt);
																	cnt--;
																	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 291 "105.y"
    { 	printf("\nElse Block\n");
											if(forifelse)
											{
												print_single(str_flag, val_flag, str_prior, val_prior);
											}
										;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 298 "105.y"
    {   
															printf("\nFor Loop!!\n");
															if(store[(yyvsp[(3) - (16)])]!=1)
															{
																printf("Undeclared variable : %c\n",(yyvsp[(3) - (16)])+'a');
															}
																						
															else
															{
																for( sym[(yyvsp[(3) - (16)])]=(yyvsp[(5) - (16)]); sym[(yyvsp[(3) - (16)])] <= (yyvsp[(9) - (16)]); sym[(yyvsp[(3) - (16)])]++)
																{
																	if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																	if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																}
															}
															str_flag=val_flag=0;
															single=multi=0;
												;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 317 "105.y"
    {   
															printf("\nFor Loop!!\n");
															if(store[(yyvsp[(3) - (16)])]!=1)
															{
																printf("Undeclared variable : %c\n",(yyvsp[(3) - (16)])+'a');
															}
																						
															else
															{
																for( sym[(yyvsp[(3) - (16)])]=(yyvsp[(5) - (16)]); sym[(yyvsp[(3) - (16)])] >= (yyvsp[(9) - (16)]); sym[(yyvsp[(3) - (16)])]--)
																{
																	if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																	if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																}
															}
															str_flag=val_flag=0;
															single=multi=0;
												;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 336 "105.y"
    {
															if(un_dec()==0){
																							
															ind = check_index(cnt);
															printf("\nFor Loop!!\n");
															int temp = multichar[ind][99];
															for( temp=(yyvsp[(5) - (16)]); temp<=(yyvsp[(9) - (16)]); temp++)
															{
																multichar[ind][99]=temp;
																if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																if(single)print_single(str_flag,val_flag,str_prior,val_prior);
															}
															str_flag=val_flag=0;
													}
															clear_multichar(cnt-1);
															clear_multichar(cnt-2);
															cnt = cnt - 3;
																						
															
															single=multi=0;
													 ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 358 "105.y"
    {
															if(un_dec()==0){
																							
															ind = check_index(cnt);
															printf("\nFor Loop!!\n");
															int temp = multichar[ind][99];
															for( temp=(yyvsp[(5) - (16)]); temp>=(yyvsp[(9) - (16)]); temp--)
															{
																multichar[ind][99]=temp;
																if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																if(single)print_single(str_flag,val_flag,str_prior,val_prior);
															}
															str_flag=val_flag=0;
													}
															clear_multichar(cnt-1);
															clear_multichar(cnt-2);
															cnt = cnt - 3;
																						
															
															single=multi=0;
													 ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 380 "105.y"
    { 
														printf("\nSwitch case\n"); 
														forswitchcase=sym[(yyvsp[(3) - (7)])]; 
														if(val_flag)
															for( i=0; i<l; i++){
																if(check[i]==forswitchcase){
																	printf("Case %d: Value of %c = %d\n", forswitchcase, switchstack[check[i]]+'a', sym[switchstack[check[i]]]);
																	flag=0;
																	break;
																}
															}
														l=0;
														if(str_flag)
															for( i=0; i<ll; i++){
																if(checkstr[i]==forswitchcase){
																	printf("Case %d: Your statement is = %s\n", forswitchcase, switchstackstr[check[i]]);
																	flag=0;
																	break;
																}
															}
														
														if(flag&&str_flagd)printf("Default: Your statement = %s\n",switchstackstr[ll]);
														if(flag&&val_flagd)printf("Default: value of %c = %d\n",val+'a',sym[val]);
														ll=0;
													;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 412 "105.y"
    { 	
														switchstack[(yyvsp[(2) - (8)])]=(yyvsp[(5) - (8)]);
														check[l]=(yyvsp[(2) - (8)]);
														l++;
														val_flag = 1;
													;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 419 "105.y"
    {
														checkstr[ll]=(yyvsp[(2) - (8)]);
														for(i=0;str[i]!='\0';i++)
														{
															switchstackstr[ll][i]=str[i];
														}
														
														ll++;
														str_flag = 1;
														clear_str();
													;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 432 "105.y"
    {
														//printf("Default \n");
														val=(yyvsp[(4) - (5)]);
														val_flagd=1;
													;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 437 "105.y"
    {
														
														//printf("Default\n");
														str_flagd=1;
										
														for(i=0;str[i]!='\0';i++)
														{	
															switchstackstr[ll][i]=str[i];
															printf("%c ",switchstackstr[ll][i]);
														}
														printf("%s\n",switchstackstr[ll]);
														clear_str();
													;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 456 "105.y"
    { 	
														fvalue=(yyvsp[(2) - (3)]); 
														val_flag=1;
														val_prior=++prior;
														single=1;
													;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 462 "105.y"
    { 	
														printf("This var = %s\n",multichar[cnt-1]);
														un_dec();
														
														fvalue = multichar[check_index(cnt)][99];
														printf("%s = %d\n",multichar[check_index(cnt)],fvalue);
														
														val_flag=1;
														val_prior=++prior;
														multi=1;
														
													;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 475 "105.y"
    {
														str_flag=1;
														for(i=0;str[i]!='\0';i++)finsidestr[i]=str[i];
														str_prior=++prior;
														clear_str();
													;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 484 "105.y"
    { printf("\nvalue of expression: %d\n", (yyvsp[(1) - (2)])); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 485 "105.y"
    {
										sym[(yyvsp[(1) - (4)])] = (yyvsp[(3) - (4)]); 
										if(store[(yyvsp[(1) - (4)])]!=1)printf("'%c' is Undeclared",(yyvsp[(1) - (4)])+'a');
										printf("%c = %d assigned!\n",(yyvsp[(1) - (4)])+'a',(yyvsp[(3) - (4)]));
									;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 490 "105.y"
    {
										multi_flag = 0;
										
										un_dec();

										for(i=0;i<cnt-1;i++)
										{
											if(!strcmp(multichar[cnt-1],multichar[i]))
											{
												multichar[i][99] =(char)(yyvsp[(3) - (4)]);
												printf("%s = %d assigned!\n",multichar[i],multichar[i][99]);
											}
										}
										
									;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 510 "105.y"
    {
										printf("Prininting statement : %s\n",str);
										clear_str();
							;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 514 "105.y"
    {			
										printf("Prininting value : %c = %d\n",(yyvsp[(1) - (3)])+'a',sym[(yyvsp[(1) - (3)])]);
							;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 517 "105.y"
    {
										ind = check_index(cnt);
										printf("Prininting value : %s = %d\n",multichar[ind],multichar[ind][99]);
							;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 523 "105.y"
    { (yyval) = sym[(yyvsp[(1) - (1)])]; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 524 "105.y"
    { (yyval) = multichar[check_index(cnt)][99]; clear_multichar(cnt); cnt--; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 525 "105.y"
    { (yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(3) - (3)]); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 526 "105.y"
    { (yyval) = (yyvsp[(1) - (3)]) - (yyvsp[(3) - (3)]); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 530 "105.y"
    { (yyval) = (yyvsp[(1) - (3)]) * (yyvsp[(3) - (3)]); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 531 "105.y"
    { 
										if((yyvsp[(3) - (3)])) 
										{
												(yyval) = (yyvsp[(1) - (3)]) / (yyvsp[(3) - (3)]);
										}
										else
										{
											(yyval) = 0;
											printf("\ndivision by zero\t");
										}
									;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 545 "105.y"
    { (yyval) = pow((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 549 "105.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 550 "105.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 553 "105.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2207 "105.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 557 "105.y"


int yywrap()
{
return 1;
}

int yyerror(char *s){
	printf( "%s\n", s);
	return 1;
}
