/*
Author: Jan Jasa
Assignment Title: Mean
Assignment Description: Display means and deviation
Due Date: 9/9/2022
Date Created: 9/7/2022
Date Last Modified: 9/9/2022

Data Abstraction:
    5 variables are initialized for use to store the data
Input:
    The program reads input and places them in "n1, n2,... n5"
Process:
    A series of if statements are used to place the numbers in
     ascending order
    The arithmetic, geometric, and harmonic mean are also
     calculated before their output
Output:
    The data in ascending order is outputted,
     along with the different means and deviation
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
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int T;

    cout << "Enter five numbers: " << endl;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    cin >> n5;
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << n5 << endl;

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



    cout << "Result: " << endl;
    cout << "\n";
    cout << "Data: " << endl;
    cout << n5 << endl;
    cout << n4 << endl;
    cout << n3 << endl;
    cout << n2 << endl;
    cout << n1 << endl;

    double ArithMean;
    ArithMean = (n1+n2+n3+n4+n5)/5.0;
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << ArithMean << endl;

    long double GeoMean;
    GeoMean = pow(n1,(0.2))*pow(n2,(0.2))*pow(n3,(0.2))
    *pow(n4,(0.2))*pow(n5,(0.2));
    cout << "Geometric Mean = " << GeoMean << endl;

    double HarmonicMean;
    double InverseHolder; // to process reciprocals
    InverseHolder = (1.0/n1)+(1.0/n2);
    InverseHolder = InverseHolder + (1.0/n3);
    InverseHolder = InverseHolder + (1.0/n4);
    InverseHolder = InverseHolder + (1.0/n5);
    HarmonicMean = 5/InverseHolder;
    cout << "Harmonic Mean = " << HarmonicMean << endl;

    double deviation;
    deviation = sqrt((pow((n1-ArithMean),2)
    +pow((n2-ArithMean),2)+pow((n3-ArithMean),2)
    +pow((n4-ArithMean),2)+pow((n5-ArithMean),2))/5);
    cout << "Standard Deviation = " << deviation << endl;


}
