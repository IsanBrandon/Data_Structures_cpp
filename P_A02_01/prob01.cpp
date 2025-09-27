#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	// sort, find
using namespace std;

int main() {
	vector<string> words;
	string input;

	while (true) {
		cout << "Enter a word: ";		// ������Ʈ ���
		cin >> input;					// �� �ܾ� �Է� 
		if (input == "exit") break;

		auto it = find(words.begin(), words.end(), input);	
		// find�� iterator Ÿ���� ���� ��ȯ�ϴ� �Լ�
		// input�� ��ġ�ϴ� �ܾ ã����,		return �ش� ���Ҹ� ����Ű�� iterator
		// input�� ��ġ�ϴ� �ܾ ã�� ���ϸ�, return last index
		
		if (it != words.end()) words.erase(it);
		else words.push_back(input);

		sort(words.begin(), words.end());	// �������� (������) ����

		for (auto& w : words) cout << w << " ";
		cout << endl;
	}

	return 0;
}