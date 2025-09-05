#include <iostream>
#include <string>

int main() {
	std::string str("This is an example sentence.");
	std::cout << str << '\n';

	str.erase(10, 8);				// str�� 10��° �ε���(0���� ����) ��ġ���� 8����("example ")�� ����ϴ�. (���: str = "This is an sentence.")
	std::cout << str << '\n';

	str.erase(str.begin() + 9);		// str�� 9��° �ε���(0���� ����) ��ġ�� �ִ� ����('s')�� ����ϴ�. (���: str = "This is an entence.")
	std::cout << str << '\n';

	str.erase(str.begin() + 5, str.end() - 9); // str�� 5��° �ε���(0���� ����) ��ġ���� ������ 9��° �ε��� ��ġ ������("an ")�� ����ϴ�. (���: str = "This is entence.")
	std::cout << str << '\n';

	return 0;
}