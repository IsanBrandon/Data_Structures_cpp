#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	// sort, find
using namespace std;

int main() {
	vector<string> words;
	string input;

	while (true) {
		cout << "Enter a word: ";		// 프롬프트 출력
		cin >> input;					// 한 단어 입력 
		if (input == "exit") break;

		auto it = find(words.begin(), words.end(), input);	
		// find는 iterator 타입의 값을 반환하는 함수
		// input과 일치하는 단어를 찾으면,		return 해당 원소를 가리키는 iterator
		// input과 일치하는 단어를 찾지 못하면, return last index
		
		if (it != words.end()) words.erase(it);
		else words.push_back(input);

		sort(words.begin(), words.end());	// 오름차순 (사전순) 정렬

		for (auto& w : words) cout << w << " ";
		cout << endl;
	}

	return 0;
}