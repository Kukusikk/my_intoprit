%{  
#include "C:\cygwin64\home\Kukusik\my_bis.tab.h"   /*подсоединяем наш бизон файл*/
#include <stdlib.h>  
//#include "C:\cygwin64\home\Kukusik\tree.h"
#include <string>
#include <bitset>
extern void yyerror(const char*);
std::string for_dv_chis;//строка для проверки на 2ичную систему
char *help2;
using namespace std;
%} 

%% 
true         {printf("TRUE\n");
              yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return TRUE;}
false        {printf("FALSE\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return FALSE;}
[c]          {printf("CONSTANT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return CONSTANT;}
[v]          {printf("VECTOR\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return VECTOR;}
[m]          {printf("MATRIX\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return MATRIX;}
int    {printf("INT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return INT;}
bool     {printf("T_BOOL\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return T_BOOL;}
[0-9]+       {if((yytext[0]=='0')&(yytext[1]!='\0')){help2=yytext;help2++; for_dv_chis=_strdup(help2);yylval.num=bitset<32>(for_dv_chis).to_ulong();return NUMBER ;}
                yylval.num=atoi(yytext);printf("NUMBER\n");
				 yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);
				return NUMBER ;}///тут пропишем что если у нас число начианчетс на 0 то тут же переводим мз 2 в 10 и возвращаем в 10 форме
","          {printf("ZAPAT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return ZAPAT;}
"|"          {printf("OR\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return OR;}
";"          {printf("TZAP\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return TZAP;}
=          {printf("RAVN\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return RAVN;}
[<] {printf("SRAVN_P\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return SRAVN_P;}
[>] {printf("SRAVN_L\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return SRAVN_L;}
"("          {printf("IN2\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return IN2;}
")"          {printf("OUT2\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return OUT2;}
"{"          {printf("IN1\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return IN1;}
"}"          {printf("OUT1\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return OUT1;}
[\\+]          {printf("PLUS\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return PLUS;}
-          {printf("MINUS\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return MINUS;}
"*"          {printf("YMN_M\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return YMN_M;}
".*"          {printf("YMN_E\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return YMN_E;}
"`"          {printf("TRAN\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return TRAN;}
sum          {printf("SUMM\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return SUMM;}
\\<<         {printf("SDVIG_LEV\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return SDVIG_LEV;}
>>          {printf("SDVIG_PRAV\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return SDVIG_PRAV;}
!          {printf("NOT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return NOT;}
and|&&          {printf("AND\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return AND;}
"["          {printf("IN3\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return IN3;}
"]"          {printf("OUT3\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return OUT3;}
for          {printf("FOR\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return FOR;}
function {printf("FUNCTION\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return FUNCTION;}
begin          {printf("BEGI\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return BEGI;}
end          {printf("END\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return END;}
if          {printf("IF\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return IF;}
move          {printf("MOOV\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return MOOV;}
right          {printf("NAPRAVLEN_RIT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return NAPRAVLEN_RIT;}
left          {printf("NAPRAVLEN_LEFT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return NAPRAVLEN_LEFT;}
wall          {printf("WALL\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return WALL;}
exit          {printf("EXIT\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return EXIT;}
[a-zA-Z][a-zA-z0-9]*           {yylval.str=_strdup(yytext);printf(" NAME\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return NAME;}

  "...\n"          {yylloc.last_line=++yylloc.first_line; yylloc.last_column = yylloc.first_column = 0;}//игнор
[\\:]         {printf("DVOET\n"); yylloc.first_column = yylloc.last_column + 1; yylloc.last_column += strlen (yytext);return DVOET;}
\n      {yylloc.last_line=++yylloc.first_line;  yylloc.last_column = yylloc.first_column = 0; return ENDLINE;} /* игнорируем символ конца строки */;
[ \t]+    {yylloc.first_column = yylloc.last_column + 1;yylloc.last_column += strlen (yytext); } /* игнорируем пробелы и символы табуляции */;
. {yylloc.first_column = ++yylloc.last_column;yyerror("Unknown character");}
%%
int yywrap(void) {return 1;}
