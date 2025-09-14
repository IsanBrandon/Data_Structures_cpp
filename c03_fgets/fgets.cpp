#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) { // 키보드로부터 한 라인을 입력 받음
		// fgets reads at most BUFFER_SIZE-1 characters and appends a null terminator \n까지 읽기 때문에 길이가 +1되어서 나온다
		if (buffer[strlen(buffer) - 1] == '\n') // 마지막 글자가 만약 개행 문자라면
			buffer[strlen(buffer) - 1] = '\0'; // remove the newline character
		printf("%s:%d\n", buffer, strlen(buffer));
	}
	return 0;
} 