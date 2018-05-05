/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @author Mohamed Ismail
 * @date 23/12/2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
    print_array(test,SIZE);
    print_statistics(test,SIZE);
    sort_array(test,SIZE);
    
  
}

/* Add other Implementation File Code Here */
void print_array( unsigned char test[] , int size) {
    printf("{ ");
  
    for (int i = 0; i < size ; i++) {
            
        printf("%d ",test[i]);
        if (i < size-1) {
            printf(",");
        }
        if ( (i+1)% 5 == 0 && i < size-1) {
            printf("\n  ");
        }
    }
        
    printf("}\n");       
}



int find_maximum ( unsigned char test[] , int size) {
    
    int max = 0;
    
    for (int i = 0 ; i < size; i++) {
        
        if(max < test[i]) {
            max = test[i];
        }
    }
    return max;
}

int find_minimum ( unsigned char test[] , int size) {
    
    int min = test[0];
    
    for (int i = 0 ; i < size; i++) {
        
        if(min > test[i]) {
            min = test[i];
        }
    }
    return min;
    
}


int find_median ( unsigned char test[] , int size) {
    
    int n;
    
    if (size % 2 == 0) {
        n = size/2;
        return (test[n-1]+test[n])/2;
    }else {
        n = size/2;
        return test[n];
    }
    
}

int find_mean ( unsigned char test[] , int size) {
    
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += test[i];
    }
    return sum/size;
}

void print_statistics(unsigned char test[] , int size) {
    
    printf("minimum is ( %d ) \n",find_minimum(test,size));
    printf("maximum is ( %d ) \n",find_maximum(test,size));
    printf("median is ( %d ) \n",find_median(test,size));
    printf("mean is ( %d ) \n",find_mean(test,size));
    
}

void sort_array ( unsigned char test[] , int size) {

    int temp;
    
    for (int i = 0 ; i < size; i++) {
        
        for (int j = 0; j < size; j++) {
            if(test[j] < test[i]) {
                temp = test[j];
                test[j] = test[i];
                test[i] = temp;
            }
        }
        
    }
    print_array (test,size);
}
