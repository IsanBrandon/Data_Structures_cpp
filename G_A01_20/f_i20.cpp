#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "We think in generalities, but we live in details.";
	string str2 = str.substr(3, 5);			// str�� 3��° �ε������� 5����("think")�� �߶󳻾� str2�� �����մϴ�.
	size_t pos = str.find("live");			// str���� "live"�� ó�� �����ϴ� ��ġ(�ε���)�� ã���ϴ�.
	string str3 = str.substr(pos);			// pos���� ������("live in details.")�� �߶󳻾� str3�� �����մϴ�.
	cout << str2 << ' ' << str3 << '\n';	// ���: think live in details.

	return 0;
}