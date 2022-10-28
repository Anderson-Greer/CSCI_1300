// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 4

#include <iostream>
#include <cassert>

using namespace std;

// Algorithm: takes in an input_string, a separator char, an array of strings, and the size of that array.
// The function searches through the input_string and each time it finds the separator char, it stores
// the substring between that separator and the last into the passed in array. If it is the first
// case of the separator, everything before it is placed into the array
int split(string input_string, char separator, string arr[], int arr_size) {
    if(input_string.length() == 0)
        return 0;
         
    arr[0] = input_string;
    
    int subIndex = 0;
    int count = 0;
    for(int i = 0; i <= input_string.length(); i++) {
        if(input_string[i] == separator) {
            arr[count] = input_string.substr(subIndex, i - subIndex);
            count++;
            subIndex = i + 1;
            
            if(count >= arr_size)
                return -1;
        }
    }
    arr[count] = input_string.substr(subIndex, input_string.length() - subIndex);
    
    return count + 1;
}

int main() {
    // declare arrays and other variables
    string testcase = "RST,UVW,XYZ";
    char separator = ',';
    int arr_size = 3;
    string arr1[arr_size];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr1, arr_size);

    // first test case
    assert(arr1[0] == "RST");
    assert(arr1[1] == "UVW");
    assert(arr1[2] == "XYZ");
    assert(num_splits == 3);

    testcase = "ABCDEFG";
    separator = ' ';
    arr_size = 3;
    string arr2[arr_size];
    // num_splits is the value returned by split
    num_splits = split(testcase, separator, arr2, arr_size);

    // second test case
    assert(arr2[0] == "ABCDEFG");
    assert(num_splits == 1);

    testcase = "";
    separator = 'A';
    arr_size = 3;
    string arr3[arr_size];
    // num_splits is the value returned by split
    num_splits = split(testcase, separator, arr3, arr_size);

    // third test case
    assert(num_splits == 0);

    testcase = "fal;kje gfhiurehg m hjadhfe  ";
    separator = ' ';
    arr_size = 4;
    string arr4[arr_size];
    // num_splits is the value returned by split
    num_splits = split(testcase, separator, arr4, arr_size);

    // fourth test case
    assert(arr4[0] == "fal;kje");
    assert(arr4[1] == "gfhiurehg");
    assert(arr4[2] == "m");
    assert(arr4[3] == "hjadhfe");
    assert(num_splits == -1);


    return 0;
}
