#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v{ 1, 2, 3, 4, 5 };
	vector<int>::iterator it1, it2;

	it1 = v.begin();
	it2 = v.end();
	it2--;				// pointer arithmetic과 비슷한 iterator의 이동 연산이 수행됨.
	it2--;

	v.erase(it1, it2);	// 앞 폐구간, 뒤 개구간 범위 삭제
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	return 0; 
}