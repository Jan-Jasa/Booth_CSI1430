/*
Author: Jan Jasa
Assignment Title: Letter Grade
Assignment Description: Display average and letter grade
Due Date: 9/16/2022
Date Created: 9/4/2022
Date Last Modified: 9/16/2022

Data Abstraction:
    5 variables are initialized for use to store the data
Input:
    The program reads input and places them in "n1, n2,... n5"
Process:
    A series of if statements are used to determine if the
     test scores are valid
    A series of if statements are used to also determine the
     letter grade by comparing it to the minimum grade allowed
    A series of if statements are used to place the numbers in
     ascending order
Output:
    The average, letter grade, min, max, and median are displayed.
Assumptions:
    There are 5 numbers in the series
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;

    cout << "Please Enter Five Test Scores." << endl;
    cout << fixed << setprecision(2);
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    cin >> n5;
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;

    bool goodData = true; // Determines if the score is valid
    if (n1<0 || n1>100) {
        goodData = false;
    }
    if (n2<0 || n2>100) {
        goodData = false;
    }
    if (n3<0 || n3>100) {
        goodData = false;
    }
    if (n4<0 || n4>100) {
        goodData = false;
    }
    if (n5<0 || n5>100) {
        goodData = false;
    }
    if (goodData==false){
        cout << "\n";
        cout << "ERROR: BAD DATA" << endl;
    }

    double sum = n1+n2+n3+n4+n5;
    double avg = sum/5.0
    char grade;
    if(avg>=89.5){
        grade = 'A';
    }
    else if(avg>=79.5){
        grade = 'B';
    }
    else if(avg>=69.5){
        grade = 'C';
    }
    else if(avg>=59.5){
        grade = 'D';
    }
    else{
        grade = 'F';
    }

    double T; // temp value holder
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

    if(goodData==true){
        cout << "\n";
        cout << fixed << setprecision(2);
        cout << "Average = " << avg << endl;
        cout << "Grade   = " << grade << endl;
        cout << "Min     = " << minimum << endl;
        cout << "Max     = " << maximum << endl;
        cout << "Median  = " << median << endl;
    }




    return 0;
}
