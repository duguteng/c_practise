/*
 ============================================================================
 Name        : sorters.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quick_sorter.h"
#include "insertion_sorter.h"
#include "shell_sorter.h"
#include "radix_sorter.h"
#include "merge_sorter.h"
#include "heap_sorter.h"

#define ARRAY_SIZE 10
#define IS_PRINT 1

int is_array_ascend(int array[], int size)
{
	int i;
	for(i=0; i<size-1; i++)
		if(array[i] > array[i+1])
			return 0;
	return 1;
}

int main(void) {
	int array[ARRAY_SIZE];
	int i;
	srand((unsigned int)time(NULL));

//	printf("3/2=%d\t 5/3=%d\t 5/4=%d\n",3/2,5/3,5/4);

	for(i=0; i<ARRAY_SIZE; i++)
		array[i] = rand()%(ARRAY_SIZE*10);

	if(IS_PRINT)
	{
		for(i=0; i<ARRAY_SIZE; i++)
		{
			printf("%d\t", array[i]);
			if(i%10 == 9)
				putchar('\n');
		}
		putchar('\n');
	}

//	quick_sorter(array, ARRAY_SIZE);
//	printf("quick_sorter: the array %s ascend!\n",
//			is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");

//	insertion_sorter(array, ARRAY_SIZE);
//	printf("insertion_sorter: the array %s ascend!\n",
//				is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");

//	shell_sorter(array, ARRAY_SIZE);
//	printf("shell_sorter: the array %s ascend!\n",
//				is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");

//	radix_sorter(array, ARRAY_SIZE);
//	printf("radix_sorter: the array %s ascend!\n",
//				is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");

//	merge_sorter(array, ARRAY_SIZE);
//	printf("merge_sorter: the array %s ascend!\n",
//				is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");

	heap_sorter(array, ARRAY_SIZE);
	printf("heap_sorter: the array %s ascend!\n",
				is_array_ascend(array, ARRAY_SIZE)? "IS" : "IS NOT");


	if(IS_PRINT)
	{
		for(i=0; i<ARRAY_SIZE; i++)
		{
			printf("%d\t", array[i]);
			if(i%10 == 9)
				putchar('\n');
		}
	}

	return EXIT_SUCCESS;
}
