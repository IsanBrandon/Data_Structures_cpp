#include <iostream>
#include <vector>

int main() {
	std::vector<int> v = { 8, 4, 5, 9 };
	v.push_back(6);	// vector�� variable-length(���� ����)�� �迭
	v.push_back(9); // ���Ҹ� �߰��ϸ� ���̰� �ڵ����� �þ�ٰ� �����ϸ� ��.
	// ���������� capacity�� �����ϸ� capacity�� �����ϸ� �� ū �޸𸮸� ���� �Ҵ��� - array reallocation
	// ���� �����͸� �ű�� ������� ũ�⸦ Ȯ����.
	
	v[2] = -1;	// vector�� ����� ���Ҵ� �迭ó�� �ε��� ������([])�� �����Ͽ� �б�/���� ����

	for (int n : v)
		std::cout << n << ' ';
	std::cout << '\n';
}