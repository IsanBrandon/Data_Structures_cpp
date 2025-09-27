#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> my_vec = { 1, 3, 1, 4, 4, 6, 5, 6, 6 };
	sort(my_vec.begin(), my_vec.end());	// [begin, end) 오름차순 정렬
	for (int item : my_vec)
		cout << item << " ";
	cout << endl;
	auto it = unique(my_vec.begin(), my_vec.end());	// 중복된 인접 원소를 "뒤로 밀어내고", 앞부분을 고유 원소로 채움
													// 컨테이너의 크기를 줄이지는 않음
													// it는 garbage 값의 시작점을 가리키게 됨
	for (int item : my_vec)
		cout << item << " ";
	cout << endl;

	my_vec.erase(it, my_vec.end());
	for (int item : my_vec)
		cout << item << " ";
	cout << endl;
	return 0;
}