// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 1

#ifndef POINT2D_H
#define POINT2D_H

#include <string>

using namespace std;

class Post {
    private:
        string body_;
        string post_author_;
        int num_likes_;
        string date_;

    public:
        Post();
        Post(string, string, int, string);

        string getPostBody();
        void setPostBody(string);

        string getPostAuthor();
        void setPostAuthor(string);

        int getPostLikes();
        void setPostLikes(int);

        string getPostDate();
        void setPostDate(string);
};

#endif