#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

void multiply(int a1[], size_t size, int z){
    for (int i = 0; i < size; i++){
        a1[i] = a1[i] * z;
    }

}

void adding(int a2[], size_t size, int z){
    for (int i = 0; i < size; i++){
        a2[i] = a2[i] + z;
    }
}

void print_array(int a1[], size_t size){
    for(int i = 0; i < size; i++){
        printf("a[%d] = %d\n", i, a1[i]);
    }
}

void print_array_b(int a1[], size_t size){
    for(int i = 0; i < size; i++){
        printf("b[%d] = %d\n", i, a1[i]);
    }
}

void print_array_c(int a4[], size_t size, int b4[], int c4[]){
    print_array(a4, size);
    print_array_b(b4, size);
      for(int i = 0; i < size; i++){
        printf("c[%d] = %d\n", i, c4[i]);
    }
}



void copy(int a3[], size_t size, int b3[]){
    for(int i = 0; i < size; i++){
        b3[i] = a3[i];
    }
}

void combine(int a4[], size_t size, int b4[], int c4[]){
    for(int i = 0; i < size; i++){
       c4[i] = b4[i] + a4[i];
    }
}

void product(int a5[], size_t size, int b5[], int c5[]){
    for(int i = 0; i < size; i++){
       c5[i] = b5[i] * a5[i];
    }
}

void invertedproduct(int a6[], size_t size, int b6[], int c6[]){
    for(int i = 0; i < size; i++){
       c6[i] = b6[size - 1 - i] * a6[i];
    }
}

void reverse(int a7[], size_t size){
    int m;
    for(int i = 0; i < size/2 ; i++){
        m = a7[i];
        a7[i] = a7[size - 1 - i];
        a7[size - 1 - i] = m;
    }
}

void randomarr(int a8[], size_t size, int k){
    srandom(time(NULL));
    for(int i = 0; i < size; i++){
        a8[i] = get_random_int(k);
    }
}

int get_random_int(int n){
    return random() % n;
}

/* Define all of your functions here for your Array Problems, #1-8 */
