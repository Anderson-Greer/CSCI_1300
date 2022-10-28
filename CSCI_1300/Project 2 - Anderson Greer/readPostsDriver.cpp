// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 2

#include <cassert>
#include <string>
#include <iostream>
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

/* Algorithm
 * 1. Take parameters
 * 2. If the number of posts stored is greater than or equal to the array size, return -2
 * 3. If file fails, return -1
 * 4. Loop through empty elements of posts array
 * 5. Create new post object with each non-empty file line
 * 6. Return the new number of elements in the posts array
*/
int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size) {
    if(num_posts_stored >= posts_arr_size)
        return -2;

    ifstream fin(file_name);
    int count = num_posts_stored;
    string line;
    string lineArr[4];

    if(fin.fail())
        return -1;

    for(int i = num_posts_stored; i < posts_arr_size; i++) {
        if(getline(fin, line)) {
            if(line != "" && split(line, ',', lineArr, 4) == 4) {
                Post post(lineArr[0], lineArr[1], stoi(lineArr[2]), lineArr[3]);
                posts[i] = post;
                
                count++;
            }
            else
                i--;
        }
        
    }

    fin.close();

    return count;
}

int main() {
    // test case 1
    Post posts[50];
    assert(readPosts("posts.txt", posts, 0, 50) == 50);
    assert(posts[48].getPostBody() == "Psst… calling all Buffs again. We missed you over spring break! CU on campus again soon");

    // test case 2
    Post post1("hi", "John Green", 100, "12/10/24"), post2, post3("hello cu", "ralphie", 1000000, "1/15/20");
    Post postList[50] = {post1, post2, post3};
    assert(readPosts("posts.txt", postList, 3, 47) == 47);
    assert(postList[2].getPostBody() == "hello cu");

    // test case 3
    Post postList2[1];
    assert(readPosts("posts.txt", postList2, 1, 1) == -2);

    // test case 4
    assert(readPosts("does-not-exist.txt", postList2, 1, 10) == -1);

    return 0;
}