/*
Author: Jan Jasa
Assignment Title: Program 4 - Sum the digits
Assignment Description: Reads and sums the digits in the inputted integer.
Due Date: 8/31/2022
Date Created: 8/30/2022
Date Last Modified: 8/31/2022

Data Abstraction:
    n is used as a placeholder for the input
    sum is initialized to hold the value of the digits added together
Input:
    The program reads the input and stores it in variable n.
Process:
    The remainder of n divided by 10 is taken and added to sum
        n is divided by 10 in order to gain the next digit.
Output:
    The sum of all the digits originally found in n are printed to the screen
Assumptions:
    It is assumed that the input is between 0 and 9999999
*/

#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main()
{
    int n;
    int sum=0;

    cin >> n;
    cout << "Enter an integer between 0 and 9999999: " << n << endl;

    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;

    cout << "The sum of the digits is " << sum << "." << endl;
    return 0;
}
