#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void main(void){
//	char* blah = (char*)calloc(256, sizeof(char));
	char* blah = (char*)malloc(sizeof(char) * 256);
	//strcpy(blah, "hi");
	blah[0] = 'a';
	blah[1] = 'b';
	blah[2] = '\0';
	int i = 0;
	while( *(blah + i)) // 0 should be a falsey
		printf("char: %c", *(blah + i++));

	printf("\ni value: %d\n", i);
	printf("is null: %s\n", *(blah + i) == '\0' ? "True" : "False");

	char test = 0;

	char* test1 = (char*)malloc(sizeof(char) * strlen("hi"));
	printf("length is: %d\ntest1 size: %d\nchar size: %d\n", strlen("hi"), sizeof(test1), sizeof(char));
	strcpy(test1, "hi");

	test1 = (char*)realloc(test1, sizeof(char) * (strlen("hi!") + 1));
	i = 0;
	strncat(test1, "!", 1); // strcat(char* d, char* s)
	while( *(test1 + i) )
		printf("%c", *(test1 + i++));
	printf("\nderef ascii value: %d\n", *(test1 + i));

	char* testNull = 0;
	printf("is testNull null: %s\n", testNull == NULL ? "true" : "false");

	int x = 0;
	printf("is x (0) false: %s\n", x ? "no" : "yes");

	char noNull[] = {'a','b', '\0'};
	printf("length of noNull string is: %d\n", strlen(noNull));
}
