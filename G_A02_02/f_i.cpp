#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> g1;
	for (int i = 1; i <= 10; i++)
		g1.push_back(i * 10);

	cout << "g1[2] = " << g1[2] << endl;			// 지정된 원소에 대한 참조 리턴(원소를 직접 접근 및 수정 가능) - bound check 안 함
	cout << "g1.at(4) = " << g1.at(4) << endl;		// 지정된 원소에 대한 참조 리턴(원소를 직접 접근 및 수정 가능) - bound check 함
	cout << "g1.front() = " << g1.front() << endl;	// g1[0]을 참조 리턴
	cout << "g1.back() = " << g1.back() << endl;	// g1[g1.size()-1]을 참조 리턴 
	return 0;
}