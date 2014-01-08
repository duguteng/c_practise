/*
 * quick_sorter.h
 *
 *  Created on: 2013-8-25
 *      Author: liusir
 */

#ifndef QUICK_SORTER_H_
#define QUICK_SORTER_H_

static void qsort_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void _quick_sorter(int array[], int start, int end)
{
	if(end <= start) return;
	if(end - start == 1)
		if(array[start] > array[end])
			qsort_swap(&array[start], &array[end]);

	int p,q;
	int stub;

	stub = start;
	p = start+1;
	q = end;

	while(p<q)
	{
		while(p<q && array[p] <= array[stub])
			p++;
		while(q>p && array[q] > array[stub])
			q--;

		if(p<q)
			qsort_swap(&array[p], &array[q]);
	}
	if(array[p] > array[stub])
	{
		qsort_swap(&array[stub], &array[p-1]);
		stub = p-1;
	}
	else
	{
		qsort_swap(&array[stub], &array[p]);
		stub = p;
	}

	_quick_sorter(array, start, stub-1);
	_quick_sorter(array, stub+1, end);
}

static void quick_sorter(int array[], int size)
{
	_quick_sorter(array, 0, size - 1);
}

#endif /* QUICK_SORTER_H_ */
