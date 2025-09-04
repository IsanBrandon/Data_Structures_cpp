#include <iostream>
using namespace std;

void increase(void* data, int psize) {
	if (psize == sizeof(char)) {
		
	}
}

int main() {
	char a = 'x';
	int b = 1602;
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	cout << a << ", " << b << '\n';
	return 0;
}