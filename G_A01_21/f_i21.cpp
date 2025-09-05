#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 ("green apple");
	string str2 ("red apple");

	if (str1.compare(str2) != 0)							// str1과 str2를 비교합니다. 같지 않으면 0이 아닌 값을 반환합니다.
		cout << str1 << " is not " << str2 << '\n';

	if (str1.compare(6, 5, "apple") == 0)					// str1의 6번째 인덱스부터 5글자("apple")와 "apple"을 비교합니다.
		cout << "still, " << str1 << " is an apple.\n";

	if (str2.compare(str2.size() - 5, 5, "apple") == 0)		// str2의 끝에서 5글자("apple")와 "apple"을 비교합니다.
		cout << "and, " << str2 << " is also an apple.\n";

	if (str1.compare(6, 5, str2, 4, 5) == 0)				// str1의 6번째 인덱스부터 5글자("apple")와 str2의 4번째 인덱스부터 5글자("apple")를 비교합니다.
		cout << "therefore, both are apples.\n";

	return 0;
}