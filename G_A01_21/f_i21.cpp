#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 ("green apple");
	string str2 ("red apple");

	if (str1.compare(str2) != 0)							// str1�� str2�� ���մϴ�. ���� ������ 0�� �ƴ� ���� ��ȯ�մϴ�.
		cout << str1 << " is not " << str2 << '\n';

	if (str1.compare(6, 5, "apple") == 0)					// str1�� 6��° �ε������� 5����("apple")�� "apple"�� ���մϴ�.
		cout << "still, " << str1 << " is an apple.\n";

	if (str2.compare(str2.size() - 5, 5, "apple") == 0)		// str2�� ������ 5����("apple")�� "apple"�� ���մϴ�.
		cout << "and, " << str2 << " is also an apple.\n";

	if (str1.compare(6, 5, str2, 4, 5) == 0)				// str1�� 6��° �ε������� 5����("apple")�� str2�� 4��° �ε������� 5����("apple")�� ���մϴ�.
		cout << "therefore, both are apples.\n";

	return 0;
}