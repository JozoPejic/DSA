#include <stdio.h>

int maxniz(int* niz, int n) {
	int m = niz[0];
	for (int i = 0; i < n; i++) {
		if (niz[i] > m)
			m = niz[i];
	}
	return m;
}

int* maxnizp(int* niz, int n) {
	int mi = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] > niz[mi])
			mi = i;
	}
	return niz + mi; // &niz[mi]
}

int main5() {
	
	// char* s[3] = { "a", "b", "c"};

	//char s[] = { 'a', 'b', 'c', '\0' };

	int niz[] = { 5, 2, 3, 4 };


	return 0;
}