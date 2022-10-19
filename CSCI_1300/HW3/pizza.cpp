// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 3

#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    char sizeInput;
    int toppingsInput;
    double topCost;
    double total;
    
    // prompt user and take input
    cout << "What size pizza would you like to order?" << endl;
    cin >> sizeInput;
    
    // sets costs depending on what the user input is
    if(sizeInput == 'S') {
        topCost = 0.75;
        total = 4.99;
    }
    else if(sizeInput == 'M') {
        topCost = 1.50;
        total = 5.99;
    }
    else if(sizeInput == 'L') {
        topCost = 2.25;
        total = 6.99;
    }
    else { // invalid input case
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    
    // prompt user and take input
    cout << "How many toppings do you want?" << endl;
    cin >> toppingsInput;
    
    if(toppingsInput < 0) { // checks for invalid case again
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    
    // outputs final message
    cout << "Your total is $" << (total + topCost * toppingsInput) << endl;
    
    return 0;
}