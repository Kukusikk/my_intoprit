%{
#include <iostream>
#include "C:\cygwin64\home\Kukusik\tree.h"

#define YYDEBUG 1
extern FILE * yyin;
extern std::map<std::string, Function*>tab_f;//таблица функций
int yylex(void);      //объявили тут функцию из лексического анализатора, определение которой генерируется из l файла
void yyerror(const char *);
//int for_main(void);
const char* for_er[5] = {"heve not ;", "net 2 ckobki","net 2 operada","lishnii posle predlogenia","net kluchevogo slova"};//массив для видов ошибок
int line1;
int line2;
int line3;
int line4;
%}
//наши токены

%token TRUE FALSE CONSTANT FUNCTION VECTOR MATRIX INT T_BOOL ZAPAT IN1 OUT1 TZAP  IN2 OUT2 IN3 OUT3 FOR BEGI END IF NAPRAVLEN_RIT NAPRAVLEN_LEFT WALL EXIT MOOV DVOET CONTIN_PREDLOG ENDLINE

%right TRAN SUMM SDVIG_LEV SDVIG_PRAV 
%left OR RAVN SRAVN_L SRAVN_P PLUS MINUS AND 
%left YMN_M YMN_E
%left NOT 

//здесь объявили объединение. Это объединение позволяет присвоить разным терминалам и составным единицам разные типы данных.

%union {
int num;
char* str;
//дальше будут какие то вспомогательные классы 
class expression* exp;
class spis_predlog* sp;
class vec* varr;
class predlog* predl;
class matr* mm;
}
%token <num> NUMBER //часть токенов имеют тип, эти токены помимо ид токена, также будут передавать некоторую информацию
%token <str> NAME //указатели на строки

//тут объявляем разоичные составные единицы (то, на чём строится грамматика)


%type <sp>Predlog_s Parametr_s Parametr_s2
%type <predl>Predlog 
%type <predl>Funcion_v Virag_predlog Obav_predlog If_predlog Robot_predlog For_predlog Funcion
%type <mm>Ar_virag_form Ar_virag_form2
%type <exp>Peremen Ar_virag 
%type <varr>Ar_virag_forv Ar_forv2 Peremen_s Peremen_s2
//начало зоны правил грамматики

%%
  programm:Predlog_s{ go_pr22($1);exit(0);}
/*предложения являются набором из нескольких предложений*/

Predlog_s:  Predlog{$$=new spis_predlog;$$->add($1);}

	| Predlog_s Predlog {$$->add($2);}
	
	;

	

/*предложение бывает 7 видов. все онни вернут указатель на прдложние*/

 Predlog: Obav_predlog TZAP ENDLINE{$$=$1;} /*предложения объявления переменных*/
	| Obav_predlog error ENDLINE  { line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line; line4 = @2.last_column;yyerror("heve not ;"); yyerrok;}   /*предложения выражения без ; это ошибка*/
          | Virag_predlog  TZAP ENDLINE  {$$=$1;}   /*предложения выражения*/
	 | Virag_predlog error ENDLINE  { line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line; line4 = @2.last_column; yyerror("heve not ;"); yyerrok;}   /*предложения выражения без ; это ошибка*/
          | Funcion ENDLINE {$$=$1;}//функция это тоже предложение языка

          | Robot_predlog ENDLINE {$$=$1;}         /*предложения для робота*/
	
          | If_predlog  ENDLINE {$$=$1;}      /*предложения условия*/
	
          | For_predlog ENDLINE {$$=$1;}      /*предложения циклы*/
          |Funcion_v ENDLINE {$$=$1;} //предложения вызов функции

	  ;
	
	   //ВЫЗОВ функции являетмя одним из типов предложений
Funcion_v: Ar_virag_forv RAVN RAVN Ar_virag IN2 Ar_virag_forv OUT2{$$=new  predlog(funct_v,$1,$4->name,$6);}
           |Ar_virag RAVN RAVN Ar_virag IN2 Ar_virag_forv OUT2{$$=new  predlog(funct_v,$1,$4->name,$6);}
	        ;           
				  
Robot_predlog: Ar_virag RAVN MOOV IN2 Ar_virag OUT2{$$=new predlog(robot,mOOV,$1,$5);}
               |NAPRAVLEN_RIT{$$=new predlog(robot,nAPRAVLEN_RIT);}
               |NAPRAVLEN_LEFT{$$=new predlog(robot,nAPRAVLEN_LEFT);}
               |Ar_virag RAVN WALL{$$=new predlog(robot,wALL,$1);}
               |Ar_virag RAVN EXIT{$$=new predlog(robot,eXIT,$1);}
               ;
