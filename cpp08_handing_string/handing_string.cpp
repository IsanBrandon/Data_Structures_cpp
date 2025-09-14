#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2, str3;

	cin >> str1 >> str2; // read two words (separated by whitespace)

	str3 = str1;
	cout << "str3: " << str3 << endl;

	str3 = str1 + " " + str2;
	cout << "str1 + str2: " << str3 << endl;

	int len = str3.length();
	cout << "length of str3: " << len << endl;

	string str4 = "hello";
	if (str1 == str4)				// or, if (str1.compare(str4) == 0)
		cout << "Same" << endl;
	else if (str1 < str4)
		cout << "Str1 first" << endl;
	else
		cout << "Str2 first" << endl; 

	return 0;
}