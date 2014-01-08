/*
 ============================================================================
 Name        : fork_var.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>

int main(void) {
	int i;
	pid_t pid;
	i = 0;
	pid = fork();
	if(pid<0)
		puts("error\n"); /* prints !!!Hello World!!! */
	else if(pid == 0)
	{
		i++;
		printf("child:%d\n",i);
	}
	else
	{
		i++;
		printf("parent:%d\n",i);
	}
	return EXIT_SUCCESS;
}
