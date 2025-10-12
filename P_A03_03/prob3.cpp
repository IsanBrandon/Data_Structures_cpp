#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Term {
	int coef;
	int expo;
	Term* next = nullptr;

	Term() {}	// default constructor; 생성자가 하나라도 있는 경우 만들어 두는 것이 좋음

	Term(int c, int e) : coef(c), expo(e) {}
	Term(int c, int e, Term* p) : coef(c), expo(e), next(p) {}
};

struct Polynomial {
	char name; // 다항식 이름
	Term* first = nullptr;
	int size = 0;
	Polynomial() {}
	Polynomial(char name) : name(name) {}
};

vector<Polynomial> polys;

void add_term(Polynomial& poly, int c, int e) {
	if (c == 0) return;

	Term* p = poly.first, * q = nullptr;

	while (p != nullptr && p->expo > e) {	// 차수 내림차순 유지: expo 큰 게 앞
		q = p; p = p->next;
	}

	if (p != nullptr && p->expo == e) {	// 동일 차수 -> 계수 더하기
		p->coef += c;
		if (p->coef == 0) {				// 0이 되면 항 삭제
			if (q == nullptr) poly.first = p->next;	// 바로 while문을 빠져나온 경우, 첫번째 노드 삭제
			else q->next = p->next;					// 중간 노드 삭제
			delete p;
			poly.size--;
		}
		return;
	}

	// 동일 차수가 없으면 새 노드 삽입 (q ... p 사이)
	Term* node = new Term(c, e, p);
	if (q == nullptr) poly.first = node;	// 바로 while문을 빠져나온 경우, 맨 앞 삽입
	else q->next = node;					// 중간/맨뒤 삽입
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
	if (p.first == nullptr) { cout << "0\n"; return; }	// 항이 하나도 없으면 그냥 0을 출력하고 함수 종료.

	Term* t = p.first;	// t로 리스트를 처음부터 끝까지 돈다.
	bool first = true;	// first는 “첫 항인지”를 알려주는 플래그(첫 항은 부호 출력 규칙이 다름).

	while (t) {
		int c = t->coef, e = t->expo;	// c가 실제 계수, e는 지수.
		int a = (c < 0 ? -c : c);		// |c|; 출력할 땐 부호를 따로 찍고, 본체에는 절대값 계수 a를 사용한다.

		// 부호 출력 규칙
		if (first) { if (c < 0) cout << "-"; }	// 첫 항: 음수면 -만 찍고, 양수면 아무 부호도 안 찍는다.
												// (예: x^2 앞에 +가 안 붙음)
		else { cout << (c < 0 ? "-" : "+"); }	// 둘째 항부터: 음수면 -, 양수면 +를 붙인다.
												// (예: +3x 또는 -2x^3)
		// 본체(계수·변수·지수) 출력
		if (e == 0) {		// 상수항
			cout << a;	
		}
		else if (e == 1) {	// 1차항
			if (a != 1) cout << a;
			cout << "x"; 
		}
		else {				// 2차항 이상
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
	auto it = find_poly(p.name); // 같은 이름을 가진 애가 있는지 검사
	if (it == polys.end()) {
		polys.push_back(p);
	}
	else {
		clear_poly(*it); // 없애주고
		*it = p;		 // 덮어씌기
	}
}

void handle_print(char name) {
	auto it = find_poly(name);
	if (it == polys.end())
		cout << "No such polynomial exists." << endl;
	else
		print_poly(*it);
}

int calc_term(const Term* term, int x) {	// 하나의 항의 값을 계산하는 함수 
	// term: 하나의 항을 가리키는 포인터 (coef와 expo를 가짐)
	// x: 대입할 값
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) result *= x;	// 지수만큼 반복해서 x를 곱함
	return result;	// 해당 항의 값, 즉 coef * x^expo
}

int calc_poly(const Polynomial& poly, int x) { // 다항식의 값을 계산하는 함수 
	// poly: 계산할 다항식(읽기 전용으로 받음: const &)
	// x: 대입할 값
	int result = 0;
	for (Term* t = poly.first; t; t = t->next)	// t; 는 t != nullptr;
		result += calc_term(t, x);		// 각각의 항의 값을 계산하여 더한다
	return result;	// 다항식 값, 즉 모든 항의 값의 합 
}

Polynomial add_two(const Polynomial& A, const Polynomial& B, char dst_name) {
	// 다항식 A, B(읽기 전용), 결과 다항식의 이름 dst_name
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