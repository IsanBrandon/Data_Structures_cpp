#include <iostream>
#include <cmath>   // sqrt 사용
using namespace std;

int main() {
	int* num = new int;	// 입력 개수 
	cout << "Enter num: ";
	cin >> *num;

	if (*num <= 0 || *num > 100) {
		cout << "Wrong Input." << endl;
		delete num;
		return 0;
	}

	// 정수 5개를 저장할 동적 배열
	int* arr = new int[*num];

	cout << "Enter " << *num << " integers: ";
	for (int i = 0; i < *num; i++) {
		cin >> *(arr + i);  // 포인터 산술을 사용하여 입력 받기
	}

	// 최소값, 최대값, 평균, 표준편차를 저장할 포인터 변수
	int* minVal = new int(*arr);
	int* maxVal = new int(*arr);
	double* avg = new double(0);
	double* stddev = new double(0);

	// 최소, 최대, 합 계산
	\for (int i = 0; i < *num; i++) {
		if (*(arr + i) < *minVal) *minVal = *(arr + i);
		if (*(arr + i) > *maxVal) *maxVal = *(arr + i);
		*avg += *(arr + i);
	}
	*avg /= *num;

	// 표준편차 계산
	for (int i = 0; i < *num; i++) {
		double diff = static_cast<double>(*(arr + i)) - *avg;	// i번째 정수 값을 double로 변환.
		// 이유: 평균(*avg)은 double*이므로 정수와 뺄셈하면 형변환이 필요. 
		// static_cast<double>는 안전하고 명시적인 타입 변환 방법.
		*stddev += diff * diff;
	}
	*stddev = sqrt(*stddev / *num);

	// 결과 출력
	cout << *minVal << " " << *maxVal << " " << *avg << " " << *stddev << endl;

	// 동적 메모리 해제
	delete num;
	delete[] arr;
	delete minVal;
	delete maxVal;
	delete avg;
	delete stddev;

	return 0;
}