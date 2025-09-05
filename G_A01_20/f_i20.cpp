#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "We think in generalities, but we live in details.";
	string str2 = str.substr(3, 5);			// str의 3번째 인덱스부터 5글자("think")를 잘라내어 str2에 저장합니다.
	size_t pos = str.find("live");			// str에서 "live"가 처음 등장하는 위치(인덱스)를 찾습니다.
	string str3 = str.substr(pos);			// pos부터 끝까지("live in details.")를 잘라내어 str3에 저장합니다.
	cout << str2 << ' ' << str3 << '\n';	// 출력: think live in details.

	return 0;
}