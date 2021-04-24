#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void testMalloc(void);

int main(void){

	char word[] = "hello world";
	char* wordPtr = &word[0]; // same as word by itself -- pointer to first char
	// same as wordPtr = word;

	printf("sentence: %s\naddress: %u\n", word, wordPtr);
	printf("sentence (using ptr): %s\n", wordPtr);

	printf("first char in both word: %c %c\n", word[0], *wordPtr);

	printf("address of array: %u\naddress of first char: %u\n", word, wordPtr);

	// modify word's endpoint and see if the pointer's value still points to 'hello world'
	//word = "hello world";
	// CAN'T re-assign an array

	testMalloc();

	return 0;
}

void testMalloc(void){
	char** charPointers = malloc(sizeof(char*)); // pointer is just 8 bytes, but type safety is ensured through the pointer type
	// charPointers === &charPointers[0] === &(&charPointers[0])[0] --> first element of the first array/word

	// assignment can be done two ways
	
	// easy way
	charPointers[0] = malloc(10 * sizeof(char));
	strcpy(charPointers[0], "nick");
	

	// hard way
	// charPointers[0] = "nick";


	printf("memory address of 2d array (should be first el): %u\naddress 2: %u\naddress 3: %u\n", *&charPointers[0], *charPointers, &((*charPointers)[0]));
}
