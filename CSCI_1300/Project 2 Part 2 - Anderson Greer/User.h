// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 4

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
    private:
        string username_;
        static const int size_ = 50;
        int likes_[size_];
        int num_posts_;

    public:
        User();
        User(string, int[], int);
        string getUsername();
        void setUsername(string);
        int getLikesAt(int);
        bool setLikesAt(int, int);
        int getNumPosts();
        void setNumPosts(int);
        int getSize();
};

#endif