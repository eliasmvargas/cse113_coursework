/**
 * @file credit.c
 * @author
 * @date
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALID 0
#define INVALID -1

void print_card(int card[], int size);
void luhns(int card[], int size);

int main(void)
{
	int num_digits; 	/* use to determine number of digits in credit card */
	//int card[] = {4,0,1,2,8,8,8,8,8,8,8,8,1,8,8,1}; /* valid card */
	int card[] = {4,0,1,2,8,8,8,8,8,8,8,8,1,8,8,2}; /* invalid card */
	//int card[] = {3,8,5,2,0,0,0,0,0,2,3,2,3,7};
	
	num_digits = sizeof(card) / sizeof(int);

	print_card(card, num_digits);
	luhns(card, num_digits);
	// print_card(card, num_digits); //debug purposes
	
	return 0;

}

/**
 * @brief prints a credit card number separated by location within an array. 
 *        Used for debugging purposes. Should not be called in final program.
 * @param card 
 * @param size size of card array
 */
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/**
 * @brief Applies luhn's algorithm to a given array of card numbers
 * @param card 
 * @param size Size of card array
 */
void luhns(int card[], int size){

	int card_sum = 0;

	for (int i = size - 2; i >= 0; i = i - 2){ 
		card[i] = card[i] * 2;
	}

	for (int i = 0; i < size; i++){
		card_sum = (card[i] / 10) + (card[i] % 10) + card_sum;
	}

	if (card_sum % 10 == 0){
		printf("The card is valid \n");
		//printf("DEBUG %d\n", mod);
		//printf("DEBUG %d\n", card_sum);
	}
	else {
		printf("The card is invalid \n");
		//printf("DEBUG %d\n", mod);
		//printf("DEBUG %d\n", card_sum);
	}

}