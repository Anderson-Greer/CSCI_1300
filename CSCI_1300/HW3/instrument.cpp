// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 5

#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    int type, instrument;
    
    // prompt user and take input
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> type;
    
    // switch case based on user category input
    switch(type) {
        case 1:
            // prompt user and take input
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> instrument;
            
            // switch case for chosen instrument
            switch(instrument) {
                case 1:
                    cout << "Your instrument will be $350." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $400." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        case 2:
            // prompt user and take input
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> instrument;
            
            // switch case for chosen instrument
            switch(instrument) {
                case 1:
                    cout << "Your instrument will be $325." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $425." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        case 3:
            // prompt user and take input
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> instrument;
            
            // switch case for chosen instrument
            switch(instrument) {
                case 1:
                    cout << "Your instrument will be $275." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $200." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        
        default: // input validation
            cout << "Please enter a valid input." << endl;
            return 0;
    }
    
    return 0;
}