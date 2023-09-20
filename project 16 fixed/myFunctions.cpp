// Author: Jan Jasa
// Assignment Title: My Functions
// Assignment Description: Create functions that do
// 	normal math functions such as min, max, etc;
// Due Date: 10/28/2022
// Date Created: 10/27/2022
// Date Last Modified: 10/27/2022
//

#include "myFunctions.h"


/*int max(int a, int b){
    int MaxNum = a;
    if(MaxNum<b){
        MaxNum=b;
    }

    return MaxNum;
}

double max(double a, double b){
    double MaxNum = a;
    if(MaxNum<b){
        MaxNum=b;
    }

    return MaxNum;
}

int max(int a[], int n){
    int v;


    v=a[0];
    for(int i=1; i<n; i++){
        if(a[i] > v){
            v=a[i];
        }
    }

    return v;
}

double max(double m[], int n){
    double v;
    v=m[0];

    for(int i=1; i<n; i++){
        if(m[i] > v){
            v=m[i];
        }
    }
    return v;
}

int min(int a, int b){
    int MinNum = a;
    if(MinNum>b){
        MinNum=b;
    }

    return MinNum;
}

double min(double a, double b){
    double MinNum = a;
    if(MinNum>b){
        MinNum=b;
    }

    return MinNum;
}

int min(int m[], int n){
    int v;
    v = m[0];

    for(int i=1; i<n; i++){
        if(m[i]<v){
            v=m[i];
        }
    }
    return v;
}

double min(double m[], int n){
    double v;
    v = m[0];

    for(int i=1; i<n; i++){
        if(m[i]<v){
            v=m[i];
        }
    }
    return v;
}*/

//absoluteValue functions
int absoluteValue(int n){
    if(n<0){
        n*=-1;
    }
    return n;
}

double absoluteValue(double n){
    if(n<0){
        n*=-1;
    }
    return n;
}

double factorial(int n){
    assert(n>=0);
    double v = 1;

    while(n>0){
        v*=n;
        n--;
    }

    return v;
}

double combination(int m, int n){
    double mFactorial=factorial(m);
    double nFactorial=factorial(n);
    double diffFactorial=factorial(m-n);

    double result;
    result=(mFactorial)/(nFactorial*diffFactorial);

    return result;
}

double permutation(int m, int n){
    double mFactorial=factorial(m);
    double diffFactorial=factorial(m-n);

    double result;
    result=mFactorial/diffFactorial;

    return result;
}
