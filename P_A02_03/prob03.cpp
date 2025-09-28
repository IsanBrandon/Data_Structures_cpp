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
	// s: 앞쪽에서부터 처음으로 공백이 아닌 문자의 인덱스를 찾기 위한 포인터
	// t: 뒤쪽에서부터 처음으로 공백이 아닌 문자의 인덱스를 찾기 위한 포인터 (마지막 문자에서 시작)
	while (s < str.length() && isspace(str[s])) s++;
	// 왼쪽에서 공백을 모두 건너뜀. 종료 시점에는 s는 첫 비공백 문자를 가리킴
	while (t >= 0 && isspace(str[t])) t--;
	// 오른쪽에서 공백을 모두 건너뜀. 종료시점에는 t는 마지막 비공백 문자를 가리킴
	if (s <= t) return str.substr(s, t - s + 1);
	// std::string::substr(pos, count)는 pos부터 count개 문자를 복사한 새 문자열을 반환
	// 길이는 [s, t]이므로 t - s + 1
	else return "";
	// 전부 공백이거나 빈 문자열이면 "" 반환
}

// 토큰 양끝의 비문자 제거(알파벳만 남기기)
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

// 선형 탐색으로 단어 찾기 (없으면 -1)
int find_word_index(const string& key) {
	for (int i = 0; i < (int)directory.size(); ++i) {
		if (directory[i].letters == key) return i;
	}
	return -1;
}

void print_word(Word& w) {
	cout << w.letters << ": " << w.description << endl;
}

// 이미 출력했는지 확인 (중복 방지용)
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

	// 1) 질의어 먼저 출력
	print_word(directory[idx]);

	// 2) 설명에서 길이>=3 단어들을 등장 순서대로 재검색, 중복 없이 출력
	vector<string> printed;
	printed.push_back(directory[idx].letters); // 질의어는 다시 출력하지 않음

	// 공백 기준 분리 (여러 공백이 있으면 빈 토큰이 나올 수 있어 필터링)
	vector<string> tokens = split_line(directory[idx].description, ' ');
	for (int i = 0; i < (int)tokens.size(); ++i) {
		if (tokens[i].empty()) continue;
		string t = strip_edges_letters(tokens[i]); // 양끝 기호 제거
		if ((int)t.size() < 3) continue;          // 길이 3 미만 제외
		if (contains(printed, t)) continue;       // 중복 제외

		int j = find_word_index(t);
		if (j != -1) {
			print_word(directory[j]);
			printed.push_back(t);
		}
	}
	return 0;
}