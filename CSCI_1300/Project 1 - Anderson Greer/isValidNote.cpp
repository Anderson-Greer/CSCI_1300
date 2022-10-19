// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Project 1 - Problem 1

#include <iostream>
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

int main() {
    assert(isValidNote("y") == false);
    assert(isValidNote("D4") == true);
    assert(isValidNote("d4") == false);
    assert(isValidNote("E72") == false);
    assert(isValidNote("I love coding") == false);
}