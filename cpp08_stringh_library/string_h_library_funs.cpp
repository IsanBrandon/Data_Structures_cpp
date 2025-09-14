#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "hello";
	char str2[] = "world!";

	printf("%d\n", strlen(str1));
	printf("%d\n", strlen(str2));

	char str3[20];
	strcpy(str3, str1);
	printf("str3: %s\n", str3);

	strcat(str3, str2);
	printf("str3 after strcat: %s\n", str3);

	int result = strcmp(str1, str2);
	printf("strcmp result: %d\n", result);

	result = strcmp(str2, str1);
	printf("strcmp result: %d\n", result);

	char str4[] = "hello";
	result = strcmp(str1, str4);
	printf("strcmp result: %d\n", result);

	return 0;
}