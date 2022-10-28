// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 4

#include <string>
#include "User.h"

using namespace std;

User::User() {
    username_ = "";
    for(int i = 0; i < size_; i++) {
        likes_[i] = -1;
    }
    num_posts_ = 0;
}

User::User(string username, int likes[], int num_posts) {
    username_ = username;
    for(int i = 0; i < size_; i++) {
        if(i < num_posts)
            likes_[i] = likes[i];
        else
            likes_[i] = -1;
    }
    num_posts_ = num_posts;
}

string User::getUsername() {
    return username_;
}

void User::setUsername(string username) {
    username_ = username;
}

int User::getLikesAt(int post_id) {
    if(post_id >= size_ || post_id < 0) {
        return -2;
    }

    return likes_[post_id];
}

bool User::setLikesAt(int post_id, int num_likes) {
    if(post_id >= num_posts_ || post_id < 0 || num_likes > 10 || num_likes < -1) {
        return false;
    }

    likes_[post_id] = num_likes;
    return true;
}

int User::getNumPosts() {
    return num_posts_;
}

void User::setNumPosts(int posts) {
    if(posts > 0 && posts < size_)
        num_posts_ = posts;
}

int User::getSize() {
    return size_;
}