 #include <stdio.h>
#include <stdlib.h>

void ary_rcopy(int a[], const int b[], int n) {
	int i;
	for (i = 0; i < n; i++)
		a[i] = b[n - i - 1];
}

int main(void)
{
	int i;
	int* x, * y;			/* 배열의 첫 번째 요소에 대한 포인터 */
	int n;				/* 배열 x와 y의 요솟수 */

	printf("요솟수 : ");
	scanf_s("%d", &n);
	x = (int*)calloc(n, sizeof(int));			/* 요솟수 n인 int 형 배열 x를 생성 */
	y = (int*)calloc(n, sizeof(int));			/* 요솟수 n인 int 형 배열 y를 생성 */

	printf("%d 개의 정수를 입력하세요.\n", n);
	for (i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	ary_rcopy(y, x, n); /* 배열 x의 모든 요소를 배열 y로 역순으로 복사합니다. */

	printf("배열 x의 모든 요소를 배열 y로 역순으로 복사했습니다.\n");
	for (i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x); /* 배열 x를 해제 */
	free(y); /* 배열 y를 해제 */

	return 0;
}