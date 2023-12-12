#include <stdio.h>

int main()
{
    int i = 1000;
    while(i >= 1)
    {
        printf("T minus %d\n", i);
        --i;
    }
}