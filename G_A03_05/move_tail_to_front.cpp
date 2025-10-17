/* IDEA
 * 1. empty list or ���� 1���� �״��
 * 2. `second_last`�� `last`�� ã�´�.
 * 3. `second_last->next = nullptr`�� ������ ����,
 * 4. `last->next = head; head = last;`�� �� ������ ���δ�.
 */

struct Node {
	int data;
	Node* next;
};

void move_tail_to_front(Node*& head, Node*& tail) {
	if (!head || !head->next) return;	// 0�� or 1���� ��ȭ ����

	Node* prev = nullptr;
	Node* curr = head;
	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}
	// curr=tail(������), prev=�� ����
	prev->next = nullptr;
	curr->next = head;
	head = curr;
	tail = prev;	// tail�� �Բ� ������Ʈ
}

int main() {
	/* ... */
	move_tail_to_front(head, tail);
	/* ... */
	return 0;
}

