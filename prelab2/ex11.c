/**
 * @file ex11.c
 * @author Jessica Elias
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
 int main()
{
    int area_code;
    printf("Enter an area code: ");
    scanf("%d",&area_code);
    switch(area_code){
        case 229:
            printf("Albany\n");
            break;
        case 404:
            printf("Atlanta\n");
            break;
        case 470:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon\n");
            break;
        case 678:
            printf("Atlanta\n");
            break;
        case 706:
            printf("Columbus\n");
            break;
        case 762:
            printf("Columbus\n");
            break;
        case 770:
            printf("Atlanta\n");
            break;
        case 912:
            printf("Savannah\n");
            break;
        default:
            printf("Area code not recognized. \n");
    }
    return 0;
}