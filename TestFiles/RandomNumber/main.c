#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void main(void){
	// creates a time type (no init)
	time_t time_v;

	// time(&time_v);
	// seeds random number
	srand( (unsigned) time(NULL) );

	// prints five random numbers
	for(int i = 1; i < 6; i++)
		printf("Random number [%d]: %d\n", i, rand() % 100);
}
