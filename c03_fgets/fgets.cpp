#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) { // Ű����κ��� �� ������ �Է� ����
		// fgets reads at most BUFFER_SIZE-1 characters and appends a null terminator \n���� �б� ������ ���̰� +1�Ǿ ���´�
		if (buffer[strlen(buffer) - 1] == '\n') // ������ ���ڰ� ���� ���� ���ڶ��
			buffer[strlen(buffer) - 1] = '\0'; // remove the newline character
		printf("%s:%d\n", buffer, strlen(buffer));
	}
	return 0;
} 