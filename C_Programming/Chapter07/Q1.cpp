#include <stdio.h>

int main(void) {
	int i;
	int j;
	for (i = 1; i <= 5; i++) {
		for (j = 5; j >= i; j--)
			printf("%d", j);
		putchar('\n');
	}
	return 0;
}