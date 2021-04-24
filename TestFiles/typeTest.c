#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

const static int hello = 3;

// creates prototype that accepts the multi-char input
void printWord(char* word[]);

int main(void){
	// creates target word
	char wordToPrint[1][50] = {"hello world"};
	char* myWordPtr = (char*)calloc(13, sizeof(char));
	myWordPtr = "hello world";
	myWordPtr[12] = '\0';
	char* word = "nick said hi";

	//int isEven = 5 % 2 == 0;
	//printf("isEven: %d", isEven);


	//printWord(&wordToPrint[0][0]);
//	printWord(&"hello world");
	
	printf("static value is: %d\n", hello);
	return 0;
}

// implements prototype to print word to console stream
void printWord(char* word[]){
	// imp not important
	printf("works");
}

//void printWord(char arr[]){}
