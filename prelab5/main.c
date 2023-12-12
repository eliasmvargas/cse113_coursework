#include <stdio.h>
#include "vector.h"
#include "vector.c"


int main(void)
{	
	int arr_size = sizeof(a1) / sizeof(a1[0]);
	int arr_size6 = sizeof(a6) / sizeof(a6[0]);
	int c4[arr_size];
	int c5[arr_size];
	int c6[arr_size6];
	int a8[arr_size];

	multiply(a1, arr_size, 5);
	adding(a2, arr_size, 3);
	copy(a3, arr_size, b3);
	combine(a4, arr_size, b4, c4);
	product(a5, arr_size, b5, c5);
	invertedproduct(a6, arr_size6, b6, c6);
	reverse(a7, arr_size6);
	randomarr(a8, arr_size, 50);


	print_array(a1, arr_size);
	printf("++++++++++++++++++++++\n"); // Visual seperation
	print_array(a2, arr_size);
	printf("++++++++++++++++++++++\n");
	print_array_b(b3, arr_size);
	printf("++++++++++++++++++++++\n");
	print_array_c(a4, arr_size, b4, c4);
	printf("++++++++++++++++++++++\n");
	print_array_c(a5, arr_size, b5, c5);
	printf("++++++++++++++++++++++\n");
	print_array_c(a6, arr_size6, b6, c6);	
	printf("++++++++++++++++++++++\n");
	print_array(a7, arr_size6);
	printf("++++++++++++++++++++++\n");
	print_array(a8, arr_size);
	return 0;
}
