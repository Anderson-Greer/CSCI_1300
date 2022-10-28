// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 1

#include <iostream>

using namespace std;

int main() {
    // declare each array
    int distance[10];
    string cities[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};
    int sequence[100];
    char letters[52];
    
    // loop through the distance array, assign a value to each index and print that element
    for(int i = 0; i < sizeof(distance)/sizeof(int); i++) {
        distance[i] = i + 5;
        // should print out the numbers 5 through 14 inclusive
        cout << distance[i] << endl;
    }
    // loop through the cities array and print each element
    for(int i = 0; i < sizeof(cities)/sizeof(string); i++) {
        // should print out five different cities
        cout << cities[i] << endl;
    }
    // loop through the sequence array, assign a value to each index and print that element
    for(int i = 0; i < sizeof(sequence)/sizeof(int); i++) {
        sequence[i] = (i + 1) * 6;
        // should print multiples of 6 starting at 6 and going to 600
        cout << sequence[i] << endl;
    }
    // loop through the letters array, assign a value to each index and print that element
    for(int i = 0; i < 52; i += 2) {
        letters[i] = 65 + i / 2;
        letters[i + 1] = 97 + i / 2;
        // should print the alphabet, each letter is upper case then followed by its lower case counterpart
        cout << letters[i] << "\n" << letters[i + 1] << endl;
    }

    return 0;   
}
