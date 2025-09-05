#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string s1 = "hello";
	std::string s2 = "world";
	std::string s3 = "hello";

	if (s1 == s3) {
		std::cout << "s1 and s3 are equal." << std::endl;
	}
	if (s1 < s2) {
		std::cout << "s1 comes before s2 lexicographically." << std::endl;	// 사전식 순서
	}
	return 0;
}