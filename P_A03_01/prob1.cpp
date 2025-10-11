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
	// rects.txt ������ �о �簢������ ���Ͽ� ����� �������
	// head�� ����Ű�� ���Ḯ��Ʈ�� �����Ѵ�.
	ifstream fin("rects.txt");	// file���� ����, �ٹٲ� ���� ��ŵ
	if (!fin) {
		cerr << "Cannot open rects.txt!" << endl;
		return;	// ���� ��ȯ���� �ʰ� ����
	}

	int n;	// �簢�� ����
	fin >> n;

	Node* tail = nullptr; // List�� ������ ��带 ����Ű�� ������

	for (int i = 0; i < n; i++) {
		int x, y, w, h;
		fin >> x >> y >> w >> h;
		Node* new_node = new Node{ x, y, w, h, nullptr };

		if (head == nullptr) {	// ù ���
			head = tail = new_node;
		}
		else {					// �� ��° ���� ���
			tail->next = new_node;
			tail = new_node;
			}
		}
}


void sort_by_area() {	// head�� ����Ű�� ���Ḯ��Ʈ�� ���������� �����Ѵ�.
	Node* sorted_head = nullptr;	// ���ĵ� ����Ʈ�� head 
	Node* curr = head;		// ���� ���ĵ��� ���� ����� head

	while (curr != nullptr) {
		Node* next_node = curr->next;	// ���� ��带 �̸� ���� (curr�� �̵��� ����)
											// curr->next = (*curr).next: ��� ���� ������ 
		int area = curr->w * curr->h;	// ���� ����� ����

		// (1) ���ĵ� ����Ʈ�� ����ְų� ù ��庸�� ���� ���: �� �տ� ����
		if (sorted_head == nullptr || area < sorted_head ->w * sorted_head ->h) {
			curr->next = sorted_head;
			sorted_head = curr; 
		}
		// (2) ���ĵ� ����Ʈ �ȿ��� ��ġ�� ã�� ����
		else {
			Node* p = sorted_head;
			while (p->next != nullptr && p->next->w * p->next->h <= area) {
				p = p->next;
			}
			curr->next = p->next;
			p->next = curr;

		}
		curr = next_node;	// ���� ���� �̵�
	}
	head = sorted_head;	// head�� ���ĵ� ����Ʈ�� head�� ����Ű���� �Ѵ�.
}

void remove_rects(int min_w, int min_h) {
	// �ʺ� min_w���� �۰ų� ���̰� min_h���� ���� �簢������
	// head�� ����Ű�� ���Ḯ��Ʈ���� �����Ѵ�.
	
	// (1) ���� ��� �غ�
	Node dummy{0,0,0,0, head};				// �ӽ� ���
											// ���̰� ���� head �տ� �ٵ���
	Node* prev = &dummy;	// �׻� curr�� �ٷ� ���� ����Ŵ
	Node* curr = head;		// ���� �˻� ���� ���

	// (2) ��ȸ
	while (curr != nullptr) {
		bool small_w = (curr->w < min_w);
		bool small_h = (curr->h < min_h);
		if (small_w || small_h) {
			// ������ ���� �޸� ����
			Node* target = curr;
			prev->next = curr->next;
			curr = prev->next;
			delete target;	// �޸� ����
		}
		else {
			// ���: ������ �� �� ������
			prev = curr;
			curr = curr->next; 
		}
	}
	// (3) head ����
	head = dummy.next;
}

int main() {
	// (1)
	read_file();	// ������ �о ���Ͽ� ����� ������� ����� ���Ḯ��Ʈ�� �����Ѵ�.
	print_list();	// ���Ͽ� ����� ������� ��µȴ�. 

	cout << endl;	// �� ���� ����.

	// (2)
	sort_by_area();	// ���Ḯ��Ʈ�� ������ ���������� �����Ѵ�.
	print_list();   // ���ĵ� ������� ����Ѵ�.
	cout << endl;	// �� ���� ����.

	// (3)
	int min_w, min_h;
	cin >> min_w >> min_h;
	remove_rects(min_w, min_h);
	print_list();

	return 0;
}