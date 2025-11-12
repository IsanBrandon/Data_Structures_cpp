#include <iostream>
#include <string>
using namespace std;

char mystack[MAX_CAPACITY];	// 스택에 저잘되는 데이터의 타입을 char라고 가정할 때
int top_pos = -1;			// 스택이 비어있을 때의 top 위치

bool full() {
	return top_pos == MAX_CAPACITY - 1;
}

bool empty() {
	return top_pos == -1;
}

void push(char c) {
	if (full())
		throw runtime_error("stack_full");
	mystack[++top_pos] = c;
}

void pop() {
	if (empty())
		throw runtime_error("stack_empty");
	top_pos--;
}

char top() {
	if (empty())
		throw runtime_error("stack_empty");
	return mystack[top_pos];
}