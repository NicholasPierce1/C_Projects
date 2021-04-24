#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// for variadics
#include <stdarg.h>

int foo(double x){ return x > 0? 1 : 0; }

void bar(void){ printf("you called me\n"); }

int fooBar(int x, int y){ return x + y > 0 ? 1: 0; }

void FooBar(void* ptr, int size, ...){
	va_list args;
	va_start(args, size);
	double x = 0;
	for(int i = 0; i < size; i++){
		//printf("value at [%d]: %d\n", i, va_arg(args, int));
		x += va_arg(args, double);
		printf("x is: %f\n",x);
	}

	va_end(args);
	printf("sum is: %.2f\n", x);
}

void main(void){
	int (*fooPtr)(double) = &foo; // or foo itself
	printf("return is: %d\n", (*fooPtr)(1.0));

	void (*barPtr)(void) = &bar;
	(*barPtr)();  // still needs () to invoke

	int (*fooBarPtr)(int, int) = &fooBar;
	printf("return is: %d\n",(*fooBarPtr)(0,1));

	FooBar(0,3,(double)1,(double)2,(double)3);

	void (*FooBarPtr)(void*, int, ...) = &FooBar;
	(*FooBarPtr)(NULL,2,(double)5,(double)3);
}
