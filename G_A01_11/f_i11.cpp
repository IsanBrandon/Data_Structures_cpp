#include <iostream>
#include <string>

int main() {
	std::string str;
	std::string str2 = "Writing";
	std::string str3 = "print 10 and then 5 more";

	str.append(str2);					// str에 str2("Writing")을 덧붙입니다. (결과 : str = "Writing")
	str.append(str3, 6, 3);				// str3의 6번째 인덱스(0부터 시작)부터 3글자만큼을 str에 덧붙입니다. (결과: str = "Writing10 dots ")
	str.append("dots are cool", 5);		// "dots are cool" 문자열의 앞에서부터 5글자("dots ")를 str에 덧붙입니다. (결과: str = "Writing10 dots ")

	std::cout << str << '\n';
	return 0;
}

// •	append("dots are cool", 5)처럼 리터럴 문자열도 부분적으로 덧붙일 수 있습니다.