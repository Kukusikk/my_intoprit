#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
//#include "C:\\Users\\Kukusik\\Desktop\\bdz\2_63\f_operator.h"
#include "C:\cygwin64\home\Kukusik\this_main.h"
typedef enum { operat, peremen, constant,nado_dodel }type_exp;//���� ������������� ���������
typedef enum { int_, bool_, int_v, bool_v, int_m, bool_m, err2 }perem;//��� ����������
typedef enum { obyav, viragen, robot, if_, for_, funct, funct_v }type_predlog;
typedef enum { mOOV, nAPRAVLEN_RIT, nAPRAVLEN_LEFT, wALL, eXIT }if_robot;
typedef enum { chislo, vetor, matriz }type_obav;//��� ����������� ��������� � ����� �����
typedef enum { plus, minus, koordin, sd_l, sd_p, sravn_p, sravn_l, sum, ymn, vector_stolb, matr_matr, vector_strok, ymm, tran, not_, and_ }for_operat;//���� ����� ����������
typedef enum { levo, pravo, vverh, vniz }napravl_r;
class predlog;
class expression;
class spis_predlog;
class vec;
class matr;
class Function;
int vecisb(vec*, std::map<std::string, expression*>);//функция проверки вектор реально булевый да-1
int matisb(expression*, std::map<std::string, expression*>);//функция проверки матрица реально булевая да-1
expression* res_vir(expression* ее, std::map<std::string, expression*>);//функция считает результат выражения и записывает резултат в нум/мвектор/матр которое и возвращает по сути и обязательно заполнить ячейку type_obav what где пропишим тип результата
expression* have_with_op(expression* ее, std::map<std::string, expression*>);//функция  вызываемая при встрече с оператором
																			 //функции операторов
