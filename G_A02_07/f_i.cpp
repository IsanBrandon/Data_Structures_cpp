#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.assign(5, 10);	// assign(count, value): ������ ���� ������ ��� ����� - count��ŭ value�� ä�� �ֱ� (���� �����)
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	v.push_back(15);	
	int n = v.size();
	cout << "The last element is: " << v[n - 1] << endl;
	v.pop_back();

	cout << "The vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v.insert(v.begin(), 5); // ������ ��ġ�� ���� ����, �� ���� ���ҵ��� �� ĭ�� �ڷ� �и���. 
	cout << "The first element is: " << v[0] << endl;

	v.erase(v.begin());
	cout << "The first element is: " << v[0] << endl;

	v.clear();	// v.begin()���� v.end()���� ��� ���ҵ� ���� ����.
	cout << "Vector size: " << v.size() << endl;
	return 0; 
}