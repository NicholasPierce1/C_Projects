#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

typedef struct Test{
	int x,y;
	char** strPointer;
} Test;

void main(void){
	int x = 0;
	addOne(&x);
	printf("value of x is: %d\n", x);

	Test test;
	printf("what is an int def value: %d\n", test.x);
	printf("is test null: %s\n", &test == NULL ? "true" : "false");
	printf("is test's strPointer null: %s\nmemory address of pointer: %X\n", test.strPointer == NULL ? "true" : "false", &(test.strPointer));

	test.x = 5;
	Test* test1 = &test;
	test1->x*=2;
	printf("can I print a value with partial assigned struct: %d\n", test.x);

	test.y = 0;
	test.strPointer = (char**)malloc(sizeof(char*) * test.x);

	printf("what is memory address of pointer: %X\n", test.strPointer);

}
