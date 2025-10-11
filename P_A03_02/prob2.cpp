#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 입력 형식: 파일은 영문 소문자로만 구성. 공백으로 토큰화하면 될 것
 * 중요 제약:
	-> 파일에서 읽는 즉시 연결리스트에 반영 (배열에 모다뒀다가 나중에 금지)
	-> 중복 없이 리스트 유지 (이미 있는 단어면 cnt++만, 새 단어는 삽입)
	(1) 사전식 오름차순으로 항상 정렬 상태 유지 (삽입 시 위치 찾아 넣기)
	(2) 등장 빈도 <= 10인 노드 삭제 (연결만 바꾸고 delete)
	(3) (2)의 결과 리스트를 등장 빈도 내림차순, 동률은 사전식으로 재정렬
		-> 노드를 하나씩 떼어 새 리스트에 삽입하는 방식으로 구현
*/

struct WordNode {
	string word;
	int cnt;
	WordNode* next;
};

WordNode* head = nullptr;

void insert_or_increment(const string& w) {
	if (!head || w < head->word) { // 맨 앞 처리
		head = new WordNode{ w, 1, head };
		return;
	}
	WordNode* prev = head;
	WordNode* curr = head->next;

	while (curr && curr->word < w) {
		prev = curr; curr = curr->next;
	}

	if (curr && curr->word == w) {	// curr가 같은 단어면 ++
		curr->cnt++;
	}
	else if (prev->word == w) {		// head가 같은 단어면 여기서 ++
		prev->cnt++;				// 같은 단어일 때는 while 루프 0회 실행이라 
	}								// prev가 head에 머무름
	else {							
		prev->next = new WordNode{ w, 1, curr };	// 사이 or 맨뒤 삽입
	}
}

void build_list_from_file(const string& filename) {	// 굳이 filename을 복사하지 않고 const로 참조해 사용
	ifstream fin(filename);
	if (!fin) { cerr << "cannot open\n"; return; }
	string w;
	while (fin >> w) insert_or_increment(w);	// 'fin >> w'는 추출 연산자: 입력 스트림 fin에서 토큰 하나를 읽어 w에 저장
												// 읽기 성공 시	true, 실패(더 읽을 게 없으면) 시 false 반환
	fin.close();
}

int print_words() {
	int distinct_count = 0;
	for (auto p = head; p; p = p->next) {
		cout << p->word << ": " << p->cnt << '\n';
		distinct_count++;
	}
	cout << distinct_count << '\n';
	return distinct_count;
}

void remove_low_freq(int k = 10) {
	WordNode dummy{ "", 0, head };
	WordNode* prev = &dummy;
	WordNode* curr = head;
	while (curr) {
		if (curr->cnt <= k) {
			WordNode* del = curr;
			prev->next = curr->next;
			curr = prev->next;
			delete del;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	head = dummy.next;
}

bool is_before(const WordNode* a, const WordNode* b) {
	if (a->cnt != b->cnt) return a->cnt > b->cnt;	// 더 큰 빈도가 앞에 오도록
	return a->word < b->word;
}

void sort_by_freq_then_lex() {
	WordNode* sorted = nullptr;	// 정렬된 새 리스트의 헤드
	WordNode* curr = head;		// 아직 정렬되지 않은 원본 리스트에서 현재 삽입할 노드
	while (curr) {
		WordNode* nxt = curr->next;	// curr의 다음 노드를 미리 저장해 두는 임시 포인터
									// curr를 sorted에 삽입할 것이므로 curr->next가 바뀔 것임
		if (!sorted || is_before(curr, sorted)) {	// sorted에 curr 삽입 위치 찾기
			// sorted가 비었거나, curr이 맨 앞이어야 하는 경우
			curr->next = sorted;
			sorted = curr;
		}
		else {	// 그 외엔 sorted를 앞에서부터 순회하며 삽입 지점 찾기 
			WordNode* p = sorted;
			while (p->next && !is_before(curr, p->next)) p = p->next;
			curr->next = p->next;	// p 다음 위치에 끼우기
			p->next = curr;
		}
		curr = nxt;
	}
	head = sorted;
}

int main() {
	build_list_from_file("harry.txt");	// (1)
	print_words();

	remove_low_freq(10);				// (2)
	print_words();

	sort_by_freq_then_lex();			// (3)	
	print_words();

	return 0;
}