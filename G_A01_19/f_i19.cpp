#include <iostream>
#include <string>
using namespace std;

int main() {
	string str ("Please replace the vowels in this sentence by asterisks.");
	size_t found = str.find_first_of("aeiou");			// •	find_first_of 함수는 str에서 "aeiou" 중 하나가 처음 등장하는 위치(인덱스)를 반환합니다.
														// •	만약 모음이 없다면 string::npos를 반환합니다.
	while (found != string::npos) {						// •	found가 유효한 위치일 때 반복합니다.
		str[found] = '*';								// •	해당 위치의 문자를 *로 바꿉니다.
		found = str.find_first_of("aeiou", found+1);	// •	다음 모음의 위치를 찾기 위해 found+1부터 다시 검색합니다.
	}

	cout << str << '\n';					
	return 0;
}

// •	대문자 모음(A, E, I, O, U)은 바뀌지 않습니다.
// •	한글이나 특수문자는 영향을 받지 않습니다.