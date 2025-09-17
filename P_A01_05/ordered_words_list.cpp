#include <iostream>      // ǥ�� �����
#include <fstream>       // ���� �����
#include <string>        // std::string
#include <unordered_map> // �ܾ� -> �� �ؽø�
#include <vector>        // ������ ���� Ű ����
#include <algorithm>     // std::sort
#include <cctype>		 // std::isalpha, std::isdigit

using namespace std;

/*
 * ���� 5 �䱸����:
 * 1) input4.txt���� �������� ��ū�� �и��Ѵ�.
 * 2) �� ��ū�� "�յ�"�� ���� Ư�����ڿ� ���ڸ� �����Ѵ�.
 *    - ������ Ư������/���ڴ� ����(��: "co-operate", "x2y"�� ���� ����)
 *    - ���Ŵ� "��"�� "��"������ �����Ѵ�(Ʈ����).
 * 3) Ʈ���� �� ���̰� 2 �̻��� �ܾ �����Ѵ�.
 * 4) ��ҹ��� ����(�빮��/�ҹ��� �����Ͽ� ���� �ٸ� �ܾ�).
 * 5) ������(ASCII) ������������ �����Ͽ� "�ܾ� ��" ���.
 *    - ASCII �������� �빮�ڰ� �ҹ��ں��� �ռ���.
 * 6) (���� ����) �� �ܾ� �� �� 1000, �� �ܾ� ���� �� 20.
 */

 // �糡���� ���ĺ��� �ƴ� ���� (= Ư������/���� ����)�� �����ϴ� �Լ�
static string trim_edges_nonalpha(const string& s) {
	if (s.empty()) return "";

	// ���ʿ������� ������ ���ĺ� ��ġ 1 Ž��
	size_t l = 0, r = s.size();
	while (l < r && !std::isalpha(static_cast<unsigned char>(s[l]))) {
		++l;
	}
	// �����ʿ������� ������ ���ĺ� ��ġ r-1 Ž��
	while (r > l && !std::isalpha(static_cast<unsigned char>(s[r - 1]))) {
		--r;
	}
	// l >= r �̸� ���ĺ��� �ϳ��� ���ٴ� �� -> �� ���ڿ�
	if (l >= r) return "";

	return s.substr(l, r - l);
}

int main() {
	ios::sync_with_stdio(false);	// C ǥ�� ����°� ����ȭ ����
	cin.tie(nullptr);				// ����� �ӵ� ���

	// 1) �Է� ���� ����
	ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
	if (!fin) {
		cerr << "Couldn't read the file" << endl;
		return 1;
	}

	// 2) �ܾ� �� �ؽø�
	unordered_map<string, int> freq;	// �ܾ� -> ��

	// 3) ���� �������� ��ū�� �а�, �յ� Ư������/���� ���� �� ���� �˻�
	string token;
	while (fin >> token) {
		string w = trim_edges_nonalpha(token); // ��/�� Ư�����ڡ����� ����
		if (w.size() >= 2) {
			++freq[w];         
		}
	}
	fin.close();

	// 4) Ű(�ܾ�)�� ��Ƽ� ����
	vector<string> words;
	words.reserve(freq.size());
	for (const auto& kv : freq) words.push_back(kv.first);

	// ASCII ������ �������� ���� (�빮�� < �ҹ���)
	sort(words.begin(), words.end());

	// 5) ���: "�ܾ� ��" ����
	for (const string& w : words) {
		cout << w << ' ' << freq[w] << '\n';
	}

	return 0; 
}