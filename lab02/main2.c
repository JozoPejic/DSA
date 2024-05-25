#include <stdio.h>

int dbl(int a) {
	return 2 * a;
}

void dbl2(int* a) {
	*a = 2 * (*a);
}

int main2() {
	int x = 6;

	// x = dbl(x);

	dbl2(&x);

	printf("%d\n", x);

	return 0;
}