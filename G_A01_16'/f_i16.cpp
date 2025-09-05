#define _CRT_SECURE_NO_WARNINGS					// Visual Studio에서 strtok 함수 사용 시 보안 경고를 무시하기 위한 매크로입니다.
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string str("Please split this sentence into tokens");

	char* cstr = new char[str.length() + 1];	// +1은 null 문자('\0')를 위한 공간입니다. new 연산자를 사용하여 동적 할당합니다.
	strcpy(cstr, str.c_str());					// string을 C 스타일 문자열로 복사합니다. (c_str() 함수는 string을 C 스타일 문자열로 변환합니다.)
	
	char* p = std::strtok(cstr, " ");			// std::strtok 함수는 첫 번째 인자로 처리할 문자열을, 두 번째 인자로 구분자(delimiter)를 받습니다. 여기서는 공백 문자를 구분자로 사용합니다.
												// strtok 함수는 첫 번째 호출에서 문자열의 처음부터 시작하여 구분자를 만나기 전까지의 부분 문자열을 반환합니다.
												// 이후 호출에서는 첫 번째 인자로 NULL을 주어 이전에 처리하던 문자열의 나머지 부분을 계속 처리합니다.
	while (p != 0) {
		cout << p << '\n';
		p = std::strtok(NULL, " ");				// NULL을 첫 번째 인자로 주면 이전에 처리하던 문자열의 나머지 부분을 계속 처리합니다.
	}

	delete[] cstr;								// 동적 할당한 메모리를 해제합니다.
	return 0;
}