#include <iostream>      // std::cout, std::cin
#include <string>        // std::string, std::getline
#include <cctype>		 // std::isspace 
using namespace std;

/*
 * 문자열에서 "단어 개수"를 세는 함수 
 * - 단어: 공백이 아닌 문자가 연속된 구간
 * - 공백: isspace(c)가 true인 문자 (스페잉스, 탭 등 모두 포함)
 */

int count_words(const string& s) {
	int count = 0;
	bool in_word = false; // 현재 단어 내부에 있는지 여부

	for (unsigned char ch : s) {
		if (!isspace(ch)) {
			if (!in_word) {
				in_word = true; // 단어 시작
				++count;        // 단어 개수 증가
			}
		}
		else {
			in_word = false;    // 공백 -> 단어 종료 
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);	// C 표준 입출력과 동기화 해제
	cin.tie(nullptr);				// 입출력 속도 향상

	string line;

	while (true) {
		// 1) 프롬프트 출력
		cout << "$ ";

		// 2) 한 줄 입력 (공백 포함)
		if (!getline(cin, line)) { // EOF or error
			break;	// 입력 스트림이 끝나면 종료
		}

		// 3) 종료 조건 : 정확히 "exit" 입력 시 종료
		if (line == "exit") {
			break;
		}

		// 4) 길이 = 문자열 전체 길이 (getline은 개행은 제외)
		size_t length = line.size();

		// 5) 단어 개수 계산
		int words = count_words(line);

		// 6) 출력 -> 원문장:길이:단어수
		cout << line << ":" << length << ":" << words << "\n";
	}

	return 0;
}