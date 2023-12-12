/**
 * @file init.c
 * @author Rhys Trembath, Elias Vargas
 * @brief prints 1 - 1000 using an array and for loop
 * @date 2023-09-15
 *
 */

#include <stdio.h>

void print_array(int a[1000], size_t len);

int main()
{
    int i = 0;
    int array[1000];

    for(; i <= 1000; i++)
    {
        array[i] = i + 1;
    }

    print_array(array, 1000);
}

/**
 * @brief print 1 - 1000 using array and for loop
 *  
 * @param a 
 * @param len 
 */


void print_array(int a[1000], size_t len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
}