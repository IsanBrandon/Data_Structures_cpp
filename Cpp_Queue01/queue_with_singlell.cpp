#include <iostream>
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
};