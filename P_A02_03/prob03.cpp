#include <iostream>  
#include <fstream>
#include <sstream>
#include <string>	
#include <vector>
#include <cctype>
#include <cassert>
using namespace std;

struct Word {
	string letters, description;
};

vector<Word> directory;

vector<string> split_line(string& line, char delimiter) {
	vector<string> tokens;
	stringstream sstream(line);
	string str;
	while (getline(sstream, str, delimiter)) tokens.push_back(str);
	return tokens;
}

string trim(string str) {
	int s = 0, t = str.length() - 1;
	// s: ���ʿ������� ó������ ������ �ƴ� ������ �ε����� ã�� ���� ������
	// t: ���ʿ������� ó������ ������ �ƴ� ������ �ε����� ã�� ���� ������ (������ ���ڿ��� ����)
	while (s < str.length() && isspace(str[s])) s++;
	// ���ʿ��� ������ ��� �ǳʶ�. ���� �������� s�� ù ����� ���ڸ� ����Ŵ
	while (t >= 0 && isspace(str[t])) t--;
	// �����ʿ��� ������ ��� �ǳʶ�. ����������� t�� ������ ����� ���ڸ� ����Ŵ
	if (s <= t) return str.substr(s, t - s + 1);
	// std::string::substr(pos, count)�� pos���� count�� ���ڸ� ������ �� ���ڿ��� ��ȯ
	// ���̴� [s, t]�̹Ƿ� t - s + 1
	else return "";
	// ���� �����̰ų� �� ���ڿ��̸� "" ��ȯ
}

// ��ū �糡�� ���� ����(���ĺ��� �����)
string strip_edges_letters(const string& tok) {
	int a = 0, b = (int)tok.size() - 1;
	while (a <= b && !isalpha(tok[a])) ++a;
	while (b >= a && !isalpha(tok[b])) --b;
	if (a > b) return "";
	return tok.substr(a, b - a + 1);
}

void load_data(string file_name) {
	ifstream infile(file_name);	// fopen
	if (!infile) {
		cerr << "Failed to open: " << file_name << "\n";
		return;
	}

	string line;
	while (getline(infile, line)) {
		vector<string> tokens = split_line(line, '\t');

		Word w;
		w.letters = tokens.at(0);
		w.description = tokens.at(1);
		directory.push_back(w);
	}
	infile.close();
}

// ���� Ž������ �ܾ� ã�� (������ -1)
int find_word_index(const string& key) {
	for (int i = 0; i < (int)directory.size(); ++i) {
		if (directory[i].letters == key) return i;
	}
	return -1;
}

void print_word(Word& w) {
	cout << w.letters << ": " << w.description << endl;
}

// �̹� ����ߴ��� Ȯ�� (�ߺ� ������)
bool contains(const vector<string>& v, const string& s) {
	for (int i = 0; i < (int)v.size(); ++i)
		if (v[i] == s) return true;
	return false;
}

void list_directory() {
	for (auto& word : directory) {
		print_word(word);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	load_data("shuffled_dict.txt");

	string finding_word;
	if (!getline(cin, finding_word)) return 0;
	string name = trim(finding_word);

	int idx = find_word_index(name);
	if (idx == -1) return 0;

	// 1) ���Ǿ� ���� ���
	print_word(directory[idx]);

	// 2) ������ ����>=3 �ܾ���� ���� ������� ��˻�, �ߺ� ���� ���
	vector<string> printed;
	printed.push_back(directory[idx].letters); // ���Ǿ�� �ٽ� ������� ����

	// ���� ���� �и� (���� ������ ������ �� ��ū�� ���� �� �־� ���͸�)
	vector<string> tokens = split_line(directory[idx].description, ' ');
	for (int i = 0; i < (int)tokens.size(); ++i) {
		if (tokens[i].empty()) continue;
		string t = strip_edges_letters(tokens[i]); // �糡 ��ȣ ����
		if ((int)t.size() < 3) continue;          // ���� 3 �̸� ����
		if (contains(printed, t)) continue;       // �ߺ� ����

		int j = find_word_index(t);
		if (j != -1) {
			print_word(directory[j]);
			printed.push_back(t);
		}
	}
	return 0;
}