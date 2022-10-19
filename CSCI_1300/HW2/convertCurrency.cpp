// convertCurrency.cpp

// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 2 - Problem 5

#include <iostream>

using namespace std;

int main() {
    
    // Variables for later calculations
    int gems;
    int goldCoins;

    int userBolts; // Variable for user input

    cout << "Enter the number of Bolts:" << endl; // Prompts the user for number of bolts
    cin >> userBolts; // Stores user input in variable

    // Calculations for the number of gems, coins, and bolts
    gems = userBolts / (23 * 13);
    userBolts = userBolts % (23 * 13);
    goldCoins = userBolts / 13;
    userBolts = userBolts % 13;

    cout << gems << " Gem(s) " << goldCoins << " Gold coin(s) " << userBolts << " Bolt(s)"; // Outputs final statement based on user input to console

    return 0; // Ends program
}