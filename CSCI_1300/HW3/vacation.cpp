// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 2

#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    double budget;
    char transportMode;

    // prompt the user & get their input
    cout << "What is your budget?" << endl;
    cin >> budget;

    // input validation: budget must be positive
    if (budget <= 0)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    
    // Prompt user and take input for transport
    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> transportMode;
    
    // input validation
    if(transportMode == 'B' || transportMode == 'T' || transportMode == 'A')
        switch(transportMode) {
            case 'B':
                if(budget >= 175.25) // if they chose bus and can afford it
                    cout << "Yes, this vacation is within your budget!" << endl;
                else
                    cout << "Sorry, this vacation is outside your budget." << endl;
                return 0;
            case 'T':
                if(budget >= 240.66) // if they chose train and can afford it
                    cout << "Yes, this vacation is within your budget!" << endl;
                else
                    cout << "Sorry, this vacation is outside your budget." << endl;
                return 0;
            case 'A':
                if(budget >= 350.93) // if they chose airplane and can afford it
                    cout << "Yes, this vacation is within your budget!" << endl;
                else
                    cout << "Sorry, this vacation is outside your budget." << endl;
                return 0;
        }
    else { // invalid input
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    
    return 0;
}