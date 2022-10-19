// snowfall.cpp

// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 2 - Problem 4

#include <iostream>

using namespace std;

int main() {
    
    // Constant rates for calculations
    const int BRECK_SNOW_RATE = 10;
    const int BRECK_MELT_RATE = 5;
    const int VAIL_SNOW_RATE = 14;
    const int VAIL_MELT_RATE = 2;
    const int COPPER_SNOW_RATE = 5;
    const int COPPER_MELT_RATE = 3;

    cout << "How many days in the future would you like a prediction for?" << endl; // Prompts user for how many days in the future they would like to predict
    int userNumDays; // Variable to store user input
    cin >> userNumDays; // Collects user input and stores it in variable

    // Calculations for the number of inches each resort will have given user input
    int breckInchCalc = 25 + userNumDays * (BRECK_SNOW_RATE - BRECK_MELT_RATE);
    int vailInchCalc = 28 + userNumDays * (VAIL_SNOW_RATE - VAIL_MELT_RATE);
    int copperInchCalc = 40 + userNumDays * (COPPER_SNOW_RATE - COPPER_MELT_RATE);

    // Outputs answers to user through console based on user input
    cout << "Breckenridge will have " << breckInchCalc << " inches, Vail will have " << vailInchCalc << " inches, and Copper will have " << copperInchCalc << " inches." << endl;

    return 0;
}