#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* prev, * next;
};

void ordered_insert(string item);	// 항상 사전식 순서 유지하며 삽입 (중복 허용)
void remove_dup();					// 중복 단어 모두 제거, 한 개만 남김
void print_list_twice();			// 정방향, 역방향 출력

Node* head = nullptr, * tail = nullptr;		/* 2중 연결리스트의 처음과 마지막 노드 */

int main() {
	int n;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		ordered_insert(word);
	}

	print_list_twice();
	remove_dup();
	print_list_twice();
	return 0;
}

void ordered_insert(string item) {
	/* head와 tail이 가리키는 2중 연결리스트에 문자열들이 사전식 순서로
	   정렬된 순서를 유지하도록 새로운 문자열 item을 삽입한다. */
	Node* n = new Node{ item, nullptr, nullptr };

	if (!head) {				// 빈 리스트
		head = tail = n;
		return;
	}
	if (item <= head->data) {	// head 앞
		n->prev = nullptr;
		n->next = head;
		head->prev = n;
		head = n;
		return;
	}
	if (item >= tail->data) {	// tail 뒤
		n->prev = tail;
		n->next = nullptr;
		tail->next = n;
		tail = n;
		return; 
	}
	// 중간: 첫 data >= item 인 노드 x를 찾고, x 앞에 삽입
	Node* x = head->next;
	while (x && x->data < item) x = x->next;

	n->prev = x->prev;
	n->next = x;
	x->prev->next = n;
	x->prev = n;
}

void remove_dup() {
	/* 2중 연결리스트에 저장된 문자열들 중에서 모든 중복된 문자열을 찾아
	   하나만 남기고 제거한다. */

	if (head == nullptr) return;

	Node* p = head;
	while (p) {
		Node* q = p->next;
		// p와 동일한 문자열을 가진 노드들을 모두 제거
		while (q && q->data == p->data) {
			Node* del = q;
			q = q->next;

			// del 제거 (head는 아님; del == p->next부터 시작)
			if (del->next) del->next->prev = del->prev;
			else tail = del->prev;	// del이 tail인 경우, tail 갱신
			del->prev->next = del->next;

			delete del;
		}
		p = q;	// 다음 고유 단어로 이동
	}
}

void print_list_twice() {
	Node* p = head;
	while (p != nullptr) { 
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	Node* q = tail;
	while (q != nullptr) {
		cout << q->data << " ";
		q = q->prev;
	}
	cout << endl;
}