#include <iostream>      // 표준 입출력
#include <fstream>       // 파일 입출력
#include <string>        // std::string
#include <unordered_map> // 단어 -> 빈도 해시맵
#include <vector>        // 정렬을 위한 키 모음
#include <algorithm>     // std::sort
#include <cctype>		 // std::isalpha, std::isdigit

using namespace std;

/*
 * 과제 5 요구사항:
 * 1) input4.txt에서 공백으로 토큰을 분리한다.
 * 2) 각 토큰의 "앞뒤"에 붙은 특수문자와 숫자를 제거한다.
 *    - 내부의 특수문자/숫자는 보존(예: "co-operate", "x2y"는 내부 유지)
 *    - 제거는 "앞"과 "뒤"에서만 수행한다(트리밍).
 * 3) 트리밍 후 길이가 2 이상인 단어만 집계한다.
 * 4) 대소문자 구분(대문자/소문자 구별하여 서로 다른 단어).
 * 5) 사전식(ASCII) 오름차순으로 정렬하여 "단어 빈도" 출력.
 *    - ASCII 기준으로 대문자가 소문자보다 앞선다.
 * 6) (문제 보장) 총 단어 수 ≤ 1000, 각 단어 길이 ≤ 20.
 */

 // 양끝에서 알파벳이 아닌 문자 (= 특수문자/숫자 포함)를 제거하는 함수
static string trim_edges_nonalpha(const string& s) {
	if (s.empty()) return "";

	// 왼쪽에서부터 최초의 알파벳 위치 1 탐색
	size_t l = 0, r = s.size();
	while (l < r && !std::isalpha(static_cast<unsigned char>(s[l]))) {
		++l;
	}
	// 오른쪽에서부터 최초의 알파벳 위치 r-1 탐색
	while (r > l && !std::isalpha(static_cast<unsigned char>(s[r - 1]))) {
		--r;
	}
	// l >= r 이면 알파벳이 하나도 없다는 뜻 -> 빈 문자열
	if (l >= r) return "";

	return s.substr(l, r - l);
}

int main() {
	ios::sync_with_stdio(false);	// C 표준 입출력과 동기화 해제
	cin.tie(nullptr);				// 입출력 속도 향상

	// 1) 입력 파일 열기
	ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
	if (!fin) {
		cerr << "Couldn't read the file" << endl;
		return 1;
	}

	// 2) 단어 빈도 해시맵
	unordered_map<string, int> freq;	// 단어 -> 빈도

	// 3) 공백 기준으로 토큰을 읽고, 앞뒤 특수문자/숫자 제거 후 길이 검사
	string token;
	while (fin >> token) {
		string w = trim_edges_nonalpha(token); // 앞/뒤 특수문자·숫자 제거
		if (w.size() >= 2) {
			++freq[w];         
		}
	}
	fin.close();

	// 4) 키(단어)만 모아서 정렬
	vector<string> words;
	words.reserve(freq.size());
	for (const auto& kv : freq) words.push_back(kv.first);

	// ASCII 사전식 오름차순 정렬 (대문자 < 소문자)
	sort(words.begin(), words.end());

	// 5) 출력: "단어 빈도" 형식
	for (const string& w : words) {
		cout << w << ' ' << freq[w] << '\n';
	}

	return 0; 
}