#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec1{ 1, 2, 3 };
	vector<int> vec2{ 3, 2, 1, 4 };
	vec1 = vec2;				
	// vec1의 기존 원소들 제거 -> vec2의 모든 원소들을 copy assignment(값 복사)해서 vec1에 저장
	// 따라서 두 벡터는 여전히 서로 독립적. vec2를 수정해도 vec1은 영향 X
	for (auto item : vec1)		
	// range for문: vector vec1에 저장된 각각의 원소를  copy assignment를 하는 동작입니다.
		cout << item << " ";
	return 0;
}