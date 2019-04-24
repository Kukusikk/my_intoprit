#pragma once
#include<map>
#include <iostream>     
#include <fstream>
#include "C:\\Users\\Kukusik\\Desktop\\bdz\2_63\f_operator.h"
#include "C:\\cygwin64\\home\\Kukusik\\tree.h"
std::map<std::string, Function*>tab_f;//таблица функций
int our_err;//флаг того что ошибки есть
int game;//флаг того что игра началась
int game_win;

Robot rob;//нашобъект робот
void go_pr22(spis_predlog *p) {//начиная отсюда у нас закончилось построение дерева и дальше нужно делвть обход
	std::cout << "my program!:";
	ispolnenie(p, p->vidim);//функция обхода дерева
}
void predlog::add_funk() {//добавление новой функции в талицу фунцмй

	tab_f[f->name] = f;
}

void go_obav(predlog * pr, std::map<std::string, expression*>& vidim) {//функция разбра предложения объявления
	auto it = vidim.find(pr->vir1->name);
	//тут мы идем такие и заносим их в таблицу символов
	//также нужно проверить что переменной с таким именем еще нет
	//также что тип объявления у переменной и то что мы ей присваиваем совпадает
	//а присваивать ей мы можем значение другой переменной
	//или непоредственно инициализируем конкретно как норм люди
	//заносим сюда имя нашей переменной
	if (it == vidim.end())//если такой переменной еще не было то нам нужны ледующие проверки
	{//проверки нам нужно делать только сли присваиваем одной переменной другую
	 //так как если мы инициализируем непосредственно то значит тут ошибки нет т к изон этого не позволит
		if (pr->vir2->type == peremen) {

			//то проверяем есть ли такая переменная чье значение мы присваиваем вообще в таблице символов
			auto rr = vidim.find(pr->vir2->name);
			if (rr == vidim.end()) {
				our_err++;
				std::cout << "sorry,but not know peremennia";
			}
			else {

				//проверяем тип этой переменной
				if ((pr->vir1->const_ == it->second->const_) && (pr->vir1->per == it->second->per))
					vidim[pr->vir1->name] = it->second;
				else { std::cout << "ne sootvetctvie tipov"; our_err++; }
			}
		}
		else {
			//иначе просто пихаем в таблицу символов
			//если оно объявленно как константа
			//сперва создадим точное выражение число/вектор/матрица которое будет посчитано в целых числах
			auto l = ob_res_vir(pr, vidim);
			vidim[pr->vir1->name] = l;
		}
	}
	else { std::cout << "povtornoe obiavlenie"; our_err++; }
}


void go_robot(predlog *pr, std::map<std::string, expression*>& vidim) {
	//и тут мы тоже что то будем делать когда сделаем робота 
	if (!game) {//если мы не играем то мы не можем пользоваться этими функциями
		std::cout << "we can not this becous we dont play game";
		our_err++;
		return;
	}
	if (game_win) {//если мы выйграли и так
		std::cout << "we already have win!!!!!!!!";
			return;
			}
	if (pr->x == mOOV) {
		//единственная функция с аргументом
		//надо ее посчитать и убедиться что это число
		auto arg = res_vir(pr->vir1, vidim);
		if (arg->per != int_) {
			std::cout << "ne verniy argument";
			our_err++;
			return; 
		}
		//проверяем что в vir2 переменная
		if (pr->vir2->type != peremen) {
			std::cout << "ne vernoe prisvaivanie";
			our_err++;
			return;
		}
		//возвращаем на нее указатель
		auto ll = res_vir(pr->vir2,vidim);
		//провеляем его тип
		if(ll->per!=bool_)
		{
			std::cout << "ne sootvetsvie tipov";
			our_err++;
			return;
		}
		//меняем значение числа там
		vidim[pr->vir2->name]->chis= rob.move_(arg->chis);
		//ll->chis = rob.move_(arg->chis);
		 return ;
	}
	if (pr->x == nAPRAVLEN_RIT) {
		rob.right_(); return;
	}
	if (pr->x == nAPRAVLEN_LEFT) {
		rob.left_(); return;
	}
	if (pr->x == wALL) {
		//проверяем что в vir2 переменная
		if (pr->vir2->type != peremen) {
			std::cout << "ne vernoe prisvaivanie";
			our_err++;
			return;
		}
		//возвращаем на нее указатель
		auto ll = res_vir(pr->vir2, vidim);
		//провеляем его тип
		if (ll->per != int_)
		{
			std::cout << "ne sootvetsvie tipov";
			our_err++;
			return;
		}
		//меняем значение числа там
		ll->chis = rob.wall();
		return;
	}
	if (pr->x == eXIT) {
		//проверяем что в vir2 переменная
		if (pr->vir2->type != peremen) {
			std::cout << "ne vernoe prisvaivanie";
			our_err++;
			return;
		}
		//возвращаем на нее указатель
		auto ll = res_vir(pr->vir2, vidim);
		//провеляем его тип
		if (ll->per != bool_)
		{
			std::cout << "ne sootvetsvie tipov";
			our_err++;
			return;
		}
		//меняем значение числа там
		ll->chis = rob.exit();
		return;

	}
}
void go_virag(predlog * pr, std::map<std::string, expression*>& vidim) {
	//предложение выражение
	//первое что мы долны проверить это то что первый операнд у нас является переменной
	if (pr->vir1->type == peremen) {
		//и эта переменная у нас есть в таблице символов
		auto it = vidim.find(pr->vir1->name);
		if (it != vidim.end()) {
			//если это известная переменная
			//то нужно проверить что она не константа
			if (it->second->const_ == 0)
				//то мы долны просто присвоить ее содержимое новой посчинной томы что получилось
				vidim[pr->vir1->name] = res_vir(pr->vir2, vidim);
			else { std::cout << "we can not const znachenie"; our_err++; }
		}
		else { std::cout << "dont know peremen"; our_err++; }
	}

	else { std::cout << "this is not peremen"; our_err++; }
}

