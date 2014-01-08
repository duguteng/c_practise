/*
 ============================================================================
 Name        : hermite.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int hermite( int n, int x)
{
	if(n <= 0)
		return 1;
	if(n == 1)
		return 2*x;
	return 2*x*hermite(n-1,x) - 2*(n-1)*hermite(n-2,x);
}

int main(void) {

	printf("%d\n", hermite(3,2));
	return EXIT_SUCCESS;
}
