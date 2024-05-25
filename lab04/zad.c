#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RANDOM (rand() * rand())

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* generate(int n) {
	int* niz = (int*)malloc(n * sizeof(int));
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int presjek(int* skupA, int* skupB, int n) {

	int duzinaPresjeka = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (skupA[i] == skupB[j]) {
				duzinaPresjeka++;
			}
		}
	}
	return duzinaPresjeka;
}

int presjek_jedan_sortiran(int* skupA, int* skupB, int n) {

	int duzinaPresjeka = 0;

	qsort(skupB, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		if ((int*)bsearch(&skupA[i], skupB, n, sizeof(int), compare) != NULL) {
			duzinaPresjeka++;
		}
	}
	return duzinaPresjeka;
}

int presjek_oba_sortirana(int* skupA, int* skupB, int n) {
	
	int duzinaPresjeka = 0;
	int indeksA = 0, indeksB = 0;

	qsort(skupA, n, sizeof(int), compare);

	while (indeksA < n && indeksB < n) {
		if (skupA[indeksA] < skupB[indeksB]) {
			indeksA++;
		}
		else if (skupB[indeksB] < skupA[indeksA]) {
			indeksB++;
		}
		else {
			duzinaPresjeka++;
			indeksA++;
			indeksB++;
		}
	}

	return duzinaPresjeka;
}

int presjek_po_indeksima(int* skupA, int* skupB, int n) {

	int duzinaPresjeka = 0;
	int* indexA, * indexB;
	int i = 0, j = 0;

	int maxA = skupA[n - 1];
	int maxB = skupB[n - 1];

	indexA = (int*)calloc(maxA + 1, sizeof(int));
	indexB = (int*)calloc(maxB + 1, sizeof(int));

	for (int i = 0; i < n; i++) {
		indexA[skupA[i]] = 1;
		indexB[skupB[i]] = 1;
	}

	while (i < maxA && j < maxB) {
		if (indexA[i] == 1 && indexB[j] == 1) {
			duzinaPresjeka++;
			i++;
			j++;
		}
		else {
			i++;
			j++;
		}
	}

	free(indexA);
	free(indexB);

	return duzinaPresjeka;
}

int main() {
	
	int n = 200000;
	int* skupA;
	int* skupB;
	int duzinaPresjeka;
	int stime, etime;

	skupA = generate(n);
	skupB = generate(n);
	
	shuffle(skupA, n);
	shuffle(skupB, n);

	//1)prva funkcija
	stime = clock();
	duzinaPresjeka = presjek(skupA, skupB, n);
	etime = clock();

	printf("%d\n", duzinaPresjeka);
	printf("%f\n", ((float)(etime - stime)) / CLOCKS_PER_SEC);
	

	/*2) funkcija sa jednim sortiranim skupom
	stime = clock();
	duzinaPresjeka = presjek_jedan_sortiran(skupA, skupB, n);
	etime = clock();

	printf("%d\n", duzinaPresjeka);
	printf("%f\n", ((float)(etime - stime)) / CLOCKS_PER_SEC);

	//3)oba sortirana
	stime = clock();
	duzinaPresjeka = presjek_oba_sortirana(skupA, skupB, n);
	etime = clock();

	printf("%d\n", duzinaPresjeka);
	printf("%f\n", ((float)(etime - stime)) / CLOCKS_PER_SEC);

	//4) po indeksima
	stime = clock();
	duzinaPresjeka = presjek_po_indeksima(skupA, skupB, n);
	etime = clock();

	printf("%d\n", duzinaPresjeka);
	printf("%f\n", ((float)(etime - stime)) / CLOCKS_PER_SEC);
	*/
	

	free(skupA);
	free(skupB);

	
	return 0;
}