// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 3 - Problem 5

#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    int deptInput;
    int classInput;
    int sectInput;
    
    // prompt user and take input
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> deptInput;
    
    // switch cases for departments
    switch(deptInput) {
        case 1:
            // prompt user and take input
            cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl;
            cin >> classInput;
            
            // switch cases for class choice
            switch(classInput) {
                case 1:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 100 (2)Section 200" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 100 of Starting Computing!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 200 of Starting Computing!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                case 2:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 101 (2)Section 201" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 101 of Data Structures!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 201 of Data Structures!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                case 3:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 102 (2)Section 202" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 102 of Algorithms!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 202 of Algorithms!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                default: // invalid input case
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        
        case 2:
            // prompt user and take input
            cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl;
            cin >> classInput;
            
            // switch cases for class choice
            switch(classInput) {
                case 1:
                    cout << "Select a section: (1)Section 400 (2)Section 500" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 400 of Calculus 1!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 500 of Calculus 1!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                case 2:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 401 (2)Section 501" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 401 of Calculus 2!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 501 of Calculus 2!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                case 3:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 402 (2)Section 502" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 402 of Linear Algebra!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 502 of Linear Algebra!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                default: // invalid input case
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        
        case 3:
            // prompt user and take input
            cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl;
            cin >> classInput;
            
            // switch cases for class choice
            switch(classInput) {
                case 1:
                    cout << "Select a section: (1)Section 700 (2)Section 800" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 700 of General Chemistry 1!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 800 of General Chemistry 1!" << endl;
                            return 0;
                        default: // invalid input case
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                case 2:
                    // prompt user and take input
                    cout << "Select a section: (1)Section 701 (2)Section 801" << endl;
                    cin >> sectInput;
                    
                    // switch cases for section choice
                    switch(sectInput) {
                        case 1:
                            cout << "You've been enrolled in Section 701 of Physics 1!" << endl;
                            return 0;
                        case 2:
                            cout << "You've been enrolled in Section 801 of Physics 1!" << endl;
                            return 0;
                        default:
                            cout << "Please enter a valid input." << endl;
                            return 0;
                    }
                default: // invalid input case
                    cout << "Please enter a valid input." << endl;
                    return 0;
            }
        
        // invalid input case
        default:
            cout << "Please enter a valid input." << endl;
            return 0;
    }

    return 0;
}