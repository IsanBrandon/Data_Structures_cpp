#include <iostream>
#include <fstream>
using namespace std;

int N;
int K;
int a[1000];

int floorRec(int l, int r, int K) {
	if (l > r) return -1; 
	int m = (l + r) / 2; 
	if (a[m] > K) return floorRec(l, m - 1, K);
	int t = floorRec(m + 1, r, K);
	return (t == -1 ? a[m] : t);
}

int ceilRec(int l, int r, int K) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (a[m] < K) return ceilRec(m + 1, r, K);
	int t = ceilRec(l, m - 1, K);
	return (t == -1 ? a[m] : t);
}

int main() {
	ifstream fin("input.txt");   // input.txt 파일에서 입력 받는다고 가정

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	cin >> K;

	cout << floorRec(0, N - 1, K) << "\n";
	cout << ceilRec(0, N - 1, K) << "\n";
	return 0;
}



