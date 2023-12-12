/**
 * @file init.c
 * @author Rhys Trembath, Elias Vargas
 * @brief stores 1 - 1000 in an array before printing it out.
 * @date 2023-09-15
 *
 */

#include <stdio.h>

int main()
{
    int i = 1;
    int array[1000];

    for(; i <= 1000; i++)
    {
        array[999] = i;
        printf("The number is %d\n",array[999]);
    }
}