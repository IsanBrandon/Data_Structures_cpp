#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Term {
	int coef;
	int expo;
	Term* next = nullptr;

	Term() {}	// default constructor; �����ڰ� �ϳ��� �ִ� ��� ����� �δ� ���� ����

	Term(int c, int e) : coef(c), expo(e) {}
	Term(int c, int e, Term* p) : coef(c), expo(e), next(p) {}
};

struct Polynomial {
	char name; // ���׽� �̸�
	Term* first = nullptr;
	int size = 0;
	Polynomial() {}
	Polynomial(char name) : name(name) {}
};

vector<Polynomial> polys;

void add_term(Polynomial& poly, int c, int e) {
	if (c == 0) return;

	Term* p = poly.first, * q = nullptr;

	while (p != nullptr && p->expo > e) {	// ���� �������� ����: expo ū �� ��
		q = p; p = p->next;
	}

	if (p != nullptr && p->expo == e) {	// ���� ���� -> ��� ���ϱ�
		p->coef += c;
		if (p->coef == 0) {				// 0�� �Ǹ� �� ����
			if (q == nullptr) poly.first = p->next;	// �ٷ� while���� �������� ���, ù��° ��� ����
			else q->next = p->next;					// �߰� ��� ����
			delete p;
			poly.size--;
		}
		return;
	}

	// ���� ������ ������ �� ��� ���� (q ... p ����)
	Term* node = new Term(c, e, p);
	if (q == nullptr) poly.first = node;	// �ٷ� while���� �������� ���, �� �� ����
	else q->next = node;					// �߰�/�ǵ� ����
	poly.size++;
}

vector<Polynomial>::iterator find_poly(char name) {
	for (auto it = polys.begin(); it != polys.end(); it++) {
		if (it->name == name) return it;
	}
	return polys.end();
}

void print_term(Term* pTerm) {
	cout << pTerm->coef << "x^" << pTerm->expo;
}

void print_poly(Polynomial& p) {
	cout << p.name << " = ";	// e.g. h = 
	if (p.first == nullptr) { cout << "0\n"; return; }	// ���� �ϳ��� ������ �׳� 0�� ����ϰ� �Լ� ����.

	Term* t = p.first;	// t�� ����Ʈ�� ó������ ������ ����.
	bool first = true;	// first�� ��ù ���������� �˷��ִ� �÷���(ù ���� ��ȣ ��� ��Ģ�� �ٸ�).

	while (t) {
		int c = t->coef, e = t->expo;	// c�� ���� ���, e�� ����.
		int a = (c < 0 ? -c : c);		// |c|; ����� �� ��ȣ�� ���� ���, ��ü���� ���밪 ��� a�� ����Ѵ�.

		// ��ȣ ��� ��Ģ
		if (first) { if (c < 0) cout << "-"; }	// ù ��: ������ -�� ���, ����� �ƹ� ��ȣ�� �� ��´�.
												// (��: x^2 �տ� +�� �� ����)
		else { cout << (c < 0 ? "-" : "+"); }	// ��° �׺���: ������ -, ����� +�� ���δ�.
												// (��: +3x �Ǵ� -2x^3)
		// ��ü(���������������) ���
		if (e == 0) {		// �����
			cout << a;	
		}
		else if (e == 1) {	// 1����
			if (a != 1) cout << a;
			cout << "x"; 
		}
		else {				// 2���� �̻�
			if (a != 1) cout << a;
			cout << "x^" << e;
		}

		first = false;
		t = t->next;
	}
	cout << '\n';
}

void clear_poly(Polynomial& p) {
	Term* t = p.first, * tmp;
	while (t != nullptr) {
		tmp = t;
		t = t->next;
		delete tmp;
	}
	p.first = nullptr;
	p.size = 0;
}

void insert_polynomial(Polynomial p) {
	auto it = find_poly(p.name); // ���� �̸��� ���� �ְ� �ִ��� �˻�
	if (it == polys.end()) {
		polys.push_back(p);
	}
	else {
		clear_poly(*it); // �����ְ�
		*it = p;		 // �����
	}
}