void go_if(predlog * pr, std::map<std::string, expression*>& vidim) {//обработка условного предложения
																	//область видимости того списка предложений который сюда передали
	auto l = res_vir(pr->vir1, vidim);
	//результатом вычесления должно быть число 
	if (l->type != constant) {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return;
	}
	if (l->chis != 0) {
		//если у нас оно не 0
		ispolnenie(pr->spisss, vidim);//функция обхода дерева
	}
	else return;
}
void go_for(predlog * pr, std::map<std::string, expression*>& vidim) {
	//проверим что переменная объявленна как скаляр
	if (!pr->vir1->per == int_) {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return;
	}
	//занесем эту новую переменную в область видимости

	auto p = res_vir(pr->vir2, vidim);
	if (!p->what == chislo) {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return;
	}

//	vidim[pr->vir1->name] = p;

	int dd = p->chis;//гачальное значение переменной цикла
	auto p2 = res_vir(pr->vir3, vidim);
	if (!p2->what == chislo) {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return;
	}
	int dd2 = p2->chis;//конечное значение переменной цикла
	for (; dd<dd2; dd++)
		ispolnenie(pr->spisss, vidim);//функция обхода дерева

}
void go_funct(predlog * pr, std::map<std::string, expression*>& vidim) {//тут предложение-функция
																	   //когда нам такое встречется то мы должны его занести в таблицу функций а вот уже все действия расписывать при 
																	   //встречи с вызовом функции
																	   //внутри функции не может быть функции
	for (int i = 0; i < pr->f->pred->spisok.size(); i++) {
		if (pr->f->pred->spisok[i]->type == funct) {
			std::cout << "v funktii ne can be funktion";
			our_err++;
			return;
		}
	}
	//посчитать чему равны параметры по умолчанию  и записать их конечный результат в таблицу видимости
	for (int i = 0; i < pr->f->param->spisok.size(); i++)
		go_obav(pr->f->param->spisok[i], pr->f->param->vidim);
	//дальше просто добавляем эту функцию в таблицу ф
	pr->add_funk();
}


