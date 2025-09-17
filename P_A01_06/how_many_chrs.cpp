#include <iostream>      // std::cout, std::cin
#include <string>        // std::string, std::getline
#include <cctype>		 // std::isspace 
using namespace std;

/*
 * ���ڿ����� "�ܾ� ����"�� ���� �Լ� 
 * - �ܾ�: ������ �ƴ� ���ڰ� ���ӵ� ����
 * - ����: isspace(c)�� true�� ���� (�����׽�, �� �� ��� ����)
 */

int count_words(const string& s) {
	int count = 0;
	bool in_word = false; // ���� �ܾ� ���ο� �ִ��� ����

	for (unsigned char ch : s) {
		if (!isspace(ch)) {
			if (!in_word) {
				in_word = true; // �ܾ� ����
				++count;        // �ܾ� ���� ����
			}
		}
		else {
			in_word = false;    // ���� -> �ܾ� ���� 
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);	// C ǥ�� ����°� ����ȭ ����
	cin.tie(nullptr);				// ����� �ӵ� ���

	string line;

	while (true) {
		// 1) ������Ʈ ���
		cout << "$ ";

		// 2) �� �� �Է� (���� ����)
		if (!getline(cin, line)) { // EOF or error
			break;	// �Է� ��Ʈ���� ������ ����
		}

		// 3) ���� ���� : ��Ȯ�� "exit" �Է� �� ����
		if (line == "exit") {
			break;
		}

		// 4) ���� = ���ڿ� ��ü ���� (getline�� ������ ����)
		size_t length = line.size();

		// 5) �ܾ� ���� ���
		int words = count_words(line);

		// 6) ��� -> ������:����:�ܾ��
		cout << line << ":" << length << ":" << words << "\n";
	}

	return 0;
}