// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 7

#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "User.h"
#include "Post.h"

/* Algorithm
 * 1. Take the username_tag, users array, and number of users in the array as parameters
 * 2. If the number of users in the array is less than or equal to 0, print no users in database
 * 3. Loop through each user in the users array and compare each possible substring in that username to the username_tag
 * 4. If any substring is equal to the username_tag, add that username to a separate array and increase a count variable by 1
 * 5. Once the loop is finished, if the count variable is greater than one print out each username in the separate array
 * 6. If count is equal to 0, print no users found
*/
void findTagUser(string username_tag, User users[], int num_users_stored) {
    if(num_users_stored <= 0) { // input validation
        cout << "No users are stored in the database" << endl;
        return;
    }
    
    string names[num_users_stored]; // array for usernames with the tag
    int count = 0; // count variable
    
    for(int i = 0; i < num_users_stored; i++) { // loops through users array to look at each user
        
        string username = users[i].getUsername(); // stores the username of the user object
        
        for(int j = 0; j < username.length() - username_tag.length() + 1; j++) { // compares each possible substring in the username to the tag
            if(username.substr(j, username_tag.length()) == username_tag) {
                names[count] = users[i].getUsername(); // store matching username
                count++; // increase count variable by one
            }
        }
    }
    
    if(count == 0) { // no usernames matched the tag
        cout << "No matching user found" << endl;
        return;
    }
    cout << "Here are all the usernames that contain " << username_tag << endl;
    for(int i = 0; i < count; i++) { // print out all usernames with the tag
        cout << names[i] << endl;
    }
}

int main() {
    
    User user_array[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array[0] = User("foliwn22", likes1, 3);
    user_array[1] = User("joh23k", likes2, 3);
    user_array[2] = User("anyjoh432", likes2, 3);
    user_array[3] = User("luwkml1", likes2, 3);
    user_array[4] = User("fwollow3", likes1, 3);

    // test case 1, should return:
    // Here are all the usernames that contain fwo
    // fwollow3
    findTagUser("fwo", user_array, 5);

    // test case 2, should return:
    // No matching user found
    findTagUser("and", user_array, 5);

    // test case 3, should return:
    // Here are all the usernames that contain joh
    // joh23k
    // anyjoh432
    findTagUser("joh", user_array, 5);

    // test case 4, should return:
    // No users are stored in the database
    findTagUser("joh", user_array, 0);


    return 0;
}