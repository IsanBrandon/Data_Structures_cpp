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