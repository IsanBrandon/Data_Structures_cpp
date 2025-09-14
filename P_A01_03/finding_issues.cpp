#include <stdio.h>
#include <string.h>
#define MAXWORDS 100
#define MAXLEN 30

int main() {
	char* words[MAXWORDS];
	int n;
	scanf("%d", &n);

	char buf[MAXLEN];
	for (int i = 0; i < n; i++) {
		// issue 1:
		scanf("%s", words[i]);

		// issue 2:
		scanf("%s", buf);

		// issue 3:
		scanf("%s", buf);
		strcpy(words[i], buf);
	}

	for (int i = 0; i < n; i++)
		printf("%s\n", words[i]);

	return 0;
}

// 세 방법 모두 공통 문제는 "문자열 저장할 메모리를 직접 마련하지 않고, 단지 포인터 변수만 선언했다"는 점입니다.
// 따라서 입력받은 문자열을 저장할 공간이 없기 때문에, 정의되지 않은 동작(Undefined Behavior)이 발생합니다.
// 그러므로 입력받은 문자열을 저장할 메모리를 직접 할당해주어야 합니다.