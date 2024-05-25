//reverse() – prima dva stringa i kopira prvi string u drugi string naopako (funkcija ne postoji u string.h)

#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

void reverse(char* str2, char* str1) {
	int i;
	int lenght = strlen(str1);
	
	for (i = 0; i < lenght; i++) {
		str2[i] = str1[lenght - i - 1];
	}
	str2[lenght] = '\0';
}
int main() {

	char str1[15] = "aabb";
	char str2[15];

	reverse(str2, str1);

	printf("%s\n", str2);
	printf("%s\n", str1);

	return 0;
}