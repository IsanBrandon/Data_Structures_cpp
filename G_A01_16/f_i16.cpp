#define _CRT_SECURE_NO_WARNINGS					// Visual Studio���� strtok �Լ� ��� �� ���� ��� �����ϱ� ���� ��ũ���Դϴ�.
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string str("Please split this sentence into tokens");

	char* cstr = new char[str.length() + 1];	// +1�� null ����('\0')�� ���� �����Դϴ�. new �����ڸ� ����Ͽ� ���� �Ҵ��մϴ�.
	strcpy(cstr, str.c_str());					// string�� C ��Ÿ�� ���ڿ��� �����մϴ�. (c_str() �Լ��� string�� C ��Ÿ�� ���ڿ��� ��ȯ�մϴ�.)
	
	char* p = std::strtok(cstr, " ");			// std::strtok �Լ��� ù ��° ���ڷ� ó���� ���ڿ���, �� ��° ���ڷ� ������(delimiter)�� �޽��ϴ�. ���⼭�� ���� ���ڸ� �����ڷ� ����մϴ�.
												// strtok �Լ��� ù ��° ȣ�⿡�� ���ڿ��� ó������ �����Ͽ� �����ڸ� ������ �������� �κ� ���ڿ��� ��ȯ�մϴ�.
												// ���� ȣ�⿡���� ù ��° ���ڷ� NULL�� �־� ������ ó���ϴ� ���ڿ��� ������ �κ��� ��� ó���մϴ�.
	while (p != 0) {
		cout << p << '\n';
		p = std::strtok(NULL, " ");				// NULL�� ù ��° ���ڷ� �ָ� ������ ó���ϴ� ���ڿ��� ������ �κ��� ��� ó���մϴ�.
	}

	delete[] cstr;								// ���� �Ҵ��� �޸𸮸� �����մϴ�.
	return 0;
}