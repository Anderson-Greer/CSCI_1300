// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 4

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    // declare all the variables
    double input1;
    double input2;
    double input3;
    
    // prompt user and take input
    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> input1;
    cin >> input2;
    cin >> input3; 
    
    // input validation
    if(input1 < 0 || input2 < 0 || input3 < 0) {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    
    // checks cases
    if(input3 > input2 && input2 > input1) {
        cout << "The wifi is getting faster!" << endl;
        return 0;
    }
    else if(input1 > input2 && input2 > input3) {
        cout << "The wifi is getting slower!" << endl;
        return 0;
    }
    
    // output final message
    cout << "The wifi speed is changing unpredictably." << endl;

    return 0;
}