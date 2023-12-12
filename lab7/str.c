/**
 * @file str.c
 * @author Elias Vargas
 * @brief Definitions for a bunch of pointer based operations

 * @date 2023-11-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cswap(char *c, char *d){
	int tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}


char *pindex(char *s, int c){
	/* this is here so the code compiles */
	int i;
	char * t = NULL;
	for (i = 0; i < str_len(s); i++){
		if (*(s + i) == c){
			t = (s + i);
			break;
		}
	}
	return t;
}


void reverse(char *s)
{
	int c, i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = c;
	}
	
}

/* concantenate t to the end of s; s must be big enough */
void str_cat(char *s, char *t)
{
	while (*s != '\0') 	/* find end of s */
		s++;
	while ((*s++ = *t++) != '\0') /* copy t */
		;
}


int str_len(char *s)
{
	/* this is here so code compiles */
	char *p = s;
	while (*p != '\0'){
		p++;
	}
	return p-s;
}


void str_ncpy(char *dest, char *src, int n){
	while (*src != '\0'){
		*dest++ = *src++;
	}
}


int str_ncmp(char *s, char *t, int n){
	/* this is here so the code compiles */
	int c = 0;
	int i;
	for (i = 0; i < n; i++){
		if (*(s + i) != (*(t + i))){
			if ((*(s + i)) < (*(t + i))){
				c = -1;
			}
			else {
				c = 1;
			}
		}
	}
	return c;
}




