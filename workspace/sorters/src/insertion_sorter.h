/*
 * insertion_sorter.h
 *
 *  Created on: 2013-8-26
 *      Author: liusir
 */

#ifndef INSERTION_SORTER_H_
#define INSERTION_SORTER_H_

static void insertion_sorter(int array[], int size)
{
	int stub;
	int m;
	int p;

	for(stub=1; stub < size; stub ++)
	{
		m = array[stub];

		for(p=stub; p>0 && array[p-1]>m; p--)
		{
			array[p] = array[p-1];
		}
		array[p] = m;
	}
}


#endif /* INSERTION_SORTER_H_ */
