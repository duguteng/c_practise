/*
 * merge_sorter.h
 *
 *  Created on: 2013-8-26
 *      Author: liusir
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

static void merge(int a[],int an, int b[], int bn, int c[])
{
	int p,q;
	int i=0;
	p = q = 0;
	while(p<an && q<bn)
	{
		if(a[p] <= b[q])
			c[i++] = a[p++];
		else
			c[i++] = b[q++];
	}
	while(p<an)
		c[i++] = a[p++];
	while(q<bn)
		c[i++] = b[q++];
}

static void _merge_sorter(int array[], int start, int mid, int end, int temp[])
{
	if(mid-start > 1)
		_merge_sorter(array,start,(start+mid)/2,mid,temp);

	if(end-mid > 1)
		_merge_sorter(array,mid,(end+mid)/2,end,temp);

	merge(array+start, mid-start, array+mid, end-mid, temp+start);

	int i;
	for(i=0; i<end-start; i++)
		array[start+i] = temp[start+i];
}

static void merge_sorter(int array[], int size)
{
	int *temp;
	temp = (int*)malloc(sizeof(int)*size);
	_merge_sorter(array, 0, size/2, size,temp);
	free(temp);
}

#endif /* MERGE_SORT_H_ */
