/*
Author: Jan Jasa
Assignment Title: Quadratic Formula
Assignment Description: Calculate both roots of a quadratic
Due Date: 9/21/2022
Date Created: 9/19/2022
Date Last Modified: 9/20/2022

Data Abstraction:
    3 integers are used in quadratic formula
        with the formula ax^2 + bx + c
Input:
    The program reads the input and places them in a, b, c
Process:
    The program calculates the root and vertexes
Output:
    Depending on the root, the root or no real roots
        are shown
Assumptions: 3 integers are inputted
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a;
    double b;
    double c;
    double root1;
    double root2;
    double discrim;

    cin >> a;
    cin >> b;
    cin >> c;

    //calculate roots
    root1 = -b+sqrt(pow(b,2)-(4.0*a*c));
    root1 = root1/(2.0*a);
    root2 = -b-sqrt(pow(b,2)-(4.0*a*c));
    root2 = root2/(2.0*a);
    discrim = (pow(b,2));
    discrim = discrim-(4*a*c);
    if(root1>root2){
        swap(root1,root2); //least to greatest
    }
    //calculate vertexs
    double vertex1;
    double vertex2;
    vertex1 = (-b/(2.0*a));
    vertex2 = (-b/(2.0*a));
    vertex2 = (a*(pow(vertex2,2.0)))+(b*vertex2)+c;

    //fixes 0=-0
    if(root1==0 || root1==-0) {
        root1=0;
    }
    if(root2==0 || root2==-0){
        root2=0;
    }
    if(vertex1==-0){
        vertex1=0;
    }
    if(vertex2==-0){
        vertex2=0;
    }

    //output
    cout << fixed << setprecision(2) << endl;
    if(discrim<0){ //check for neg discrim
        cout << "NO REAL ROOTS" << endl;
    }
    else if(root1==root2){
        cout << root1 << endl;
    }
    else if(root1==0 && root2==0){
        cout << root1 << endl;
    }
    else {
        cout << root1 << " " << root2 << endl;
    }
    cout << "(" << vertex1 << "," << vertex2 << ")" << endl;

    return 0;
}
