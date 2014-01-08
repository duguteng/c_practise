/*
 ============================================================================
 Name        : queen_lib.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <assert.h>

int main(void) {
	struct queue *q;
	q = queue_initial(10);
	assert(queue_is_empty(q));

	int i;
	for(i=0;i<5;i++)
		queue_enqueue(q,i+100);

	assert(queue_is_empty(q) == 0);
	assert(queue_is_full(q) == 0);

	for(i=0;i<5;i++)
		printf("%d\t",queue_dequeue(q));

	assert(queue_is_empty(q));
	assert(queue_is_full(q) == 0);

	for(i=0;i<10;i++)
			queue_enqueue(q,i+100);

	assert(queue_is_empty(q) == 0);
	assert(queue_is_full(q));

	return EXIT_SUCCESS;
}
