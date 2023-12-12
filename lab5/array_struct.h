/**
 * @file array_struct.h
 * @author Elias Vargas
 * @brief Header file for array_struct.c
 * @date October 15 2023
 * 
 */

#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_
#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */
	
};

void init_array(struct data_t data[], int index, char id, int years, int inches);
int min_age(struct data_t data[]);
int min_height(struct data_t data[]);
int max_age(struct data_t data[]);
int max_height(struct data_t data[]);
float avg_age(struct data_t data[]);
float avg_height(struct data_t data[]);
void structprint(struct data_t data[], int i);
void dataprint(struct data_t data[]);

#endif
