#include <stdio.h>

int getsum(int n);

int main(void) {
	int max = 0;

	printf("1���� n������ ���� ���� n�� �Է��Ͻÿ�. >> ");
	scanf_s("%d", &max);

	printf("1���� %d������ ��: %d\n",max, getsum(max));

	return 0;
}

int getsum(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += i;

	return sum;
}