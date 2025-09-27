#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(5);	// [0, 0, 0, 0, 0]
	int i = 0;

	vector<int>::reverse_iterator rit = v.rbegin();	// v.rbegin()은 마지막 원소를 가리킴
	for (; rit != v.rend(); ++rit)					// v.rend()는 before-begin을 가리킴
	// 이미 초기식은 위에서 초기화를 해둠.
		*rit = ++i;
	// 따라서 사실상 위의 코드는
//  while (rit != v.rend()) {
//	*rit = ++i;
//	++rit;
// }

	for (auto it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	return 0;
}