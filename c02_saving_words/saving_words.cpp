#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXWORDS 100
#define MAXLEN 30

int main() {
	char* words[MAXWORDS];
	int n;
	scanf("%d", &n);

	char buf[MAXLEN];
	for (int i=0; i<n; i++) {
		scanf("%s", buf); // read into a buffer first
		words[i] = strdup(buf); // allocate memory and copy the buffer content
		
		// common mistake
		// {case1}
		// scanf("%s", &words[i]); // wrong, words[i] is uninitialized pointer
		// {case2}
		// scanf("%s", buf); // correct, read into a buffer first
		// words[i] = buf; // but this makes all words[i] point to the same buffer
		// {case3}
		// scanf("%s", buf); // correct, read into a buffer first
		// strcpy(words[i], buf); // wrong, words[i] is uninitialized pointer
	}
}