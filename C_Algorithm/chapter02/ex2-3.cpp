// int�� ��ü�� �������� �����ϰ� �����մϴ�.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* x;
	x = (int *)calloc(1, sizeof(int));       // calloc()�� �ϸ� ����ȯ ���� �߻�  ->  (int *)�� calloc�տ� �ٿ� ��������ȯ ���Ѿ���
	if (x == NULL) { 
		puts("�޸� �Ҵ翡 �����߽��ϴ�.");
	}
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);
	}

	return 0;
}