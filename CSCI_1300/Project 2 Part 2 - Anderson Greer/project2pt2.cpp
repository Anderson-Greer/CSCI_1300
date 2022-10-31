// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 2 - Problem 10

#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
#include "Buffchat.h"

using namespace std;

int main() {
    bool quit = false;
    Buffchat buff;
    
    while(!quit) {
        int val;
    
        cout << "======Main Menu=====" << endl;
        cout << "1. Read posts" << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes" << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Add a new post" << endl;
        cout << "7. Print popular posts for a year" << endl;
        cout << "8. Find least active user" << endl;
        cout << "9. Find unique likes for a post author" << endl;
        cout << "10. Quit" << endl;
            
        string input;
        cin >> input;
        
        switch(stoi(input)) { // switch statement for user input
            case 1: // user entered 1
            {
                string filename;
                cout << "Enter a post file name:" << endl; // prompt user for a filename
                cin >> filename;
                //cout << buff.getNumPosts() << ", " << buff.getPostSize() << endl;
                val = buff.readPosts(filename); // read the posts from the file
                
                if(val == -1) { // print if file failed to open
                    cout << "File failed to open. No posts saved to the database." << endl;
                    break;
                }
                else if(val == -2) { // print if posts was already full
                    cout << "Database is already full. No posts were added." << endl;
                    break;
                }
                else if(val == buff.getPostSize()) { // print if posts was filled before the file was fully read
                    cout << "Database is full. Some posts may have not been added." << endl;
                    break;
                }
                else if(val >= 0 && val < buff.getPostSize()) { // prints if posts was not filled by the file
                    cout << "Total posts in the database: " << buff.getNumPosts() << endl;
                    break;
                }
            }
            case 2: // user entered 2
            {
                string year;
                cout << "Enter the year(YY):" << endl; // prompt user for yera
                cin >> year;
                buff.printPostsByYear(year); // print the posts for that year
                break;
            }
            case 3: // user entered 3
            {
                string filename;
                cout << "Enter a user file name:" << endl; // prompt user for filename
                cin >> filename;
                
                val = buff.readLikes(filename); // read the likes from the user file
                
                if(val == -1) { // prints if file could not be opened
                    cout << "File failed to open. No users saved to the database." << endl;
                    break;
                }
                else if(val == -2) { // print if users was already full
                    cout << "Database is already full. No users were added." << endl;
                    break;
                }
                else if(val == buff.getUserSize()) { // prints if users was filled before the file was fully read
                    cout << "Database is full. Some users may have not been added." << endl;
                    break;
                }
                else if(val >= 0 && val < buff.getUserSize()) { // prints if users was not filled up by the file
                    cout << "Total users in the database: " << buff.getNumUsers() << endl;
                    break;
                }
                break;
            }
            case 4: // user entered 4
            {
                string post_author, username;
                cout << "Enter a post author:" << endl; // prompt user for post author and username
                cin >> post_author;
                cout << "Enter a user name:" << endl;
                cin >> username;
                
                val = buff.getLikes(post_author, username); // get the likes from the user object on inputted post
                
                if(val == 0) { // prints if the user object has not liked the author's post
                    cout << username << " has not liked the post posted by " << post_author << endl;
                    break;
                }
                else if(val == -1) { // prints if the user object has not viewed the author's post
                    cout << username << " has not viewed the post posted by " << post_author << endl;
                    break;
                }
                else if(val == -2) { // prints if users is empty
                    cout << "Database is empty." << endl;
                    break;
                }
                else if(val == -3) { // prints if either username or author do not exist
                    cout << username << " or " << post_author  << " does not exist." << endl;
                    break;
                }
                else {
                    cout << username << " liked the post posted by " << post_author << " " << val << " times" << endl;
                }
                break;
            }
            case 5: // user entered 5
            {
                string tag;
                cout << "Enter a tag:" << endl; // propmt user for a tag
                cin >> tag;
                
                buff.findTagUser(tag); // find the tag in list of users
                break;
            }
            case 6: // user entered 6
            {
                string body;
                cout << "Enter a post body:" << endl; // propmt user for a tag
                getline(cin, body);
                string author;
                cout << "Enter a post author:" << endl; // propmt user for a tag
                getline(cin, author);
                string date;
                cout << "Enter a date(mm/dd/yy):" << endl; // propmt user for a tag
                getline(cin, body);
    
                bool result = buff.addPost(body, author, date);
    
                if(result) {
                    cout << author << "'s post added successfully" << endl;
                    break;
                }
                cout << "Database is already full,. " << author << "'s post was not added." << endl;
            }
            case 7: // user entered 7
            {
                int postsNum;
                cout << "Enter the number of posts:" << endl;
                cin >> postsNum;
                string date;
                cout << "Enter the year(YY):" << endl;
                cin >> date;
    
                buff.printPopularPosts(postsNum, date);
                break;
            }
            case 8: // user entered 8
            {
                User user = buff.findLeastActiveUser();
                if(user.getUsername() == "") {
                    cout << "There are no users stored" << endl;
                    break;
                }
                cout << user.getUsername() << " is the least active user" << endl;
                break;
            }
            case 9: // user entered 9
            {
                string author;
                cout << "Enter a post author:" << endl;
                cin >> author;

                int num = buff.countUniqueLikes(author);

                if(num > 0) {
                    cout << "The posts posted by " << author << " have been liked by " << num << " unique users." << endl;
                    break;
                }
                else if(num == 0) {
                    cout << "The posts posted by " << author << " have received 0 likes so far." << endl;
                    break;
                }
                else if(num == -1) {
                    cout << "The posts posted by " << author << " have not been viewed by anyone." << endl;
                    break;
                }
                else if(num == -2) {
                    cout << "There are no users stored" << endl;
                    break;
                }
                break;
            }
            case 10:
            {
                cout << "Good bye!" << endl;
                quit = true;
                break;
            }
            default:
            {
                cout << "Invalid input" << endl;
                break;
            }
        }
    }

    return 0;
}