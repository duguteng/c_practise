/*
 ============================================================================
 Name        : var_args.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float averages(int nr_args, ... )
{
	float sum;
	va_list list;
	va_start(list, nr_args);

	int i;
	for(i=0; i<nr_args; i++)
	{
		sum += va_arg(list,double);
	}
	va_end(list);
	return sum/nr_args;
}

int main(void) {

	printf("%f\n",averages(4,1.0,2.0,3.0,4.0));
	return EXIT_SUCCESS;
}
