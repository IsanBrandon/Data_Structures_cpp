#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "This is a test string.";
	string str2 = "n example";
	string str3 = "sample phrase";

	str.replace(9, 5, str2);			// str의 9번째 인덱스(0부터 시작) 위치부터 5글자("test ")를 str2("n example")로 바꿉니다. (결과: str = "This is an example string.")
	cout << str << '\n';

	str.replace(str.begin(), str.end() - 3, str3); // str의 처음부터 끝에서 3번째 인덱스 위치 전까지("This is an example str")를 str3("sample phrase")로 바꿉니다. (결과: str = "sample phraseing.")
	cout << str << '\n';

	return 0;
}