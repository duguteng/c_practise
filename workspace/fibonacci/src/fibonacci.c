/*
 ============================================================================
 Name        : fibonacci.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n)
{
	int a1,a2;
	int i, rst;
	if( n <= 2 )
		return 1;

	a1 = a2 = 1;
	for(i=3; i<=n; i++)
	{
		rst = a1 + a2;
		a1 = a2;
		a2 = rst;
	}

	return rst;
}


int main(void) {
	int i;
	for(i=1; i<20; i++){
		printf("%d\t", fibonacci(i));
		if(i%5 == 0)
				putchar('\n');
	}
	return EXIT_SUCCESS;
}
