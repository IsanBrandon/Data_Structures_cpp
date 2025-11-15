#include <iostream>
#include <vector>
using namespace std;

template <typename T> class ListQueue {
private:
	class Node {
	public:
		T data;
		Node* next;
		Node () {}
		Node (T d, Node *p): data(d), next(p) {}
	};
	Node* head = nullptr, * tail = nullptr;
	int size_queue = 0;

	// 문제점 1번 해결방법: 소멸자 구현
	void clear_list() {
		while (head != nullptr) {
			Node* p = head;
			head = head->next;
			delete p;
		}
		head = tail = nullptr;
		size_queue = 0;
	}

	// 문제점 2번 해결방법: 깊은 복사 구현 
	void copy_from(const ListQueue<T>& que) {
		Node* p = que.head;
		while (p != nullptr) { push(p->data); p = p->next; }
	}

public:
	void push(T item) {
		Node* p = new Node(item, nullptr);
		if (head == nullptr) { head = tail = p; }
		else { tail->next = p; tail = p; }
		size_queue++;
	}

	void pop() {
		if (empty()) { throw runtime_error("Queue is empty"); }
		Node* p = head;
		head = head->next;
		if (head == nullptr) tail = nullptr;
		delete p;
		size_queue--;
	}
	
	bool empty() { return head == nullptr; }
	T front() {
		if (empty()) { throw runtime_error("Queue is empty"); }
		return head->data;
	}

	int size() { return size_queue; }

	void print() {	// just for testing
		Node* p = head;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	~ListQueue() { clear_list(); }
	ListQueue() = default;
	ListQueue(const ListQueue<T>& que) { copy_from(que); }

	ListQueue<T>& operator=(const ListQueue<T>& que) {
		clear_list(); // 기존 데이터 삭제
		copy_from(que); // 깊은 복사
		return *this; // 자기 자신을 반환
	}

};

void func(vector<int> v) {
	ListQueue<int> q;
	for (int d : v) q.push(d);
}

int main() {
	// 문제점 1번: 메모리 누수 발생
	vector<int> v{ 1, 2, 3, 4 };
	func(v);

	// 문제점 2번: shallow copy만 발생
	ListQueue<int> que;
	for (int d : v) que.push(d);
	ListQueue<int> que2(que);
	ListQueue<int> que3;
	que3 = que2;

	que.push(5);

	que.print();
	que2.print();
	que3.print();

	return 0;
}