// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 2: Question 0

#ifndef BUFFCHAT_H
#define BUFFCHAT_H

#include <string>

using namespace std;

class Buffchat {
    private:
        const static int posts_size_;
        const static int users_size_;
        Post posts_[];
        User users_[];
        int num_posts_;
        int num_users_;

    public:
        Buffchat();
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();

        int readPosts(string);
        void printPostsByYear(string);
        int readLikes(string);
        int getLikes(string, string);
        void findTagUser(string);
        bool addPost(string, string, string);
        void printPopularPosts(int, string);
        User findLeastActiveUser();
        int countUniqueLikes(string);
};

#endif