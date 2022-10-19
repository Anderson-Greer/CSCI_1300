// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 3a

#include <iostream>
#include <cassert>

using namespace std;

// Algorithm: takes in an array of input strings, the number of elements in the array, the size of the array, 
// the index at which a new string is inserted after, and a string to be inserted. This function loops through
// the array from back down to the index and shifts each element to the right one spot. Then, the desired string
// is inserted into its spot after the index.
bool insertAfter(string inputStrings[], int numElements, int size, int index, string stringToInsert) {
    if(numElements >= size || index >= size)
        return false;
    
    for(int i = size - 1; i > index; i--) {
        if(inputStrings[i] != "") {
            inputStrings[i + 1] = inputStrings[i];
        }
    }
    
    inputStrings[index + 1] = stringToInsert;
    
    return true;

}

int main() {
    // declare arrays and other variables
    int size = 5;
    string input_strings1[size] = {"pikachu", "meowth", "snorlax"};
    int num_elements = 3;
    int index = 2;
    string string_to_insert = "clefairy";
    // result contains the value returned by insertAfter
    bool result = insertAfter(input_strings1, num_elements, size, index, string_to_insert);

    // first test case
    assert(input_strings1[0] == "pikachu");
    assert(input_strings1[1] == "meowth");
    assert(input_strings1[2] == "snorlax");
    assert(input_strings1[3] == "clefairy");
    assert(result == 1);

    size = 2;
    string input_strings2[size] = {"pichu", "ponyta"};
    num_elements = 2;
    index = 1;
    string_to_insert = "charizard";
    // result contains the value returned by insertAfter
    result = insertAfter(input_strings2, num_elements, size, index, string_to_insert);

    // second test case
    assert(input_strings2[0] == "pichu");
    assert(input_strings2[1] == "ponyta");
    assert(result == 0);

    size = 0;
    string input_strings3[size] = {};
    num_elements = 0;
    index = 10;
    string_to_insert = "charizard";
    // result contains the value returned by insertAfter
    result = insertAfter(input_strings3, num_elements, size, index, string_to_insert);
    // third test case
    assert(result == 0);

    size = 10;
    string input_strings4[size] = {"pichu", "ponyta", "charizard", "geodude"};
    num_elements = 4;
    index = 5;
    string_to_insert = "charizard";
    // result contains the value returned by insertAfter
    result = insertAfter(input_strings4, num_elements, size, index, string_to_insert);
    // fourth test case
    assert(input_strings4[0] == "pichu");
    assert(input_strings4[1] == "ponyta");
    assert(input_strings4[2] == "charizard");
    assert(input_strings4[3] == "geodude");
    assert(input_strings4[4] == "");
    assert(input_strings4[5] == "");
    assert(input_strings4[6] == "charizard");
    assert(result == 1);

    return 0;   
}
