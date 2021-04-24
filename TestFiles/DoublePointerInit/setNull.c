#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Test{
	int* x;
} Test;

void setNull(Test** test);
// does NOT work!!
void main(void){
	//Test** test;
	//printf("memory address before allocation: %x\n", test);
	//test = (Test**)malloc(sizeof(Test*));
	Test* test1; // is null rn
	printf("calling\n");
	setNull(&test1);
	Test** test = &test1;
	printf("mem address in main of test: %x %x\n", test, *test);
	printf("x is: %x\nvalue: %d\n", (*test)->x, *((*test)->x));
}

void setNull(Test** test){
	int* x = (int*)malloc(sizeof(int));
	(*test) = (Test*)malloc(sizeof(Test));
	printf("a\n");
	(*test)->x = x;
	printf("b\n");
	(*x) = 3;
	printf("mem address: %x %x\n", test, *test);
}
