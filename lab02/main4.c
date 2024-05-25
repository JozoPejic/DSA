#include <stdio.h>

int maxint(int xf, int yf) {
	if (xf > yf)
		return xf;
	else
		return yf;
}

int* maxintp(int* xf, int* yf) {
	if (*xf > *yf)
		return xf;
	else
		return yf;
}

void maxintpp(int* xf, int* yf, int** p) {
	if (*xf > *yf)
		*p = xf;
	else
		*p = yf;
}

int main4() {
	int x = 3;
	int y = 6;
	int *p = NULL;

	maxintpp(&x, &y, &p);

	printf("%d\n", *p);

	return 0;
}