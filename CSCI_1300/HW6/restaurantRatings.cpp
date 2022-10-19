// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 6 - Problem 4a

#include <iostream>
#include <string>
#include <fstream>
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

/*
 * Algorithm:
 * Read file and loop through each line
 * If the line has the correct number  of items, store the restaurant name in an array of names and store each review
 * in another 2d array and increment the count of correct lines by one
 * Return the count
*/
int readRestaurantData(string filename, string resturants[], int ratings[][3], int arrSize) {
    ifstream in_file(filename);
    string input[4];
    string line;
    int count = 0;
    
    if(in_file.fail())
        return -1;
    
    for(int i = 0; i < arrSize; i++) {
        if(getline(in_file, line)) {
            if(split(line, '~', input, 4) == 4) {
                resturants[i] = input[0];
            
                for(int j = 1; j <= 3; j++) {
                    ratings[count][j - 1] = stoi(input[j]);
                }
            
                count++;
            }
            else {
                i--;
            }
        }
    }
    
    return count;
}

int main() {
    // test case 1, should print:
    // max number of restaurants to read
    int num_restaurants = 3;

    // make arrays to store data
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];

    // call read data function
    assert(readRestaurantData("restaurant_samples.txt", restaurants, ratings, num_restaurants) == 3);
    assert(readRestaurantData("does-not-exist.txt", restaurants, ratings, num_restaurants) == -1);

    return 0;
}
