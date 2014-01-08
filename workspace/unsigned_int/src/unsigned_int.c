/*
 ============================================================================
 Name        : unsigned_int.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "stdlib.h"

int main(void) {
	unsigned size;
	size = 10;
	printf("%u\n", size-11); //4294967295

	return EXIT_SUCCESS;
}
