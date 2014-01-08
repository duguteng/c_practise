/*
 ============================================================================
 Name        : chain_lib.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "chain_lib.h"

int main(void) {
	chain *head, *head2;
	head = chain_initial();
	head2 = chain_initial();

	chain_insert_order(head,10);
	chain_insert_order(head,12);
	chain_insert_order(head,14);
	chain_insert_order(head,16);
	chain_insert_order(head,8);
	chain_insert_order(head,4);

	chain_print(head);

	chain_delete(head,10);
	chain_delete(head,8);

	chain_print(head);

	chain_insert_order(head2,7);
	chain_insert_order(head2,13);
	chain_insert_order(head2,15);
	chain_insert_order(head2,11);
	chain_insert_order(head2,9);
	chain_insert_order(head2,1);
	chain_insert_order(head2,3);

	chain_print(head2);

	chain_merge(head, head2);
	chain_print(head);

	return EXIT_SUCCESS;
}
