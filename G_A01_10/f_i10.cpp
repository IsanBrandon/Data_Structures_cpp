#include <iostream>
#include <string>

int main() {
	std::string name("John");
	std::string family("Smith");
	name += " K. ";
	name += family;					// name = name + family; �� ����
	name += '\n';			

	std::cout << name;
	return 0;
}