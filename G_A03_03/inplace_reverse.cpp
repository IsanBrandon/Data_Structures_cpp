#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void reverse(Node* &head) {		
	// ����(reference)�� �̿��ؼ� �Լ� ���ο��� ���� ��ü�� �ٲ�
	Node* prev = nullptr;			// ���� ��带 ������ ������
	Node* current = head;			// ���� ó�� ���� ���
	Node* next;
	while (current != nullptr) {
		next = current->next;		// ���� ��� �ӽ� ���� 
		current->next = prev;		// ���� ����� ȭ��ǥ�� ������
		prev = current;				// �� ĭ ����: prev <- current
		current = next;
	}
	head = prev;					// head ���� ���� 
}

int main() {
	// �׽�Ʈ�� ������ ���Ḯ��Ʈ ����
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

