/*
 * radix_sorter.h
 *
 *  Created on: 2013-8-26
 *      Author: liusir
 */

#ifndef RADIX_SORTER_H_
#define RADIX_SORTER_H_

#include "queue_lib.h"
#include "stdlib.h"

#define N_BIN 8
#define BIN_BITS_MASK 0x7
#define BIN_BITS_N 3

struct queue *bins[N_BIN];

static int rs_max_element(int array[], int size)
{
	int i;
	int result = array[0];
	for(i=0; i<size; i++)
		if(array[i] > result)
			result = array[i];
	return result;
}

static int leftmost_bit(unsigned int x)
{
	int n=0;
	while(x!=0)
	{
		x = x>>1;
		n++;
	}
	return n;
}

/*
 * NOTE: array[n] >= 0;
 */
static void radix_sorter(int array[], int size)
{
	int n = leftmost_bit((unsigned int)rs_max_element(array, size));
	n = (n+BIN_BITS_N-1)/BIN_BITS_N;

	int turns;
	for(turns=0; turns<n; turns++)
	{
		int p;
		// distribute
		for(p=0; p<size; p++)
		{
			int index = BIN_BITS_MASK & (array[p] >>(BIN_BITS_N * turns)) ; // 注意！不能用mask & array[p]!
			if(bins[index] == NULL)
				bins[index] = queue_initial(size+1); // size+1!!! 循环队列有一个成员不能用
			queue_enqueue(bins[index], array[p]);
		}

		// merge
		for(p=0; p<size; p++)
		{
			int i;
			int m;
			struct queue *queue;
			for(i=0; i<N_BIN && (bins[i] == NULL); i++);
			if(i == N_BIN)
			{
				printf("i==N_BIN!,error!");
				return;
			}
			queue = bins[i];

			m = queue_dequeue(queue);
			if(queue_is_empty(queue))
			{
				queue_delete(queue);
				bins[i] = NULL;
			}

			array[p] = m;
		}
	}
}


#endif /* RADIX_SORTER_H_ */
