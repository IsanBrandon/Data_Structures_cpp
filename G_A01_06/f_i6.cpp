#include <iostream>
using namespace std;

int addition(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}

// operation은 "어떤 연산을 할지"를 외부에서 받아서 실행하는 '다목적 계산기' 역할을 합니다.
int operation(int x, int y, int (*functocall)(int, int)) {	// functocall: 두 개의 int를 받아서 int를 반환하는 함수 포인터
	int g;						// functocall은 함수의 주소를 담고 있습니다.
	g = (*functocall)(x, y);	// (*functocall)(x, y)는 functocall이 가리키는 함수를 x, y 인자를 넣어 호출합니다.
	return (g);					// 예를 들어, addition 함수가 들어오면 addition(x, y)와 동일하게 동작합니다.
}								// 호출 결과를 g에 저장하고, 그 값을 반환합니다.

int main() {
	int m, n;
	int (*minus)(int, int) = subtraction;

	m = operation(7, 5, addition);
	n = operation(20, m, minus);
	cout << n;
	return 0;
}