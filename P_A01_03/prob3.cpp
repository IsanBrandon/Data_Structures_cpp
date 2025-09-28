#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
		// words[i]는 단순히 char* 포인터일 뿐, 실제 문자열을 담을 메모리를 가리키지 않음.
		// 따라서 scanf가 입력된 문자열을 쓸 곳이 없어서 미정의 동작(세그폴트, 메모리오염) 발생.

		// issue 2:
		scanf("%s", buf);
		// buf는 함수 안에서 선언된 고정 배열 → 모든 반복에서 같은 주소.
		// 따라서 모든 words[i]가 같은 buf를 가리킴 → 결국 마지막 단어만 중복 출력됨.

		// issue 3:
		scanf("%s", buf);
		strcpy(words[i], buf);
		// words[i]는 여전히 초기화되지 않은 포인터 → strcpy가 복사할 목적지 메모리 없음
		// 따라서 미정의 동작.

		// Right way:
		scanf("%29s", buf);                // 한 단어 입력 (최대 29글자)

		words[i] = malloc(strlen(buf) + 1); // 메모리 동적 할당
		if (!words[i]) {
			fprintf(stderr, "메모리 할당 실패\n");
			return 1;
		}

		strcpy(words[i], buf);             // 복사

	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", words[i]);
		free(words[i]);                    // 메모리 해제
	}
	return 0;
}

// 세 방법 모두 공통 문제는 "문자열 저장할 메모리를 직접 마련하지 않고, 단지 포인터 변수만 선언했다"는 점입니다.
// 따라서 입력받은 문자열을 저장할 공간이 없기 때문에, 정의되지 않은 동작(Undefined Behavior)이 발생합니다.
// 그러므로 입력받은 문자열을 저장할 메모리를 직접 할당해주어야 합니다.