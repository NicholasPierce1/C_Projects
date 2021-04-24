#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void){
	int terminate = 1;
	int size = 0;
	int capacity = 2;
	char* string = (char*)calloc(capacity, sizeof(char));
	do{
		char* ptr = (char*)calloc(1, sizeof(char));
		scanf("%c", ptr);
		printf("char is: %c\n", *ptr);
		terminate = *ptr == '\n' ? 0 : 1;
		if(terminate){
			if(size + 1 == capacity)
				string = (char*)realloc(string, sizeof(char) * ++capacity);
			string[size++] = *ptr;
		}
		else
			string[size + 1] = '\0'; // or capacity - 1
		free(ptr);
		ptr = NULL;
	}while(terminate);
	printf("string: %s\n", string);
	printf("size of string: %u\n", strlen(string));
}
