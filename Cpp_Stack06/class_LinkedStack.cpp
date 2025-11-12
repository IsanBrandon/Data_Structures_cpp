#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class LinkedStack;
private:
	int data;
	Node* next;
	Node() {}
	Node(int c, Node* p) : data(c), next(p) {}
};

class LinkedStack {
private:
	Node* head = nullptr;

public:
	bool full() {return false;}
	bool empty() { return head == nullptr; }
	void push(int c) { head = new Node(c, head); }
	void pop() {
		if (empty()) throw runtime_error("stack_empty");
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	int top() {
		if (empty()) throw runtime_error("stack_empty");
		return head->data;
	}
};

int main() {
	LinkedStack s1, s2;
	s1.push(1);
	s2.push(2);
	cout << s1.top() << ' ' << s2.top() << endl;
	return 0;
}