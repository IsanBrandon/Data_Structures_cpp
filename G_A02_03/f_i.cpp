#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec1{ 1, 2, 3 };
	vector<int> vec2{ 3, 2, 1, 4 };
	vec1 = vec2;				
	// vec1�� ���� ���ҵ� ���� -> vec2�� ��� ���ҵ��� copy assignment(�� ����)�ؼ� vec1�� ����
	// ���� �� ���ʹ� ������ ���� ������. vec2�� �����ص� vec1�� ���� X
	for (auto item : vec1)		
	// range for��: vector vec1�� ����� ������ ���Ҹ�  copy assignment�� �ϴ� �����Դϴ�.
		cout << item << " ";
	return 0;
}