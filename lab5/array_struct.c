/**
 * @file array_struct.c
 * @author Elias Vargas
 * @assignment Lab 5
 * @brief Performing various algorithms using an array of struct.
 * @date October 15 2023
 * 
 * 
 */

#include "array_struct.h"
#include <stdio.h>

/**
 * @brief Stores data in structs from function call inputs.
 * 
 * @param data Array of structs
 * @param i Struct array index
 * @param id Unique char ID of struct in array
 * @param years Age in years 
 * @param inches Height in inches
 */
void init_array(struct data_t data[], int i, char id, int years, int inches){
	data[i].subject = id;
	data[i].age = years;
	data[i].height = inches;
}

/**
 * @brief Finds struct index with the min age
 * 
 * @param data Struct array
 * @return int index of array with min age
 */
int min_age(struct data_t data[]){
	int min_index;
	min_index = 0;
	int min = data[0].age;
	for (int i = 0; i < SIZE; i++){
		if (min > data[i].age){
			min = data[i].age;
			min_index = i;
		}
	}
	return min_index;
}

/**
 * @brief Finds struct index with min height
 * 
 * @param data Struct array
 * @return int index of array with min height
 */
int min_height(struct data_t data[]){
	int min_index;
	min_index = 0;
	int min = data[0].height;
	for (int i = 0; i < SIZE; i++){
		if (min > data[i].height){
			min = data[i].height;
			min_index = i;
		}
	}
	return min_index;
}

/**
 * @brief Finds struct index with max age
 * 
 * @param data Struct array
 * @return int index of array with max age
 */
int max_age(struct data_t data[]){
	int max_index;
	max_index = 0;
	int max = data[0].age;
	for (int i = 0; i < SIZE; i++){
		if (max < data[i].age){
			max = data[i].age;
			max_index = i;
		}
	}
	return max_index;
}

/**
 * @brief Finds struct with max height
 * 
 * @param data Struct array
 * @return int index of array with max age
 */
int max_height(struct data_t data[]){
	int max_index;
	max_index = 0;
	int max = data[0].height;
	for (int i = 0; i < SIZE; i++){
		if (max < data[i].height){
			max = data[i].height;
			max_index = i;
		}
	}
	return max_index;
}

/**
 * @brief Finds the average of all ages
 * 
 * @param data Struct array
 * @return float of the average age
 */
float avg_age(struct data_t data[]){
	int average = 0;
	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum = sum + data[i].age;
	}
	average = sum / SIZE;
	return average;
}

/**
 * @brief Finds the average of all heights
 * 
 * @param data Struct array
 * @return float of the average height
 */
float avg_height(struct data_t data[]){
	int average = 0;
	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum = sum + data[i].height;
	}
	average = sum / SIZE;
	return average;
}

/**
 * @brief Prints the given struct
 * 
 * @param data Array of structs
 * @param i Index of struct in array to print
 */
void structprint(struct data_t data[], int i){
	printf("ID : %c \n", data[i].subject);
	printf("Age : %d \n", data[i].age);
	printf("Height : %d \n", data[i].height);
}

/**
 * @brief Uses all of the algorithms above, stores that, uses structprint to print structs of given index
 * 
 * @param data Array of structs
 */
void dataprint(struct data_t data[]){
	printf("Struct with min age: \n");
	int fmin_age = min_age(data);
	structprint(data, fmin_age);
	printf("Struct with min height: \n");
	int fmin_height = min_height(data);
	structprint(data, fmin_height);
	printf("Struct with max age: \n");
	int fmax_age = max_age(data);
	structprint(data, fmax_age);
	printf("Struct with max height: \n");
	int fmax_height = max_height(data);
	structprint(data, fmax_height);

 	/************/
	int f_avg_age = avg_age(data);
	printf("The average age is: %d \n", f_avg_age);

	/************/
	int f_avg_h = avg_height(data);
	printf("The average height is: %d \n", f_avg_h);

}

int main(void)
{

	struct data_t data[SIZE];

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);
	dataprint(data);
	return 0;
}

