#include <stdio.h>
#include <stdlib.h>

int* ispuni_niz_3() {

	int* niz = (int*) malloc(3 * sizeof(int));

	scanf("%d", &niz[0]);
	scanf("%d", niz + 1);
	scanf("%d", &niz[2]);

	return niz;
}

int* ispuni_niz_n2(int* n) {

	printf("unesite velicinu:");
	scanf("%d", n);

	int* niz = (int*)malloc((*n) * sizeof(int));
	
	for (int i = 0; i < (*n); i++)
		scanf("%d", &niz[i]);
	return niz;
}

int ispuni_niz_n(int** niz) {
	int n;
	printf("unesite velicinu:");
	scanf("%d", &n);

	*niz = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		(*niz)[i] = x;
	}
	return n;
}

int main() {

	int n;
	int* niz;

	n = ispuni_niz_n(&niz);

	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("\n");
	return 0;
}