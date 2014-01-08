/*
 ============================================================================
 Name        : bstree_lib.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bstree_lib.h"

int main(void) {
	int value;
	struct bstree *root = NULL;
	scanf("%d",&value);
	while(value != -1)
	{
		bstree_insert(&root, value);
		scanf("%d",&value);
	}
	printf("insert finished\n");
	bstree_traversal_middle(root);
	putchar('\n');
	bstree_traversal_middle_norecure(root);
	putchar('\n');

	bstree_traversal_head(root);
	putchar('\n');
	bstree_traversal_head_norecure(root);
	putchar('\n');

	bstree_traversal_tail(root);
	putchar('\n');
	bstree_traversal_tail_norecure(root);
	putchar('\n');

	bstree_traversal_level(root);
	return EXIT_SUCCESS;
}
