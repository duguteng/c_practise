/*
 * bstree_lib.h
 *
 *  Created on: 2013-8-25
 *      Author: liusir
 */

#ifndef BSTREE_LIB_H_
#define BSTREE_LIB_H_

#include <malloc.h>
#include <stdlib.h>
#include "queue_lib.h"
#include "stack_lib.h"

#define MAX_MEMBER 100

typedef int bstree_value_t;

struct bstree
{
	bstree_value_t value;
	struct bstree *lchild;
	struct bstree *rchild;
};

static void bstree_insert(struct bstree **root, bstree_value_t value)
{
	if(*root == NULL)
	{
		*root = (struct bstree *)malloc(sizeof(struct bstree));
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		(*root)->value = value;
	}else if(value < (*root)->value){
		bstree_insert(&((*root)->lchild), value);
	}else {
		bstree_insert(&((*root)->rchild), value);
	}
}

static void bstree_traversal_head(struct bstree *root)
{
	if(root != NULL)
	{
		printf("%d\t",root->value);
		bstree_traversal_head(root->lchild);
		bstree_traversal_head(root->rchild);
	}
}

static void bstree_traversal_head_norecure(struct bstree *root)
{
	struct stack *s;
	s = stack_initial(100);
	stack_push(s, root);
	while(!stack_is_empty(s))
	{
		struct bstree *subtree;
		subtree = stack_pop(s);
		while(subtree != NULL)
		{
			printf("%d\t",subtree->value);
			if(subtree->rchild != NULL)
				stack_push(s, subtree->rchild);
			subtree = subtree->lchild;
		}
	}
}

static void bstree_traversal_middle(struct bstree *root)
{
	if(root != NULL)
	{
		bstree_traversal_middle(root->lchild);
		printf("%d\t",root->value);
		bstree_traversal_middle(root->rchild);
	}
}

static void bstree_traversal_middle_norecure(struct bstree *root)
{
	struct stack *s;
	struct bstree *subtree ;
	s = stack_initial(100);
	subtree = root;
/*	while(subtree != NULL)
	{
		stack_push(s, subtree);
		subtree = subtree->lchild;
	}
	while(!stack_is_empty(s))
	{
		subtree = stack_pop(s);
		printf("%d\t", subtree->value);
		subtree = subtree->rchild;
		while(subtree != NULL)
		{
			stack_push(s, subtree);
			subtree = subtree->lchild;
		}
	}
	*/

	while(subtree != NULL || !stack_is_empty(s))
	{
		if(subtree != NULL)
		{
			stack_push(s,subtree);
			//printf("%d\t", subtree->value);
			subtree = subtree->lchild;
		} else {
			subtree = stack_pop(s);
			printf("%d\t", subtree->value);
			subtree = subtree->rchild;
		}
	}
}

static void bstree_traversal_tail(struct bstree *root)
{
	if(root != NULL)
	{
		bstree_traversal_tail(root->lchild);
		bstree_traversal_tail(root->rchild);
		printf("%d\t",root->value);
	}
}

static void bstree_traversal_tail_norecure(struct bstree *root)
{
	struct stack *sa, *sb;
	sa = stack_initial(100);
	sb = stack_initial(100);

	stack_push(sa, root);
	while(!stack_is_empty(sa))
	{
		struct bstree *tmp;
		tmp = stack_pop(sa);
		stack_push(sb, tmp);
		if(tmp->lchild != NULL)
			stack_push(sa, tmp->lchild);
		if(tmp->rchild != NULL)
			stack_push(sa, tmp->rchild);
	}

	while(!stack_is_empty(sb))
		printf("%d\t",(stack_pop(sb))->value);

}

static void bstree_traversal_level(struct bstree *root)
{
	struct queue *q;
	struct bstree *subtree;
	q = queue_initial(MAX_MEMBER);
	queue_enqueue(q,root);
//	while((subtree = queue_dequeue(q)) != NULL)
	while (!queue_is_empty(q))
	{
		subtree = queue_dequeue(q);
		printf("%d\t",subtree->value);
		if(subtree->lchild != NULL)
			queue_enqueue(q, subtree->lchild);
		if(subtree->rchild != NULL)
			queue_enqueue(q, subtree->rchild);
	}
}


#endif /* BSTREE_LIB_H_ */
