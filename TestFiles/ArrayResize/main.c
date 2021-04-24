#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void main(void){
	char* word = (char*)malloc(sizeof(char)*5);
	word = strcpy(word, "hello");
	printf("word: %s\n", word);

	word = realloc(word, sizeof(char) *7); // must be larger than string -- no promises on what bytes after new re-alloc on new string are
	// only if want to preserve the values that would be spliced^
	printf("word: %s\n", word);
	strcat(word, "!!");
	printf("word: %s\n", word);
	printf("char outside bounds: %c -- is null %s -- mem address: %X\n", word[8], &word[8] == NULL ? "t" : "f", &word[8]);
}
