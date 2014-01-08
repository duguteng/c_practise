/*
 * shell_sorter.h
 *
 *  Created on: 2013-8-26
 *      Author: liusir
 */

#ifndef SHELL_SORTER_H_
#define SHELL_SORTER_H_


static void _shell_sorter(int array[], int size, int step)
{
	int i, stub, p;
	for(i=0; i<step; i++)
	{
		for(stub=i+step; stub<size; stub += step)
		{
			int m;
			m = array[stub];

			for(p=stub; p>=step && array[p-step]>m; p-=step)
			{
				array[p] = array[p-step];
			}
			array[p] = m;
		}
	}
}

static void shell_sorter(int array[], int size)
{
	int step;
	for(step = size/2; step >= 1; step /= 2)
	 _shell_sorter(array, size, step);
}

#endif /* SHELL_SORTER_H_ */
