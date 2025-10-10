#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <cassert>
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
	
	ifstream fin("rects.txt");
	int n;	// �簢�� ����
	fin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, w, h;
		fin >> x >> y >> w >> h;
		Node* newNode = new Node(); // Node*�� �����ϴ� ����?
		newNode->x = x;
		newNode->y = y;
		newNode->w = w;
		newNode->h = h;
		newNode->next = nullptr;

	}
}

void sort_by_area() {
	// head�� ����Ű�� ���Ḯ��Ʈ�� ���������� �����Ѵ�.
}

void remove_rects(int min_w, int min_h) {
	// �ʺ� min_w���� �۰ų� ���̰� min_h���� ���� �簢������
	// head�� ����Ű�� ���Ḯ��Ʈ���� �����Ѵ�.
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