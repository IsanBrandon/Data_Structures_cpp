#include <iostream>
#include <string>

int main() {
	std::string str("This is an example sentence.");
	std::cout << str << '\n';

	str.erase(10, 8);				// str의 10번째 인덱스(0부터 시작) 위치부터 8글자("example ")를 지웁니다. (결과: str = "This is an sentence.")
	std::cout << str << '\n';

	str.erase(str.begin() + 9);		// str의 9번째 인덱스(0부터 시작) 위치에 있는 글자('s')를 지웁니다. (결과: str = "This is an entence.")
	std::cout << str << '\n';

	str.erase(str.begin() + 5, str.end() - 9); // str의 5번째 인덱스(0부터 시작) 위치부터 끝에서 9번째 인덱스 위치 전까지("an ")를 지웁니다. (결과: str = "This is entence.")
	std::cout << str << '\n';

	return 0;
}