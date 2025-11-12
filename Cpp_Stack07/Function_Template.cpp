#include <iostream>
#include <string>
using namespace std;

int compare(string& v1, string& v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int compare(double& v1, double& v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int compare(int& v1, int& v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

template <typename T>
int compare()