// almondMilk.cpp

// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 2 - Problem 3

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    // Creating variables for user input and calculations
    double sideLength;
    double height;
    double ounces;

    cout << "What is the side length of the base of the carton in inches?" << endl; // Prompts the user for the side length of the carton
    cin >> sideLength; // Collects user input
    
    cout << "What is the height of the carton in inches?" << endl; // Prompts the user for the height of the carton
    cin >> height; // Collects user input again

    ounces = 0.55 * pow(sideLength, 2) * height; // Calculates the total ounces carton can hold using user input
    
    cout << "The carton has a volume of " << ounces << " ounces." << endl; // Prints final statement back to user through console
    
    return 0; // Ends program
}