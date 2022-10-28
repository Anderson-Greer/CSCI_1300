// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 6

#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "User.h"
#include "Post.h"


/* Algorithm
 * 1. Take in post_author, posts list, number of posts stored, username, users list, and number of users stored as parameters
 * 2. Check if the username is in the users list and the post_author is in the posts list
 * 3. Return -2 if there are 0 elements in either users or posts lists
 * 4. Return -3 if either username or post_author are not present in their respective lists
 * 5. Search the users list for the desired username and save it's index
 * 6. Loop through the posts list to find the post author and return the number of likes from the user at the post author's index
*/
int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored) {
    bool userFlag = false; // flags to ensure username and post_author exist
    bool postFlag = false;
    
    for(int i = 0; i < num_users_stored; i++) { // checks to see if username exists in users array
        if(users[i].getUsername() == username)
            userFlag = true;
    }
    for(int i = 0; i < num_posts_stored; i++) { // checks to see if post_author exists in posts array
        if(posts[i].getPostAuthor() == post_author)
            postFlag = true;
    }
    
    if(num_posts_stored <= 0 || num_users_stored <= 0) // if either posts or users arrays are empty, return -2
        return -2;
    else if(!userFlag || !postFlag) // if username or post_author do not exist in respective arrays, return -3
        return -3;
    
    int index;
    
    for(int i = 0; i < num_users_stored; i++) { // find the index of the username in users array
        if(users[i].getUsername() == username)
            index = i;
    }
    
    for(int i = 0; i < num_posts_stored; i++) { // find the index of post_author in posts array
        if(posts[i].getPostAuthor() == post_author)
            return users[index].getLikesAt(i); // return the number of likes the user with given username has given the desired post
    }
    
    return -1;
}

int main() {

    Post posts[3]; 
    Post my_post_1 = Post("Hello!","Xuefei", 10, "10/02/22");
    posts[0] = my_post_1;
    Post my_post_2 = Post("new post","Morgan", 9, "10/04/22");
    posts[1] = my_post_2;
    Post my_post_3 = Post("Hey!","Jot", 10, "10/05/22");
    posts[2] = my_post_3;

    User users[2];
    // user 1
    int likes1[3] = {1, 3, 2};
    User u1 = User("bookworm43", likes1, 3);
    users[0] = u1; // insert first object at index 0
    // user 2
    users[1].setUsername("roboticscu");
    users[1].setLikesAt(0,-1); 
    users[1].setLikesAt(1,2); 
    users[1].setLikesAt(2,4);


    // test case 1, username is not in list
    assert(getLikes("Xuefei", posts, 3, "andy", users, 2) == -3);
    // test case 2, post author is not in list
    assert(getLikes("John", posts, 3, "roboticscu", users, 2) == -3);
    // test case 3, both names are in lists
    assert(getLikes("Xuefei", posts, 3, "bookworm43", users, 2) == 1);

    return 0;
}