/*
 * heap_sorter.h
 *
 *  Created on: 2013-8-26
 *      Author: liusir
 */

#ifndef HEAP_SORTER_H_
#define HEAP_SORTER_H_

#define parent(i) ((i-1)/2)
#define lchild(i) (i*2+1)
#define rchild(i) (i*2+2)

static void heap_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void tune_heap(int array[], int root, int length)
{
	int l,r;
	l = lchild(root);
	r = rchild(root);

	if(l<length)
		tune_heap(array, l, length);
	if(r<length)
		tune_heap(array, r, length);

	if(r<length)
	{
		if(array[r]>array[l])
			if(array[root]<array[r])
				heap_swap(&array[root], &array[r]);
		if(array[r] <= array[l])
			if(array[root] < array[l])
				heap_swap(&array[root], &array[l]);
	} else if(l < length)
	{
		if(array[root] < array[l])
			heap_swap(&array[root], &array[l]);
	}
}

static void heap_sorter(int array[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		tune_heap(array, 0, size-i);
		heap_swap(&array[0], &array[size-1-i]);
	}

}

#endif /* HEAP_SORTER_H_ */