void handle_print(char name) {
	auto it = find_poly(name);
	if (it == polys.end())
		cout << "No such polynomial exists." << endl;
	else
		print_poly(*it);
}

int calc_term(const Term* term, int x) {	// �ϳ��� ���� ���� ����ϴ� �Լ� 
	// term: �ϳ��� ���� ����Ű�� ������ (coef�� expo�� ����)
	// x: ������ ��
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) result *= x;	// ������ŭ �ݺ��ؼ� x�� ����
	return result;	// �ش� ���� ��, �� coef * x^expo
}

int calc_poly(const Polynomial& poly, int x) { // ���׽��� ���� ����ϴ� �Լ� 
	// poly: ����� ���׽�(�б� �������� ����: const &)
	// x: ������ ��
	int result = 0;
	for (Term* t = poly.first; t; t = t->next)	// t; �� t != nullptr;
		result += calc_term(t, x);		// ������ ���� ���� ����Ͽ� ���Ѵ�
	return result;	// ���׽� ��, �� ��� ���� ���� �� 
}

Polynomial add_two(const Polynomial& A, const Polynomial& B, char dst_name) {
	// ���׽� A, B(�б� ����), ��� ���׽��� �̸� dst_name
	Polynomial R(dst_name);
	for (Term* t = A.first; t; t = t->next) add_term(R, t->coef, t->expo);
	for (Term* t = B.first; t; t = t->next) add_term(R, t->coef, t->expo);
	return R;
} 

Polynomial multiply_two(const Polynomial& A, const Polynomial& B, char dst_name) {
	Polynomial R(dst_name);
	for (Term* a = A.first; a; a = a->next) {
		for (Term* b = B.first; b; b = b->next) {
			int c = a->coef * b->coef;
			if (c != 0) add_term(R, c, a->expo + b->expo);
		}
	}
	return R; 
}

void handle_addpoly(char dst, char left, char right) {
	auto L = find_poly(left), R = find_poly(right);
	if (L == polys.end() || R == polys.end()) {
		cout << "No such polynomial exists." << endl; return;
	}
	Polynomial res = add_two(*L, *R, dst);
	insert_polynomial(res);
}

void handle_multiply(char dst, char left, char right) {
	auto L = find_poly(left), R = find_poly(right);
	if (L == polys.end() || R == polys.end()) {
		cout << "No such polynomial exists." << endl; return;
	}
	Polynomial res = multiply_two(*L, *R, dst);
	insert_polynomial(res);
}

void handle_calc(char name, int x) {
	auto it = find_poly(name);
	if (it == polys.end())
		cout << "No such polynomial exists." << endl;
	else
		cout << calc_poly(*it, x) << endl; 
}

void handle_add(char name, int c, int e) {
	auto it = find_poly(name);
	if (it == polys.end()) {
		cout << "No such polynomial exists." << endl;
		return;
	}
	add_term(*it, c, e);
}

int main() {
	string command, arg1, arg2, arg3;
	while (1) {
		cout << "$ ";
		cin >> command;
		if (command == "print") {
			cin >> arg1;
			handle_print(arg1[0]);
		}
		else if (command == "calc") {
			cin >> arg1 >> arg2;
			handle_calc(arg1[0], stoi(arg2));
		}
		else if (command == "define") {
			cin >> arg1;
			Polynomial pol(arg1[0]);
			insert_polynomial(pol);
		}
		else if (command == "add") {
			cin >> arg1 >> arg2 >> arg3;
			handle_add(arg1[0], stoi(arg2), stoi(arg3));
		}
		else if (command == "addpoly") {
			cin >> arg1 >> arg2 >> arg3;	// dst, left, right
			handle_addpoly(arg1[0], arg2[0], arg3[0]);
		}
		else if (command == "multiplypoly") {
			cin >> arg1 >> arg2 >> arg3;    // dst, left, right
			handle_multiply(arg1[0], arg2[0], arg3[0]);
		}
		else if (command == "exit")
			break;
	}
}