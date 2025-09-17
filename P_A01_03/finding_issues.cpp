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
		// words[i]�� �ܼ��� char* �������� ��, ���� ���ڿ��� ���� �޸𸮸� ����Ű�� ����.
		// ���� scanf�� �Էµ� ���ڿ��� �� ���� ��� ������ ����(������Ʈ, �޸𸮿���) �߻�.

		// issue 2:
		scanf("%s", buf);
		// buf�� �Լ� �ȿ��� ����� ���� �迭 �� ��� �ݺ����� ���� �ּ�.
		// ���� ��� words[i]�� ���� buf�� ����Ŵ �� �ᱹ ������ �ܾ �ߺ� ��µ�.

		// issue 3:
		scanf("%s", buf);
		strcpy(words[i], buf);
		// words[i]�� ������ �ʱ�ȭ���� ���� ������ �� strcpy�� ������ ������ �޸� ����
		// ���� ������ ����.

		// Right way:
		scanf("%29s", buf);                // �� �ܾ� �Է� (�ִ� 29����)

		words[i] = malloc(strlen(buf) + 1); // �޸� ���� �Ҵ�
		if (!words[i]) {
			fprintf(stderr, "�޸� �Ҵ� ����\n");
			return 1;
		}

		strcpy(words[i], buf);             // ����

	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", words[i]);
		free(words[i]);                    // �޸� ����
	}
	return 0;
}

// �� ��� ��� ���� ������ "���ڿ� ������ �޸𸮸� ���� �������� �ʰ�, ���� ������ ������ �����ߴ�"�� ���Դϴ�.
// ���� �Է¹��� ���ڿ��� ������ ������ ���� ������, ���ǵ��� ���� ����(Undefined Behavior)�� �߻��մϴ�.
// �׷��Ƿ� �Է¹��� ���ڿ��� ������ �޸𸮸� ���� �Ҵ����־�� �մϴ�.