// Author: Jan Jasa
// Assignment Title: My Functions
// Assignment Description: Create functions that do
// 	normal math functions such as min, max, etc;
// Due Date: 10/28/2022
// Date Created: 10/27/2022
// Date Last Modified: 10/27/2022
//

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include <cassert>

//MAX FUNCTIONS
/*
 * description: Function returns the value of the larger of two integers.
 * return: integer
 * precondition: two integer values exist
 * postcondition: The value of the largest integer is returned.
    The original integers are unchanged.
    If the integers have the same value then the value of
        either integer is returned.
*/
int max(int, int);

/*
 * description: Function returns the value of the larger of two doubles.
 * return: double
 * precondition: two double values exist
 * postcondition: The value of the largest double is returned.
    The original doubles are unchanged.
    If the doubles have the same value then the value of
        either double is returned.
*/
double max (double, double);

/*
 * description: Function returns the value
    of the largest integer in an array.
 * return: integer
 * precondition: an array of integer values exist
 * postcondition: The largest value in the array is returned.
The original array is unchanged
*/
int max(int m[], int n);

/*
 * description: Function returns the value
    of the largest double in an array.
 * return: double
 * precondition: an array of double values exist
 * postcondition: The largest value in the array is returned.
The original array is unchanged
*/
double max (double m[], double n);

//MIN FUNCTIONS
/*
 * description: Function returns the value of the
    smaller of two integers.
 * return: integer
 * precondition: two integer values exist
 * postcondition: The value of the smallest integer is returned.
    The original integers are unchanged
    If the integers have the same value then the
        value of either integer is returned.
*/
int min(int, int);

/*
 * description: Function returns the value of the
    smaller of two double.
 * return: double
 * precondition: two double values exist
 * postcondition: The value of the smaller double is returned.
    The original double are unchanged
    If the double have the same value then
        the value of either double is returned.
*/
double min(double, double);

/*
 * description: Function returns the value of the
    smallest integer in an array.
 * return: integer
 * precondition: an array of integer values exist
 * postcondition: The smallest value in the array is returned.
    The original array is unchanged
*/
int min(int m[], int n);

/*
 * description: Function returns the value of the
    smallest double in an array.
 * return: double
 * precondition: an array of double values exist
 * postcondition: The smallest value in the array is returned.
    The original array is unchanged
*/
double min(double m[], double n);

//ABSOLUTE VALUE FUNCTIONS
/*
 * description: This function returns the absolute
    value of an integer
 * return: Integer
 * precondition: Some integer value exists
 * postcondition: Integer value is unchanged
*/
int absoluteValue(int n);

/*
 * description: This function returns the absolute
    value of an double
 * return: double
 * precondition: Some double value exists
 * postcondition: double value is unchanged
*/
double absoluteValue(double n);

//FACTORIAL FUNCTIONS
/*
 * description: The function calculates factorial.
 * return: double
 * precondition: Some integer value N exists
 * postcondition: The value of the N unchanged
*/
double factorial(int n);

/*
 * description: The function calculates the number of combinations
    of M items taken N at a time.
 * return: The number of combinations of M items taken N at a time.
 * precondition: Two integer value M and N exists
 * postcondition: The value of the M and N unchanged
*/
double combination(int m, int n);

/*
 * description: The function calculates the number of permutations
    of M items taken N at a time.
 * return: The number of permutations of M items taken N at a time.
 * precondition: Two integer value M and N exists
 * postcondition: The value of the M and N unchanged
*/
double permutation(int m, int n);

#endif // MYFUNCTIONS_H_INCLUDED
