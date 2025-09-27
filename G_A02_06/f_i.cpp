#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(5);	// [0, 0, 0, 0, 0]
	int i = 0;

	vector<int>::reverse_iterator rit = v.rbegin();	// v.rbegin()�� ������ ���Ҹ� ����Ŵ
	for (; rit != v.rend(); ++rit)					// v.rend()�� before-begin�� ����Ŵ
	// �̹� �ʱ���� ������ �ʱ�ȭ�� �ص�.
		*rit = ++i;
	// ���� ��ǻ� ���� �ڵ��
//  while (rit != v.rend()) {
//	*rit = ++i;
//	++rit;
// }

	for (auto it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	return 0;
}