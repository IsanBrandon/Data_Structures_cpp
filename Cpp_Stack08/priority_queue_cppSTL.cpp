#include <iostream>
#include <queue>
using namespace std;

// pqriority_queue by default is a max-heap
//int main() {
//	int arr[6] = { 10, 2, 4, 8, 6, 9 };
//
//	priority_queue<int> pq;
//
//	for (int i = 0; i < 6; i++) pq.push(arr[i]);
//	
//	while (!pq.empty()) { cout << pq.top() << " "; pq.pop(); }
//
//	return 0;
//}

void showpq(priority_queue<int, vector<int>, greater<int>> g) {
	while ( !g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main() {
	int arr[6] = { 10, 2, 4, 8, 6, 9 };
	priority_queue<int, vector<int>, greater<int>> gquiz(arr, arr + 6);

	cout << "Priority Queue : ";
	showpq(gquiz);

	return 0;
}