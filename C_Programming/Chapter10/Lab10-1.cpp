#include <stdio.h>

int getsum(int n);

int main(void) {
	int max = 0;

	printf("1에서 n까지의 합을 구할 n을 입력하시오. >> ");
	scanf_s("%d", &max);

	printf("1에서 %d까지의 합: %d\n",max, getsum(max));

	return 0;
}

int getsum(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += i;

	return sum;
}