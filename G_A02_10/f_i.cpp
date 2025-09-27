#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3, 3, 4, 5 };
	int k = 3;
	auto it = find(v.begin(), v.end(), k);	// ã���� �� ���Ҹ� ����Ű�� iterator ��ȯ, 
											// �� ã���� v.end() ��ȯ
											// ù ��° 2�� ����Ű�� �ݺ��ڸ� ��� ��
	if (it != v.end())
		v.erase(it);						// �� ��ġ�� ���Ҹ� �����ϰ� �� ���ҵ��� �� ĭ�� ������ �̵�

	for (auto element : v)
		cout << element << " ";
	cout << endl;

	return 0;
}