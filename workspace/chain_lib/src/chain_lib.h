/*
 * chain_lib.h
 *
 *  Created on: 2013-8-25
 *      Author: liusir
 */

#ifndef CHAIN_LIB_H_
#define CHAIN_LIB_H_

#define DEBUG

#include <malloc.h>
#include <stdlib.h>

typedef int value_t;

struct chain_node
{
	struct chain_node *next;
	value_t value;
};

typedef struct chain_node chain;

static chain * chain_initial()
{
	chain *p;
	p = (chain*)malloc(sizeof(chain));
	p->next = NULL;
	return p;
}

static void chain_insert(chain *parent, value_t value)
{
	chain *p;
	p = chain_initial();
	p->value = value;
	p->next = parent->next;
	parent->next = p;
}

static void chain_insert_order(chain *head, value_t value)
{
	chain *p, *q;
	q = head;
	for(p=head->next;p!=NULL && p->value > value; p = p->next)
		q = q->next;

	chain_insert(q,value);
}

static void chain_delete(chain *head, value_t value)
{
	chain *p, *q;
	q = head;
	for(p=head->next;p!= NULL && p->value != value; p = p->next)
		q = q->next;

	if(p != NULL)
	{
		q->next = p->next;
		free(p);
	}
}

static void chain_merge(chain* dst, chain *src)
{
	struct chain_node *p, *q;
	if(src->next == NULL)
		return;
	if(dst->next == NULL)
	{
		dst->next = src->next;
		return;
	}

	p = dst;
	q = src->next;
	while(q != NULL)
	{
		while( p->next != NULL && p->next->value > q->value)
			p = p->next;
		struct chain_node *tmp;
		tmp = q;
		q = q->next;
		tmp->next = p->next;
		p->next = tmp;
		p = p->next;
	}
}

#ifdef DEBUG
static void chain_print(chain *head)
{
	chain *p;
	p = head->next;
	while(p != NULL)
	{
		printf("%d\t",p->value);
		p = p->next;
	}

	putchar('\n');
}

#endif
#endif /* CHAIN_LIB_H_ */
