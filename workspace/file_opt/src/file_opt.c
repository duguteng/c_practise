/*
 ============================================================================
 Name        : file_opt.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void test_r_w_data(void)
{
	FILE * fp;
		int array1[20], array2[40];
		int i;
		for(i=0;i<20;i++)
			array1[i] = i+20;

	// write ascii
		if((fp = fopen("array.txt","w")) == NULL)
		{
			fprintf(stdout, "open %s in mode %s error!\n","array.txt", "w");
			exit(1);
		}

		for(i=0;i<20;i+=2)
		{
			fprintf(fp,"%d %d\n",array1[i],array1[i+1]);
		}
		printf("txt write succeeded!\n");
		fclose(fp);
		fp = NULL;

	// write binary
		if((fp = fopen("array.dat","wb")) == NULL)
		{
			printf("open array.dat in mode wb error!\n");
			exit(1);
		}
		if(fwrite(array1, sizeof(array1[0]),20,fp) != 20)
			printf("dat write failed!\n");
		else
			printf("dat write succeeded!\n");
		fclose(fp);
		fp = NULL;

		// read binary
		if((fp = fopen("array.dat","rb")) == NULL)
		{
			printf("open array.dat in mode rb error\n");
			exit(1);
		}
		if(fread(array2,4,10,fp) != 10)
			printf("read error");

		printf("file pointer is in %ld\n",ftell(fp));
		rewind(fp);
		printf("file pointer is in %ld\n",ftell(fp));

		if(fread(array2+10,4,20,fp) != 20)
				printf("read error");

		fseek(fp,5*4,SEEK_SET);
		if(fread(array2+30,4,10,fp) != 10)
				printf("read error");


		for(i=0; i<40; i+=2)
			printf("%d %d\n",array2[i], array2[i+1]);

}

void test_r_w_string(void)
{
	char *pstr[5] = {
			"hello\n",
			"I am liusir\n",
			" nothing\n",
			"line 4\n",
			"line 5\n"
	};

	char str1[20], str2[20];
	FILE *fp;

	if((fp = fopen("text.txt","w+")) == NULL)
	{
		printf("error\n");
		exit(1);
	}

	int i;
	for(i=0; i<5; i++)
		if(fputs(pstr[i],fp) == EOF)
		{
			printf("writing error\n");
			exit(1);
		}
	rewind(fp);

	while(!feof(fp))
	{
		fgets(str1,20,fp);
		//fputs(str1, stdout);
		puts(str1);
	}
	//getchar();
	fclose(fp);
}

int main(void) {
	//test_r_w_data();
	test_r_w_string();

	return EXIT_SUCCESS;
}
