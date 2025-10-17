#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void reverse(Node* &head) {		
	// 참조(reference)를 이용해서 함수 내부에서 인자 자체를 바꿈
	Node* prev = nullptr;			// 이전 노드를 저장할 포인터
	Node* current = head;			// 현재 처리 중인 노드
	Node* next;
	while (current != nullptr) {
		next = current->next;		// 다음 노드 임시 저장 
		current->next = prev;		// 현재 노드의 화살표를 뒤집음
		prev = current;				// 한 칸 전진: prev <- current
		current = next;
	}
	head = prev;					// head 직접 변경 
}

int main() {
	// 테스트용 간단한 연결리스트 생성
	Node* head = new Node{ 1, new Node{2, new Node{3, nullptr}} };

	cout << "Before reverse: ";
	for (Node* p = head; p; p = p->next)
		cout << p->data << " ";
	cout << endl;

	reverse(head);

	cout << "After reverse: ";
	for (Node* p = head; p; p = p->next)
		cout << p->data << " ";
	cout << endl;

	return 0;
}

