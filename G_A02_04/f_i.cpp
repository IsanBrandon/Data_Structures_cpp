#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> g1;
	for (int i = 0; i < 5; i++)
		g1.push_back(i);

	cout << "Size : " << g1.size() << endl;
	cout << "Capacity : " << g1.capacity() << endl;

	g1.resize(10);	
	// vector는 원소가 추가될 때 capacity를 자동확장하는데, 
	// resize는 사용자가 명시적으로 크기를 바꿔주는 것
	// 새 공간은 기본값인 '0'으로 채워짐. (크기가 작아지면 값들이 잘려나감)
	cout << "Size : " << g1.size() << endl;
	for (auto it = g1.begin(); it != g1.end(); it++)
	// begin()	: 첫 번째 원소를 가리키는 iterator를 생성해 줌
	// end()	: 마지막 원소의 다음 위치를 가리키는 iterator를 생성해 줌
	// it++		: pointer arithmetic와 같은 기능을 사용할 수 있습니다.
		cout << *it << " ";

	return 0;
}