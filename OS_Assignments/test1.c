#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include "test2.h"
#include <string.h>

const int var = 11;

void test(void){printf("called\n");}

static const char *homedir;

static void (*fArray[])(void) = {&test};
// static void (**fArray)(void);

void main(void){

	char* blahblah[] = {"hello", NULL};
	char blah[] = {'a'};
	printf("size: %d  %d\n", strlen(blah), sizeof(int[2]));

	printf("extern var: %d\n", var);

	if ((homedir = getenv("HOME")) == NULL) {
    		homedir = getpwuid(getuid())->pw_dir;
	}

	printf("home: %s\n", homedir);

	//fArray = {&test, NULL};
	// IF fArray type is dynamic -- void (**)(void) then uncomment below
	//fArray = (void (**)(void))calloc(2, sizeof(void (*)(void)));
	//fArray[0] = &test;
	//fArray[1] = NULL;
	//fArray[0]();
	(*(fArray[0]))();
	int i = 0;
	while(fArray[i]){
		(*(fArray[i++]))();
	}
	printf("%d\n", i);
}
