#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main(void){

	char a = 'a';
	char b = '\0';

	unsigned int x = (unsigned int) a;
	unsigned int y = b;

	printf("value of 'a' is: %u and 'b': %u\n", a, b);
        printf("value of 'a' is: %u and 'b': %u\n", x, y);
}
