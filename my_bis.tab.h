/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 28 "my_bis.y"

int num;
char* str;
//дальше будут какие то вспомогательные классы 
class expression* exp;
class spis_predlog* sp;
class vec* varr;
class predlog* predl;
class matr* mm;


/* Line 2058 of yacc.c  */
#line 115 "my_bis.tab.h"
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
