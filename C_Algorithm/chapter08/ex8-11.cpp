#include <stdio.h>
#include <string.h>

int main(void) {
	char st[128];
	puts("\"STRING\"�� ó�� 3���� ���ڿ� ���մϴ�.");
	puts("\" XXXX\"�� �Է��ϸ� �����մϴ�.");
	while (1) {
		printf("���ڿ� st : ");
		scanf_s("%s", st, sizeof(st));
		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\",st, 3) = %d\n", strncmp("STRING", st, 3));
	}
	return 0;
}