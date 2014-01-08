/*
 ============================================================================
 Name        : eight_queen.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N_QUEEN 4
int queen_location[N_QUEEN];

int put_queen(int line)
{
	int i, rst;
	if(line < 0 )
		return -1;
	if(line >= N_QUEEN)
		return 1;
	for(i=queen_location[line]; i<N_QUEEN; i++)
	{
		int j;
		for(j=0; j<line; j++)
		{
			if(i == queen_location[j])
				break;
			if(i-line == queen_location[j]-j)
				break;
			if(i+line == queen_location[j]+j)
				break;
		}

		if(j >= line) break;
	}

	if(i < N_QUEEN) // succeed in this line
	{
		queen_location[line] = i;
		queen_location[line+1] = 0;
		rst = put_queen(line+1);
	} else { // go back
		queen_location[line-1]++;
		rst = put_queen(line-1);
	}
	return rst;
}

void print_queen(void)
{
	int i,j;
	for(i=0; i<N_QUEEN; i++)
	{
		for(j=0; j<N_QUEEN; j++)
		{
			if(j==queen_location[i])
				putchar('*');
			else
				putchar(' ');
			putchar('|');
		}
		putchar('\n');
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>\n");
}

int main(void) {
	int n_rst=0;
	if( put_queen(0)>0 )
	{
		print_queen();
		n_rst++;
	}

	while(queen_location[N_QUEEN-1]++, put_queen(N_QUEEN-1)>0)
		n_rst++, print_queen();

	printf("<<<<<<<<<<<<--%d-->>>>>>>\n", n_rst);
	return EXIT_SUCCESS;
}
