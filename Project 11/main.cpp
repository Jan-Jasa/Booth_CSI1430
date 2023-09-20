/*
Author: Jan Jasa
Assignment Title: Max Min Sum Count
Assignment Description: Read a file containing integers
    and output the max, min, sum, count,
    and average of the list.
Due Date: 9/30/2022
Date Created: 9/29/2022
Date Last Modified: 9/30/2022

Data Abstraction:
    max, min, sum, count, and avg
        are initialized to store
        their respective values.
        Current value is used to hold
        the value that is currently being
        read by the program.
Input:
    The user inputs a file name which
        is stored into fileName, then
        read by inFS, which opens the file.
Process:
    A loop is ran until the end of the file
        is reached, during which the max and
        min values are found through if statements.
        At the end of each loop, the currentValue is
        added onto sum, and the count is increased by one.
        After the loop has ended, the average is calculated
Output:
    The program outputs the max, min, sum, count and avg.
Assumptions:
    One file is opened.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int currentValue;
    int maxValue;
    int minValue;
    int sum=0;
    int count=0;
    double avg;
    string fileName;
    ifstream inFS;

    //input
    cout << "Enter Data File Name: ";
    cin >> fileName;
    cout << fileName << endl;
    inFS.open(fileName);

    //loops input statement until a goodfile is made
    while(!inFS.is_open()){
        cout << "Error: File Not Open." << endl;
        inFS.close(); // ensures the current file closes
        cout << "Enter Data File Name: ";
        cin >> fileName;
        inFS.open(fileName);
        cout << fileName << endl;
    }

    //process
    while(inFS >> currentValue){
        if(count==0){
            maxValue=currentValue;
            minValue=currentValue;
        }
        if(currentValue>maxValue){
            maxValue=currentValue;
        }
        if(currentValue<minValue){
            minValue=currentValue;
        }
        sum+=currentValue;
        count+=1;
    }
    //calculate avg && close file
    avg = (double)sum/count;
    inFS.close();

    //output
    cout << "Min = " << minValue << endl;
    cout << "Max = " << maxValue << endl;
    cout << "Sum = " << sum << endl;
    cout << "Count = " << count << endl;
    cout << fixed << setprecision(2);
    cout << "Average = " << avg << endl;
    return 0;
}
