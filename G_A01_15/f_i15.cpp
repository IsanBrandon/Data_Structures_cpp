#include <iostream>
#include <string>

int main() {
	std::string str("hello world!");
	str.pop_back();			// str�� ������ ����('d')�� ����ϴ�. (���: str = "hello worl")
	std::cout << str << '\n';
	return 0; 
}