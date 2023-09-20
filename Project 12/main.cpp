/*
Author: Jan Jasa
Assignment Title: CaesarCipher
Assignment Description: Encrypt or decrypt
Due Date: 10/5/2022
Date Created: 10/4/2022
Date Last Modified: 10/5/2022

Data Abstraction:
    Output and input file stream opened
    string variables to handle messages, file name
        and commands
    boolean variables to determine if there's an error
    count variables to count the amount of
        reoccuring syllables
Input:
    Program reads the first input, and stores it
        into fileName.
    Program reads the second input and stores in
        the command.
Process:
    Program first determines if there will be an error.
    The shift of the message is then determined by the cmd
    The program will then shift all characters by 3
Output:
    outputs either a error message or the encrypted/decrypted
        message, along with the file
Assumptions:
    It is assumed that the file has a message
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    bool badCMD = false;
    bool badFile = false;
    string message;
    string fileName;
    string command;
    string outputMSG;
    char c;
    ifstream inFS;
    ofstream outFS;
    int ACount=0;
    int ECount=0;
    int ICount=0;
    int OCount=0;
    int UCount=0;
    int YCount=0;
    int shift;
    int length;

    // input
    cout << "Enter File Name: ";
    cin >> fileName;
    cout << fileName << endl;
    cout << "Enter encrypt or decrypt: ";
    cin >> command;
    cout << command << endl;

    //false start checks
    inFS.open(fileName);
    outFS.open("message");
    if(command!="encrypt" && command!="decrypt"){
        badCMD=true;
        cout << "Error: Bad Command." << endl;
    }
    if(!inFS.is_open()){
        badFile=true;
        cout << "Error: File did NOT open." << endl;
    }

    //process
    if(command=="encrypt"){
        shift=3;
    }
    else if(command=="decrypt"){
        shift=-3;
    }

    while(!inFS.eof()){
        getline(inFS, message);
        length = message.length();
        for(int i=0;i<length;i++){
            c=message[i];
            if(c=='A' || c=='a'){
                ACount+=1;
            }
            if(c=='E' || c=='e'){
                ECount+=1;
            }
            if(c=='I' || c=='i'){
                ICount+=1;
            }
            if(c=='O' || c=='o'){
                OCount+=1;
            }
            if(c=='U' || c=='u'){
                UCount+=1;
            }
            if(c=='Y' || c=='y'){
                YCount+=1;
            }
            message[i]+=shift;
            c=message[i];
            outputMSG.push_back(c);
            outFS << message[i];
        }
    }


    //output
    inFS.close();
    outFS.close();

    if(!badCMD && !badFile){
        cout << outputMSG << endl;
        cout << "Letter Frequency" << endl;
        cout << "   A";
        cout << setw(7) << right << ACount << endl;
        cout << "   E";
        cout << setw(7) << right << ECount << endl;
        cout << "   I";
        cout << setw(7) << right << ICount << endl;
        cout << "   O";
        cout << setw(7) << right << OCount << endl;
        cout << "   U";
        cout << setw(7) << right << UCount << endl;
        cout << "   Y";
        cout << setw(7) << right << YCount << endl;
    }




    return 0;
}
