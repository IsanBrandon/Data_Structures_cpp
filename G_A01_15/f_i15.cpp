#include <iostream>
#include <string>

int main() {
	std::string str("hello world!");
	str.pop_back();			// str의 마지막 글자('d')를 지웁니다. (결과: str = "hello worl")
	std::cout << str << '\n';
	return 0; 
}