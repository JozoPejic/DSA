#include<stdio.h>
#include<string.h>

int mystrcmp(char* kraci_str, char* duzi_str) {
	unsigned i;
	int flag_str1 = 0, flag_str2 = 0;

	for (i = 0; i < strlen(kraci_str); i++) {
		if (kraci_str[i] < duzi_str[i]) {
			flag_str1 = 1;
			break;
		}
		else if (kraci_str[i] > duzi_str[i]) {
			flag_str2 = 1;
			break;
		}
		else
			continue;
	}
	if (flag_str1 == 1) {
		return -1;
	}
	else if (flag_str2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int mystrlen(char* a) {
	int i, br = 0;

	for (i = 0; a[i] != '\0'; i++) {
		br++;
	}

	return br;
}

int main() {

	char str1[10] = "aaa";
	char str2[10] = "abab";
	int duzina_str1, duzina_str2;
	char* kraci_str, * duzi_str;

	duzina_str1 = mystrlen(str1);
	duzina_str2 = mystrlen(str2);

	if (duzina_str1 < duzina_str2) {
		kraci_str = str1;
		duzi_str = str2;
	}
	else if (duzina_str1 > duzina_str2) {
		kraci_str = str2;
		duzi_str = str1;
	}
	else {
		kraci_str = str1;
		duzi_str = str2;
	}

	printf("%d", mystrcmp(kraci_str, duzi_str));


	return 0;
}