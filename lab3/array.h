/**
 * @file array.h
 * @author Ely Knowles
 * @date 15 Spetember 2023
 * Assignment: Lab 3 
 * @brief header file for array.c
 * @details see array.c for details
 * @bugs none
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#define LT 10
#define GT 15
#define LTE 20
#define GTE 25
#define EE 30

#include <stdlib.h> 		/* for size_t declaration */


void print_array(int a[], size_t size);
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);
void print_summary(size_t size, int found_max, int found_min, int found_midpoint, int GT_midpoint, int LT_midpoint, int searchvalue, int foundsum, float foundavg, int foundmed, int evens, int odds, int min_divisibles);

/* your function declarations go here */

int find_max(int a[], size_t size);
int find_min(int a[], size_t size);
int midpoint(int min, int max);
int get_count(int a[], size_t size, int type, int x);
int linear_search(int a[], size_t size, int x);
void reverse(int a[], size_t size);
int sum(int a[], size_t size);
float average(int a[], size_t size, int foundsum);
int median(int a[], size_t size);
int even_count(int a[], size_t size);
int odd_count(int a[], size_t size);
int divisible_count(int a[], size_t size, int x);


#endif

