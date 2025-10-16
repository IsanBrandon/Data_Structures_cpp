struct Node {
	int data;
	Node* next;
};

// ���1
Node* remove_multiple_three(Node* head) {		  // (QA1) ��ȯ���� Node*�� �ٲ㼭 modified head�� ��ȯ
  //Node* p = head;									 (Q2) ���� ù ��° ����� ���� 3�� ������?
  //while (p->next->data % 3 != 0) p = p->next;		 (Q3) p->next�� nullptr�� �� ���� ���� �߻�
  //if (p->next == nullptr) return;
  //p->next = p->next->next;						 (Q4) ������ ��� �޸� ���� �ʿ�

	// (A2) head�� 3�� ����� ��� ���� ó�� & ���ÿ� head�� nullptr�� ��� ó��
	if (head == nullptr) return nullptr;
	if (head->data % 3 == 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;	// (A1) Return modified head
	}

	// head ���� Ž��
	Node* p = head;
	while (p->next && p->next->data % 3 != 0) p = p->next;	// (A3) p->next�� nullptr���� ���� üũ
	if (p->next == nullptr) return head;

	// (A4) ������ ��� �޸� ����
	Node* temp = p->next;
	p->next = p->next->next;
	delete temp;

	return head; // (A1) Retrun modified head
}

// ���2
Node* remove_multiple_three(Node* head) {
	Node dummy{ 0, head };		// Add dummy node before head
	Node* p = &dummy;

	while (p->next && p->next->data % 3 != 0) p = p->next;
	
	if (!p->next) return head;	// There is no node to remove

	Node* del = p->next;
	p->next = del->next;
	delete del;

	return dummy.next; // Return modified head
}