#include <iostream>
#include <string>

int main() {
	std::string str = "to be question";
	std::string str2 = "the ";
	str.insert(6, str2);					// str�� 6��° �ε���(0���� ����) ��ġ�� str2("the ")�� �����մϴ�. (���: str = "to be the question")

	std::cout << str << '\n';
	return 0;
}