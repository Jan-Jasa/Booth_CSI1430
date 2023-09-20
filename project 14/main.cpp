/*
Author: Jan Jasa
Assignment Title: Array Backwards
Assignment Description: read into an array
    and display it in reverse
Due Date: 10/12/2022
Date Created: 10/12/2022
Date Last Modified: 10/12/2022

Data Abstraction:
    Vector is initialized to hold ints
    inputNumber holds the size of vector
    max, min, and sum are to hold said values
    int i is for loops
Input:
    User inputs the number of elements
    User then inputs integers for each element
Process:
    The program puts each integer into
        the vector.
    The program then uses for and if loops
        to find the max and min value of
        the vector
    Program finds the amount of duplicate numbers as well.
Output:
    Program outputs both forward and backwards vectors
        then outputs sum, duplicates, max and min
Assumptions:
    All numbers are integers, less than 2500 elements
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int inputNumber;
    int sum=0;
    int max;
    int min;
    int i;
    bool onList;

    cout << "Input the number of elements to store in the array: ";
    cin >> inputNumber;
    cout << inputNumber << endl;

    vector<int> inputIntegers(inputNumber);

    //process, get vector and sum
    cout << "Input " << inputNumber << " integers:" << endl;
    for(i=0; i<inputNumber; i++){
        cout << "integer - " << i << " : ";
        cin >> inputIntegers.at(i);
        sum+=inputIntegers.at(i);
        cout << inputIntegers.at(i) << endl;
    }

    //find duplicates
    vector<int> duplicates;
    for(i=0;i<inputNumber-1;i++){
        for(int j=i+1;j<inputNumber;j++){
            if(inputIntegers.at(i)==inputIntegers.at(j)){
                onList=false;
                for(size_t k=0;k<duplicates.size();k++){
                    if(duplicates.at(k)==inputIntegers.at(i)){
                        onList=true;
                    }
                }
                if(!onList){
                    duplicates.push_back(inputIntegers.at(i));
                }
            }
        }
    }

    //find max&min loop
    max = inputIntegers.at(0);
    min = inputIntegers.at(0);
    for(i=0; i<inputNumber; i++){
        if(inputIntegers.at(i)>max){
            max=inputIntegers.at(i);
        }
        if(inputIntegers.at(i)<min){
            min=inputIntegers.at(i);
        }
    }

    //output
    cout << "The values stored into the array are : "<< endl;
    for(i=0;i<inputNumber;i++){
        cout << inputIntegers.at(i) << " ";
    }
    cout << endl << '\n';

    cout << "The values stored into the array in reverse are :" << endl;
    for(i=inputNumber-1;i>=0;--i){
        cout << inputIntegers.at(i) << " ";
    }
    cout << endl << '\n';

    cout << "The sum of all elements of the array is " << sum << endl;
    cout << "The total number of duplicate elements in the array is "
        << duplicates.size() << endl;
    cout << "The maximum and minimum element in the array are " <<
        max << " , " << min << endl;

    return 0;
}
