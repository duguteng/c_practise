/*
 * queue.h
 *
 *  Created on: 2013-8-24
 *      Author: liusir
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <malloc.h>
#include <stdlib.h>

typedef int queue_t;

struct queue
{
	queue_t *data;
	int head;
	int tail;
	int length;
};

static struct queue* queue_initial(int size)
{
	struct queue *result;
	result = (struct queue*)malloc(sizeof(struct queue));
	result->data = (queue_t*)calloc(sizeof(queue_t), size);
	result->head = result->tail = 0;
	result->length = size;
	return result;
}

static void queue_delete(struct queue* p)
{
	free(p->data);
	free(p);
}

static void queue_enqueue(struct queue *q, queue_t m)
{
	if(q && (q->tail+1)%(q->length) != q->head)
	{
		*(q->data+q->tail) = m;
		q->tail++;
		q->tail %= q->length;
	}
}

static queue_t queue_dequeue(struct queue *q)
{
	queue_t m=0;
	if(q && (q->tail+1)%(q->length) != q->head)
	{
		m = *(q->data + (q->head++));
		q->head %= q->length;
	}
	return m;
}

static int queue_is_empty(struct queue *q)
{
	return q->tail == q->head;
}

static int queue_is_full(struct queue *q)
{
	return (q->tail+1)%q->length == q->head;
}

#endif /* QUEUE_H_ */
