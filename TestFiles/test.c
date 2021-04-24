#include <stdio.h>

void wordRef(char wordPointer[], int length);

int main(void){
	int arr[] = {0, 1, 2};
	int* pointer = &arr[0];
	int* pointer1 = arr;  // arr ~= &arr[0]
	printf("memory location of arr: %d\n", arr);
	printf("1st value is: %d\n", *(arr));
	printf("1st value of arr using point: %d\n", *pointer);
	printf("1st value of arr using pointer equavalence: %d\n", *pointer1);

	char word[] = {'b', 'l', 'a', 'h', '\0'};  // can store as char word[] = "blah";
	char word1[] = "blah";
	printf("your word is: %s\n", word);
	printf("your word is also: %s\n", word1);

	wordRef(&word[0], 4);

	return 0;
}

void wordRef(char wordPointer[], int length){
	for(int i = 0; i < length; i++){
		printf("your letter is: %c\n", *(wordPointer + i));
	}
	printf("the word is: %s\n", wordPointer, wordPointer[0]);
}
