/*
Author: Jan Jasa
Assignment Title: Min Max Median
Assignment Description: Display means and deviation
Due Date: 9/14/2022
Date Created: 9/13/2022
Date Last Modified: 9/14/2022

Data Abstraction:
    5 variables are initialized for use to store the scores
Input:
    The program reads input and places them in "n1, n2,... n5"
Process:
    A series of if statements are used to place the numbers in
     ascending order
    The min, max, and median are then set using the sorted data
Output:
    The data in ascending order is outputted,
     along with the min, max, and median
Assumptions:
    There are 5 numbers in the series
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;
    double T;

    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    cin >> n5;
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;

    if (n1>n2) {
        T=n1;
        n1=n2;
        n2=T;
    }
    if (n1>n3) {
        T=n1;
        n1=n3;
        n3=T;
    }
    if (n1>n4) {
        T=n1;
        n1=n4;
        n4=T;
    }
    if (n1>n5) {
        T=n1;
        n1=n5;
        n5=T;
    }
    if (n2>n3){
        T=n2;
        n2=n3;
        n3=T;
    }
    if (n2>n4) {
        T=n2;
        n2=n4;
        n4=T;
    }
    if (n2>n5) {
        T=n2;
        n2=n5;
        n5=T;
    }
    if (n3>n4) {
        T=n3;
        n3=n4;
        n4=T;
    }
    if (n3>n5) {
        T=n3;
        n3=n5;
        n5=T;
    }
    if (n4>n5) {
        T=n4;
        n4=n5;
        n5=T;
    }
    double minimum = n1;
    double maximum = n5;
    double median = n3;

    cout << "\n" << endl;
    cout << "Min    = " << minimum << endl;
    cout << "Median = " << median << endl;
    cout << "Max    = " << maximum << endl;

    return 0;
}
