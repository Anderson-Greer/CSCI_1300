// helloYou.cpp

// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 2 - Problem 2

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string input; // Declared input variable to be used to take user input
    
    cout << "Please enter your name below: " << endl; // Prompts user for their name
    cin >> input; // Takes the input the user gives and stores in input variable
    
    cout << "Hello, " + input + "!" << endl; // Prints the final statement with user input to console
    
    return 0; // Ends program
}