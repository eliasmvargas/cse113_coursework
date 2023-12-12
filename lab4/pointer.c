#include<stdio.h>


int main() 
{
	int *p;
	int a, b;
	a = 0;
	b = 1;
	
	//p = a;
	p = &a;

	printf("%d\n", *p); 

	//b = &p;
	p = &b;
	
	printf("%d\n", b); 

 	return 0;
}
