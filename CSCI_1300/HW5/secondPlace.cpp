// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 3b

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

// Algorithm: takes in an array of input strings, the number of elements in the array, the size of the array, 
// the index at which a new string is inserted after, string to be inserted, the string to have inserted string
// placed after, and the number of target strings in the array. 
// The function loops through the array of strings and looks for the string_to_find. For each instance
// of string_to_find, string_to_insert is inserted after as long as the number of elements does not exceed
// the size of the array. 
int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count) {
    
    if(num_elements + count > arr_size)
        return num_elements;
    
    for(int i = 0; i <= num_elements; i++) {
        if(input_strings[i] == string_to_find) {
            insertAfter(input_strings, num_elements, arr_size, i, string_to_insert);
            num_elements++;
            i++;
        }
    }
    
    return num_elements;
}

int main() {
    // declare arrays and other variables
    int size = 12;
    string input_strings1[size] = {"clefairy", "charizard", "pikachu", "clefairy" };
    int num_elements = 4;
    int count = 2;
    string string_to_insert = "pichu";
    string string_to_find = "clefairy";
    // updating num_elements with the updated value returned by secondPlace
    num_elements = secondPlace(input_strings1, string_to_insert, string_to_find, num_elements, size, count);

    // first test case
    assert(input_strings1[0] == "clefairy");
    assert(input_strings1[1] == "pichu");
    assert(input_strings1[2] == "charizard");
    assert(input_strings1[3] == "pikachu");
    assert(input_strings1[4] == "clefairy");
    assert(input_strings1[5] == "pichu");
    assert(num_elements == 6);
    
    size = 4;
    string input_strings2[size] = {"caterpie", "charizard", "pikachu", "ponyta"};
    num_elements = 4;
    string_to_insert = "pichu";
    string_to_find = "ponyta";
    count = 1;
    // updating num_elements with the updated value returned by secondPlace
    num_elements = secondPlace(input_strings2, string_to_insert, string_to_find, num_elements, size, count);

    // second test case
    assert(input_strings2[0] == "caterpie");
    assert(input_strings2[1] == "charizard");
    assert(input_strings2[2] == "pikachu");
    assert(input_strings2[3] == "ponyta");
    assert(num_elements == 4);

    size = 0;
    string input_strings3[size] = {};
    num_elements = 100;
    string_to_insert = "pichu";
    string_to_find = "ponyta";
    count = 1;
    // updating num_elements with the updated value returned by secondPlace
    num_elements = secondPlace(input_strings3, string_to_insert, string_to_find, num_elements, size, count);

    // third test case
    assert(num_elements == 100);

    size = 100000;
    string input_strings4[size] = {"ponyta", "caterpie"};
    num_elements = 2;
    string_to_insert = "geodude";
    string_to_find = "caterpie";
    count = 1;
    // updating num_elements with the updated value returned by secondPlace
    num_elements = secondPlace(input_strings4, string_to_insert, string_to_find, num_elements, size, count);

    // fourth test case
    assert(input_strings4[0] == "ponyta");
    assert(input_strings4[1] == "caterpie");
    assert(input_strings4[2] == "geodude");
    assert(num_elements == 3);

    return 0;   
}
