#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(void){

	int result = fork();
	if(result == -1)
		printf("oops\n");
	else if(result == 0){
		char* args[] = {"./callMe2", "hello", "world"};
		execvp(args[0], args);
	}
	else
		printf("parent id: %d  child id: %d\n", getpid(), result);

}
