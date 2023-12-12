#include <stdio.h>

int main()
{
    double p = 3.14159;

    /* assignment code goes here */
    double *e;
    e = &p;
    *e = 2.71828;

    printf("Address of P: %p \n", &p);
    printf("Value of P: %lf\n", p);
    printf("Address of pointer: %p\n", e);
    printf("Value of pointer: %lf\n", *e);


    return 0;
}