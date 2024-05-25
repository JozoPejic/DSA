#include <stdio.h>

void f(char* s, int len) {


}

int main3() {
	char* s1 = "abc";
	char s2[] = "abc";
	char s3[100] = "abc";

	int n = sizeof(s2) / sizeof(char);

	*s2 = *s1;
	s2[0] = s1[0];

	*(s2+3) = *(s1 + 3);
	s2[3] = s1[3];

	//(*s2 + 3) = (*s1 + 3);

	*s1 = *s2;


	return 0;
}