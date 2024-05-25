#include<stdio.h>

void mystrcpy(char *str1, char *str2) {
	int i;
	int br = 0;

	
	for (i = 0; str1[i] != '\0'; i++) {
		br++;
	}
	for (i = 0; i < br; i++) {
		str1[i] = str2[i];
	}
}
int main() {

	char str1[15] = "Dobar";
	char str2[15] = "Dannnnnn!";

	mystrcpy(str1, str2);

	printf("%s", str1);

	return 0;
}