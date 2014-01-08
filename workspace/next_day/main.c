/*
 * main.c
 *
 *  Created on: 2013-8-15
 *      Author: liusir
 */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	printf("please input date\n");
	printf("year month day\n");
	int month2day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year, month,day;
	scanf("%d %d %d",&year,&month,&day);
	if(month<=0 || month > 12)
	{
		printf("error!\n");
		return;
	}
	if(day<0 || day > month2day[month])
	{
	 if(!(day == 29 && month == 2 &&
				((year%100 != 0 && year%4 == 0) || year%400 == 0)))
		{
		 	printf("error!\n");
		 	return;
		}
	}

	day++;
	if(day<month2day[month])
		goto end;




end:
	printf("%d/%d/%d\n",year,month,day);
}
