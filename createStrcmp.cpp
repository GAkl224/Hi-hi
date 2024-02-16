#include <iostream>
#include <stdio.h>
using namespace std;

int strcmp_case_insensitive(string X, string Y)
{
    int i; 
    for (i = 0; X[i] && Y[i]; ++i) 
    { 
        // If characters are same or inverting the 
       // 6th bit makes them same
        if (X[i] == Y[i] || (X[i] ^ 32) == Y[i])
        {
        continue; 
        }
        else
        {
        break; 
        }
    } 
 
    // Compare last or mismatched characters
    if (X[i] == Y[i])
    { 
        return 0; 
    }
 
    // Set, then compare 
    if ((X[i] | 32) < (Y[i] | 32)) 
        return -1; 
    return 1; 

}

//global variables
string strA;
string strB;
string strAA;
string strBB;

void output(){
    cout << "Comparison of two strings\nEnter the first string: " << endl;
    getline(cin, strA);

    strAA += strA;

    cout <<"\nEnter the second string : " << endl;
    getline(cin, strB);

    strBB += strB;

    cout << "\n\nThe comparison of: " << strAA << " and " << strBB << " returns " << strcmp_case_insensitive(strA, strB);
}

int main(){

    output();

    return 0;

}