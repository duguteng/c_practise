/*
 * string_lib.h
 *
 *  Created on: 2013-9-3
 *      Author: liusir
 */

#ifndef STRING_LIB_H_
#define STRING_LIB_H_
#include <stdio.h>

typedef int size_t;

static size_t strlen(const char *str)
{
	size_t n = 0;
	while(str[n] != '\0')
		n++;
	return n;
}

static char* strcpy(char *dest, const char *source)
{
	char *p, *q;
	p = dest;
	q = source;
	while((*p++ = *q++) != '\0');

	return dest;
}

static char *strncpy(char *dest, const char *source, size_t n)
{
	char *p, *q;
	for(p=dest,q=source; --n>=0 && (*p++ = *q++)!='\0';);
	return dest;
}

static char *strdup(char *source)
{
	int n;
	char *p = NULL;
	n = strlen(source);
	if(n>0)
		if((p = (char*)malloc(n+1)) != NULL)
			strcpy(p, source);
	return p;
}

static char *strcat(char *str1, char* str2)
{
	char *p;
	p = str1 + strlen(str1);
	strcpy(p,str2);
	return str1;
}

static char *strncat(char *str1, char *str2, size_t n)
{
	char *p;
	p = str1 + strlen(str1);
	strncpy(p,str2,n);
	return str1;
}

/*
 * return -1, 0, 1
 */
static int strcmp(const char *str1, const char *str2)
{
	int res=0;
	for(;*str1 != '\0' && *str2 != '\0' && res==0; str1++, str2++)
		res = *str1 - *str2;
	if (res != 0) return res;

	if(*str1 == '\0' && *str2 != '\0')
		res = -1;
	else if(*str2 == '\0' && *str1 != '\0')
		res = 1;

	return res;
}

static int strncmp(const char *str1, const char *str2, size_t n)
{
	int res=0;
	for(;*str1 != '\0' && *str2 != '\0' && res==0 && n-- > 0; str1++, str2++)
		res = *str1 - *str2;
	if (res != 0 || n <= 0) return res;

	if(*str1 == '\0' && *str2 != '\0')
		res = -1;
	else if(*str2 == '\0' && *str1 != '\0')
		res = 1;

	return res;
}

static char* strchr(const char *str, int ch)
{
	while(*str != '\0' && *str != ch)
		str++;
	if(*str == '\0') return NULL;
	return str;
}

static char* strrchr(const char *str, int ch)
{
	char *p = NULL;
	while(*str != '\0')
		if(*str == ch)
			p = str;
	return p;
}

/*
 * NOTE: return strlen(str1) if all missing match
 */
static size_t strcspn(const char *str1, const char * str2)
{
	char array[127];
	char *p;
	int i;
	for(i=0; i<127; i++)
		array[i] = 0;
	for(p=str2; *p!='\0'; p++)
		array[*p]++;

	for(p=str1; *p !='\0'; p++)
		if(array[*p]>0)
				break;

	return p-str1;
}

static size_t strspn(const char *str1, const char * str2)
{
	char array[127];
	char *p;
	int i;
	for(i=0; i<127; i++)
		array[i] = 0;
	for(p=str2; *p!='\0'; p++)
		array[*p]++;

	for(p=str1; *p !='\0'; p++)
		if(array[*p]==0)
				break;

	return p-str1;
}

static char *strpbrk(const char *str1, const char *str2)
{
	char array[127];
	char *p;
	int i;
	for(i=0; i<127; i++)
		array[i] = 0;
	for(p=str2; *p!='\0'; p++)
		array[*p]++;

	for(p=str1; *p !='\0'; p++)
		if(array[*p]>0)
				break;

	if(*p == '\0') return NULL;
	return p;
}

/*
 * return:
 * 	NULL if all miss match.
 * 	0 if strlen(str2) == 0.
 */
static char *strstr(const char *str1, const char *str2)
{
	char *p=NULL, *q=NULL, *r=NULL;
	for(p=str1; *p != '\0'; p++)
	{
		for(q=str2,r=p;*q!='\0' && *r!='\0'; q++, r++)
			if(*q != *r)
				break;
		if(*q == '\0')
			break;
	}
	if(q!=NULL && *q == '\0')
		return p;
	return NULL;
}

static char *strlwr(char *str)
{
	char *p;
	for(p=str; p!=NULL && *p != '\0'; p++)
		if(*p>='A' && *p <= 'Z')
		{
			*p -= 'A';
			*p += 'a';
		}
	return str;
}

static char *strupr(char *str)
{
	char *p;
	for(p=str; p!=NULL && *p != '\0'; p++)
		if(*p>='a' && *p <= 'z')
		{
			*p -= 'a';
			*p += 'A';
		}
	return str;
}

static char *strrev(char *str)
{
// TODO
	return str;
}

#endif /* STRING_LIB_H_ */
