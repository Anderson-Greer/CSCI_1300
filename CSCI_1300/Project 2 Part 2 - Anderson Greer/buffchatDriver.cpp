// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 2 - Problem 0

#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
#include "Buffchat.h"

using namespace std;

int main() {
    Buffchat buff;
    // test case 1
    assert(buff.getPostSize() == 50);
    assert(buff.getUserSize() == 50);
    assert(buff.getNumPosts() == 0);
    assert(buff.getNumUsers() == 0);

    // test case 2
    int num = buff.readPosts("posts.txt");
    assert(num == 50);
    num = buff.readPosts("does-not-exist.txt");
    assert(num == -2);

    // test case 3, should print:
    // Here is a list of posts for year 19
    // Are you ready to cheer on some @cubuffs athletes?
    // Swipe to see what everyone was taking photos of!
    // Hey Buffs here’s your reminder to call those who support you
    // First week of the 2022 school year complete
    // Look at all the clubs and organizations that showed up for the Be Involved Fair!
    // See you all at the game on friday night
    // For some tomorrow marks the first day of their college adventure and for others it marks the start of their final college years.
    // Great energy in Folsom tonight for CU Kick Off!
    // It's #BestFriendsDay and we know there are many best friend Buffs out there! Tag your Buffs BFF below.
    // Chances are pretty good you've seen CU scientist Tomoko Borsa's photos of campus when scrolling #CUBoulder photos on the various social networks.
    buff.printPostsByYear("19");

    // test case 4, should print:
    // No posts stored for year 01
    buff.printPostsByYear("01");

    // test case 5
    num = buff.readLikes("users.txt");
    assert(num == 49);
    num = buff.readLikes("does-not-exist.txt");
    assert(num == -1);

    // test case 6
    num = buff.getLikes("benjohnston", "cualerts");
    assert(num == -1);
    num = buff.getLikes("Julia", "cualerts");
    assert(num == 7);

    // test case 7, should print:
    // no matching user found
    buff.findTagUser("ben");

    // test case 8, should print:
    // Here are all the usernames that contain cu
    // cuboulderalumni
    // culegislative
    // cubuffnews
    // roboticscu
    // cubouldermusic
    // cubuffs
    // cuweatherclub678
    // cuhikingclub
    // cuisthebest
    // cucornhole
    // MarcusCU
    // cuboulder
    // cuconstrution
    // cualerts
    buff.findTagUser("cu");

    // test case 9
    bool result = buff.addPost("Hi all!", "andy", "10/12/19");
    assert(result == false);

    // test case 10, should print:
    // Top 2 posts for year 19
    // 252 likes: Are you ready to cheer on some @cubuffs athletes?
    // 245 likes: First week of the 2022 school year complete
    buff.printPopularPosts(2, "19");

    // test case 11, should print:
    // No posts stored for year 23
    buff.printPopularPosts(2, "23");

    // test case 12, should print:
    // There are fewer than 100 posts for year 19. Top 10 posts for year 19...
    buff.printPopularPosts(100, "19");

    // test case 13
    User user = buff.findLeastActiveUser();
    assert(user.getUsername() == "michelleryan");

    // test case 14
    num = buff.countUniqueLikes("michelleryan");
    assert(num == 110);

    // test case 14
    num = buff.countUniqueLikes("johngreene");
    assert(num == -1);

    return 0;
}