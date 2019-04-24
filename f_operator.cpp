#include "C:\\Users\\Kukusik\\Desktop\\bdz\2_63\f_operator.h"
extern int our_err;

//���������� �������� �����/�����/�������
//����:1)������ �+����� �����
//2)�����-����+�����
//3)�����+�����
//4)��+��
//5)����+����

expression* and__(expression* jj, std::map<std::string, expression*> vidim) {
	expression* l2, *l1;
	if ((jj->op1->type == constant) | (jj->op1->type == constant)) {
		if ((jj->op1->type == constant) & (jj->op1->type == constant)) {
			if (((jj->op1->chis == 0) | (jj->op1->chis == 1)) & ((jj->op2->chis == 0) | (jj->op2->chis == 1))) {
				auto res = new expression(constant, bool_, chislo, for_bool(jj->op1->chis , jj->op2->chis));
				return res;
			}
			else {
				std::cout << "ne bool tipov";
				our_err++;
				return jj;
			}
		}
		else {
			if (jj->op1->type == constant)
			{
				l2 = res_vir(jj->op2, vidim);  l1 = jj->op1;
			}
			else {
				l1 = res_vir(jj->op2, vidim);  l2 = jj->op1;
			}
			//���� ���� ���
			if (l1->per == l2->per) {
				if (((l1->chis == 0) | (l1->chis == 1)) & ((l2->chis == 0) | (l2->chis == 1))) {
					int k = for_bool(l1->chis, l2->chis);
					auto res = new expression(constant, bool_, chislo, k);
					return res;
				}
				else {
				std::cout << "ne bool tipov";
				our_err++;
				return jj;
			}
		}
			else {
				std::cout << "ne sootvetstvie tipov";
				our_err++;
				return jj;
			}
			}
		}
	
	else {//���� ��� ���� ��������
		auto l1 = res_vir(jj->op1, vidim);
		auto l2 = res_vir(jj->op2, vidim);
		if (l1->what == l2->what) {
			if (l1->what) return new expression(constant, bool_, chislo, for_bool(l1->chis, l2->chis));
			if (l1->what) return new expression(constant, bool_v, vetor, for_bool_v(l1->vec_, l2->vec_,vidim));
			if (l1->what) return new expression(constant, bool_m, matriz, for_bool_m(l1->matr_, l2->matr_,vidim));
		}
		else {
			std::cout << "ne sootvetstvie tipov";
			our_err++;
			return jj;
		}
	}
}

int for_bool(int k1, int k2) {
	if (k1 == k2 == 1)
		return 1;
	else return 0;
}

//��� �������
vec* for_bool_v(vec* v1, vec* v2, std::map<std::string, expression*> vidim) {
	//��� ������ �������� ������� �� � ��� ������
	if ((vecisb(v1,vidim))&(vecisb(v2, vidim))) {
		if (v1->x1 == v2->x1) {
			//�������� �� �����������
			for (int i = 0; i < v1->x1;i++) {
				v1->arr[i]->chis = for_bool(v1->arr[i]->chis, v2->arr[i]->chis);

			}return v1;
		}
		else {
			std::cout << "ne sootvetstvie razmer";
			our_err++;
			return v1;
		}
	}
	else {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return v1;
	}
}

//��� �������
matr* for_bool_m(matr* m1, matr* m2, std::map<std::string, expression*> vidim) {
	//����� ������������ ���������� � �������� ������� ������� � �����
	if ((m1->x1 == m2->x1)&(m1->x2 == m2->x2)) {
		for (int i = 0; i < m1->x2;i++) {
			m1->arr[i] = for_bool_v(m1->arr[i], m2->arr[i],vidim);
		}return m1;
	}
	else {
		std::cout << "ne sootvetstvie razmer";
		our_err++;
		return m1;
	}
}

//////////////////////////////////////////////////////////////////////
expression* koordin_(expression* ee, std::map<std::string, expression*> vidim) {
	auto res2 = new expression;
	auto l2 = res_vir(ee->op2, vidim);
	//������ ������� ��������� ���������� ������� �������� ����� �������
	//������ � ������ ������� ��� �������������� ��������� ������� � ����������� ���� �����
	auto l3 = res_vir(ee->op3, vidim);
	if ((ee->op1->type == peremen)&(ee->op1->what == matriz)&(l2->what == chislo)&(l3->what == chislo)) {
		return m_koord(ee->name, l2->chis, l3->chis, vidim);
	}
	else {
		std::cout << "ne sootvetctvie tipov"; our_err++; return res2;
	}
}

