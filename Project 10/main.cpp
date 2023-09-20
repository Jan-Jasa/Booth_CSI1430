/*
Author: Jan Jasa
Assignment Title: Avg Start and Stop
Assignment Description: Find the average
        start and stop time from 3 files
Due Date: 9/28/2022
Date Created: 9/28/2022
Date Last Modified: 9/28/2022

Data Abstraction:
    start and stop hours, minutes, seconds
    and average variables are initialized
Input:
    3 files names, which the program opens
Process:
    program takes the start and stop time from
    each file, then gets the total seconds for
    each time. the average hours and minutes are
    found for each time.
Output:
    the average start and stop time
    are outputted
Assumptions:
    3 files are given
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

int main()
{
    int startH1, startH2, startH3;
    int stopH1, stopH2, stopH3;
    int startM1, startM2, startM3;
    int stopM1, stopM2, stopM3;
    int startS1, startS2, startS3;
    int stopS1, stopS2, stopS3;
    int totalStopSec, totalStartSec;
    bool badfile = false;
    int totalStartSec1, totalStartSec2, totalStartSec3;
    int totalStopSec1, totalStopSec2, totalStopSec3;
    int averageTotalStartSec, averageTotalStopSec;

    int averageStartHours, averageStartMin;
    int averageStopHours;
    double averageStopMin;
    string inputFile1, inputFile2, inputFile3;
    string junk, startAMPM1, stopAMPM1, startAMPM2;
    string stopAMPM2, startAMPM3, stopAMPM3;
    string avgStartAMPM, avgStopAMPM;
    char c;
    ifstream file1, file2, file3;

    cin >> inputFile1;
    cin >> inputFile2;
    cin >> inputFile3;

    file1.open(inputFile1);
    file2.open(inputFile2);
    file3.open(inputFile3);

    //checks if files opened
    if(!file1.is_open() || !file2.is_open() || !file3.is_open()){
        badfile = true;
    }

    file1 >> junk >> startH1 >> c
          >> startM1 >> c >> startS1
          >> startAMPM1 >> junk
          >> stopH1 >> c >> stopM1
          >> c >> stopS1 >> stopAMPM1;

    file2 >> junk >> startH2 >> c
          >> startM2 >> c >> startS2
          >> startAMPM2 >> junk
          >> stopH2 >> c >> stopM2
          >> c >> stopS2 >> stopAMPM2;

    file3 >> junk >> startH3 >> c
          >> startM3 >> c >> startS3
          >> startAMPM3 >> junk
          >> stopH3 >> c >> stopM3
          >> c >> stopS3 >> stopAMPM3;



    //fix hours
    startH1 %= 12;
    if(startAMPM1 == "PM") {
        startH1 +=12;
    }
    startH2 %= 12;
    if(startAMPM2 == "PM") {
        startH2 +=12;
    }
    startH3 %= 12;
    if(startAMPM3 == "PM") {
        startH3 +=12;
    }
    stopH1 %= 12;
    if(stopAMPM1 == "PM") {
        stopH1 +=12;
    }
    stopH2 %= 12;
    if(stopAMPM2 == "PM") {
        stopH2 +=12;
    }
    stopH3 %= 12;
    if(stopAMPM3 == "PM") {
        stopH3 +=12;
    }


    //calculate average start
    totalStartSec1 = startH1*3600 + startM1*60 + startS1;
    totalStartSec2 = startH2*3600 + startM2*60 + startS2;
    totalStartSec3 = startH3*3600 + startM3*60 + startS3;

    totalStartSec = totalStartSec1+totalStartSec2+totalStartSec3;
    averageTotalStartSec = totalStartSec/3.0;
    averageStartHours = averageTotalStartSec/3600;
    averageStartMin = averageTotalStartSec - (averageStartHours*3600);
    averageStartMin /= 60;

    //calculate average stop
    totalStopSec1 = stopH1*3600 + stopM1*60 + stopS1;
    totalStopSec2 = stopH2*3600 + stopM2*60 + stopS2;
    totalStopSec3 = stopH3*3600 + stopM3*60 + stopS3;

    totalStopSec = totalStopSec1+totalStopSec2+totalStopSec3;
    averageTotalStopSec = totalStopSec/3.0;
    averageStopHours = averageTotalStopSec/3600;
    averageStopMin = averageTotalStopSec - (averageStopHours*3600);
    averageStopMin /= 60;

    //Fix AM or PM value
    if(averageStartHours==12){
        avgStartAMPM = "PM";
    }
    else if(averageStartHours>12){
        avgStartAMPM = "PM";
        averageStartHours -= 12;
    }
    else{
        avgStartAMPM = "AM";
    }

    if (averageStopHours==12){
        avgStopAMPM = "PM";
    }
    else if(averageStopHours>12){
        avgStopAMPM = "PM";
        averageStopHours -= 12;
    }
    else{
        avgStopAMPM = "AM";
    }

    //set 0 AM to 12 AM
    if(averageStartHours==0){
        averageStartHours=12;
    }
    if(averageStopHours==0){
        averageStopHours=12;
    }

    if(averageStartHours==averageStopHours && averageStartMin==averageStopMin){
        averageStopMin+=1;
    }

    // Add 0 to start of single digit minutes
    if(badfile==false){
        if(averageStartMin<10){
            cout << "Average Start Time: "
            << averageStartHours << c <<
            "0" << averageStartMin << c
            << "00" << " " << avgStartAMPM << endl;
        }
        else{
            cout << "Average Start Time: " << averageStartHours
            << c << averageStartMin << c << "00"
            << " " << avgStartAMPM << endl;
        }
        if(averageStopMin<10){
            cout << "Average Stop TIme: " << averageStopHours
            << c << "0" << ceil(averageStopMin) << c << "00"
            << " " << avgStopAMPM << endl;
        }
        else{
            cout << "Average Stop TIme: " << averageStopHours
            << c << ceil(averageStopMin) << c << "00"
            << " " << avgStopAMPM << endl;
        }
    }
    else{
        cout << "Error: At Least One File Failed To Open." << endl;
    }


    file1.close();
    file2.close();
    file3.close();

    return 0;
}
