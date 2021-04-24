#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const static int hello = 3;

// creates prototype that accepts the multi-char input
void printWord(char* word[]);

int main(void){
        // creates target word
        char wordToPrint[1][50] = {"hello world"};
        char* myWordPtr = (char*)calloc(13, sizeof(char));
       // *myWordPtr = 'hello world';

	//printf("char is: %c\n", *myWordPtr);

       // printf("word is: %s\n", *myWordPtr);
       char word[] = "nick said hi";
	printf("word is %s\n", word);
       bool isEven = 4 % 2 == 0;
	int x = 1 == 0;
	x = -1;
	printf("this is a false value: %s\n", x ? "true" : "false" );
       printf("isEven: %s %d\n", isEven ? "true" : "false", isEven );

	bool _boolean = true;
        //printWord(&wordToPrint[0][0]);
//      printWord(&"hello world");

        printf("static value is: %d\n", hello);
       
	 return 0;
}

// implements prototype to print word to console stream
void printWord(char* word[]){
        // imp not important
        printf("works");
}

//void printWord(char arr[]){}

