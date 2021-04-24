#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int size, char* args[]){
	if(size >= 2){
		printf("size of argument array: %d\n", size);
		for(int i = 0; i < size; i++){
			if( i == 0)
				printf("\n");
			printf("word[%d]: %s\n",i,args[i]);
		}
	}
	else{
		printf("no word\n");
	}

}
