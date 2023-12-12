/**
 * @file multiply.c
 * @author Rhys Trembath, Elias Vargas
 * @brief Calculate a factorial from two inputs
 * @date 2023-09-15
 *  
 */
#include <stdio.h>

int multiply(int start, int stop);

int main()
{

    int begin, end;

    int multi;

    printf("Enter a starting integer: ");
    scanf("%d", &begin);

    printf("Enter the end number: ");
    scanf("%d", &end);

    multi = multiply(begin, end);

    printf("The fractorial is: %d\n", multi);

}
/**
 * @brief Takes two inputs as start and stop being going through a for loop to calculate the factorial.
 * 
 * @param start 
 * @param stop 
 * @return int 
 */
int multiply(int start, int stop)
{
    int product = 1;
    int i;

    if (start > stop){
        int tmp;
        tmp = start;
        start = stop;
        stop = tmp;
    }

    for(i = start; i <=stop; i++)
    {
        product = product * i;

    }

    return product;
}