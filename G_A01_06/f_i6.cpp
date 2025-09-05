#include <iostream>
using namespace std;

int addition(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}

// operation�� "� ������ ����"�� �ܺο��� �޾Ƽ� �����ϴ� '�ٸ��� ����' ������ �մϴ�.
int operation(int x, int y, int (*functocall)(int, int)) {	// functocall: �� ���� int�� �޾Ƽ� int�� ��ȯ�ϴ� �Լ� ������
	int g;						// functocall�� �Լ��� �ּҸ� ��� �ֽ��ϴ�.
	g = (*functocall)(x, y);	// (*functocall)(x, y)�� functocall�� ����Ű�� �Լ��� x, y ���ڸ� �־� ȣ���մϴ�.
	return (g);					// ���� ���, addition �Լ��� ������ addition(x, y)�� �����ϰ� �����մϴ�.
}								// ȣ�� ����� g�� �����ϰ�, �� ���� ��ȯ�մϴ�.

int main() {
	int m, n;
	int (*minus)(int, int) = subtraction;

	m = operation(7, 5, addition);
	n = operation(20, m, minus);
	cout << n;
	return 0;
}