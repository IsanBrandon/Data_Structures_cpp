#include <iostream>  
#include <list>
using namespace std;

void print(list<string>& lst) {
	for (auto it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main() {
	list<int> empty_list;
	list<string> lst = { "C++", "list" };
	// cout << lst[0] << endl;		// Not supported
	// cout << lst.at(0) << endl;	// Not supported

	lst.push_front("hello");	// push_front�� pop_front�� �����Ѵ�.
	lst.push_back("class");
	lst.push_back("template");
	cout << lst.size() << endl;
	lst.pop_back();

	list<string>::iterator it = lst.begin();
//		it++;	// list������ ��� ���� 
	it = next(it);
	cout << *it << endl;
	it = lst.end();
//		it--;
	it = prev(it);
	cout << *it << endl;

	print(lst);

	list<string>::iterator it2 = lst.begin();
	it2 = next(it2, 2);
	it2 = lst.insert(it2, "doubly");

	print(lst);

	it2 = lst.erase(it2);
	print(lst);
}