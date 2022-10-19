// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Project 1 - Problem 2

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
 * isValidNote checks if inputted string is a valid SPN note.
 * Algorithm:
 * 1. Check if the length of note is 2
 * 2. If 1 is true, check if the ASCII value of the first char in note is between 65 and 71(chars A and G)
 * 3. If 2 is also true, check if the ASCII value of the second char is between 48 and 57(integers 0 and 9)
 * 4. If 3 is true, return true
 * 5. If any of the steps are false, return false
 * Parameters:
 * 1. note (string): untested note that is given by user
 * Returns:
 * 1. boolean: whether note is a valid note or not
 */
bool isValidNote(string note) {
    // checks length of note
    if(note.length() == 2) {
        // checks ASCII value of first char of note
        if(note[0] >= 65 && note[0] <= 71) {
            // checks ASCII value of second char
            if(note[1] >= 48 && note[1] <= 57) {
                return true; // note is valid and returns true
            }
        }
    }
    return false; // note is invalid and returns false
}

/**
 * isValidTune checks to see if inputted string consists of a series of notes
 * Algorithm:
 * 1. Checks if tune has a length greater than 1 and has an even length, if not it returns false.
 * 2. Loops through tune and checks if every two chars are a valid note uing isValidNote,
 *    if not then it returns false.
 * 3. If every pair of chars pass the test, the function returns true.
 * Parameters:
 * tune (string): inputted series of notes to be checked
 * Returns:
 * boolean: returns true if tune is valid, false if not
 */
bool isValidTune(string tune) {
    if(tune.length() < 2 && tune.length() % 2 == 0)
        return false;
    
    // loops through each pair of chars in tune
    for(int i = 0; i < tune.length(); i += 2) {
        if(!isValidNote(tune.substr(i, 2))) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(isValidTune("A2B4C7") == true);
    assert(isValidTune("M5D2E1") == false);
    assert(isValidTune("A5D2E11") == false);
    assert(isValidTune("") == false);
    assert(isValidTune("Hello1300") == false);
}