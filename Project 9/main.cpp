/*Author: Jan Jasa
Assignment Title: Data Transformation
Assignment Description: Take file values and do a cmd
Due Date: 9/23/2022
Date Created: 9/21/2022
Date Last Modified: 9/23/2022

Data Abstraction:
    10 values & command are obtained from the
        input file, skipping first two lines
Input:
    The first file is set as the opened file,
        while the second is used to output the result
Process:
    The first two lines are skipped, then the
        values and command are obtained from lines
        3-13. The result is obtained using the specific
        command.
Output:
    The result is displayed on the screen and output file.
Assumptions:
    The first two lines are filler, while lines 3-12 are
        numbers and line 13 is a command.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string skip1;
    string skip2;
    string file1;
    string file2;
    string cmd;
    ifstream inFS;
    ofstream oFS;
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;
    double n6;
    double n7;
    double n8;
    double n9;
    double n10;
    double result;

    cin >> file1;
    cin >> file2;
    inFS.open(file1);
    oFS.open(file2);

    //Checks if file fails to open
    if(!inFS.is_open() || !oFS.is_open()){
        cout << "ERROR: File failed to open." << endl;
        return 1;
    }
    //Gets rid of first two lines
    inFS >> skip1;
    inFS >> skip2;

    //Reads numbers & command
    inFS >> n1;
    inFS >> n2;
    inFS >> n3;
    inFS >> n4;
    inFS >> n5;
    inFS >> n6;
    inFS >> n7;
    inFS >> n8;
    inFS >> n9;
    inFS >> n10;
    inFS >> cmd;

    //Produces result based off cmd
    if(cmd=="aav"){
        result=n1+n2;
        result=result+n3+n4;
        result=result+n5+n6;
        result=result+n7+n8;
        result=result+n9+n10;
    }
    else if(cmd=="mav"){
        result=n1*n2;
        result=result*n3*n4;
        result=result*n5*n6;
        result=result*n7*n8;
        result=result*n9*n10;
    }
    else if(cmd=="avg"){
        result=n1+n2;
        result=result+n3+n4;
        result=result+n5+n6;
        result=result+n7+n8;
        result=result+n9+n10;
        result=result/10.0;
    }
    else if(cmd=="dav"){
        result=n1/n2;
        result=result/n3/n4;
        result=result/n5/n6;
        result=result/n7/n8;
        result=result/n9/n10;
    }
    else if(cmd=="sav"){
        result=n1-n2;
        result=result-n3-n4;
        result=result-n5-n6;
        result=result-n7-n8;
        result=result-n9-n10;
    }
    inFS.close();

    cout << result << endl;
    oFS << result;
    oFS.close();

    return 0;
}
