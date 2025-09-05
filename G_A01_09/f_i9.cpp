#include <iostream>
#include <string>

int main() {
	std::string str("Test string");				// std::string 객체를 생성하고, 문자열의 길이만큼 반복합니다.
	for(unsigned i = 0; i < str.length(); ++i)	// str.at(i)로 각 문자를 출력합니다.
		std::cout << str.at(i);					// at()는 인덱스 범위를 벗어나면 예외(std::out_of_range)를 발생시킵니다.
	return 0;
}

// •	at()는 안전하지만 약간 느릴 수 있습니다(예외 검사 때문).
// •	operator[]는 빠르지만 실수로 범위를 벗어나면 버그가 발생할 수 있습니다.