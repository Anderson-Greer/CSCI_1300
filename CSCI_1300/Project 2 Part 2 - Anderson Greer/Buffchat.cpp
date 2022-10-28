// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 1

#include <string>
#include <fstream>
#include "Buffchat.h"
#include "Post.cpp"
#include "User.cpp"

using namespace std;

Buffchat::Buffchat() {
    num_posts_ = 0;
    num_users_ = 0;
}

int Buffchat::getPostSize() {
    return posts_size_;
}

int Buffchat::getUserSize() {
    return users_size_;
}

int Buffchat::getNumPosts() {
    return num_posts_;
}

int Buffchat::getNumUsers() {
    return num_users_;
}

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

int Buffchat::readPosts(string file_name) {
    if(num_posts_ >= posts_size_)
        return -2;

    ifstream fin(file_name);
    int count = num_posts_;
    string line;
    string lineArr[4];

    if(fin.fail())
        return -1;

    for(int i = num_posts_; i < posts_size_; i++) {
        if(getline(fin, line)) {
            if(line != "" && split(line, ',', lineArr, 4) == 4) {
                Post post(lineArr[0], lineArr[1], stoi(lineArr[2]), lineArr[3]);
                posts_[i] = post;
                
                count++;
            }
            else
                i--;
        }
        
    }

    fin.close();

    return count;
}

// void Buffchat::printPostsByYear(string);

// int Buffchat::readLikes(string);

// int Buffchat::getLikes(string, string);

// void Buffchat::findTagUser(string);

// bool Buffchat::addPost(string, string, string);

// void Buffchat::printPopularPosts(int, string);

// User Buffchat::findLeastActiveUser();

// int Buffchat::countUniqueLikes(string);