void go_fact_v(predlog *pr, std::map<std::string, expression*>&vidim) {
	//предложения вызов функции
	//проверяем что имя такой функции вообще существует
	auto l = tab_f.find(pr->per);
	if (l == tab_f.end()) {
		std::cout << "function ne sushestvuet";
		our_err++;
		return;
	}
	//проверяем что количество присваивымаех и возвращаемых элиментов совпадает
	if (pr->vec_->x1 != l->second->for_return->x1) {
		std::cout << "ne sushestvuet kolich return_eliment";
		our_err++;
		return;
	}
	//проверим что параметров в вызове функции столько же или равно количеству параметров в самой функции
	if (pr->vec2_->x1 > l->second->for_return->x1) {
		std::cout << "ne sushestvuet kolich parametrov";
		our_err++;
		return;
	}
	//проверить что присваиваемые и возвращаемые значениия одного типа
	//и что присваиваемые вообще есть в таблице
	//те значения что мы присваиваем должны быть переменные
	for (int i = 0; i < pr->vec2_->x1; i++) {
		if (pr->vec2_->arr[i]->type != peremen)
		{
			std::cout << "this is ne peremennaia";
			our_err++;
			return;
		}
		auto prisvaiv = res_vir(pr->vec2_->arr[i], vidim);//////значение перематра нашей функции его надо щас присвоить
		if (prisvaiv->per != l->second->for_return->arr[i]->per)
		{
			std::cout << "ne sootvetstv tipov";
			our_err++;
			return;
		} //l->second->for_return->arr[i]
	}
	//проаерить что параметры в вызове и определыннные в функции одного типа
	//присваиваем их
	auto nn = l->second->param->vidim.begin();
	for (int i = 0; i < pr->vec2_->x1; i++) {
		if (!((pr->vec2_->arr[i]->type == peremen) | (pr->vec_->arr[i]->type != constant)))
		{
			std::cout << "this is ne peremennaia or constanta";
			our_err++;
			return;
		}
		auto param = res_vir(pr->vec2_->arr[i], vidim);//значение параметра
		l->second->param->vidim[l->second->param->spisok[i]->vir1->name] = param;//меняем это значение в таблтце вдимости
		
	}

	
		//совершаем обход списка предложений
		ispolnenie(l->second->pred, l->second->param->vidim);//функция обхода дерева
	
	//приваиваем из талицы видимости значения тех что получилиь
	for (int g = 0; g < pr->vec_->arr.size(); g++) {
		//пока переменные которым присваиваем не кончились
		//берем имя первой переменной для присваивания
		auto pp = l->second->for_return->arr[g]->name;
		//идем по списку видисости функции
		if (l->second->param->vidim.find(pp) == l->second->param->vidim.end()) {
			std::cout << "vidimo v funksii vi ne obavili this peremen";
			our_err++;
			return;
		}
		//ищем в таблице символов тот элиент которому присваиваем
		auto res = vidim.find(pr->vec_->arr[g]->name);
		res->second = l->second->param->vidim.find(pp)->second;
		//очищаем облость видимости для следующего вызова
		l->second->param->vidim.clear();
	}

}int vecisb(vec*p, std::map<std::string, expression*>vidim)//функция проверки вектор реально булевый да-1
{
	for (int i = 0; i<p->arr.size(); i++)
		if ((res_vir(p->arr[i], vidim)->what != chislo)&((res_vir(p->arr[i], vidim)->chis != 1) | (res_vir(p->arr[i], vidim)->chis != 0)))
		{
			our_err++;
			std::cout << "nevernoe prisvaivanie  for bool"; return 0;
		}return 1;

}

int matisb(expression*p, std::map<std::string, expression*>vidim) {//проверяем матрицу на булевость
	for (int i = 0; i < p->matr_->arr.size(); i++)
		if (vecisb(p->matr_->arr[i], vidim) == 0)
			return 0;
	return 1;
}










expression* res_vir(expression* jj, std::map<std::string, expression*> vidim) {

	if (jj->type == constant)//если это и так была константа то тупо ее вернем
		return jj;

	//функция считает результат выражения и записывает резултат в нум/мвектор/матр которое и возвращает по сути и обязательно заполнить ячейку type_obav what где пропишим тип результата
	//функция по сути используется для возврата конкретного значения

	//в выражении у нас только действия тут и нет присваиваний
	//результат всегда может быть только константа
	//в конце мы создадим укаазатель на выражение и засуним в него результат

	//если это переменная то тупо находим ее в таблице символов и возвращаем его значение
	if (jj->type == peremen) {
		//В НАчале проверим есть ли она в таблице символов
		auto it = vidim.find(jj->name);
		if (it != vidim.end()) {
			//если это известная переменная
			//то тупо возвращаем ее значение
			return it->second;
		}
		else { std::cout << "dont know peremen"; our_err++; }
	}
	//если тут у нас оператор то нам надо начало посчитать
	if (jj->type == operat) {//возвращаем что скажет оператор
		return have_with_op(jj, vidim);
	}
}

