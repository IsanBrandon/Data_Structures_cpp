#include <iostream>
#include <string>

int main() {
	std::string str = "to be question";
	std::string str2 = "the ";
	str.insert(6, str2);					// str의 6번째 인덱스(0부터 시작) 위치에 str2("the ")를 삽입합니다. (결과: str = "to be the question")

	std::cout << str << '\n';
	return 0;
}