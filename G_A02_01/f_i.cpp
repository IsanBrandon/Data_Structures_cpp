#include <iostream>
#include <vector>

int main() {
	std::vector<int> v = { 8, 4, 5, 9 };
	v.push_back(6);	// vector는 variable-length(가변 길이)의 배열
	v.push_back(9); // 원소를 추가하면 길이가 자동으로 늘어난다고 생각하면 됨.
	// 내부적으로 capacity를 관리하며 capacity가 부족하면 더 큰 메모리를 새로 할당해 - array reallocation
	// 기존 데이터를 옮기는 방식으로 크기를 확장함.
	
	v[2] = -1;	// vector에 저장된 원소는 배열처럼 인덱스 연산자([])로 접근하여 읽기/쓰기 가능

	for (int n : v)
		std::cout << n << ' ';
	std::cout << '\n';
}