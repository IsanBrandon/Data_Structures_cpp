#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "This is a test string.";
	string str2 = "n example";
	string str3 = "sample phrase";

	str.replace(9, 5, str2);			// str�� 9��° �ε���(0���� ����) ��ġ���� 5����("test ")�� str2("n example")�� �ٲߴϴ�. (���: str = "This is an example string.")
	cout << str << '\n';

	str.replace(str.begin(), str.end() - 3, str3); // str�� ó������ ������ 3��° �ε��� ��ġ ������("This is an example str")�� str3("sample phrase")�� �ٲߴϴ�. (���: str = "sample phraseing.")
	cout << str << '\n';

	return 0;
}