expression* ob_res_vir(predlog * pr, std::map<std::string, expression*> vidim);
void go_obav(predlog *, std::map<std::string, expression*>&);
void go_virag(predlog *, std::map<std::string, expression*>&);
void go_robot(predlog *, std::map<std::string, expression*>&);
void go_if(predlog *, std::map<std::string, expression*>&);
void go_for(predlog *, std::map<std::string, expression*>&);
void go_funct(predlog *, std::map<std::string, expression*>&);
void go_fact_v(predlog *, std::map<std::string, expression*>&);
 

	
	//extern std::map<std::string, Function*>tab_f;//таблица функций


	
	


	class vec {
	public:

		std::vector<expression*>arr;
		vec() {};
		int x1;//����� ����� ���������� ������ �������
		void add(expression* p) { arr.push_back(p); x1 = arr.size(); }
	};
	class matr {
	public:
		std::vector<vec*>arr;
		matr() {};
		int x1;//������� �������
		int x2;
		int add(vec* p) {
			arr.push_back(p);
			if ((x1 == 0) | (x1 == p->x1)) {//проверка если длина нашего вектора была равна 0 или она какой была такой и осталась
				x1 = p->x1;
				x2 = arr.size(); return 1;
			}

			return 0;
		}
	};
	class spis_predlog {
	public:
		std::vector<predlog *>spisok;
		//�� ������� ��������� ��� ������ ����������� � ������ ������� �������� ������ �����������
		//�� � ������� ������ �� ������� ������� ���������
		std::map<std::string, expression*>vidim;
		spis_predlog *add(predlog* c) { spisok.push_back(c); return this; }
		//void add2(predlog* l) { spisok.push_back(l); }
	};



	class Function {
	public:
		std::string name;
		vec* for_return;//������ ������������ ��������
		spis_predlog *param;//��������� ������� � �� ��������� �� ���������
		spis_predlog *pred;//����������� ������
		Function(vec* m, std::string o, spis_predlog* p1, spis_predlog*p2) :for_return(m), name(o), pred(p2) {
			param = new spis_predlog;
			param->spisok = p1->spisok;
			param->vidim.clear();
			std::cout << "KG";
		}
		Function(vec* m, char*o, spis_predlog* p1, spis_predlog*p2) :for_return(m), name(o), pred(p2) { 
			param = new spis_predlog;
			param->spisok = p1->spisok;
			param->vidim.clear();
			std::cout << "KG";
		}
	
		Function() {}

	};





	class expression {//��������� �� ������� ��� ����������� �� ��� ����� ��������� ��������� ��� �� ������� ������������ � �� ������� ������������ ������
	public:
		int kolvo;//���������� ���������
		for_operat op;//���� ����� �������� ���������
		std::string name;//���� ��������� ��� ���������� 
		int const_;//��� �������������� ��� ���
		int chis;//����� ������� �������� ������ ����� ���� �� ��� ������ ��� ������ ����� ��������
		type_exp type;//��� ���������
		perem per;//���� �������� ��� ����������
		vec * vec_;//��� ��������� ������� �� ������� ��������
		matr* matr_;//��� ��������� ������� ��� ������� ��������
		type_obav what; //��� ��� ������� ������ ��� �����
		expression *op1;//��������� �� �����
		expression *op2;//��������� �� ������
		expression *op3;//��������� �� ������
		//������������
		//����� 2 ��������
		expression() {}
		expression(type_exp type22):type(type22) {}
		expression(int l) :chis(l) {}//нужен будет для оператора сравнения
		expression(expression*p, expression* p2, for_operat i, type_exp b, int k) :op1(p), op2(p2), type(b), kolvo(k), op(i) {}
		//для того что получается когда 2 операнда и на выходе число
		expression(type_exp x1, perem x2, type_obav x3, int x4) :chis(x4), what(x3), type(x1), per(x2) {}
		//для того что получается когда 2 операнда и на выходе вектор
		expression(type_exp x1, perem x2, type_obav x3, vec * x4) :vec_(x4), what(x3), type(x1), per(x2) {}
		//для того что получается когда 2 операнда и на выходе матрица
		expression(type_exp x1, perem x2, type_obav x3, matr* x4) :matr_(x4), what(x3), type(x1), per(x2) {}
		//����� 1 �������
		expression(expression*p, for_operat i, type_exp b, int k) :op1(p), type(b), kolvo(k), op(i) {}
		//����� 3 ��������
		expression(expression*p, expression* p2, expression* p3, for_operat i, type_exp b, int k) :op1(p), op2(p2), op3(p3), type(b), kolvo(k), op(i) {}
		expression(char* n, type_exp l) :name(n), type(l) {}//������ ����������
		expression(int v, type_exp f, type_obav b) :type(f), what(b), chis(v) {}//��� ������ �������
		expression(int c, perem l, char*p, type_exp b, type_obav j) :const_(c), per(l), name(p), type(b), what(j) {
			std::cout << "p=" << p;
		}//���������� ����������
	};

	//����� ����������� 
	//�������� ����������
	//����������� ���� 
	//������������ ����� �������
	//����� ����������� ���������� ���������
	//����������� �����
	class predlog {
	public:
		Function * f;//� ������ ��������� ���� �������
		spis_predlog * spisss;
		type_predlog type;
		vec *vec_;
		vec *vec2_;//специально для вызова функции
		matr *matr_;
		std::string per;//��� ����������� ��������� 
		expression *vir1;//
		expression *vir2;
		expression *vir3;
		type_obav if_ob;
		if_robot x;
		//��� ����������� ��������� 
		predlog(type_predlog v, expression *pp, expression *pp2) :vir1(pp), type(v), vir2(pp2) {}
		//����������� ����� �������
		predlog(type_predlog v, vec* l, char* ll, vec* l2) :vec2_(l2), type(v), per(ll), vec_(l) {}
		predlog(type_predlog v, vec* l, std::string ll, vec* l2) :vec2_(l2), type(v), per(ll), vec_(l) {}
		predlog(type_predlog v, expression* l, std::string ll, vec* l2) :vec2_(l2), type(v), per(ll) { vec_ = new vec; vec_->add(l); }
		//��� ����������� ���������� ����������
		//��� �����, ����� ������� ����� �������
		predlog(type_predlog v, expression *pp, expression* y, type_obav m) : type(v), vir1(pp), vir2(y), if_ob(m) {}
		predlog(type_predlog v, expression *pp, vec* y, type_obav m) : type(v), vir1(pp), vec_(y), if_ob(m) { vir2 = new expression(nado_dodel); }
		predlog(type_predlog v, expression *pp, matr* y, type_obav m) : type(v), vir1(pp), matr_(y), if_ob(m) { vir2 = new expression(nado_dodel); }
		//��� ����������� ������
		predlog(type_predlog v, if_robot pp, expression *pp1 = nullptr, expression *pp2 = nullptr) :x(pp), vir1(pp2),vir2(pp1), type(v) {}
		//���  �������� �����������
		predlog(type_predlog v, expression *pp2, spis_predlog *o) :spisss(o), vir1(pp2), type(v) {}
		//��� ����������� ������
		predlog(type_predlog v, expression *pp1, expression *pp2, expression *pp3, spis_predlog *o) :spisss(o), vir1(pp1), vir2(pp2), vir3(pp3), type(v) {
			std::cout << "ji";
		}
		//объявление функции
		predlog(type_predlog v, vec* l, char*  g, spis_predlog *o, spis_predlog *o2) :type(v) { f = new Function(l, g, o, o2); }
		predlog(type_predlog v, vec* l, std::string  g, spis_predlog *o, spis_predlog *o2) :type(v) { f = new Function(l, g, o, o2); }
		void add_funk(); 
	};
	
	
	//все для робота
	
	class Robot {
	public:
		int x;
		int y;
		int x_v;//координаты выхода инициализируются ели exit возвращает 1
		int y_v;
		int f_v;//влаг того что мы знаем выход
		napravl_r nap;
		matr world;//0-проход 1-препятствие
		Robot():x(0),y(0),x_v(0),y_v(0),f_v(0),nap(vverh){}
		int  move_(int);//int будет показывать направление
						//перемесить вверх-1 вниз-2 вправо-3 влево-4
						//все хорошо-врнем 1 иначе-0
		void right_();//поворот вправо
		void left_();//поворот влево
		int wall();//измерение расстояния до прептствия
		int exit();//если есть выходв текущем направлнии-1 иначе-0
		void read_would();//считывание карты. требуется в начале игры
	};
	
	void ispolnenie(spis_predlog *p, std::map<std::string, expression*>& vv);
	void go_pr22(spis_predlog *p);


	void ispolnenie(spis_predlog *p, std::map<std::string, expression*>& vv);
	void go_play_game();//на случай если мы решили поиграть