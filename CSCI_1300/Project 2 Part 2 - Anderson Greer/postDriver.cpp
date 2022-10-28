// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 1

#include <cassert>
#include <string>
#include <fstream>
#include "Post.h"

using namespace std;

int main() {

    // test case 1
    Post post1;
    assert(post1.getPostBody() == "");
    post1.setPostBody("hi");
    assert(post1.getPostBody() == "hi");

    assert(post1.getPostAuthor() == "");
    post1.setPostAuthor("Jonathan Green");
    assert(post1.getPostAuthor() == "Jonathan Green");

    assert(post1.getPostDate() == "");
    post1.setPostDate("10/12/2020");
    assert(post1.getPostDate() == "10/12/2020");

    assert(post1.getPostLikes() == 0);
    post1.setPostLikes(100);
    assert(post1.getPostLikes() == 100);

    // test case 2
    Post post2("hello csci 1300", "Marx", 10000, "12/25/1885");
    assert(post2.getPostBody() == "hello csci 1300");

    assert(post2.getPostAuthor() == "Marx");

    assert(post2.getPostDate() == "12/25/1885");

    assert(post2.getPostLikes() == 10000);

    return 0;
}