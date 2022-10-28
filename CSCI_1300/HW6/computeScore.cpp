// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 6 - Problem 4a

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cassert>

using namespace std;

// These are #included for you, do not put them in the answer box.
//  #include <string>
//  #include <iostream>
//  #include <fstream>

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

void calcOverallScore(string resturants[], int ratings[][3], int num_resturants) {
    double score;
    
    cout << fixed << setprecision(1);
    
    for(int i = 0; i < num_resturants; i++) {
        cout << resturants[i] << " overall score: ";
        score = (6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 * (5 - ratings[i][2]));
        cout << score << endl;
    }
}

int main() {
    string filename = "restaurant_samples.txt";

    // max number of restaurants to read
    int num_restaurants = 3;

    // make arrays to store data
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];

    // call read data function
    int num_lines = readRestaurantData(filename, restaurants, ratings, num_restaurants);

    if (num_lines == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        // test case 1, should return:
        // Wendys overall score: 60.9
        // Chick-fil-a overall score: 78.2
        // Snarfburger overall score: 87.0
        calcOverallScore(restaurants, ratings, num_lines);
    }

    // test case 2, should return:
    // Could not open file.
    num_lines = readRestaurantData("does-not-exist.txt", restaurants, ratings, num_restaurants);
    if (num_lines == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        // test case 1, should return:
        // Wendys overall score: 60.9
        // Chick-fil-a overall score: 78.2
        // Snarfburger overall score: 87.0
        calcOverallScore(restaurants, ratings, num_lines);
    }

    return 0;
}