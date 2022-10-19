// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 6 - Problem 3

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
 * Take in a file and begin to read it
 * Loop through each line and split it using the split function
 * If it returns 3, increase the count of posts by one
 * If not, do nothing
 * Return number of posts
*/
int readPosts(string filename) {
    ifstream in_file(filename);
    string list[3];
    string input;
    int numAttr, numPosts = 0;
    
    if(in_file.fail())
        return -1;
    
    while(!in_file.eof()) {
        getline(in_file, input);
        numAttr = split(input, ',', list, 3);
        
        if(numAttr == 3)
            numPosts++;
    }
    
    return numPosts;
}

int main() {
    // test case 1, should print:
    // Number of posts: 7
    int num_posts = readPosts("posts.txt");
    if (num_posts == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "Number of posts: " << num_posts << "." << endl;
    }

    // test case 2, should print
    // Could not open file.
    num_posts = readPosts("does-not-exist.txt");
    if (num_posts == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "Number of posts: " << num_posts << "." << endl;
    }
}
