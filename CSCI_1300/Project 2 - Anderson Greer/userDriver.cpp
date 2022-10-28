// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 4

#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
#include "User.h"

using namespace std;

int main() {

    // test case 1
    User user1;
    assert(user1.getUsername() == "");
    assert(user1.getLikesAt(0) == -1);
    assert(user1.getNumPosts() == 0);
    user1.setUsername("ldkfja");
    assert(user1.getUsername() == "ldkfja");
    user1.setNumPosts(5);
    assert(user1.getNumPosts() == 5);
    user1.setLikesAt(0, 8);
    assert(user1.getLikesAt(0) == 8);

    // test case 2
    int likes[] = {5, 2, 3};
    User user2("Andy", likes, 3);
    assert(user2.getUsername() == "Andy");
    assert(user2.getLikesAt(0) == 5);
    assert(user2.getNumPosts() == 3);

    return 0;
}