#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* �Է� ����: ������ ���� �ҹ��ڷθ� ����. �������� ��ūȭ�ϸ� �� ��
 * �߿� ����:
	-> ���Ͽ��� �д� ��� ���Ḯ��Ʈ�� �ݿ� (�迭�� ��ٵ״ٰ� ���߿� ����)
	-> �ߺ� ���� ����Ʈ ���� (�̹� �ִ� �ܾ�� cnt++��, �� �ܾ�� ����)
	(1) ������ ������������ �׻� ���� ���� ���� (���� �� ��ġ ã�� �ֱ�)
	(2) ���� �� <= 10�� ��� ���� (���Ḹ �ٲٰ� delete)
	(3) (2)�� ��� ����Ʈ�� ���� �� ��������, ������ ���������� ������
		-> ��带 �ϳ��� ���� �� ����Ʈ�� �����ϴ� ������� ����
*/

struct WordNode {
	string word;
	int cnt;
	WordNode* next;
};

WordNode* head = nullptr;

void insert_or_increment(const string& w) {
	if (!head || w < head->word) { // �� �� ó��
		head = new WordNode{ w, 1, head };
		return;
	}
	WordNode* prev = head;
	WordNode* curr = head->next;

	while (curr && curr->word < w) {
		prev = curr; curr = curr->next;
	}

	if (curr && curr->word == w) {	// curr�� ���� �ܾ�� ++
		curr->cnt++;
	}
	else if (prev->word == w) {		// head�� ���� �ܾ�� ���⼭ ++
		prev->cnt++;				// ���� �ܾ��� ���� while ���� 0ȸ �����̶� 
	}								// prev�� head�� �ӹ���
	else {							
		prev->next = new WordNode{ w, 1, curr };	// ���� or �ǵ� ����
	}
}

void build_list_from_file(const string& filename) {	// ���� filename�� �������� �ʰ� const�� ������ ���
	ifstream fin(filename);
	if (!fin) { cerr << "cannot open\n"; return; }
	string w;
	while (fin >> w) insert_or_increment(w);	// 'fin >> w'�� ���� ������: �Է� ��Ʈ�� fin���� ��ū �ϳ��� �о� w�� ����
												// �б� ���� ��	true, ����(�� ���� �� ������) �� false ��ȯ
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
	if (a->cnt != b->cnt) return a->cnt > b->cnt;	// �� ū �󵵰� �տ� ������
	return a->word < b->word;
}

void sort_by_freq_then_lex() {
	WordNode* sorted = nullptr;	// ���ĵ� �� ����Ʈ�� ���
	WordNode* curr = head;		// ���� ���ĵ��� ���� ���� ����Ʈ���� ���� ������ ���
	while (curr) {
		WordNode* nxt = curr->next;	// curr�� ���� ��带 �̸� ������ �δ� �ӽ� ������
									// curr�� sorted�� ������ ���̹Ƿ� curr->next�� �ٲ� ����
		if (!sorted || is_before(curr, sorted)) {	// sorted�� curr ���� ��ġ ã��
			// sorted�� ����ų�, curr�� �� ���̾�� �ϴ� ���
			curr->next = sorted;
			sorted = curr;
		}
		else {	// �� �ܿ� sorted�� �տ������� ��ȸ�ϸ� ���� ���� ã�� 
			WordNode* p = sorted;
			while (p->next && !is_before(curr, p->next)) p = p->next;
			curr->next = p->next;	// p ���� ��ġ�� �����
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