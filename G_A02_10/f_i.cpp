#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3, 3, 4, 5 };
	int k = 3;
	auto it = find(v.begin(), v.end(), k);	// 찾으면 그 원소를 가리키는 iterator 반환, 
											// 못 찾으면 v.end() 반환
											// 첫 번째 2을 가리키는 반복자를 얻게 됨
	if (it != v.end())
		v.erase(it);						// 그 위치의 원소를 제거하고 뒤 원소들을 한 칸씩 앞으로 이동

	for (auto element : v)
		cout << element << " ";
	cout << endl;

	return 0;
}