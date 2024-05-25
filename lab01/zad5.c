#include<stdio.h>
#include<string.h>

char* mystrstr(char* str1, char* str2) {
	int i, j;

	for (i = 0; str1[i] != '\0'; i++) {
		for (j = 0; str2[j] != '\0' && str2[j] == str1[i + j]; j++) {
		}
		if (str2[j] == '\0') {
			return &str1[i];
		}
	}
	return NULL;
}

int main() {

	char *rez;
	char str1[] = "Dobar dan";
	char str2[] = "dan";
	char* rez2;

	rez = mystrstr(str1, str2);

	if (rez != NULL) {
		printf("Prvo pojavljivanje je na mjestu: %d\n", rez - str1);
	}
	else {
		printf("Nije pronadjen.");
	}

	rez2 = strstr(str1, str2);

	printf("%d", rez2 - str1);

	return 0;
}