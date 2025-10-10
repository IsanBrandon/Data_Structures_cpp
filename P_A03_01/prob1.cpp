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
	// rects.txt 파일을 읽어서 사각형들을 파일에 저장된 순서대로
	// head가 가리키는 연결리스트에 저장한다.
	
	ifstream fin("rects.txt");
	int n;	// 사각형 개수
	fin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, w, h;
		fin >> x >> y >> w >> h;
		Node* newNode = new Node(); // Node*로 생성하는 이유?
		newNode->x = x;
		newNode->y = y;
		newNode->w = w;
		newNode->h = h;
		newNode->next = nullptr;

	}
}

void sort_by_area() {
	// head가 가리키는 연결리스트를 면적순으로 정렬한다.
}

void remove_rects(int min_w, int min_h) {
	// 너비가 min_w보다 작거나 높이가 min_h보다 작은 사각형들을
	// head가 가리키는 연결리스트에서 제거한다.
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