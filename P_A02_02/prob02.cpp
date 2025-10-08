#include <iostream>  
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 2) return 0;	// 2 �̸��̸� �Ҽ� ����
	
	vector<int> nums;
	for (int i = 2; i <= n; i++) nums.push_back(i);

	for (auto it = nums.begin(); it != nums.end(); ++it) {
		int p = *it;
		if (p * p > n) break;
		// � �ռ��� m �� n�� �׻� ��m(�¡�n) ������ ����� ����.
		// �����佺�׳׽� ü���� ������ ���� �� p�� ������� ���� ��,
		// p�� ��n�� ������ �� �̻� ���� ��� �ĺ��� �������� ����.

		auto jt = it;	// std::vector<int>::iterator
		++jt;	// �Ҽ��� �����Ǵ� ���� �����ϱ� ���� ���� �� ���ں��� üŷ
		while (jt != nums.end()) {
			if (*jt % p == 0) {
				jt = nums.erase(jt);
			}
			else {
				++jt;
			}
		}

	}

	for (auto element : nums)
		cout << element << " ";

	return 0;
}

