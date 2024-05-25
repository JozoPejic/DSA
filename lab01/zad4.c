#include<stdio.h>
#include<string.h>

void mystrcat(char* str1, char* str2) {
	int i;
	int j = 0;
	int duzina_oba_stringa;

	duzina_oba_stringa = strlen(str1) + strlen(str2);

	for (i = strlen(str1); i < duzina_oba_stringa; i++) {
		str1[i] = str2[j];
		j++;
	}
}

int main() {

	char str1[100] = "Ovo je implementacija", str2[] = " funkcije strcat";

	mystrcat(str1, str2);

	printf("%s\n", str1);
	printf("%s", str2);

	return 0;
}