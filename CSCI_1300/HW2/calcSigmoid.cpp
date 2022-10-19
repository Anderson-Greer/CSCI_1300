// calcSigmoid.cpp

// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 2 - Problem 6

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    double inputX;
    double sigVal;

    cout << "Enter a value for x:" << endl;
    cin >> inputX;

    sigVal = 1 / (1 + pow(exp(1.0), -inputX));

    cout << "The sigmoid value for x=" << inputX << " is " << sigVal << endl;
    
    return 0; // Ends program
}