If_predlog:         /*предложения условия*/

           IF Ar_virag BEGI IN3 IF OUT3 ENDLINE Predlog_s END IN3 IF OUT3{$$=new predlog(if_,$2,$8);}
		   | IF	Ar_virag BEGI IN3 IF ENDLINE error Predlog_s END IN3 IF OUT3   {line1 = @7.first_line;  line2 = @7.first_column; line3 = @7.last_line; line4 = @7.last_column; yyerror("net 2 ckobki "); yyerrok;}   /*предложения выражения без ; это ошибка*/
		| IF	Ar_virag BEGI IN3 IF OUT3 ENDLINE Predlog_s END IN3 IF error   { line1 = @12.first_line;  line2 = @12.first_column; line3 = @12.last_line; line4 = @12.last_column; yyerror("net 2 ckobki "); yyerrok;}   /*предложения выражения без ; это ошибка*/
		    | IF	Ar_virag BEGI IN3 IF OUT3 ENDLINE Predlog_s END IN3 error OUT3   { line1 = @11.first_line;  line2 = @11.first_column; line3 = @11.last_line; line4 = @11.last_column; yyerror("net kluchevogo slova"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		     | IF	Ar_virag error IN3 IF OUT3 ENDLINE Predlog_s END IN3 IF OUT3   {line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line; line4 = @3.last_column; yyerror("net kluchevogo slova"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		//	 | IF	Ar_virag BEGI IN3 error OUT3 ENDLINE Predlog_s END IN3 IF OUT3   {line1 = @5.first_line;  line2 = @5.first_column; line3 = @5.last_line; line4 = @5.last_column ;yyerror("net kluchevogo slova"); yyerrok;}   /*предложения выражения без ;
		   | error	Ar_virag BEGI IN3 IF OUT3 ENDLINE Predlog_s END IN3 IF OUT3   { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net kluchevogo slova"); yyerrok;}   /*предложения выражения без ; это ошибка*/
            ;
For_predlog: FOR Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 FOR OUT3 Predlog_s END IN3 FOR OUT3{$$=new predlog(for_,$2,$4,$6,$11);}
            | error Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 FOR OUT3 Predlog_s END IN3 FOR OUT3   { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net kluchevogo slova"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		 |FOR Peremen RAVN Ar_virag  DVOET Ar_virag error IN3 FOR OUT3 Predlog_s END IN3 FOR OUT3   { line1 = @7.first_line;  line2 = @7.first_column; line3 = @7.last_line;line4 = @7.last_column; yyerror("net kluchevogo slova"); yyerrok;} 
            | FOR Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 error OUT3 Predlog_s END IN3 FOR OUT3   { line1 = @9.first_line;  line2 = @9.first_column; line3 = @9.last_line;line4 = @9.last_column; yyerror("net kluchevogo slova"); yyerrok;}
			| FOR Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 FOR OUT3 Predlog_s END IN3 error OUT3   { line1 = @14.first_line;  line2 = @14.first_column; line3 = @14.last_line;line4 = @14.last_column; yyerror("net kluchevogo slova"); yyerrok;} 
			| FOR Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 FOR error Predlog_s END IN3 FOR OUT3   {line1 = @10.first_line;  line2 = @10.first_column; line3 = @10.last_line;line4 = @10.last_column; yyerror("net 2 ckobki "); yyerrok;} 
			| FOR Peremen RAVN Ar_virag  DVOET Ar_virag BEGI IN3 FOR OUT3 Predlog_s END IN3 FOR error   { line1 = @15.first_line;  line2 = @15.first_column; line3 = @15.last_line;line4 = @15.last_column; yyerror("net 2 ckobki "); yyerrok;} 



  Funcion:Peremen_s2  RAVN FUNCTION NAME	Parametr_s2 ENDLINE BEGI ENDLINE Predlog_s END{$$=new  predlog(funct,$1,$4,$5,$9);}//функция это тоже предложение языка
/*предложения выражения*/

Virag_predlog:
            Ar_virag RAVN Ar_virag {$$= new  predlog(viragen,$1,$3);}
            ;
			 //предложения объявления переменных. тут мы должны помещать нашу новую переменную в таблицу символов
 Obav_predlog:   Peremen RAVN Ar_virag  {$$=new predlog(obyav,$1,$3,chislo);}           //объявление числа
               | Peremen RAVN Ar_forv2     {$$=new predlog(obyav,$1,$3,vetor);}  	//объявление арифм вектора
               | Peremen RAVN Ar_virag_form2 {$$=new predlog(obyav,$1,$3,matriz);}        //объявление арифм матрицы
               ;  




//ВЫРАЖЕНИЯ
Ar_virag: NUMBER{ $$ = new expression(constant,int_,chislo,$1);} 
         |FALSE{ $$ = new expression(constant,bool_,chislo,0);} 
		 |TRUE{ $$ = new expression(constant,bool_,chislo,1);} 
         |NAME{ $$ = new expression($1,peremen);} //переменная
         |Ar_virag PLUS Ar_virag{ $$ = new expression($1,$3,plus,operat,2);}      //сложение
		 | Ar_virag PLUS error   {line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		 | Ar_virag MINUS error   {line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		  | error PLUS Ar_virag   { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		 | error MINUS Ar_virag   {line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
         |Ar_virag MINUS Ar_virag{ $$ = new expression($1,$3,minus,operat,2);}      //вычитание
         |Ar_virag IN2 Ar_virag ZAPAT Ar_virag OUT2 { $$ = new expression($1,$3,$5,koordin,operat,3);}     //получение числа по координатам матрицы
		 | Ar_virag IN2 Ar_virag ZAPAT error OUT2   { line1 = @5.first_line;  line2 = @5.first_column; line3 = @5.last_line;line4 = @5.last_column; yyerror("net 3 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
     	 | Ar_virag IN2 error ZAPAT Ar_virag OUT2   { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column;yyerror("net 2 operada"); yyerrok;}   /*предложения выражения без ; это ошибка*/
		 |Ar_virag SDVIG_LEV { $$ = new expression($1,sd_l,operat,1);}           //cдвиг в лево
         |Ar_virag SDVIG_PRAV  { $$ = new expression($1,sd_p,operat,1);}       //сдвиг в право
		   |Ar_virag SRAVN_P Ar_virag  { $$ = new expression($1,$3,sravn_p,operat,2);}           //сравнение
		 |Ar_virag SRAVN_L Ar_virag  { $$ = new expression($1,$3,sravn_l,operat,2);} 
		 		 | error SDVIG_LEV  { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}           //cдвиг в лево
         | error SDVIG_PRAV   {line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}      //сдвиг в право
         | error SRAVN_P Ar_virag  { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}         //сравнение
		 | error SRAVN_L Ar_virag   { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}
		  |Ar_virag SRAVN_P error  {line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 operada"); yyerrok;}         //сравнение
		 | Ar_virag SRAVN_L error   { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column;yyerror("net 2 operada"); yyerrok;}


         |SUMM IN2 Ar_virag OUT2  { $$ = new expression($3,sum,operat,1);}       //поэлиментное сложение
		 |SUMM IN2 Ar_virag error   {  line1 = @4.first_line;  line2 = @4.first_column; line3 = @4.last_line;line4 = @4.last_column; yyerror("net 2 ckobki"); yyerrok;}       //поэлиментное сложение
		  |SUMM IN2 error OUT2   { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 1 operada"); yyerrok;}      //поэлиментное сложение

		 |Ar_virag YMN_E Ar_virag{ $$ = new expression($1,$3,ymn,operat,2);}      //поэлиментное умножение
		  |error YMN_E Ar_virag {line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}       //поэлиментное умножение
		 |Ar_virag YMN_E error { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 operada"); yyerrok;}      //поэлиментное умножение
		 |Ar_virag IN2 Ar_virag ZAPAT DVOET OUT2 {$$=new expression($1,$3,vector_stolb,operat,2);}     //получение вектора столбца
		 |Ar_virag IN3 Ar_virag  OUT3 {$$=new expression($1,$3,matr_matr,operat,2);}     //получение матрицы по лог матрице
		 |Ar_virag IN2 Ar_virag  error { line1 = @4.first_line;  line2 = @4.first_column; line3 = @4.last_line;line4 = @4.last_column; yyerror("net 2 operada"); yyerrok;}      //получение матрицы по лог матрице
        |Ar_virag IN2 DVOET ZAPAT Ar_virag OUT2 {$$=new expression($1,$5,vector_strok,operat,2);}      //получение вектора строки

		  |error YMN_M Ar_virag{ line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}     //матричное умножение
		   |Ar_virag YMN_M error{ line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 operada"); yyerrok;}     //матричное умножение
		 |error TRAN { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}     //транспонирование
		 |NOT error { line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net 1 operada"); yyerrok;}      //циферка с отрицанием
        |error AND Ar_virag { line1 = @1.first_line;  line2 = @1.first_column; line3 = @1.last_line;line4 = @1.last_column; yyerror("net 1 operada"); yyerrok;}  //логическое умножение
		 |Ar_virag AND error{  line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 1 operada"); yyerrok;}//логическое умножение
		 |Ar_virag YMN_M Ar_virag{ $$ = new expression($1,$3,ymm,operat,2);}    //матричное умножение
		 |Ar_virag TRAN { $$ = new expression($1,tran,operat,1);}     //транспонирование
		 |NOT Ar_virag { $$ = new expression($2,not_,operat,1);}     //циферка с отрицанием
       |Ar_virag AND Ar_virag { $$ = new expression($1,$3,and_,operat,2);} //логическое умножение
		 ;
  		 /*параметры функции могут быть пустыми или являться набором отдельных параметров, разделнных запятой-----но по сути явлются списком предложений выражений*/
Parametr_s:{$$=new spis_predlog;}
	| Obav_predlog {$$->add($1);}

	| Parametr_s ZAPAT Obav_predlog {$$->add($3);}
	;
Parametr_s2:IN2	Parametr_s OUT2{$$=$2;}
	Peremen_s: Peremen {$$=new vec;$$->add($1);}
         |Peremen_s ZAPAT Peremen {$$->add($3);}
		  ;

	Peremen_s2:	  IN2	Peremen_s OUT2{$$=$2;}
				   //переменная состоит из типа(int/bool/cint/cbool/vint/vbool/mbool) и имени
Peremen: INT NAME{$$=new expression(0,int_,$2,peremen,chislo);}
         |T_BOOL NAME{$$=new expression(0,bool_,$2,peremen,chislo);}
         |CONSTANT INT NAME{$$=new expression(1,int_,$3,peremen,chislo);}
         |CONSTANT T_BOOL NAME{$$=new expression(1,bool_,$3,peremen,chislo);}
		 |CONSTANT error NAME{  line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net kluchevogo slova"); yyerrok;} 

         |VECTOR INT NAME{$$=new expression(0,int_v,$3,peremen,vetor);}
         |VECTOR T_BOOL NAME{$$=new expression(0,bool_v,$3,peremen,vetor);}
		 |VECTOR error NAME{ line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net kluchevogo slova"); yyerrok;} 

		 |CONSTANT VECTOR INT NAME{$$=new expression(1,int_v,$4,peremen,vetor);}
         |CONSTANT VECTOR T_BOOL NAME{$$=new expression(1,int_v,$4,peremen,vetor);}
		 |CONSTANT VECTOR error NAME{  line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net kluchevogo slova"); yyerrok;} 
		 |MATRIX INT NAME{$$=new expression(0,int_m,$3,peremen,matriz);}
		 |MATRIX error NAME{ line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net kluchevogo slova"); yyerrok;} 

		 |MATRIX T_BOOL  NAME{$$=new expression(0,bool_m,$3,peremen,matriz);}
		 |CONSTANT INT MATRIX NAME{$$=new expression(1,int_m,$4,peremen,matriz);}
		 |CONSTANT T_BOOL MATRIX NAME{$$=new expression(1,bool_m,$4,peremen,matriz);}
		 |CONSTANT error MATRIX NAME{ line1 = @2.first_line;  line2 = @2.first_column; line3 = @2.last_line;line4 = @2.last_column; yyerror("net kluchevogo slova"); yyerrok;} 
         ;   





//СПИСОК АРИФМЕТИЧЕСКИХ ВЫражений черз запятую для вектора
//и перечисления переменных через запятую для присваивания рзультата функции(тут проверить что ар выражение проста NAME )
//возвращает указатель на класс вектор выражений
Ar_virag_forv:  Ar_virag {$$=new vec;$$->add($1);}

	| Ar_virag_forv ZAPAT  Ar_virag{$$->add($3) ;}
      
	;	
Ar_forv2: IN1 Ar_virag_forv OUT1{$$=$2;}
         |IN1 Ar_virag_forv error  { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 ckobki"); yyerrok;} 

              ; 
//СПИСОК списков АРИФМЕТИЧЕСКИХ Векторовдля матрицы. возвращает указатель на класс матрицы 
Ar_virag_form:  Ar_forv2 {$$=new matr;$$->add($1);}

	| Ar_virag_form ZAPAT Ar_forv2{$$->add($3);}
      
	;	
Ar_virag_form2: IN1 Ar_virag_form OUT1{$$=$2;}
         |IN1 Ar_virag_form error  { line1 = @3.first_line;  line2 = @3.first_column; line3 = @3.last_line;line4 = @3.last_column; yyerror("net 2 ckobki"); yyerrok;} 
              ; 



%%

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