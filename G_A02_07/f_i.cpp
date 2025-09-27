#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.assign(5, 10);	// assign(count, value): 벡터의 현재 내용을 모두 지우고 - count만큼 value로 채워 넣기 (벡터 덮어쓰기)
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

	v.insert(v.begin(), 5); // 지정한 위치에 원소 삽입, 그 뒤의 원소들은 한 칸씩 뒤로 밀린다. 
	cout << "The first element is: " << v[0] << endl;

	v.erase(v.begin());
	cout << "The first element is: " << v[0] << endl;

	v.clear();	// v.begin()부터 v.end()까지 모든 원소들 전부 없앰.
	cout << "Vector size: " << v.size() << endl;
	return 0; 
}