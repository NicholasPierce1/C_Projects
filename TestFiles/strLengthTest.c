#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	printf("hello world\n");

	int charsTillZero = 0;
	char blah[] = "hi";

	while(blah[charsTillZero] != '\0'){
		printf("char is: %c\n", blah[charsTillZero]);
		charsTillZero++;
	}

	printf("number: %d", charsTillZero);

	return 0;
}
