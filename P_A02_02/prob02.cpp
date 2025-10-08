#include <iostream>  
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 2) return 0;	// 2 미만이면 소수 없음
	
	vector<int> nums;
	for (int i = 2; i <= n; i++) nums.push_back(i);

	for (auto it = nums.begin(); it != nums.end(); ++it) {
		int p = *it;
		if (p * p > n) break;
		// 어떤 합성수 m ≤ n는 항상 √m(≤√n) 이하의 약수를 가짐.
		// 에라토스테네스 체에서 “현재 기준 수 p의 배수”를 지울 때,
		// p가 √n을 넘으면 더 이상 지울 배수 후보가 남아있지 않음.

		auto jt = it;	// std::vector<int>::iterator
		++jt;	// 소수가 삭제되는 것을 방지하기 위해 다음 번 숫자부터 체킹
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

