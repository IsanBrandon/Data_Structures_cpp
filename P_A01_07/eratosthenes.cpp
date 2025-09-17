#include <iostream>
using namespace std;

/*
 * ���� 7: �Ҽ� ���ϱ� (�����佺�׳׽��� ü)
 *	- �Է�: n (�ִ� 10000)
 *  - ���: 2~n ������ ��� �Ҽ�
 *  - ���: �迭�� ���� �����ϸ鼭 ��� ���� (�� �ڸ� ���� ������ ���)
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // ���Ѱ� �Է�

	if (n < 2) {
		return 0; // 2 �̸��̸� �Ҽ� ����
	}

	// 1) 2���� n���� �迭�� ����
	int size = n - 1;				// ���� ���� (2~n ����)
	int* arr = new int[size];       // ���� �迭 �Ҵ�
	for (int i = 0; i < size; i++) {
		arr[i] = i + 2;           // arr[0] = 2, arr[1] = 3, ..., arr[size-1] = n
	}

	// 2) �迭�� ������� �����鼭 ��� ����
	for (int i = 0; i < size; i++) {
		int p = arr[i];				// ���� �Ҽ� �ĺ�
		if (p == -1) continue;		// �̹� ���ŵ� �ڸ��� �ǳʶ�

		// p�� ��� ���� (�ڱ� �ڽ� ����)
		for (int j = i + 1; j < size; ) {
			if (arr[j] % p == 0) {
				// j��° ���� ���� -> �� ���ҵ��� �� ĭ�� ������ ���
				for (int k = j; k < size - 1; k++) {
					arr[k] = arr[k + 1];
				}
				--size; // ��ü ũ�� ����
				// arr[j]���� �� ���� ��������Ƿ� j�� ������Ű�� �ʰ� �ݺ�
			}
			else {
				++j; // ����� �ƴϸ� ���� ���ҷ�
			}
		}
	}

	// 3) ��� ���: �迭�� ���� �ִ� ������ �Ҽ�
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}

	delete[] arr; // ���� �޸� ����
	return 0;
}