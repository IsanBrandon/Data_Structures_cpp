#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) { // read a line from standard input
		cout << line << ":" << line.length() << endl;
	}
	return 0;
}