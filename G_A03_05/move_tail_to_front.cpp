/* IDEA
 * 1. empty list or 원소 1개면 그대로
 * 2. `second_last`와 `last`를 찾는다.
 * 3. `second_last->next = nullptr`로 꼬리를 끊고,
 * 4. `last->next = head; head = last;`로 맨 앞으로 붙인다.
 */

struct Node {
	int data;
	Node* next;
};

void move_tail_to_front(Node*& head, Node*& tail) {
	if (!head || !head->next) return;	// 0개 or 1개면 변화 없음

	Node* prev = nullptr;
	Node* curr = head;
	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}
	// curr=tail(마지막), prev=새 꼬리
	prev->next = nullptr;
	curr->next = head;
	head = curr;
	tail = prev;	// tail도 함께 업데이트
}

int main() {
	/* ... */
	move_tail_to_front(head, tail);
	/* ... */
	return 0;
}

