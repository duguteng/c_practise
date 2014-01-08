/*
 ============================================================================
 Name        : array_index.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int is_little_endain()
{
	int m = 0x12345678;
	char *p = (char*)(&m);
	printf("%0x, %0x, %0x, %0x\n",p[0],p[1],p[2],p[3]);
	return *(char*)(&m) == 0x78;
}

int main(void) {
	int array[3][6];
	int *p;
	p = *array;
	int i = 0;
	for (; p < &array[2][6]; p++)
		i++, *p = i;

	printf("%d \n",*(*(array + 1)+6));
	printf("sizeof char [10] = %d",sizeof(char[10]));
	int *testp[10];
	printf("sizeof int*[10] = %d, sizeof testp = %d\n",sizeof(int*[10]), sizeof(testp));
	//printf("sizeof int[10]* = %d",sizeof(int[10]*)); //error

	// test little endain
	printf("%s\n",is_little_endain()?"little endian": "big endain");

	// test sizeof ½áºÏÐÔ
	printf("%d",sizeof(int)***array);
	return EXIT_SUCCESS;
}
