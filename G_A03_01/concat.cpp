struct Node {
	int data;
	Node* next;
};

Node* concatenate(Node* first, Node* second) {
	// ① 예외 처리: 둘 중 하나가 비었을 경우
	if (first == nullptr) return second;
	if (second == nullptr) return first;
	// ② first의 꼬리를 찾는다
	Node* tail = first;
	while (tail->next != nullptr) tail = tail->next; 
	// ③ 꼬리의 next를 second로 연결
	tail->next = second;
	// ④ head는 그대로 first의 head
	return first;
}



