#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void addOne(int* toAdd){
	printf("value of arg is: %d\n", *toAdd);
	(*toAdd)++;
	printf("value of arg is: %d\n", *toAdd);
}
