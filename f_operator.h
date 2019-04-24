#pragma once
#include "C:\\cygwin64\\home\\Kukusik\\tree.h"

//���� ��� ���������� ���� ����������

//�� � �� ����������� ���������(and__)
vec* for_bool_v(vec*, vec*, std::map<std::string, expression*> vidim);
matr* for_bool_m(matr*, matr*, std::map<std::string, expression*> vidim);
int for_bool(int, int);
expression* and__(expression* ��, std::map<std::string, expression*> vidim);

//��������� ������ � ��������� ������������ �������(f_koordin__)
expression*m_koord(std::string, int, int, std::map<std::string, expression*> vidim);//����� ���� �������� ����� ����������
expression* koordin_(expression* ee, std::map<std::string, expression*> vidim);
//�� ����� ������� ������ ������ ��� � �������-��������� �� 1 � ��� ������ ��� ������
matr* mat_mat(matr*, matr*);//��������������� ���������

////(f_minus)
vec* minus_v(vec*, vec*, std::map<std::string, expression*>);//��������� ��������
matr* minus_m(matr*, matr*, std::map<std::string, expression*>);//���������  ������
expression* minus_(expression* jj, std::map<std::string, expression*> vidim);
//(f_not_)
vec* ism_b_v(vec* k);
matr* ism_b_m(matr* k);
expression* not__(expression* ��, std::map<std::string, expression*> vidim);
//���� �� ���� ��� �������� ��������� +
//�������� ������� ����������
vec* slog_v(vec*, vec*, std::map<std::string, expression*> vidim);//�������� ��������
matr* slog_m(matr*, matr*, std::map<std::string, expression*> vidim);//�������� ������
expression* plus_(expression* jj, std::map<std::string, expression*> vidim);
//(f_sravn)
expression *sravn_p_(expression* jj, std::map<std::string, expression*> vidim);
expression *sravn_l_(expression* jj, std::map<std::string, expression*> vidim);
//f_sum_
expression* sum_(expression* jj, std::map<std::string, expression*> vidim);
////f_tran
expression* tran_(expression* xx, std::map<std::string, expression*> vidim);
//f_vec_st
vec* i_want_stolb(matr*, int);//������� �������-�������
vec* i_want_strok(matr*, int);//������� ������-�������
matr* i_want_stolb_m(matr*, vec*);//������� ������� � ��������� ������� ��������
matr* i_want_stolb_mb(matr*, vec*);//������� ������� � ��������� ���� ����� ������� ��������
matr* i_want_strok_m(matr*, vec*);//������� ������� � ��������� ������� �����
matr* i_want_strok_mb(matr*, vec*);//������� ������� � ��������� ���� ����� ������� �����
expression* vector_stolb_(expression* jj, std::map<std::string, expression*> vidim);
expression* vector_strok_(expression* jj, std::map<std::string, expression*> vidim);
//f_ymn_
expression* ymn_(expression* jj, std::map<std::string, expression*> vidim);//���������  ��������
matr* ymn_m(matr* v1, matr*v2, std::map<std::string, expression*> vidim);//���������  ������
vec* ymn_v(vec* v1, vec*v2, std::map<std::string, expression*> vidim);
//f_ymn_m
matr* i_want_ymn_m(matr*m1, matr*m2, std::map<std::string, expression*> vidim);
expression* ymn_mm_(expression* jj, std::map<std::string, expression*> vidim);
//sdvigi
matr* matr_sd(matr* mm, int k, perem oo);
expression* sd_l_(expression* jj, std::map<std::string, expression*> vidim);
expression* sd_p_(expression* ��, std::map<std::string, expression*> vidim);//����� � ����� ��� ����� ��� �������
/////
expression* matr_matr__(expression* jj, std::map<std::string, expression*> vidim);