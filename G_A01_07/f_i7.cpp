#include <iostream>
#include <string>						// std::string�� ����� ���� �ݵ�� <string> ����� �����ؾ� �մϴ�.

int main() {							// std::string�� C++ ǥ�� ���̺귯������ �����ϴ� ���ڿ� Ŭ�����Դϴ�.
	std::string str("Test string");		// "Test string"�̶�� ���ͷ��� �̿��� ���ڿ� ��ü str�� �����մϴ�.
	std::cout << str.size() << "\n";	// str.size()�� ���ڿ��� ���̸� ��ȯ�մϴ�. ���⼭�� 11�� ��µ˴ϴ�.
	return 0;							// main �Լ��� 0�� ��ȯ�ϸ�, ���α׷��� ���������� ����Ǿ����� �ü���� �˸��ϴ�.
}