/*
 ============================================================================
 Name        : stack_lib.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack_lib.h"

int main(void) {
	struct stack *s;
	s = stack_initial(10);
	int i;

	assert(stack_is_empty(s));
	for(i=0;i<5;i++)
	{
		stack_push(s,i+100);
	}

	printf("%d\n",stack_top(s));

	for(i=0;i<5;i++)
		printf("%d\t",stack_pop(s));
	assert(stack_is_empty(s));
	for(i=0;i<10;i++)
	{
		stack_push(s,i+100);
	}
	assert(stack_is_full(s));

	return EXIT_SUCCESS;
}
