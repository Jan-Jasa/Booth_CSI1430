/*
Author: Jan Jasa
Assignment Title: Multiplication Table
Assignment Description: This program will read 4 integers and
    generate a multiplication table from R1-R2 and C1-C2
Due Date: 10/21/2022
Date Created: 10/20/2022
Date Last Modified: 10/21/2022

Data Abstraction:
    r1, r2, c1, c2, numR, numC, Row, cOl
    rCount, cCount, rShift, cShift are initialized
    to be used later on
    data is initialized to hold the variables of the table
Input:
    The program will read r1, r2, c1, c2 from the input
Process:
    The program will build a multiplication table from r1 to r2 by c1 to c2
Output:
    The multiplication table is printed out to the screen
Assumptions:
    No products should be larger than 3 characters, max size is 25x25
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    //Data Abstraction
    int r1;
    int r2;
    int c1;
    int c2;
    int numR;
    int numC;
    int Row;
    int Col;
    int rCount=0;
    int cCount=0;
    int rShift=1;
    int cShift=1;
    int data[25][25];

    //Input
    cout << "Please Enter Four Integers R1 R2 C1 C2: ";
    cin >> r1 >> r2 >> c1 >> c2;
    cout << r1 << " " << r2 << " " << c1 << " " << c2 << endl;

    //use in output
    numR = abs(r1-r2)+1;
    numC = abs(c1-c2)+1;

    //Process
    if(r1>r2){
        rShift = -1;
    }

    if(c1>c2){
        cShift = -1;
    }

    rCount=0;
    for(Row=r1; Row!=r2+(rShift*2); Row+=rShift){
        cCount=0;
        if(rCount!=0 && cCount==0){
            data[rCount][0]=Row-rShift;
        }
        for(Col=c1; Col!=c2+(cShift*2);Col+=cShift){
            if(rCount==0 && cCount!=0){
                data[0][cCount] = Col-cShift;
            }
            else if(!(cCount==0 && rCount!=0)){
                data[rCount][cCount]=(Row-rShift)*(Col-cShift);
            }
            cCount++;
        }
        rCount++;
    }


    //Output
    for(Row=0; Row<=numR; Row++){
        cout << setw(8) << left;
        for(Col=0; Col<=numC; Col++){
            if(Row==0&&Col==0){
                cout << " ";
            }
            else{
                cout << data[Row][Col];
            }
            cout << setw(6) << left;
        }
        cout << endl;
        for(int i=0; i<=numC; i++){
            cout << "-----|";
        }
        cout << endl;
    }

    return 0;
}
