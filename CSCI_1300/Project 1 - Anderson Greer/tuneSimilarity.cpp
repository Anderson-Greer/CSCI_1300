// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Project 1 - Problem 4

#include <iostream>
#include <cassert>

using namespace std;

/**
 * doubles_equal will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

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

/**
 * numValidNotes returns the number of valid notes in a string
 * Algorithm:
 * 1. Initialize an integer counter variable named total to 0
 * 2. Check to see if the length of input is greater than 0, if not return total.
 * 3. Loop through input and check every two characters to see if they are a valid note, if they are then add 1 to total.
 * 4. Return total after the for loop is executed.
 * Parameters:
 * input (string): inputted series of chars that may or may not be notes
 * Returns:
 * int: returns the number of notes that were in input
 */
int numValidNotes(string input) {
    int total = 0;
    
    if(input.length() <= 0)
        return total;
    
    // loops through each character in input except the last because the if statement checks the char and the char that follows it
    for(int i = 0; i < input.length() - 1; i++) {
        if(isValidNote(input.substr(i, 2))) // extracts a character and the character that follows it to be checked as a note
            total++;
    }
    
    return total;
}

/**
 * tuneSimilarity calculates how similar two tunes are
 * Algorithm:
 * 1. Make sure both tunes are same length
 * 2. Initialize each variable that's needed for calculation
 * 3. Loop through the tunes using a for loop
 * 4. If two notes and pitches are in the same position and are equivalent, increase the respective variable by one.
 * 5. If two notes are in the same position and are equivalent, increase the respective variable by one.
 * 6. If both the notes and pitches in the same positions are unequal, increase the respective variable by one.
 * 7. Return final calculation once the for loop ends.
 * Parameters:
 * tune1 (string): first tune inputted by user.
 * tune2 (string): second tune inputted by user.
 * Returns:
 * double: final calculation using formula
 */
double tuneSimilarity(string tune1, string tune2) {
    if(tune1.length() != tune2.length())
        return 0;
    
    double matchNote = 0; // counts number of matching notes
    double totalNote = tune1.length() / 2; // stores the total notes
    double matchNP = 0; // counts the number of matching notes and pitches
    double diffNP = 0; // counts the number of different notes and pitches

    for(int i = 0; i < tune1.length() - 1; i += 2) {
        if(tune1.substr(i, 2) == tune2.substr(i, 2)) { // if two notes are the same and their pitch is also the same
            matchNP++;
        }
        if(tune1[i] == tune2[i]) { // if two notes are the same
            matchNote++;
        }
        if(tune1[i] != tune2[i] && tune1[i + 1] != tune2[i + 1]) { // if two notes are different and so are their pitches
            diffNP++;
        }
    }

    return (matchNote / totalNote) + matchNP - diffNP; // formula for final calculation
}

int main() {
    assert(doublesEqual(tuneSimilarity("G4E5D4", "G4F4D5"), 0.666667));
    assert(doublesEqual(tuneSimilarity("A0B0C0D0", "D1C1B1A1"), -4));
    assert(doublesEqual(tuneSimilarity("E5E5G5A6G5D5", "E5G5A6G5D5D5"), 0.333333));
    assert(doublesEqual(tuneSimilarity("D5G2", "F7D1E4G4"), 0));
}