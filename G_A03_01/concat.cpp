struct Node {
	int data;
	Node* next;
};

Node* concatenate(Node* first, Node* second) {
	// �� ���� ó��: �� �� �ϳ��� ����� ���
	if (first == nullptr) return second;
	if (second == nullptr) return first;
	// �� first�� ������ ã�´�
	Node* tail = first;
	while (tail->next != nullptr) tail = tail->next; 
	// �� ������ next�� second�� ����
	tail->next = second;
	// �� head�� �״�� first�� head
	return first;
}



