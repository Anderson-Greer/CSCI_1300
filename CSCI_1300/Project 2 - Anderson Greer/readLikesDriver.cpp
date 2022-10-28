// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 5

#include <fstream>
#include <cassert>
#include "User.h"

using namespace std;

// Normal split function
int split(string input_string, char separator, string arr[], int arr_size) {
    if(input_string.length() == 0)
        return 0;
        
    arr[0] = input_string;
    
    int subIndex = 0;
    int count = 0;
    for(unsigned int i = 0; i <= input_string.length(); i++) {
        if(input_string[i] == separator) {
            arr[count] = input_string.substr(subIndex, i - subIndex);
            count++;
            subIndex = i + 1;
            
            if(count >= arr_size) {
                cout << "Count: " << count << endl;
                return -1;
            }
        }
    }
    arr[count] = input_string.substr(subIndex, input_string.length() - subIndex);
    
    return count + 1;
}

/* Algorithm
 * 1. Take in a filename, users array, number of users in the array, the size of the array, and the max posts for each file line as parameters
 * 2. If number of users stored is the same as the size of the array, return -2 because the array is already full
 * 3. Return -1 if the file cannot be opened
 * 4. While there is still room in the array, loop through each line of the text file and split each line into an array
 * 4a. If the line is empty, reduce the for loop conditional variable by one
 * 5. Create a user object with the username from the file line and an array of likes that follows the username
 * 6. Increase a count variable for number of users added
 * 7. Return the count variable once the loop ends
*/
int readLikes(string filename, User users[], int num_users_stored, int users_arr_size, int max_posts) {
    ifstream fin(filename); // open file for reading
    
    if(num_users_stored == users_arr_size) // if array is already full, return -2
        return -2;
    else if(fin.fail()) // if file does not exist or will not open, return -1
        return -1;
    
    int count = 0;
    int lineLen;
    string line;
    
    for(int i = num_users_stored; i < users_arr_size; i++) { // loop through each available space in the users array
        
        if(getline(fin, line)) { // check if there is a readable line and store it in the string line
            string splitArr[max_posts + 1];
            lineLen = split(line, ',', splitArr, max_posts + 1); // use split function to split the line from the file into an array
            
            if(splitArr[0] != users[i - 1].getUsername() && lineLen != 0) { // if the user is not repeated or not an empty line, execute the rest of code
                int likes[lineLen];
                
                for(int j = 0; j < lineLen - 1; j++) { // loop through the array from split function and store every value but the first in a likes array
                    likes[j] = stoi(splitArr[j + 1]);
                }
                User user(splitArr[0], likes, lineLen); // create a user object to store with given username and likes from file line
                users[i] = user; // store user object in array
                
                count++; // increase count variable by one
            }
            else { // if the line is skipped, the for loop should be set back an iteration because the available space in the users array was not used
                i--;
            }
        }
    }

    fin.close(); // close the file

    return count + num_users_stored; // return the new number of elements in the users array
}

int main() {
    User users[50]; 
    int num_users_stored = 0; 
    int users_arr_size = 50; 
    int max_posts = 50;

    // test case 1
    assert(readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts) == 49);
    assert(users[7].getLikesAt(0) == 5);
    assert(users[48].getLikesAt(2) == -1);

    // test case 2
    assert(readLikes("does-not-exist.txt", users, num_users_stored, users_arr_size, max_posts) == -1);

    return 0;
}