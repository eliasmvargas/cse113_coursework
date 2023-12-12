/**
 * @file zombie.c
 * @author Elias Vargas
 * @brief Object file for the zombie program
 * @version 0.1
 * @date 2023-10-30
 * @bug Infinite print loop in the terminal when inputting more than 1 characer.. 
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "zombie.h"

/**
 * @brief Prints menu for input time and scans for values.
 * 
 * @param zombie_h our struct for all zombie info
 * @param i Struct array index
 */
void input_time(struct zombie zombie_h[i], int i){
    printf("Please choose the day this zombie was encountered: \n 1) Monday \n 2) Tuesday \n 3) Wednesday \n 4) Thursday \n 5) Friday \n 6) Saturday \n 7) Sunday\n");
    scanf("%d", &zombie_h[i].day);
    printf("Please enter the time this zombie was encountered. \n Separate hours, minutes, and seconds with colons. (HH:MM:SS)\n");
    scanf("%d:%d:%d", &zombie_h[i].hour, &zombie_h[i].min, &zombie_h[i].sec);
}

/**
 * @brief Prints menu for toe input and scans for values.
 * 
 * @param zombie_h our struct for all zombie info
 * @param i Struct array index
 */
void input_toes(struct zombie zombie_h[i], int i){
    printf("Please enter the number of toes the zombie had: \n"); 
    scanf("%d", &zombie_h[i].note.toes);
}

/**
 * @brief Prints menu for blood input and scans for values.
 * 
 * @param zombie_h our struct for all zombie info
 * @param i Struct array index
 */
void input_blood(struct zombie zombie_h[i], int i){
    printf("Please enter the amount of blood that oozed from its body after you eliminated it (in mL): \n");
    scanf("%f", &zombie_h[i].note.blood);
}

/**
 * @brief Prints all zombie data that is collected. 
 * 
 * @param zombie_h Struct for all zombie info. Uses a local variable k to print all entries in the data with a for loop.
 */
void print_zombies(struct zombie zombie_h[]){
	for(int k = 0; k < SIZE; k++){
        int ting = k + 1; // for indexing entries in the print statement
        if (zombie_h[k].dead == 'Y'){
            printf("\n \n \n %d)", ting);
            printf("This zombie was found DEAD.");
            printf("This zombie had %d toes.\n", zombie_h[k].note.toes);
            switch (zombie_h[k].day){
                case MONDAY:
                printf("This zombie was sighted on Monday");
                break;
                case TUESDAY:
                printf("This zombie was sighted on Tuesday");
                break;
                case WEDNESDAY:
                printf("This zombie was sighted on Wednesday");
                break;
                case THURSDAY:
                printf("This zombie was sighted on Thursday");
                break;
                case FRIDAY:
                printf("This zombie was sighted on Friday");
                break;
                case SATURDAY:
                printf("This zombie was sighted on Saturday");
                break;
                case SUNDAY:
                printf("This zombie was sighted on Sunday");
                break;
            }
            printf(" at %d:%d:%d. \n\n", zombie_h[k].hour, zombie_h[k].min, zombie_h[k].sec);
        }
        if (zombie_h[k].dead == 'N'){
            printf("\n \n \n %d)", ting);
            printf("This zombie was found ALIVE. ");
            printf("This zombie had %f mL of blood ooze from it.\n", zombie_h[k].note.blood);
            switch (zombie_h[k].day){
                case MONDAY:
                printf("This zombie was sighted on Monday");
                break;
                case TUESDAY:
                printf("This zombie was sighted on Tuesday");
                break;
                case WEDNESDAY:
                printf("This zombie was sighted on Wednesday");
                break;
                case THURSDAY:
                printf("This zombie was sighted on Thursday");
                break;
                case FRIDAY:
                printf("This zombie was sighted on Friday");
                break;
                case SATURDAY:
                printf("This zombie was sighted on Saturday");
                break;
                case SUNDAY:
                printf("This zombie was sighted on Sunday");
                break;
            }
            printf(" at %02d:%02d:%02d. \n\n", zombie_h[k].hour, zombie_h[k].min, zombie_h[k].sec);
        }
    }
}

/**
 * @brief Prints the starter menu in the terminal
 * 
 * @return int; this is for the while loop.
 */
int printmenu(void){
    while(1){
    printf(" 1) Enter new zombie information \n 2) Display zombie information \n 3) Return to fighting zombies (exit)\n");
    int n = 0;
    scanf("%d", &n);
    switch(n){
        case 1:
            printf("Was the zombie found dead? Y/N? Q to exit \n");
            scanf("%s", &zombie_h[i].dead); 
            zombie_h[i].dead = toupper(zombie_h[i].dead);
            while (zombie_h[i].dead != 'Y' && zombie_h[i].dead != 'N' && zombie_h[i].dead != 'Q') {
            printf("Please enter a valid character. \n");
            scanf("%s", &zombie_h[i].dead); 
            }
                switch(zombie_h[i].dead){
                    case 'Y':
                        input_toes(zombie_h, i);
                        input_time(zombie_h, i);
                        i++;
                        //printf("(debug index %d)\n", i);
                        break;
                    case 'N':
                        input_blood(zombie_h, i);
                        input_time(zombie_h, i);
                        i++;
                        //printf("(debug index %d)\n", i);
                        break;
                }
            break;
        case 2:
            print_zombies(zombie_h);
            break;
        case 3:
            printf("Stay alert! Keep a watch out for zombies!! \n \n GOODBYE and GOOD LUCK! \n \n ");
            return 0;
            break;
    }
}
return 0;
}