#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	v1.swap(v2);	// Vector는 내부적으로 '동적 배열을 가리키는 포인터', 'size', 'capacity' 정보를 멤버 변수로 갖고 있음
					// swap은 이 포인터와 관리 정보들을 서로 교환함. 
					// 따라서 시간 복잡도 O(1)
					// 만약 원소를 하나씩 교환했다면 O(n) 시간이 걸렸을 것
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	return 0;
}