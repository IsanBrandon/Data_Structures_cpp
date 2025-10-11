#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int x, y, w, h;
	Node* next;
};

Node* head = nullptr;

void print_list() {
	Node* p = head;
	while (p != nullptr) {
		cout << p->x << " " << p->y << " " << p->w << " " << p->h << endl;
		p = p->next;
	}
}

void read_file() {
	// rects.txt 파일을 읽어서 사각형들을 파일에 저장된 순서대로
	// head가 가리키는 연결리스트에 저장한다.
	ifstream fin("rects.txt");	// file에서 공백, 줄바꿈 등을 스킵
	if (!fin) {
		cerr << "Cannot open rects.txt!" << endl;
		return;	// 값을 반환하지 않고 종료
	}

	int n;	// 사각형 개수
	fin >> n;

	Node* tail = nullptr; // List의 마지막 노드를 가리키는 포인터

	for (int i = 0; i < n; i++) {
		int x, y, w, h;
		fin >> x >> y >> w >> h;
		Node* new_node = new Node{ x, y, w, h, nullptr };

		if (head == nullptr) {	// 첫 노드
			head = tail = new_node;
		}
		else {					// 두 번째 이후 노드
			tail->next = new_node;
			tail = new_node;
			}
		}
}


void sort_by_area() {	// head가 가리키는 연결리스트를 면적순으로 정렬한다.
	Node* sorted_head = nullptr;	// 정렬된 리스트의 head 
	Node* curr = head;		// 아직 정렬되지 않은 노드의 head

	while (curr != nullptr) {
		Node* next_node = curr->next;	// 다음 노드를 미리 저장 (curr가 이동할 예정)
											// curr->next = (*curr).next: 멤버 접근 연산자 
		int area = curr->w * curr->h;	// 현재 노드의 면적

		// (1) 정렬된 리스트가 비어있거나 첫 노드보다 작은 경우: 맨 앞에 삽입
		if (sorted_head == nullptr || area < sorted_head ->w * sorted_head ->h) {
			curr->next = sorted_head;
			sorted_head = curr; 
		}
		// (2) 정렬된 리스트 안에서 위치를 찾아 삽입
		else {
			Node* p = sorted_head;
			while (p->next != nullptr && p->next->w * p->next->h <= area) {
				p = p->next;
			}
			curr->next = p->next;
			p->next = curr;

		}
		curr = next_node;	// 다음 노드로 이동
	}
	head = sorted_head;	// head가 정렬된 리스트의 head를 가리키도록 한다.
}

void remove_rects(int min_w, int min_h) {
	// 너비가 min_w보다 작거나 높이가 min_h보다 작은 사각형들을
	// head가 가리키는 연결리스트에서 제거한다.
	
	// (1) 더미 헤드 준비
	Node dummy{0,0,0,0, head};				// 임시 노드
											// 더미가 현재 head 앞에 붙도록
	Node* prev = &dummy;	// 항상 curr의 바로 앞을 가리킴
	Node* curr = head;		// 현재 검사 중인 노드

	// (2) 순회
	while (curr != nullptr) {
		bool small_w = (curr->w < min_w);
		bool small_h = (curr->h < min_h);
		if (small_w || small_h) {
			// 연결을 끊고 메모리 해제
			Node* target = curr;
			prev->next = curr->next;
			curr = prev->next;
			delete target;	// 메모리 해제
		}
		else {
			// 통과: 포인터 둘 다 앞으로
			prev = curr;
			curr = curr->next; 
		}
	}
	// (3) head 갱신
	head = dummy.next;
}

int main() {
	// (1)
	read_file();	// 파일을 읽어서 파일에 저장된 순서대로 저장된 연결리스트를 구성한다.
	print_list();	// 파일에 저장된 순서대로 출력된다. 

	cout << endl;	// 한 줄을 띄운다.

	// (2)
	sort_by_area();	// 연결리스트의 노드들을 면적순으로 정렬한다.
	print_list();   // 정렬된 순서대로 출력한다.
	cout << endl;	// 한 줄을 띄운다.

	// (3)
	int min_w, min_h;
	cin >> min_w >> min_h;
	remove_rects(min_w, min_h);
	print_list();

	return 0;
}