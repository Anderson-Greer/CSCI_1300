// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 1

#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    int flowrate;

    // prompt the user & get their input
    cout << "What is the flowrate of Boulder Creek?" << endl;
    cin >> flowrate;

    // input validation: flowrate must be positive
    if (flowrate <= 0)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    // decide if it's safe based on flowrate
    if (flowrate <= 250)
    {
        cout << "It is safe to go tubing. Have fun!" << endl;
    }
    else // Not safe based on flowrate
    {
        cout << "The river is flowing too fast to go tubing." << endl;
    }

    return 0;
}