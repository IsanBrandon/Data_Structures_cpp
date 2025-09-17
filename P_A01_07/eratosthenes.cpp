#include <iostream>
using namespace std;

/*
 * 문제 7: 소수 구하기 (에라토스테네스의 체)
 *	- 입력: n (최대 10000)
 *  - 출력: 2~n 사이의 모든 소수
 *  - 방법: 배열을 직접 관리하면서 배수 제거 (빈 자리 없이 앞으로 당김)
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 상한값 입력

	if (n < 2) {
		return 0; // 2 미만이면 소수 없음
	}

	// 1) 2부터 n까지 배열에 저장
	int size = n - 1;				// 원소 개수 (2~n 포함)
	int* arr = new int[size];       // 동적 배열 할당
	for (int i = 0; i < size; i++) {
		arr[i] = i + 2;           // arr[0] = 2, arr[1] = 3, ..., arr[size-1] = n
	}

	// 2) 배열을 순서대로 훑으면서 배수 제거
	for (int i = 0; i < size; i++) {
		int p = arr[i];				// 현재 소수 후보
		if (p == -1) continue;		// 이미 제거된 자리면 건너뜀

		// p의 배수 제거 (자기 자신 제외)
		for (int j = i + 1; j < size; ) {
			if (arr[j] % p == 0) {
				// j번째 원소 제거 -> 뒤 원소들을 한 칸씩 앞으로 당김
				for (int k = j; k < size - 1; k++) {
					arr[k] = arr[k + 1];
				}
				--size; // 전체 크기 줄임
				// arr[j]에는 새 값이 복사됐으므로 j는 증가시키지 않고 반복
			}
			else {
				++j; // 배수가 아니면 다음 원소로
			}
		}
	}

	// 3) 결과 출력: 배열에 남아 있는 수들이 소수
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}

	delete[] arr; // 동적 메모리 해제
	return 0;
}