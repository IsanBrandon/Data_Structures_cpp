#include <iostream>
#include <cmath>   // sqrt ���
using namespace std;

int main() {
	int* num = new int;	// �Է� ���� 
	cout << "Enter num: ";
	cin >> *num;

	if (*num <= 0 || *num > 100) {
		cout << "Wrong Input." << endl;
		delete num;
		return 0;
	}

	// ���� 5���� ������ ���� �迭
	int* arr = new int[*num];

	cout << "Enter " << *num << " integers: ";
	for (int i = 0; i < *num; i++) {
		cin >> *(arr + i);  // ������ ����� ����Ͽ� �Է� �ޱ�
	}

	// �ּҰ�, �ִ밪, ���, ǥ�������� ������ ������ ����
	int* minVal = new int(*arr);
	int* maxVal = new int(*arr);
	double* avg = new double(0);
	double* stddev = new double(0);

	// �ּ�, �ִ�, �� ���
	\for (int i = 0; i < *num; i++) {
		if (*(arr + i) < *minVal) *minVal = *(arr + i);
		if (*(arr + i) > *maxVal) *maxVal = *(arr + i);
		*avg += *(arr + i);
	}
	*avg /= *num;

	// ǥ������ ���
	for (int i = 0; i < *num; i++) {
		double diff = static_cast<double>(*(arr + i)) - *avg;	// i��° ���� ���� double�� ��ȯ.
		// ����: ���(*avg)�� double*�̹Ƿ� ������ �����ϸ� ����ȯ�� �ʿ�. 
		// static_cast<double>�� �����ϰ� ������� Ÿ�� ��ȯ ���.
		*stddev += diff * diff;
	}
	*stddev = sqrt(*stddev / *num);

	// ��� ���
	cout << *minVal << " " << *maxVal << " " << *avg << " " << *stddev << endl;

	// ���� �޸� ����
	delete num;
	delete[] arr;
	delete minVal;
	delete maxVal;
	delete avg;
	delete stddev;

	return 0;
}