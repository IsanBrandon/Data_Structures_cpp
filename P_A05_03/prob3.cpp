//int data[MAX];
//int N, K;
//
//int start = 0, end = N - 1;
//int count = 0;
//while (start < end) {
//	int sum = data[start] + data[end];
//	if (sum > K)		end--;
//	else if (sum < K)	start++;
//	else { count++; start++; end--;	}
//}
//cout << count << "\n";

#include <iostream>
using namespace std;

int N, K;
int a[1000];

int solve(int l, int r) {
	if (l >= r) return 0;	// base case: 구간에 원소가 0개 또는 1개인 경우

	int sum = a[l] + a[r];
	if (sum > K) return solve(l, r - 1); // 합이 크면 오른쪽 포인터 감소
	if (sum < K) return solve(l + 1, r); // 합이 작으면 왼쪽 포인터 증가
	return 1 + solve(l + 1, r - 1);		 // 합이 K와 같으면 둘 다 이동하고 카운트 증가
}

int main() {
	freopen("input.txt", "r", stdin); // input.txt 파일에서 입력 받는다고 가정

	cin >> N;
	for (int i = 0; i < N; i++)	cin >> a[i];
	cin >> K;

	cout << solve(0, N - 1) << "\n";
	return 0;
}




