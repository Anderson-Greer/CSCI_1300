// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 6 - Problem 2

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
 * Take in a file of mountains and their heights separated by a '|'
 * Read a line of the file, separate the line into the mountain name and it's height
 * Compare every heigh and whichever is the largest, save the height and the mountain name in a variable
 * Same with the shortest
 * Output the largest and shortest mountains with their names
*/
void printMountainStats(string filename) {
    ifstream in_file(filename);
    string input, tallMountain, shortMountain;
    int height = 0;
    int count = 0; 
    int maxHeight = 0;
    int minHeight = 30000;
    string list[2];

    if(in_file.fail()) {
        cout << "Could not open file." << endl;
        return;
    }

    while(!in_file.eof()) {
        getline(in_file, input);
        if(input != "") {
            split(input, '|', list, 2);
            height = stoi(list[1]);
            
            if(height > maxHeight) {
                maxHeight = height;
                tallMountain = list[0];
            }
            else if(height < minHeight) {
                minHeight = height;
                shortMountain = list[0];
            }
            
            count++;
        }
    }
    
    cout << "Number of lines read: " << count  << "." << endl;
    cout << "Tallest mountain: " << tallMountain << " at " << maxHeight << " feet." << endl;
    cout << "Shortest Mountain: " << shortMountain << " at " << minHeight << " feet." << endl;

    in_file.close();
}

int main() {
    // test case 1, should print:
    // Number of lines read: 3.
    // Tallest mountain: Pikes Peak at 14114 feet.
    // Shortest Mountain: Vermilion Peak at 13894 feet.
    printMountainStats("mountain_data.txt");

    // test case 2, should print:
    // Could not open file.
    printMountainStats("does-not-exist.txt");

    // test case 3, should print:
    // Number of lines read: 3.
    // Tallest mountain: Mt silly goose at 30000 feet.
    // Shortest Mountain: Mt mount at 10001 feet.
    printMountainStats("mountain_data1.txt");

    return 0;
}