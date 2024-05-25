#include <stdio.h>
/* 
char <= short <= int <= long
float <= double
*/

void main1() {
	float count = 0;
	for (int i = 0; i < 100000000; i++) {
		count += 1;
	}
	printf("%f\n", count);

}