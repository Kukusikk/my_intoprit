#pragma once
#include "C:\\cygwin64\\home\\Kukusik\\tree.h"

//файл дл€ объ€влени€ всех операторов

//вс е дл логического умножени€(and__)
vec* for_bool_v(vec*, vec*, std::map<std::string, expression*> vidim);
matr* for_bool_m(matr*, matr*, std::map<std::string, expression*> vidim);
int for_bool(int, int);
expression* and__(expression* ее, std::map<std::string, expression*> vidim);

//получение €чейки с заданными координатами матрицы(f_koordin__)
expression*m_koord(std::string, int, int, std::map<std::string, expression*> vidim);//после всех проверок ловим координаты
expression* koordin_(expression* ee, std::map<std::string, expression*> vidim);
//из одной матрицы делаем другую где в матрице-переметре на 1 а где нолики там ничего
matr* mat_mat(matr*, matr*);//непосредственно получение

////(f_minus)
vec* minus_v(vec*, vec*, std::map<std::string, expression*>);//вычитание векторов
matr* minus_m(matr*, matr*, std::map<std::string, expression*>);//вычитание  матриц
expression* minus_(expression* jj, std::map<std::string, expression*> vidim);
//(f_not_)
vec* ism_b_v(vec* k);
matr* ism_b_m(matr* k);
expression* not__(expression* ее, std::map<std::string, expression*> vidim);
//файл со всем что касаетс€ оператора +
//начались функции операторов
vec* slog_v(vec*, vec*, std::map<std::string, expression*> vidim);//сложение векторов
matr* slog_m(matr*, matr*, std::map<std::string, expression*> vidim);//сложение матриц
expression* plus_(expression* jj, std::map<std::string, expression*> vidim);
//(f_sravn)
expression *sravn_p_(expression* jj, std::map<std::string, expression*> vidim);
expression *sravn_l_(expression* jj, std::map<std::string, expression*> vidim);
//f_sum_
expression* sum_(expression* jj, std::map<std::string, expression*> vidim);
////f_tran
expression* tran_(expression* xx, std::map<std::string, expression*> vidim);
//f_vec_st
vec* i_want_stolb(matr*, int);//возврат столбца-вектора
vec* i_want_strok(matr*, int);//возврат строки-вектора
matr* i_want_stolb_m(matr*, vec*);//возврат матрицы с заданными нмерами столбцов
matr* i_want_stolb_mb(matr*, vec*);//возврат матрицы с истинными знач столб нмерами столбцов
matr* i_want_strok_m(matr*, vec*);//возврат матрицы с заданными нмерами строк
matr* i_want_strok_mb(matr*, vec*);//возврат матрицы с истинными знач столб нмерами строк
expression* vector_stolb_(expression* jj, std::map<std::string, expression*> vidim);
expression* vector_strok_(expression* jj, std::map<std::string, expression*> vidim);
//f_ymn_
expression* ymn_(expression* jj, std::map<std::string, expression*> vidim);//умножение  векторов
matr* ymn_m(matr* v1, matr*v2, std::map<std::string, expression*> vidim);//умножение  матриц
vec* ymn_v(vec* v1, vec*v2, std::map<std::string, expression*> vidim);
//f_ymn_m
matr* i_want_ymn_m(matr*m1, matr*m2, std::map<std::string, expression*> vidim);
expression* ymn_mm_(expression* jj, std::map<std::string, expression*> vidim);
//sdvigi
matr* matr_sd(matr* mm, int k, perem oo);
expression* sd_l_(expression* jj, std::map<std::string, expression*> vidim);
expression* sd_p_(expression* ее, std::map<std::string, expression*> vidim);//сдвиг в право дл€ числа или матрицы
/////
expression* matr_matr__(expression* jj, std::map<std::string, expression*> vidim);