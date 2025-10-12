#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* prev, * next;
};

void ordered_insert(string item);	// �׻� ������ ���� �����ϸ� ���� (�ߺ� ���)
void remove_dup();					// �ߺ� �ܾ� ��� ����, �� ���� ����
void print_list_twice();			// ������, ������ ���

Node* head = nullptr, * tail = nullptr;		/* 2�� ���Ḯ��Ʈ�� ó���� ������ ��� */

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
	/* head�� tail�� ����Ű�� 2�� ���Ḯ��Ʈ�� ���ڿ����� ������ ������
	   ���ĵ� ������ �����ϵ��� ���ο� ���ڿ� item�� �����Ѵ�. */
	Node* n = new Node{ item, nullptr, nullptr };

	if (!head) {				// �� ����Ʈ
		head = tail = n;
		return;
	}
	if (item <= head->data) {	// head ��
		n->prev = nullptr;
		n->next = head;
		head->prev = n;
		head = n;
		return;
	}
	if (item >= tail->data) {	// tail ��
		n->prev = tail;
		n->next = nullptr;
		tail->next = n;
		tail = n;
		return; 
	}
	// �߰�: ù data >= item �� ��� x�� ã��, x �տ� ����
	Node* x = head->next;
	while (x && x->data < item) x = x->next;

	n->prev = x->prev;
	n->next = x;
	x->prev->next = n;
	x->prev = n;
}

void remove_dup() {
	/* 2�� ���Ḯ��Ʈ�� ����� ���ڿ��� �߿��� ��� �ߺ��� ���ڿ��� ã��
	   �ϳ��� ����� �����Ѵ�. */

	if (head == nullptr) return;

	Node* p = head;
	while (p) {
		Node* q = p->next;
		// p�� ������ ���ڿ��� ���� ������ ��� ����
		while (q && q->data == p->data) {
			Node* del = q;
			q = q->next;

			// del ���� (head�� �ƴ�; del == p->next���� ����)
			if (del->next) del->next->prev = del->prev;
			else tail = del->prev;	// del�� tail�� ���, tail ����
			del->prev->next = del->next;

			delete del;
		}
		p = q;	// ���� ���� �ܾ�� �̵�
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