expression*m_koord(std::string n, int k1, int k2, std::map<std::string, expression*> vidim)//����� ���� �������� ����� ����������
{
	
	//������ ���� ������� � ������
	auto ll = vidim.find(n);
	if (ll == vidim.end())
	{
		auto res = new expression;
		std::cout << "not know"; our_err++; return res;
	}
	else {
		int mm = (ll->second->matr_->arr[k1]->arr[k2])->chis;
		if (ll->second->per == int_m) {

			auto res = new expression(constant, int_, chislo, mm); return res;
		}
		else {
			auto res = new expression(constant, int_, chislo, mm);
			return res;
		}
	}
}
///////////////////////////////////////////////////////////////////////
expression* matr_matr__(expression* jj, std::map<std::string, expression*> vidim) {
	//������ ������� �������
	//������ ������� ���������� �������
	auto l1 = res_vir(jj->op1, vidim);
	auto l2 = res_vir(jj->op2, vidim);
	if ((l1->what == matriz)&(l2->per == bool_m)) {
		//���������� ���������� ������� ������ ���� ������ ��� ������
		//����������� �������� ����� ��� ����������
		if ((l1->matr_->x1<l2->matr_->x1) | (l1->matr_->x2<l2->matr_->x2))
		{
			std::cout << "ne sootvetstvie rezmernost";
			auto res = new expression; our_err++; return res;
		}if (l1->per == int_m)return new expression(constant, int_m, matriz, mat_mat(l1->matr_, l2->matr_));
		else return new expression(constant, int_m, matriz, mat_mat(l1->matr_, l2->matr_));
			

	}
	else {
		std::cout << "ne sootvetstvie tipov";
		auto res = new expression; our_err++; return res;
	}
}

