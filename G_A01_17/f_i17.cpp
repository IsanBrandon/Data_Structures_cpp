#include <iostream>
#include <string>
using namespace std;

int main() {
	string str("There are two needles with needles.");
	string str2("needle");

	size_t found = str.find(str2);		// str에서 str2("needle")이 처음 등장하는 위치(인덱스)를 반환합니다.  
										// 반환값은 size_t 타입(부호 없는 정수)이며, 찾지 못하면 string::npos를 반환합니다. 
	if (found != string::npos)			// 만약 "needle"이 존재한다면, 그 위치(인덱스)를 출력합니다. 
		cout << found << '\n';			// 예시 문자열에서는 "needle"이 14번째 인덱스(0부터 시작)에 있습니다. 

	found = str.find("needles are small", found + 1, 6);	// "needles are small"의 앞 6글자("needle")를, 이전에 찾은 위치 다음(found + 1)부터 다시 검색합니다.
	if (found != string::npos)								// 즉, 두 번째 "needle"을 찾는 과정입니다.
		cout << found << '\n';								// 예시에서는 두 번째 "needle"이 30번째 인덱스에 있습니다.

	str.replace(str.find(str2), str2.length(),				// str에서 첫 번째 "needle"을 찾아 "preposition"으로 바꿉니다.
				"preposition");								// str.find(str2)로 위치를 찾고, str2.length()만큼의 길이를 "preposition"으로 대체합니다.
	cout << str << '\n';									// 결과: "There are two prepositions with needles."

	return 0;
}

// •	find 함수의 세 번째 인자(부분 문자열 길이)를 활용하면, 긴 문자열에서 일부만 검색할 수 있습니다. 
// •	replace는 첫 번째로 찾은 부분만 바꿉니다.여러 부분을 바꾸려면 반복문이 필요합니다. 