expression* have_with_op(expression* jj, std::map<std::string, expression*> vidim) {
	//выбо по какому операнду идем
	auto res = new expression;
	switch (jj->op)
	{
		
	case(plus)://для плюов двух ар чисел
		std::cout << "now!";
		return plus_(jj, vidim);
		
		break;
	case(minus)://для минусов двух ар чисел
		std::cout << "now!";
		return minus_(jj, vidim);
		break;
	case(koordin)://для получения координаты любой матрицы
		std::cout << "now!";
		return koordin_(jj, vidim);
		break;
	case(sd_l)://для сдвига влеов чисел  ар и матриц любых
		std::cout << "now!";
		return sd_l_(jj, vidim);
		break;
	case(sd_p)://для сдвига вправо чисел  ар и матриц любых
		std::cout << "now!";
		return sd_p_(jj, vidim);
		break;
	case(sravn_p)://для правого сравнения чисел лог и ар
		std::cout << "now!";
		return sravn_p_(jj, vidim);
		break;
	case(sravn_l)://для левого сравнения чисел лог и ар
		std::cout << "now!";
		return sravn_l_(jj, vidim);
		break;
	case(sum)://для поэлиминтарного сложения для любой матрицы/вектора
		std::cout << "now!";
		return sum_(jj, vidim);
		break;
	case(ymn)://для поэлиминтарного умножения матрицы/вектора/числа
		std::cout << "now!";
		return ymn_(jj, vidim);
		break;
	case(vector_stolb)://для получения вектора столбца для любой матриц или матрицы если 2 оп вектор ар/лог!!!!!!!!!
		std::cout << "now!";
		return vector_stolb_(jj, vidim);
		break;
	case(vector_strok)://для получения вектора строки для любой матрицы или матрицы если 2 оп вектор ар\лог!!!!!!!!
		std::cout << "now!";
		return vector_strok_(jj, vidim);
		break;
	case(ymm)://для матричного умножение
		std::cout << "now!";
		//return ymn_m_(jj, vidim);
		break;
	case(tran)://для транспортирования матрицы
		std::cout << "now!";
		return tran_(jj, vidim);
		break;
	case(matr_matr)://для отрицания матрицы/вектора/числа
		std::cout << "now!";
		return matr_matr__(jj, vidim);
		break;
	case(not_)://для отрицания матрицы/вектора/числа
		std::cout << "now!";
		return not__(jj, vidim);
		break;
	case(and_)://для логич умножения матрицы/вектора/числа
		std::cout << "now!";
		return and__(jj, vidim);
		break;

	}return res;
}




expression* ob_res_vir(predlog * pr, std::map<std::string, expression*> vidim) {
	//тут мы получаем готовое выражение при объявлении
	//которое потом будет занесено в другой функции в таблицу символов
	//тут в основном будет считаться выражение числа/вктора/матрицы до конц
	//делаться его проверка на соответствие его типа инт/бул 
	//и если все норм то возвращаться оно
	if (pr->if_ob == chislo)
	{
		auto l = res_vir(pr->vir2, vidim);
		
			l->what = chislo;
			l->const_ = pr->vir1->const_;
			return l;

		
		
	}
	if (pr->if_ob == vetor) {
		auto bbb = new vec;

		//в цикле должны посчитать к чему приводит каждое число
		for (int i = 0; i < pr->vec_->x1; i++) {
			auto l = res_vir(pr->vec_->arr[i], vidim);

			if (l->what == chislo) {

				if (((pr->vir1->per == bool_v)&((l->chis == 0) | (l->chis == 1))) | (pr->vir1->per == int_v))
				{
					bbb->add(l);

				}
				else {
					std::cout << "ne sootvetstvie tipov";
					our_err++;
					return pr->vir2;;
				}
			}
			
		} return new expression(constant, pr->vir1->per, vetor, bbb);
	}
	auto bbb2 = new matr;
	if (pr->if_ob == matriz) {
		
		//в цикле должны посчитать к чему приводит каждое число
		for (int i = 0; i < pr->matr_->x2; i++)
		{
			auto v = new vec;
			for (int j = 0; j < pr->matr_->x1; j++) {
				auto l = res_vir(pr->matr_->arr[i]->arr[j], vidim);
				if (l->what == chislo) {
					if (((pr->vir1->per == bool_m)&((l->chis == 0) | (l->chis == 1))) | (pr->vir1->per == int_m))
					{
						v->add(l);

					}
					else {
						std::cout << "ne sootvetstvie tipov";
						our_err++;
						return pr->vir2;
					}
				}
			}
			bbb2->add(v);
		}
	}return new expression(constant, pr->vir1->per, matriz, bbb2);
}

