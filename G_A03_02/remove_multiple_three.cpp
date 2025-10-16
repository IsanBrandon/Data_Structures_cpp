struct Node {
	int data;
	Node* next;
};

// 방법1
Node* remove_multiple_three(Node* head) {		  // (QA1) 반환값을 Node*로 바꿔서 modified head를 반환
  //Node* p = head;									 (Q2) 만약 첫 번째 노드의 값이 3의 배수라면?
  //while (p->next->data % 3 != 0) p = p->next;		 (Q3) p->next가 nullptr일 때 접근 오류 발생
  //if (p->next == nullptr) return;
  //p->next = p->next->next;						 (Q4) 삭제된 노드 메모리 해제 필요

	// (A2) head가 3의 배수일 경우 따로 처리 & 동시에 head가 nullptr일 경우 처리
	if (head == nullptr) return nullptr;
	if (head->data % 3 == 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;	// (A1) Return modified head
	}

	// head 이후 탐색
	Node* p = head;
	while (p->next && p->next->data % 3 != 0) p = p->next;	// (A3) p->next가 nullptr인지 먼저 체크
	if (p->next == nullptr) return head;

	// (A4) 삭제된 노드 메모리 해제
	Node* temp = p->next;
	p->next = p->next->next;
	delete temp;

	return head; // (A1) Retrun modified head
}

// 방법2
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