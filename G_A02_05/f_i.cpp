#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> g1;
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);
	for (auto i = g1.begin(); i != g1.end(); ++i) 
		cout << *i << " ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
	// rebegin(): 마지막 원소를 가리키는 iterator를 반환 = end()-1; reverse-begin
	// rend()	: 첫 번째 원소의 "앞"을 가리킴
	// 따라서 루프는 뒤에서 앞으로 순회함 
		cout << *ir << " ";
	return 0;
}