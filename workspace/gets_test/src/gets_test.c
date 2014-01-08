/*
 ============================================================================
 Name        : gets_test.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array[20];
	int i = 0;
	do
	{
		char c;
		scanf("%d",&array[i++]);
		do
		{
			c = getchar();
			if(c == '\n')
				goto end;
		}while(c<'0' || c>'9');

		ungetc(c,stdin);
	}while(1);
end:
	i--;
	while(i>=0)
		printf("%d ",array[i--]);
	return EXIT_SUCCESS;
}
