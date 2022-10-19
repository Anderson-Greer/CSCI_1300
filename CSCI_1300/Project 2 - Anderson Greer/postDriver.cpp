// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 1

#include <cassert>
#include <string>
#include <fstream>
#include "Post.h"

using namespace std;

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

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size) {
    if(num_posts_stored == posts_arr_size)
        return -2;

    ifstream fin(file_name);
    int count = 0;
    string line;
    string lineArr[4];

    if(fin.fail())
        return -1;

    for(int i = num_posts_stored - 1; i < posts_arr_size; i++) {
        if(getline(fin, line)) {
            split(line, ',', lineArr, 4);
        }
        
    }

    fin.close();
}

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