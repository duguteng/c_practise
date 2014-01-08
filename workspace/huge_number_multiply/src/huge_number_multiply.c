/*
 ============================================================================
 Name        : huge_number_multiply.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int i_bits(int i)
{
	int result=0;
	unsigned int n = (unsigned)i;
	while(n)
	{
		n = (n>>1);
		result++;
	}

	return result;
}

enum
{
	FIRST,
	SECOND,
	THIRD,
	FORTH,
	FIFTH,
	N_BLOCK
};
void huge_number_multiply(int a, int b)
{
	int result[N_BLOCK];
	int i,j;
	int mult;
	for(i=0; i<N_BLOCK; i++)
		result[i] = 0;
	int ax[3], bx[3];
	for(i=0; i<3; i++)
	{
		ax[i] = a%10000;
		bx[i] = b%10000;

		a /= 10000;
		b /= 10000;
	}

	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
		{
			mult = ax[i]*bx[j];
			result[i+j] += mult % 10000;
			result[i+j+1] += mult / 10000;
		}
	// print result
	int is_highest = 0;
	for(i=N_BLOCK-1; i>=0; i--)
	{
		if(!is_highest)
		{
			if(result[i] == 0)
				continue;
			else
			{
				is_highest = 1;
				printf("%d",result[i]);
			}
		} else {
			printf("%04d", result[i]);
		}
	}
	putchar('\n');
}

/*
 * input should be positive number!
 */
int main(void) {
	int a,b;
	int i,j;

again:
	scanf("%d %d", &a, &b);
	if(a<0 || b<0)
	{
		printf("should be positive number!\n");
		goto again;
	}
	i=i_bits(a); j=i_bits(b);
	if(i+j<30)
	{
		printf("%d*%d=%d\n",a,b,a*b);
	} else
	{
		huge_number_multiply(a,b);
	}

	return EXIT_SUCCESS;
}
