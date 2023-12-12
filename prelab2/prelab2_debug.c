/**
 * @file prelab2_debug.c
 * @author Jessica Elias
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * 
 * 
 */

//missing .h in stdio.h
#include <stdio>

void main()
{
    char input;

    printf("Enter a character: \n");
    //Does not say &input
    //Wrong type of variable
    scanf("%f", input);

    switch(input){
        case 'a':
            //missing break
            printf("A is for apple. \n");
        //should end with colon not semicolon
        case 'b';
            //\n is the wrong slash
            printf("B is for Banana!/n");
            break;
        default:
            //Wrong type of variable
            printf("The letter %d isn't important!\n", input);
    }
    return 0;
}