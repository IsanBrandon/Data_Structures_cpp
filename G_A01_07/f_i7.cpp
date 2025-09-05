#include <iostream>
#include <string>						// std::string을 사용할 때는 반드시 <string> 헤더를 포함해야 합니다.

int main() {							// std::string은 C++ 표준 라이브러리에서 제공하는 문자열 클래스입니다.
	std::string str("Test string");		// "Test string"이라는 리터럴을 이용해 문자열 객체 str을 생성합니다.
	std::cout << str.size() << "\n";	// str.size()는 문자열의 길이를 반환합니다. 여기서는 11이 출력됩니다.
	return 0;							// main 함수가 0을 반환하면, 프로그램이 정상적으로 종료되었음을 운영체제에 알립니다.
}