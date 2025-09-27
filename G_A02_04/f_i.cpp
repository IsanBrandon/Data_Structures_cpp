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
	// vector�� ���Ұ� �߰��� �� capacity�� �ڵ�Ȯ���ϴµ�, 
	// resize�� ����ڰ� ��������� ũ�⸦ �ٲ��ִ� ��
	// �� ������ �⺻���� '0'���� ä����. (ũ�Ⱑ �۾����� ������ �߷�����)
	cout << "Size : " << g1.size() << endl;
	for (auto it = g1.begin(); it != g1.end(); it++)
	// begin()	: ù ��° ���Ҹ� ����Ű�� iterator�� ������ ��
	// end()	: ������ ������ ���� ��ġ�� ����Ű�� iterator�� ������ ��
	// it++		: pointer arithmetic�� ���� ����� ����� �� �ֽ��ϴ�.
		cout << *it << " ";

	return 0;
}