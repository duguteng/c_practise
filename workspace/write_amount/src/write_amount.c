/*
 ============================================================================
 Name        : write_amount.c
 Author      : liusir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


void write_amount(unsigned int amount, char *buffer)
{
	unsigned int tmp;
	char *tens[10] = {
			"", "", " TWENTY", " THIRTY"," FORTY",
			" FIFTY"," SIXTY"," SEVENTY"," EIGHTY"," NINTY"
	};
	char *ones[20] ={
			""," ONE", " TWO", " THREE", " FOUR", " FIVE",
			" SIX", " SEVENT", " EIGHT", " NINE", " TEN",
			" ELEVENT", " TWELVE", " THIRTEEN", " FOURTEEN",
			" FIFTEEN", " SIXTEET", " SEVENTEEN", " EITHTEEN"
			" NINTEEN"
	};
	if((tmp = amount/1000000000) > 0)
	{
		write_amount(tmp, buffer);
		strcat(buffer, " BILLION");
		amount = amount % 1000000000;
	}
	if((tmp = amount/1000000) > 0)
	{
		write_amount(tmp, buffer);
		strcat(buffer, " MILLION");
		amount = amount % 1000000;
	}
	if((tmp = amount/1000) > 0)
	{
		write_amount(tmp, buffer);
		strcat(buffer, " THOUSAND");
		amount = amount % 1000;
	}
	if((tmp = amount/100) > 0)
	{
		write_amount(tmp,buffer);
		strcat(buffer, " HANDRED");
		amount = amount % 100;
		if(amount != 0)
			strcat(buffer, " AND");
	}
	if(amount >= 20)
	{
		tmp = amount/10;
		strcat(buffer, tens[tmp]);
		amount %= 10;
	}
	strcat(buffer, ones[amount]);

}

int main(void) {
	char *buffer;
	buffer = (char*)malloc(200);
	memset(buffer,0, 200);
	write_amount(12190, buffer);
	puts(buffer);
	return EXIT_SUCCESS;
}