matr* mat_mat(matr* m1, matr* m2) {//��������������� ���������
	auto res = new matr;
	vec*nn= new vec;
	for (int i = 0; i < m2->x1; i++) {
		for (int k = 0; k < m2->x1; k++) {
			auto help = new vec;
			help->add(m2->arr[i]->arr[k]);
			if (m2->arr[i]->arr[k]->chis == 0) {
				help->arr[k]->chis = 0;
				nn = help;
			}res->add(nn);
		}
	}return res;
}
///////////////////////////////////////////////////////////////////////
//(f_minus)
expression* minus_(expression* jj, std::map<std::string, expression*> vidim) {	//������ ������� ������� ������ � ������ �������
	auto op1 = res_vir(jj->op1, vidim);
	auto op2 = res_vir(jj->op2, vidim);
	//������ �������� � �� ��������� �� ���
	if ((op1->type == constant) | (op2->type == constant)) {
		///�������� ���� ������ 2 ��������� �� ���� �� ���������
		if ((op1->type == constant) & (op2->type == constant)) {
			auto l = new expression(constant, int_, chislo, (op1->chis - op2->chis));
			return l;
		}
		//���� ���� �� ��� �� ��������� �� �������� �� ���
		else {
			//���� ���� �� ��������� ��������, �� ��� ���� ������ ��� ���������� � ��������� �� ���
			if ((op1->type == constant) | (op2->type == operat)) {
				auto ll = have_with_op(op2, vidim);
				if (ll->per == int_) {
					auto l2 = new expression(constant, int_, chislo, (op1->chis - ll->chis));
					return l2;
				}
			}

		}
		if ((op2->type == constant) | (op1->type == operat)) {
			auto ll = have_with_op(op1, vidim);
			if (ll->per == int_) {
				auto l2 = new expression(constant, int_, chislo, (ll->chis - op2->chis));
				return l2;
			}
		}

		if ((op1->type == constant) | (op2->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis - op2->chis));
			return l;
		}
		if ((op2->type == constant) | (op1->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis - op2->chis));
			return l;
		}
		else { std::cout << "ne sootvetctvie tipov"; our_err++; }

	}
	//��� � ���� ���� ��������� ������ ���������
	//� ��� �������� � ������ ��� � �����������
	//� �������� ��� ��� ������
	else {//������ �������� �� ������� ����������
		  //ec����� ���������
		if ((op1->type == operat) | (op2->type == operat)) {
			//������� ��������� ��
			auto l1 = have_with_op(op1, vidim);
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis - op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, minus_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, minus_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }

		}
		//���� ������ �������� � ������ �������
		if ((op1->type == operat) | (op2->type == peremen)) {
			auto l1 = have_with_op(op1, vidim);
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis - op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, minus_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, minus_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ������ �������� � ������ �������
		if ((op1->type == peremen) | (op2->type == operat)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis - op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, minus_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, minus_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ��� ����������
		if ((op1->type == peremen) | (op2->type == peremen)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis - op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, minus_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, minus_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}

	}
}
vec* minus_v(vec* v1, vec*v2, std::map<std::string, expression*> vidim) {//���������  ��������
	vec*res = new vec;
	//�������� �����������
	if (v1->x1 == v2->x1) {
		for (int i = 0; i < v1->x1; i++) {
			//��� ��� ���� ��������� ���� ����� ������ �������� � �������. ��� ������ ������ ���������� ������
			auto l1 = res_vir(v1->arr[i], vidim);
			auto l2 = res_vir(v2->arr[i], vidim);
			if ((l1->what == chislo)&(l2->what == chislo)) {
				l1->chis -= l2->chis;
				res->add(l1);
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; break; }

		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}
matr* minus_m(matr* v1, matr*v2, std::map<std::string, expression*> vidim) {//���������  ������
	matr*res = new matr;
	//�������� �����������
	if ((v1->x1 == v2->x1)&(v1->x1 == v2->x1)) {
		for (int i = 0; i < v1->x2; i++) {
			//��� �������� ������
			auto l1 = v1->arr[i];
			auto l2 = v2->arr[i];
			res->add(minus_v(l1, l2, vidim));
		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}

/////////////////////////////////////////////////////
//(f_not_)
//�������� ��� ���������� �������/��������/�����
expression* not__(expression* jj, std::map<std::string, expression*> vidim) {
	auto l = new expression;
	 l = res_vir(jj->op1, vidim);
	if (l->per == bool_) {
		if (l->chis == 1){
			l->chis = 0;
	}
	else { l->chis = 1;   }return l;
	}
	else if (l->per == bool_v) { l->vec_ = ism_b_v(l->vec_); return l; }
	else if (l->per == bool_m) { l->matr_ = ism_b_m(l->matr_); return l; }
	else { std::cout << "ne sootvetctvie tipov"; our_err++; return jj; }
}
vec* ism_b_v(vec* k) {
	//not ��� �������
	for (int i = 0; i < k->x1; i++) {
		if (k->arr[i]->chis == 0)
			k->arr[i]->chis = 1;
		else k->arr[i]->chis == 0;

	}return k;
}
matr* ism_b_m(matr* k) {
	for (int i = 0; i < k->x2; i++)
		k->arr[i] = ism_b_v(k->arr[i]);
	return k;
}
///////////////////////////////////////////////////////////////////////////////////
expression* plus_(expression* jj, std::map<std::string, expression*> vidim) {	//������ ������� ������� ������ � ������ �������
	auto op1 = res_vir(jj->op1, vidim);
	auto op2 = res_vir(jj->op2, vidim);
	//������ �������� � �� ��������� �� ���
	if ((op1->type == constant) | (op2->type == constant)) {
		///�������� ���� ������ 2 ��������� �� ���� �� ���������
		if ((op1->type == constant) & (op2->type == constant)) {
			auto l = new expression(constant, int_, chislo, (op1->chis + op2->chis));
			return l;
		}
		//���� ���� �� ��� �� ��������� �� �������� �� ���
		else {
			//���� ���� �� ��������� ��������, �� ��� ���� ������ ��� ���������� � ��������� �� ���
			if ((op1->type == constant) | (op2->type == operat)) {
				auto ll = have_with_op(op2, vidim);
				if (ll->per == int_) {
					auto l2 = new expression(constant, int_, chislo, (op1->chis + ll->chis));

					return l2;
				}
			}

		}
		if ((op2->type == constant) | (op1->type == operat)) {
			auto ll = have_with_op(op1, vidim);
			if (ll->per == int_) {
				auto l2 = new expression(constant, int_, chislo, (ll->chis + op2->chis));
				return l2;
			}
		}

		if ((op1->type == constant) | (op2->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis + op2->chis));
			return l;
		}
		if ((op2->type == constant) | (op1->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis + op2->chis));
			return l;
		}
		else { std::cout << "ne sootvetctvie tipov"; our_err++; }

	}
	//��� � ���� ���� ��������� ������ ���������
	//� ��� �������� � ������ ��� � �����������
	//� �������� ��� ��� ������
	else {//������ �������� �� ������� ����������
		  //ec����� ���������
		if ((op1->type == operat) | (op2->type == operat)) {
			//������� ��������� ��
			auto l1 = have_with_op(op1, vidim);
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis + op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, slog_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, slog_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }

		}
		//���� ������ �������� � ������ �������
		if ((op1->type == operat) | (op2->type == peremen)) {
			auto l1 = have_with_op(op1, vidim);
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis + op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, slog_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, slog_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ������ �������� � ������ �������
		if ((op1->type == peremen) | (op2->type == operat)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis + op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, slog_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, slog_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ��� ����������
		if ((op1->type == peremen) | (op2->type == peremen)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					auto res = new expression(constant, int_, chislo, (op1->chis + op2->chis));
					return res;
				}
				if (l1->what = vetor) {
					auto res = new expression(constant, int_v, vetor, slog_v(l1->vec_, l2->vec_, vidim));
					return res;
				}
				if (l1->what = matriz) {
					auto res = new expression(constant, int_m, matriz, slog_m(l1->matr_, l2->matr_, vidim));
					return res;
				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}

	}
}
vec* slog_v(vec* v1, vec*v2, std::map<std::string, expression*> vidim) {//�������� ��������
	vec*res = new vec;
	//�������� �����������
	if (v1->x1 == v2->x1) {
		for (int i = 0; i < v1->x1; i++) {
			//��� ��� ���� ��������� ���� ����� ������ �������� � �������. ��� ������ ������ ���������� ������
			auto l1 = res_vir(v1->arr[i], vidim);
			auto l2 = res_vir(v2->arr[i], vidim);
			if ((l1->what == chislo)&(l2->what == chislo)) {
				l1->chis += l2->chis;
				res->add(l1);
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; break; }

		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}
matr* slog_m(matr* v1, matr*v2, std::map<std::string, expression*> vidim) {//�������� ������
	matr*res = new matr;
	//�������� �����������
	if ((v1->x1 == v2->x1)&(v1->x1 == v2->x1)) {
		for (int i = 0; i < v1->x2; i++) {
			//��� �������� ������
			auto l1 = v1->arr[i];
			auto l2 = v2->arr[i];
			res->add(slog_v(l1, l2, vidim));
		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}
//////////////////////////////////////////////////////////////
//(f_sravn)
// ���������� �� ����� ������ ��� �����
//�� ������� � ��� ��� ��������� ����� ��� ��� �� �� ������� ��� ��� ��� ���� ��� � ��� ����
//� ����� ���������� ��������� � ������� ����� ��������� ���� ���� chis
//���� ��� ����� �� ��� ����� 1
//����� ����
expression *sravn_p_(expression* jj, std::map<std::string, expression*> vidim) {//������ ���������
	auto o1 = res_vir(jj->op1, vidim);//������ �������
	auto o2 = res_vir(jj->op2, vidim);//������ �������
	if ((o1->what == chislo)&(o2->what == chislo))//���� � �� ��� �������
	{
		if (o1->per == o2->per)
			if (o1->chis < o2->chis)
				return new expression(constant, bool_, chislo, 1);
			else return new expression(constant, bool_, chislo, 0);
	}
	else {
		std::cout << "ne sootvetsvie tipov"; auto res = new expression; return res;
	}
}

expression *sravn_l_(expression* jj, std::map<std::string, expression*> vidim) {//����� ���������
	auto o1 = res_vir(jj->op1, vidim);//������ �������
	auto o2 = res_vir(jj->op2, vidim);//������ �������
	if ((o1->what == chislo)&(o2->what == chislo))//���� � �� ��� �������
	{
		if (o1->per == o2->per)
			if (o1->chis > o2->chis)
				return new expression(constant, bool_, chislo, 1);
			else return new expression(constant, bool_, chislo, 0);
	}
	else {
		std::cout << "ne sootvetsvie tipov"; auto res = new expression; return res;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
expression* sum_(expression* jj, std::map<std::string, expression*> vidim) {//�������������� �������� �������/�������/�������
																			//�� ���� ������ ���� ������� � +
																			//������ ������ ������� ��� ���������
	return plus_(jj, vidim);
}
////////////////////////////////////////////////////////////////////////////////////
//f_tran
//��� ��� �������� �����������������
//��� � ��� ���� �������
//������� ������ ���� ��������
//����� ������������ � �������� �������� ��������� ������� � ����� ��� ��������� ��� ������
//��� ��� �������� �����������������
//��� � ��� ���� �������
//������� ������ ���� ��������
//����� ������������ � �������� �������� ��������� ������� � ����� ��� ��������� ��� ������
expression* tran_(expression* xx, std::map<std::string, expression*> vidim) {
	//������ ��������� ������� �� ������ �������
	if (xx->op1->what != matriz) {
		std::cout << "ne sootvetstvie tipov";
		our_err++;
		return xx;
	}auto l2 = res_vir(xx->op1, vidim);
	auto kk = new matr;//���� ���� �������
					   //� ����� ����� ������� � ������ ��� ������
	for (int i = 0; i < l2->matr_->x1; i++)
		kk->add(i_want_stolb(l2->matr_, i));
	auto ll = new expression(constant, xx->op1->per, matriz, kk);
	return ll;
} 
/////////////////////////////////////////////////////////////////////////////////////
//f_vec_st
//���� ��� ��������� ������/������� ������� �� �������
expression* vector_stolb_(expression* jj, std::map<std::string, expression*> vidim) {//��� ��������� ������� ������� ��� ����� �������
																					 //������ ������� ������ ���� �������� ���������� ������� ������ ���� ����� �� ��������
																					 //������ ������� � ������� ����� ������ ������ ������ ������� ����� �������� ��� ����� ����� ������� ��� �����

	auto tt = vidim.find(jj->op1->name);
	if (tt == vidim.end())
	{//���� ����� ���������� � ��� ���
		std::cout << "ne know peremen"; our_err++;
		auto res = new expression; return res;
	}
	auto op1 = res_vir(jj->op2, vidim);
	if ((tt->second->what == matriz)&(op1->what == chislo)&(op1->per == int_)) {
		if (tt->second->per == int_m)
			return new expression(constant, int_v, vetor, i_want_stolb(tt->second->matr_, op1->chis));
		else return new expression(constant, bool_v, vetor, i_want_stolb(tt->second->matr_, op1->chis));

	}  if ((tt->second->what == matriz)&(op1->what == vetor)&(op1->per == int_v)) {//////!!!!!!!!!
		if (tt->second->per == int_m)
			return new expression(constant, int_m, matriz, i_want_stolb_m(tt->second->matr_, op1->vec_));
		else return new expression(constant, bool_m, matriz, i_want_stolb_m(tt->second->matr_, op1->vec_));

	}
	if ((tt->second->what == matriz)&(op1->what == vetor)&(op1->per == bool_v)) {//////!!!!!!!!!
		if (tt->second->per == int_m)
			return new expression(constant, int_m, matriz, i_want_stolb_mb(tt->second->matr_, op1->vec_));
		else return new expression(constant, bool_m, matriz, i_want_stolb_mb(tt->second->matr_, op1->vec_));

	}
	else {
		std::cout << "ne sootvetstvie tipov"; our_err++;
		auto res = new expression; return res;
	}
}

expression* vector_strok_(expression* jj, std::map<std::string, expression*> vidim) {//��� ��������� ������� ��p��� ��� ����� �������
																					 //������ ������� ������ ���� �������� ���������� ������� ������ ���� ����� �� ��������
																					 //������ ������� � ������� ����� ������ ������ ������ ������� ����� �������� ��� ����� ����� ������� ��� �����

	auto tt = vidim.find(jj->op1->name);
	if (tt == vidim.end())
	{//���� ����� ���������� � ��� ���
		std::cout << "ne know peremen"; our_err++;
		auto res = new expression; return res;
	}
	auto op1 = res_vir(jj->op2, vidim);
	if ((tt->second->what == matriz)&(op1->what == chislo)&(op1->per == int_)) {
		if (tt->second->per == int_m)
			return new expression(constant, int_v, vetor, i_want_strok(tt->second->matr_, op1->chis));
		else return new expression(constant, bool_v, vetor, i_want_strok(tt->second->matr_, op1->chis));

	}  if ((tt->second->what == matriz)&(op1->what == vetor)&(op1->per == int_v)) {//////!!!!!!!!!
		if (tt->second->per == int_m)
			return  new expression(constant, int_m, matriz, i_want_strok_m(tt->second->matr_, op1->vec_));
		else return  new expression(constant, bool_m, matriz, i_want_strok_m(tt->second->matr_, op1->vec_));

	}
	if ((tt->second->what == matriz)&(op1->what == vetor)&(op1->per == bool_v)) {//////!!!!!!!!!
		if (tt->second->per == int_m)
			return new expression(constant, int_m, matriz, i_want_strok_mb(tt->second->matr_, op1->vec_));
		else return new expression(constant, bool_m, matriz, i_want_strok_mb(tt->second->matr_, op1->vec_));

	}
	else {
		std::cout << "ne sootvetstvie tipov"; our_err++;
		auto res = new expression; return res;
	}
}

vec* i_want_stolb(matr*mm, int k)//������� �������-�������
{
	auto res = new vec;
	if (k>mm->x1) {
		std::cout << "neprevelnaa razmer"; our_err++;
		return res;
	}
	for (int i = 0; i < mm->x2; i++) {
		res->add(mm->arr[i]->arr[k]);

	}return res;
}
vec* i_want_strok(matr*mm, int k)//������� ������-�������
{
	auto res = new vec;
	if (k>mm->x2) {
		std::cout << "neprevelnaa razmer"; our_err++;
		return res;
	}
	for (int i = 0; i < mm->x1; i++) {
		res->add(mm->arr[k]->arr[i]);

	}return res;
}

matr* i_want_stolb_m(matr* m, vec* v) {//������� ������� � ��������� ������� ��������
	auto res = new matr;
	for (int i = 0; i < v->arr.size(); i++)
		res->add(i_want_stolb(m, v->arr[i]->chis));
	return res;
}
matr* i_want_stolb_mb(matr* m, vec* v) {//������� ������� � ��������� ���� ����� ������� ��������
	auto res = new matr;
	if (v->arr.size() > m->x1)//���� � ��� ����� ��������� ������� ������ ������� ������� �� ������
	{
		std::cout << "neprevelnaa razmer vectora"; our_err++;
		return res;
	}
	for (int i = 0; i < v->arr.size(); i++) {
		if (v->arr[i]->chis)
			res->add(i_want_stolb(m, v->arr[i]->chis));
	}return res;
}
matr* i_want_strok_m(matr* m, vec* v) {//������� ������� � ��������� ������� �����
	auto res = new matr;
	for (int i = 0; i < v->arr.size(); i++)
		res->add(i_want_strok(m, v->arr[i]->chis));
	return res;
}
matr* i_want_strok_mb(matr* m, vec* v) {//������� ������� � ��������� ���� ����� ������� �����
	auto res = new matr;
	if (v->arr.size() > m->x2)//���� � ��� ����� ��������� ������� ������ ������� ������� �� ������
	{
		std::cout << "neprevelnaa razmer vectora"; our_err++;
		return res;
	}
	for (int i = 0; i < v->arr.size(); i++) {
		if (v->arr[i]->chis)
			res->add(i_want_strok(m, v->arr[i]->chis));
	}return res;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//f_ymn_
expression* ymn_(expression* jj, std::map<std::string, expression*> vidim) {//�������������� ��������� �������/�������/�������
																			//������ ������� ������� ������ � ������ �������
	auto op1 = res_vir(jj->op1, vidim);
	auto op2 = res_vir(jj->op2, vidim);
	//������ �������� � �� ��������� �� ���
	if ((op1->type == constant) | (op2->type == constant)) {
		///�������� ���� ������ 2 ��������� �� ���� �� ���������
		if ((op1->type == constant) & (op2->type == constant)) {
			auto l = new expression(constant, int_, chislo, (op1->chis * op2->chis));
			return l;
		}
		//���� ���� �� ��� �� ��������� �� �������� �� ���
		else {
			//���� ���� �� ��������� ��������, �� ��� ���� ������ ��� ���������� � ��������� �� ���
			if ((op1->type == constant) | (op2->type == operat)) {
				auto ll = have_with_op(op2, vidim);
				if (ll->per == int_)
					return new expression(constant, int_, chislo, (op1->chis * ll->chis));
			}


		}
		if ((op2->type == constant) | (op1->type == operat)) {
			auto ll = have_with_op(op1, vidim);
			if (ll->per == int_)
				return new expression(constant, int_, chislo, (ll->chis * op2->chis));

		}

		if ((op1->type == constant) | (op2->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis * op2->chis));
			return l;
		}
		if ((op2->type == constant) | (op1->per == int_)) {
			auto l = new expression(constant, int_, chislo, (op1->chis * op2->chis));
			return l;
		}
		else { std::cout << "ne sootvetctvie tipov"; our_err++; }

	}
	//��� � ���� ���� ��������� ������ ���������
	//� ��� �������� � ������ ��� � �����������
	//� �������� ��� ��� ������
	else {//������ �������� �� ������� ����������
		  //ec����� ���������
		if ((op1->type == operat) | (op2->type == operat)) {
			//������� ��������� ��
			auto l1 = have_with_op(op1, vidim);
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					return new expression(constant, int_, chislo, (op1->chis * op2->chis));

				}
				if (l1->what = vetor) {
					return new expression(constant, int_v, vetor, ymn_v(l1->vec_, l2->vec_, vidim));

				}
				if (l1->what = matriz) {
					return new expression(constant, int_m, matriz, ymn_m(l1->matr_, l2->matr_, vidim));

				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }

		}
		//���� ������ �������� � ������ �������
		if ((op1->type == operat) | (op2->type == peremen)) {
			auto l1 = have_with_op(op1, vidim);
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					return new expression(constant, int_, chislo, (op1->chis * op2->chis));

				}
				if (l1->what = vetor) {
					return new expression(constant, int_v, vetor, ymn_v(l1->vec_, l2->vec_, vidim));

				}
				if (l1->what = matriz) {
					return new expression(constant, int_m, matriz, ymn_m(l1->matr_, l2->matr_, vidim));

				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ������ �������� � ������ �������
		if ((op1->type == peremen) | (op2->type == operat)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = have_with_op(op2, vidim);
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					return new expression(constant, int_, chislo, (op1->chis * op2->chis));

				}
				if (l1->what = vetor) {
					return new expression(constant, int_v, vetor, ymn_v(l1->vec_, l2->vec_, vidim));

				}
				if (l1->what = matriz) {
					return new expression(constant, int_m, matriz, ymn_m(l1->matr_, l2->matr_, vidim));

				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}
		//���� ��� ����������
		if ((op1->type == peremen) | (op2->type == peremen)) {//������� ��������� ��
			auto l1 = op1;
			auto l2 = op2;
			//�������� ������������ �����
			if (l1->per == l2->per) {
				//���� ��� ��������� �� ��������� � ��� ����� ���� � ������� ���������
				if (l1->what = chislo) {
					return new expression(constant, int_, chislo, (op1->chis * op2->chis));

				}
				if (l1->what = vetor) {
					return new expression(constant, int_v, vetor, ymn_v(l1->vec_, l2->vec_, vidim));

				}
				if (l1->what = matriz) {
					return new expression(constant, int_m, matriz, ymn_m(l1->matr_, l2->matr_, vidim));

				}
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; }
		}

	}
}
vec* ymn_v(vec* v1, vec*v2, std::map<std::string, expression*> vidim) {//���������  ��������
	vec*res = new vec;
	//�������� �����������
	if (v1->x1 == v2->x1) {
		for (int i = 0; i < v1->x1; i++) {
			//��� ��� ���� ��������� ���� ����� ������ �������� � �������. ��� ������ ������ ���������� ������
			auto l1 = res_vir(v1->arr[i], vidim);
			auto l2 = res_vir(v2->arr[i], vidim);
			if ((l1->what == chislo)&(l2->what == chislo)) {
				l1->chis *= l2->chis;
				res->add(l1);
			}
			else { std::cout << "ne sootvetctvie tipov"; our_err++; break; }

		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}
matr* ymn_m(matr* v1, matr*v2, std::map<std::string, expression*> vidim) {//���������  ������
	matr*res = new matr;
	//�������� �����������
	if ((v1->x1 == v2->x1)&(v1->x1 == v2->x1)) {
		for (int i = 0; i < v1->x2; i++) {
			//��� �������� ������
			auto l1 = v1->arr[i];
			auto l2 = v2->arr[i];
			res->add(slog_v(l1, l2, vidim));
		}
	}
	else {
		std::cout << "ne sovpad razmer vectorov"; our_err++; return res;
	}return res;

}
/////////////////////////////////////////////////////////////////////////////////////////
//f_ymn_m
expression* ymn_mm_(expression* jj, std::map<std::string, expression*> vidim) {
	auto op1 = res_vir(jj->op1, vidim);
	auto op2 = res_vir(jj->op2, vidim);
	if ((op1->what)&(op2->what)) {
		if (op1->per == op2->per == int_m) {
			if ((op1->matr_->x1 == op2->matr_->x2)&(op1->matr_->x2 == op2->matr_->x1)) {
				if (op1->per == int_m)
					return new expression(constant, int_m, matriz, i_want_ymn_m(op1->matr_, op2->matr_, vidim));
				else return new expression(constant, bool_m, matriz, i_want_ymn_m(op1->matr_, op1->matr_, vidim));

			}


			else {
				std::cout << "ne sootvetstvie razmernosti"; auto res = new expression;  our_err++; return res;
			}
			std::cout << "ne sootvetstvie tipov"; auto res = new expression;  our_err++; return res;
		}
	}
	else { std::cout << "ne sootvetstvie tipov"; auto res = new expression; our_err++; return res; }
}

//��������������� ������������ ������
matr* i_want_ymn_m(matr*m1, matr*m2, std::map<std::string, expression*> vidim) {
	//�� ���� ���������� ��� ��� ����� ������ �������� ������ �� ������
	//� ����� ���������� � �������
	//�� ������ ����� �������� �� ������ ������ ������ � �� ������ ������
	//� ��� ������ � �����
	auto our_m = new matr;
	int xx=0;
	for (int i = 0; i < m1->x2; i++) {
		auto v1 = i_want_strok(m1, i);//�������� ������ ������ �������
		auto vvv = new vec;
		for (int j = 0; j < m1->x1; j++) {
			auto v2 = i_want_stolb(m2, i);//�������� ������ ������ �������
			auto rr = ymn_v(v1, v2, vidim);//����������� ��
			auto zz = rr->arr.begin();
			for (int t = 0; t < rr->x1; t++, zz++) {//���������� ��� �������� ��� 
				xx += zz[t]->chis;
				//����� ��������� ��� ��������� � ��������� � ������
				auto dobav = new expression(constant, int_, chislo, xx);
				vvv->add(dobav);
			}//����� ���������� ������ ������ � �������
			our_m->add(vvv);
		}return our_m;
	}
}
///////////////////////////////////////////////////////////////////
//sdvigi
//������ ������� ��� ���������� �������/����� ��� ���������-�����
expression* sd_l_(expression* jj, std::map<std::string, expression*> vidim) {   //����� � ���� ��� ����� ��� �������
	if (jj->op1->what == peremen) {
		//������ ������� ��� � ����� ������� �������
		auto ll = vidim.find(jj->op1->name);
		//���� ��� ���� � �� ����� ��� � ������� �� ��������� ������� ��� �����
		if (ll != vidim.end()) {
			//���� �����
			if (ll->second->what == chislo) {
				ll->second->chis *= 10;
			}
			//���� �������
			if (ll->second->what == matriz) {
				ll->second->matr_ = matr_sd(ll->second->matr_, 1, ll->second->per);
			}
			//���� ������ �� ������
			if (ll->second->what == vetor) {
				std::cout << "c vektorom operator ne primenim"; auto res = new expression; our_err++; return res;
			}
		}
		else { std::cout << "c vektorom operator ne primenim"; auto res = new expression; our_err++; return res; }
	}
	else if (jj->op1->what == constant) {
		//��� � ��� ������ �����
		auto res = jj->op1; res->chis = res->chis * 10;
		return res;
	}
	else { std::cout << "c operator operator ne primenim"; auto res = new expression; our_err++; return res; }
}




expression* sd_p_(expression* jj, std::map<std::string, expression*> vidim){//����� � ����� ��� ����� ��� �������
if (jj->op1->per == peremen) {
	//������ ������� ��� � ����� ������� �������
	auto ll = vidim.find(jj->op1->name);
	//���� ��� ���� � �� ����� ��� � ������� �� ��������� ������� ��� �����
	if (ll != vidim.end()) {
		//���� �����
		if (ll->second->what == chislo) {
			ll->second->chis /= 10;
		}
		//���� �������
		if (ll->second->what == matriz) {
			ll->second->matr_ = matr_sd(ll->second->matr_, 0, ll->second->per);
		}
		//���� ������ �� ������
		if (ll->second->what == vetor) {
			std::cout << "c vektorom operator ne primenim"; auto res = new expression; our_err++; return res;
		}
	}
	else { std::cout << "c vektorom operator ne primenim"; auto res = new expression; our_err++; return res; }
}
else if (jj->op1->per == constant) {
	//��� � ��� ������ �����
	auto res = jj->op1; res->chis = res->chis / 10;
	return res;
}
else { std::cout << "c operator operator ne primenim"; auto res = new expression; our_err++; return res; }
}

matr* matr_sd(matr* mm, int k, perem oo)//����� ������� � ����/����
{
	expression* ll;
	if (k) {
		//���� �����
		for (int i = 0; i < mm->x2; i++) {
			if (oo = int_m)
				ll = new expression(constant, int_, chislo, 0);
			else ll = new expression(constant, bool_, chislo, 0);
			auto it = mm->arr[i]->arr.begin();
			mm->arr[i]->arr.emplace(it, ll);
			return mm;
		}

	}
	else {
		//����� ����� ������

		for (int i = 0; i < mm->x2; i++) {
			auto it = mm->arr[i]->arr.begin();
			mm->arr[i]->arr.erase(it);

			return mm;
		}
	}
}