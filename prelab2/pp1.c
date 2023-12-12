/**
 * @file pp1.c
 * @author Jessica Elias
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 #include <stdio.h>
 #include <stdlib.h>
 
 int main()
 {
    int number;
    int i;
    printf("Enter a number: \n");
    scanf("%d",&number);
    if (0 <= abs(number) && abs(number) <= 9){
        i=1;
    }
    if (10 <= abs(number) && abs(number) <= 99){
        i=2;
    }
    if (100 <= abs(number) && abs(number) <= 999){
        i=3;
    }
    if (1000 <= abs(number) && abs(number) <= 10000){
        i=4;
    }
    printf("%d digits",i);
    return 0;
 }