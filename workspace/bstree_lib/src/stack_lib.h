/*
 * stack_lib.h
 *
 *  Created on: 2013-8-24
 *      Author: liusir
 *
 * NOTE:
 * the stack* function will NOT check if the stack is empty or full
 */

#ifndef STACK_LIB_H_
#define STACK_LIB_H_


#include <malloc.h>
#include <stdlib.h>

typedef struct bstree * stack_t;


struct stack
{
	stack_t *bottom;
	stack_t *top;
	int length;
};

static struct stack* stack_initial(int size)
{
	struct stack *result;
	result = (struct stack*)malloc(sizeof(struct stack));
	stack_t *p;
	p = (stack_t*)malloc(size*sizeof(stack_t));

	result->bottom = p+size;
	result->top = result->bottom;
	result->length = size;
	return result;
}

static void stack_push(struct stack* s, stack_t m)
{
		*(--s->top) = m;
		//s->top --;
}

static stack_t stack_pop(struct stack*s)
{
	return *(s->top++);
}

static stack_t stack_top(struct stack *s)
{
		return *(s->top);
}

static int stack_is_empty(struct stack *s)
{
	return s->bottom == s->top;
}

static int stack_is_full(struct stack *s)
{
	return s->bottom - s->top == s->length;
}

#endif /* STACK_LIB_H_ */
