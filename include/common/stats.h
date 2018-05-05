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
 * @file stats.h
 * @author Mohamed Ismail
 * @date 23/12/2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <print array function>
 *
 * function that take two arguments and iterate over input array
 * and prints it in well formated style
 *
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * 
 * @return function return void
 */
void print_array ( unsigned char test[] , int size);

/**
 * @brief <sort array function>
 *
 * function that take two arguments and iterate over input array
 * and sorted it using buble sort algorithm 
 *
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * 
 * @return function return void
 */

void sort_array ( unsigned char test[] , int size);

/**
 * @brief <find_median function>
 *
 * function that take two arguments and find the middle element of the given array
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * 
 * @return function return void
 */

int find_median ( unsigned char test[] , int size);

/**
 * @brief <find_mean function>
 *
 * function that take two arguments and calculate the average of the given array
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * 
 * @return function return void
 */

int find_mean ( unsigned char test[] , int size);

/**
 * @brief <find_max function>
 *
 * function that take two arguments and find the maximum element in the given array
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * 
 * @return function return void
 */

int find_maximum ( unsigned char test[] , int size);

/**
 * @brief <find_min function>
 *
 * function that take two arguments and find the minimum element of the given array
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * @return function return void
 */

int find_minimum ( unsigned char test[] , int size);

/**
 * @brief <find_statistics function>
 *
 * function that take two arguments and print all statistics of given array
 * including minimum, maximum, mean, and median
 * @param test -> first argument which contain the arry 
 * @param siz -> secound arg indecate to size of the given array
 * @return function return void
 */
void print_statistics(unsigned char test[] , int size);

#endif /* __STATS_H__ */