void ispolnenie(spis_predlog *p, std::map<std::string, expression*>& vv) {//функция обхода дерева
																		 //будем также отдельно передовать список видимости потому что 


																		 //при обходе списка предложений входящих к примеру в услоное там у нас свой список видимости
	for (int i = 0; i < p->spisok.size(); i++) {//тут мы таки идем по нашему списку предложений ведь это и есть наша программа 
		std::cout << "x=" << rob.x << " y="  << rob.y;
												//в зависимоти от того каким типом является наше предложение
												//таковы и будут наши последующие действия
		if ((our_err == 0)&(game_win==0)) {
			auto it = p->spisok[i];
			predlog* j = it;
			switch (p->spisok[i]->type)
			{
			case(obyav)://предложение объявление переменной
				go_obav(p->spisok[i], vv);
				break;
			case(viragen)://предложение выражение
				go_virag(p->spisok[i], vv);
				break;
			case(robot)://предложение робот
				go_robot(p->spisok[i], vv);
				break;
			case(if_)://предложение условие
				go_if(p->spisok[i], vv);
				break;
			case(for_)://предложение циклы
				go_for(p->spisok[i], vv);
				break;
			case(funct)://предложение функции
				go_funct(p->spisok[i], vv);
				break;
			case(funct_v)://предложение вызов функции
				go_fact_v(p->spisok[i], vv);
				break;
			}
		}
		else {
			if (game_win) {
				std::cout << "we win alredy!!!!!!!!!!!!!!!!!!! so we go home";
			}else
			std::cout << "we have error"; return;
		}
	}
}

int Robot::move_(int where_) {//int будет показывать направление
				//перемесить вверх-1 вниз-2 вправо-3 влево-4
				//все хорошо-врнем 1 иначе-0
	if (nap == levo) {
		switch (where_)
		{
		case(1)://выбор в какую сторону идти
			if (y+1==world.x2)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y+1]->arr[x ]->chis == 1)
				return 0;
			else{
				y++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			//проверка чтобы не встретить прептствие
				//все норм. исполняем и возвращаем 1
			break;
		case(2):
			if (y ==0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y-1]->arr[x ]->chis == 1)
				return 0;
			else {
				y--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			
			}
			break;
		case(3):
			if (x ==0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x-1]->chis == 1)
				return 0;
			else {
				x--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(4):
			if (x+1 == world.x1)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x+1]->chis == 1)
				return 0;
			else {
				x++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
			}
	}
	if (nap == pravo)
	{
		switch (where_)
		{
		case(1)://выбор в какую сторону идти
			if (y == 0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y-1]->arr[x]->chis == 1)
				return 0;
			else {
				y--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			//проверка чтобы не встретить прептствие
			//все норм. исполняем и возвращаем 1
			break;
		case(2):
			if (y+1 ==world.x2)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y+1]->arr[x]->chis == 1)
				return 0;
			else {
				y++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(3):
			if (x+1  == world.x1)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x+1 ]->chis == 1)
				return 0;
			else {
				x++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(4):
			if (x==0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x-1 ]->chis == 1)
				return 0;
			else {
				x--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		}
	}
	if (nap == vverh)
	{
		switch (where_)
		{
		case(1)://выбор в какую сторону идти
			if (x ==0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x-1 ]->chis == 1)
				return 0;
			else {
				x--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			//проверка чтобы не встретить прептствие
			//все норм. исполняем и возвращаем 1
			break;
		case(2):
			if (x+1==world.x1)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x+1 ]->chis == 1)
				return 0;
			else {
				x++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(3):
			if (y==0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y-1]->arr[x]->chis == 1)
				return 0;
			else {
				y--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(4):
			if (y+1==world.x2)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y+1]->arr[x]->chis == 1)
				return 0;
			else {
				y++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		}
	}
	if (nap == vniz)
	{
		switch (where_)
		{
		case(1)://выбор в какую сторону идти
			if (x+1  ==world.x1)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x+1 ]->chis == 1)
				return 0;
			else {
				x++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			//проверка чтобы не встретить прептствие
			//все норм. исполняем и возвращаем 1
			break;
		case(2):
			if (x == 0)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y]->arr[x-1]->chis == 1)
				return 0;
			else {
				x--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(3):
			if (y+1==world.x2)//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y+1]->arr[x]->chis == 1)
				return 0;
			else {
				y++;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
			}
			break;
		case(4):
			if (y==0 )//проверка чтобы не выйти за пределы карты
				return 0;
			if (world.arr[y-1]->arr[x ]->chis == 1)
				return 0;
			else {
				y--;
				if ((x == x_v)&(y == y_v)&(f_v == 1)) {
					std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
					game_win++;
				}
					return 1;
				
				
			}
			break;
		}
	}
}


