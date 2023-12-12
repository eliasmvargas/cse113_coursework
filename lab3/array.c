/**
 * @file array.c
 * @author Ely Knowles
 * @date 15 September 2023
 * Assignment: Lab 3
 * @brief Functions for fundamental array algorithms.
 * @details The functions implemented include basic counting,
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * selection sort.
 *
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */

#include "array.h"
#include <stdio.h>

int max, min, mid, x, count;

/**
 * @brief performs a selection sort on a given array
 * 
 * @param arr the array to be sorted
 * @param n number of elements in the array
 */
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/**
 * @brief performs a swap of two elements
 * 
 * @param xp element to be swapped
 * @param yp element to be swapped
 */
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/** 
 * @brief prints out the elements of an array, one element per line. For debugging purposes
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;

	for(i = 0; i < size; ++i)
		printf("a[%d] = %d\n", i, a[i]);
}

/** 
 * @brief prints out the largest element of an array
 * @param a[] array being operated on
 * @param size the size of the array
 * * @returns the max value
 * */

int find_max(int a[], size_t size){
    max = a[0];
    for (int i = 0; i < size; ++i){
        if (max < a[i]){
            max = a[i];
        }
    }
    return max;
}

/** 
 * @brief prints out the smallest element of an array
 * @param a[] array being operated on
 * @param size the size of the array
 * * @returns the min value
 * */
int find_min(int a[], size_t size){
    min = a[0];
    for (int i = 0; i < size; ++i){
        if (min > a[i]){
            min = a[i];
        }
    }
    return min;
}

/**
 * @brief finds the function midpoint
 * @param a[] array being operated on
 * @param size size of array
 * @returns midpoint
 */ 
int midpoint(int max, int min){
    mid = (min + max) / 2;
    return mid;
}

/**
 * @brief counts number of elements in an array with given parameters
 * @param a[] array being operated on
 * @param size size of array
 * @param type operator type, less than, greater than, equal to, etc.
 * @param x number for comparisons
 * @returns midpoint
 */ 
int get_count(int a[], size_t size, int type, int x){
    int count = 0;
    switch(type){
        case LT:
            for (int i = 0; i < size; i++){
                if (a[i] < x){
                    count = count + 1;
                }
            }
            break;
        case GT:
            for (int i = 0; i < size; i++){
                if (a[i] > x){
                    count = count + 1;
                }
            }
            break;
        case LTE:
            for (int i = 0; i < size; i++){
                if (a[i] <= x){
                    count = count + 1;
                }
            }
            break;
        case GTE:
            for (int i = 0; i < size; i++){
                if (a[i] >= x){
                    count = count + 1;
                }
            }
            break;
        case EE:
            for (int i = 0; i < size; i++){
                if (a[i] == x){
                    count = count + 1;
                }
            }
            break;
    }
    return count;
}

/**
 * @brief searches array for a given value
 * 
 * @param a array using
 * @param size size of array
 * @param x value to search for
 * @return index
 */
int linear_search(int a[], size_t size, int x){
    int indx = 0;
    int i = 0;

    while(i <= size & x != a[i]){
        i = i + 1;
    }

    if (i <= size){
        indx = i; // x was found in the list
    }
    else {
        indx = -1; // x was not found in the list
    }

    return indx;
}

/**
 * @brief Sums elements in array
 * 
 * @param a array using
 * @param size size of array
 * @return int sum of array
 */
int sum(int a[], size_t size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + a[i];
    }
    return sum;
}

/**
 * @brief averages an array
 * 
 * @param a array using
 * @param size size of array
 * @param foundsum found sum of array
 * @return float avg
 */
float average(int a[], size_t size, int foundsum){
    float avg = 0;
    avg = foundsum / size;
    return avg;
}

/**
 * @brief Reverses an array element
 * 
 * @param a array
 * @param size size of array
 * @return int reversed array
 */
void reverse(int a[], size_t size){
    int tmp;
    for(int i = 0; i < size/2; i++){
        tmp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = tmp;
    }
}

/**
 * @brief finds median value in an array
 * 
 * @param a - array
 * @param size size of array
 * @return int median
 */
int median(int a[], size_t size){
    int median;
    selectionSort(a, size);
    if (a[size] % 2 == 0){
        median = ((a[size / 2] + a[(size / 2) + 1]) / 2);
    }
    else {
        median = a[(size + 1) / 2];
    }

    return median;
}

/**
 * @brief finds number of even elements
 * 
 * @param a array
 * @param size array size
 * @return int count of even numbers
 */
int even_count(int a[], size_t size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (a[i] % 2 == 0){
            count = count + 1;
        }
    }
    return count;
}

/**
 * @brief finds number of odd elements
 * 
 * @param a array
 * @param size array size
 * @return int count of odd numbers
 */
int odd_count(int a[], size_t size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (a[i] % 2 == 1){
            count = count + 1;
        }
    }
    return count;
}

/**
 * @brief finds number of elements divisible by a given number
 * 
 * @param a array
 * @param size array size
 * @param x number to check mod
 * @return int count of divisible numbers
 */
int divisible_count(int a[], size_t size, int x){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (a[i] % x == 0){
            count = count + 1;
        }
    }
    return count;
}