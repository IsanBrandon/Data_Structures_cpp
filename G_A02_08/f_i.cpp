#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> v2 = { 7, 8, 9 };

	for (int i = 0; i <= 4; i += 2)
		swap(v1[i], v1[i + 1]);
	cout << "Vector v1 = ";
	for (int i = 0; i < 6 ; i++)
		cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < 3; i++)
		swap(v1[i], v2[i]);	// v1[i]�� v2[i]�� ������ i��° ���ҿ� ���� reference(����)

	cout << "Vector v1 = ";
	for (int i = 0; i < 6; i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "Vector v2 = ";
	for (int i = 0; i < 3; i++)
		cout << v2[i] << " ";
	return 0;
}