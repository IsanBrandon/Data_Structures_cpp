#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* next;
};

Node* top_node = nullptr;

void push(string item) {
	Node* p = new Node;
	p->data = item;
}

void pop() {
	if (empty())
		throw runtime_error("stack_empty");
	Node* tmp = top_node;
	top_node = top_node->next;
	delete tmp; 
}

string top() {
	if (empty())
		throw runtime_error("stack_empty");
	return top_node->data;
}

bool empty() {
	return top_node == nullptr;
}