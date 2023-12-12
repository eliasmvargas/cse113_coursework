/* compile: gcc -g -Wall dynamic_array.c -o da */
/* execute: ./da < data */

#include <stdio.h>
#include <stdlib.h>

#define LEN 100
#define boi 11

struct stringfo{
    int smax;
    int smin;
    int smedian;
    int smum;
};

struct stringfo stringy_h;

/** 
 * @brief prints out the largest element of an array
 * @param ptr string being operated on
 * * @returns the max value
 * */

int find_max(int* ptr){
    int max = *ptr;
    for (int i = 0; i < boi; ++i){
        if (max < (ptr[i])){
            max = (ptr[i]);
        }
    }
    return max;
}

/** 
 * @brief prints out the smallest element of an array
 * @param ptr string being operated on
 * * @returns the min value
 * */
int find_min(int* ptr){
    int min = *ptr;
    for (int i = 0; i < boi; ++i){
        if ((ptr[i]) < min)  {
            min = (ptr[i]);
        }
    }
    return min;
}

/**
 * @brief Sums elements in array
 * @param ptr string using
 * @return int sum of array
 */
int sum(int *ptr){
    int sum = 0;
    for (int i = 0; i < boi; i++){
        sum = sum + ptr[i];
    }
    return sum;
}


/**
 * @brief finds median value in an array
 * @param ptr string using
 * @return int median
 */
int median(int *ptr){
    int median;
    if (ptr[boi] % 2 == 0){
        median = ((ptr[boi / 2] + ptr[(boi / 2) + 1]) / 2);
    }
    else {
        median = ptr[(boi + 1) / 2];
    }

    return median;
}

/**
 * @brief prints the struct of the info
 * 
 * @param string_h 
 */
void print_stringy(struct stringfo string_h){
    printf("____________STATS___________\n");
    printf("Max: %d \n", string_h.smax);
    printf("Min: %d \n", string_h.smin);
    printf("Sum: %d \n", string_h.smum);
    printf("Median: %d \n", string_h.smedian);


}

int main()
{
    FILE *fp = fopen("data", "r");
    char a[LEN];
    int d; /* holds integer to be added to array */
    int count = 0;
    int* ptr = NULL; 


    while(count < boi && fgets(a, LEN, fp)){
        /* scan the input integer into d */
         sscanf(a, "%d", &d);
        ptr = (int *)realloc(ptr, (count + 1) * sizeof(int));
        ptr[count] = d;
        count++;
    }

    printf("String Output:\n");
        for (int i = 0; i < boi; i++){
            printf("%d", *(ptr+i));
        }
    printf("\n");

    stringy_h.smax = find_max(ptr);
    stringy_h.smin = find_min(ptr);
    stringy_h.smum = sum(ptr);
    stringy_h.smedian = median(ptr);
    print_stringy(stringy_h);
    
    free(ptr);

    return 0;
}




