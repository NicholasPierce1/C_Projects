#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void test(char* charPtr);

void main(void){
	char* charPtr = (char*)malloc(sizeof(char*));
	printf("mem address before free: %X\n", charPtr);
	free(charPtr);
	printf("mem address after free: %X\n", charPtr);
	int x;
	printf("is charPtr null: %s\n", charPtr == NULL ? "true" : "false");

	char charPtr1 = 'b';
	char* charPtr2 = &charPtr1;
	printf("memory address: %X\n", &charPtr1);
	charPtr2 = NULL;
	test(charPtr2);
	printf("memory address: %X -- value: %c\n", charPtr2, charPtr2);

}

void test(char* charPtr){
	char temp = 'a';
	charPtr = &temp;
	printf("mem address in method: %X\n", charPtr);
}
