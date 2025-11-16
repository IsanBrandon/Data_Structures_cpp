#include <deque>
#include <iostream>
using namespace std;

void showdq(deque<int> g) {
	deque<int>::iterator it;
	for (it = g.begin(); it != g.end(); ++it) cout << '\t' << *it;
	cout << '\n';
}

int main() {
	deque<int> deq;
	deq.push_back(10);
	deq.push_front(20);
	deq.push_back(30);
	deq.push_front(15);
	showdq(deq);

	cout << deq.size() << '\n';
	cout << deq.at(2) << '\n';
	cout << deq.front() << '\n';
	cout << deq.back() << '\n';

	deq.pop_back();
	showdq(deq);
	return 0;
}