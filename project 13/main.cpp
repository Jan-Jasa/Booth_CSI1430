/*
Author: Jan Jasa
Assignment Title: GPS
Assignment Description: GPS system
Due Date: 10/7/2022
Date Created: 10/7/2022
Date Last Modified: 10/7/2022

Data Abstraction:
    x and y values created to store later on
    distance values initialized to calculate the
        different distances later on
    x and y squared made to prevent overflow
        while processing distance using sqrt&pow
Input:
    User inputs a file to be opened
Process:
    Program stores the data with START
        into xstart and ystart
    If command is stop then the program
        will set the final values
    Else will set the x1,x2,y1,y2 values and calculate
        the distance
Output:
    Outputs the total distance, average distance
        and distance to starting point
Assumptions:
    points in the file first start with START
        DATA, or STOP
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
    string junk;
    string command;
    string fileName;
    ifstream inFS;
    double x1;
    double x2;
    double xfinal;
    double xstart;
    double xsquared;
    double y1;
    double y2;
    double yfinal;
    double ystart;
    double ysquared;
    int count=0;
    double totalDistance=0;
    double avgDistance=0;
    double startendDistance=0;
    bool trueStart = false;
    bool trueStop = false;


    cout << "Please Enter The Name Of The Data File: ";
    cin >> fileName;
    cout << fileName << endl;

    //check if open
    inFS.open(fileName);
    while(!inFS.is_open()){
        inFS.close();
        cout << "Error: File failed to open." << endl;
        cout << "Please Enter The Name Of The Data File: ";
        cin >> fileName;
        cout << fileName << endl;
        inFS.open(fileName);
    }

    cout << "\n";
    getline(inFS, junk);
    getline(inFS, junk);
    while(!trueStop && inFS >> command){
        if(command == "START"){
            inFS >> xstart >> ystart;
            x2 = xstart;
            y2 = ystart;
            trueStart = true;
        }
        else if(trueStart && command == "STOP"){
            inFS >> xfinal >> yfinal;
            xsquared = pow((xfinal-x2),2);
            ysquared = pow((yfinal-y2),2);
            totalDistance += sqrt(xsquared+ysquared);

            avgDistance+=sqrt(pow((xfinal-xstart),2)+pow((yfinal-ystart),2));
            count+=1;
            trueStop = true;
        }
        else if(trueStart){
            x1=x2;
            y1=y2;
            inFS >> x2 >> y2;
            xsquared = pow((x2-x1),2);
            ysquared = pow((y2-y1),2);
            totalDistance += sqrt(xsquared+ysquared);

            avgDistance+=sqrt(pow((x2-xstart),2)+pow((y2-ystart),2));
            count+=1;
        }
    }
    //calculate other variables
    avgDistance/=count;
    startendDistance=sqrt(pow((xfinal-xstart),2)+pow((yfinal-ystart),2));


    cout << fixed << setprecision(1);
    cout << "Final Location: (" << xfinal << ", " << yfinal << ")" << endl;
    cout << "Total distance traveled " << totalDistance << endl;
    cout << "Distance to starting point " << startendDistance << endl;
    cout << "Average distance to start point = " << avgDistance << endl;
    inFS.close();
    return 0;
}
