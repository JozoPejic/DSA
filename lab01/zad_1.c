#include<stdio.h>
int mystrlen(char *a) {
	int i, br = 0;

	for (i = 0; a[i] != '\0'; i++) {
		br++;
	}

	return br;
}
int main() {

	char a[50] = "Hello World!";


	printf("%d", mystrlen(a));


	return 0;
}