void Robot::right_()//поворот вправо
{
	if (nap == levo) {
		nap = vverh; return;
	}
	if (nap == pravo)
	{
		nap = vniz; return;
	}
	if (nap == vverh)
	{
		nap = pravo; return;
	}
	if (nap == vniz)
	{
		nap = levo; return;
	}
}
void Robot::left_() {//поворот влево

	if (nap == levo) {
		nap = vniz; return;
	}
	if (nap == pravo)
	{
		nap = vverh; return;
	}
	if (nap == vverh)
	{
		nap = levo; return;
	}
	if (nap == vniz)
	{
		nap = pravo; return;
	}
}
int Robot::wall() {//измерение расстояния до прептствия,в случае отсутстви препятстви возвращает расстояние до конца карты
	int res = 0;
	int koord;
	if (nap == levo) {
		koord = x;
		while (koord > 0)//пока нет припятствия и не кончилась карта
		{
			if (world.arr[y]->arr[koord]->chis != 1)
			{
				res++; koord--;
			}
			else return res;
		}
	}
	if (nap == pravo) {
		koord = x;
		while (koord < world.x1-1)//пока нет припятствия и не кончилась карта
		{
			if (world.arr[y]->arr[koord]->chis != 1)
			{
				res++; koord++;
			}
			else return res;
		}
	}
	if (nap == vverh) {
		koord = y;
		while (koord > 0)//пока нет припятствия и не кончилась карта
		{
			if (world.arr[koord]->arr[x]->chis != 1)
			{
				res++; koord--;
			}
			else return res;
		}
	}
	if (nap == vniz) {
		koord = y;
		while (koord < world.x2-1)//пока нет припятствия и не кончилась карта
		{
			if (world.arr[koord]->arr[x]->chis != 1) {
				res++; koord++;
			}
			else return res;
		}
	}return res;


}
int Robot::exit() {//если есть выходв текущем направлнии-1 иначе-0
	if(world.arr[y]->arr[x]->chis==2){
		std::cout << "WIN!!!!!!!!!!!!!!!!!!!!!" << std::endl;
		game_win++;
		return 1;
	}
	if (nap == levo) {
		if (wall() == x) {//возможно там есть выход
			if (world.arr[y]->arr[x - wall()]->chis == 2) {

				x_v = x - wall();
				y_v = y;
				f_v = 1;
				return 1;
			}else return 0;
		}
			
		
	}
	if (nap == pravo) {
		if (wall() == world.x1 - 1 - x)
		{
			if (world.arr[y]->arr[x + wall()]->chis == 2) {
				x_v = x + wall();
				y_v = y;
				f_v = 1;
				return 1;
			}
			else return 0;

		}
	}
	if (nap == vverh) {
		if (wall() == y)
		{
			if (world.arr[y-wall()]->arr[x]->chis == 2) {
				x_v = x;
				y_v = y + wall();
				f_v = 1;
				return 1;
			}
			else return 0;
		}
	}
	if (nap == vniz) {
		if (wall() == world.x2 - 1 - y)
		{
			if (world.arr[y + wall()]->arr[x]->chis == 2) {
				x_v = x;
				y_v = y - wall();;
				f_v = 1;
				return 1;
			}
			else return 0;
		}
	}
	return 0;

}
void Robot::read_would() {//считывание карты. требуется в начале игры
	std::ifstream f("C:\\Users\\Kukusik\\Desktop\\bdz\\2_63\\my_game.txt", std::ifstream::in);//создаем объект потока istream  по имени file
	std::string str;
	expression* help;
	char* one = "1";
	char* two = "2";
	while (!f.eof()) {//пока не конец файла
		while (getline(f, str)) {//считывам одну строку
			auto vv = new vec;
			for (int i = 0; i < str.size(); i++, str) {
				if (str[i] == *one)
					help = new expression(constant, int_, chislo, 1);
				else {
					if (str[i] == *two) help = new expression(constant, int_, chislo, 2);
					else help = new expression(constant, int_, chislo, 0);
				}
				vv->add(help);
			}world.add(vv);
		}
	} f.close();
}

void go_play_game() {//на случай если мы решили поиграть
	game = 1;
	rob.read_would();
}