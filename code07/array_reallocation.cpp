#include <iostream>
using namespace std;

int main() {
	int size = 5;
	int *data = new int [size];
	int n = 0, k;
	while (1) {
		cin >> k;
		if (k == -1) break;	// ����ڰ� ���� -1�� �Է��ϸ� �Է��� �����Ѵ�.
		if (n == size) {
			size *= 2;
			int *tmp = new int[size];
			for (int i = 0; i < n; i++)
				tmp[i] = data[i];
			data = tmp;
		}
		data[n++] = k;
	}

	// Do something with array data

	return 0; 
}