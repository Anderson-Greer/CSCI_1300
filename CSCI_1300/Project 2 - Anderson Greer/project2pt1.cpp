// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1: Question 8

#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "User.h"
#include "Post.h"

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size) {
    if(input_string.length() == 0)
        return 0;
        
    arr[0] = input_string;
    
    int subIndex = 0;
    int count = 0;
    for(unsigned int i = 0; i <= input_string.length(); i++) {
        if(input_string[i] == separator) {
            arr[count] = input_string.substr(subIndex, i - subIndex);
            count++;
            subIndex = i + 1;
            
            if(count >= arr_size) {
                return -1;
            }
        }
    }
    arr[count] = input_string.substr(subIndex, input_string.length() - subIndex);
    
    return count + 1;
}

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

void printPostsByYear(Post posts[], string year, int num_posts_stored) {
    if(num_posts_stored <= 0) {
        cout << "No posts are stored" << endl;
        return;
    }
    
    int count = 0;
    
    for(int i = 0; i < num_posts_stored; i++) {
        if(posts[i].getPostDate().substr(6, 2) == year) {
            count++;
            if(count == 1)
                cout << "Here is a list of posts for year " << year << endl;
            cout << posts[i].getPostBody() << endl;
        }
    }
    
    if(count == 0)
        cout << "No posts stored for year " << year << endl;
}

int readLikes(string filename, User users[], int num_users_stored, int users_arr_size, int max_posts) {
    ifstream fin(filename);
    
    if(num_users_stored == users_arr_size)
        return -2;
    else if(fin.fail())
        return -1;
    
    int count = 0;
    int lineLen;
    string line;
    
    for(int i = num_users_stored; i < users_arr_size; i++) {
        
        if(getline(fin, line)) {
            string splitArr[max_posts + 1];
            lineLen = split(line, ',', splitArr, max_posts + 1);
            
            if(splitArr[0] != users[i - 1].getUsername() && lineLen != 0) {
                int likes[lineLen];
                
                for(int j = 0; j < lineLen - 1; j++) {
                    likes[j] = stoi(splitArr[j + 1]);
                }
                User user(splitArr[0], likes, lineLen);
                users[i] = user;
                
                count++;
            }
            else {
                i--;
            }
        }
    }

    fin.close();

    return count + num_users_stored;
}

int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored) {
    bool userFlag = false;
    bool postFlag = false;
    
    for(int i = 0; i < num_users_stored; i++) {
        if(users[i].getUsername() == username)
            userFlag = true;
    }
    for(int i = 0; i < num_posts_stored; i++) {
        if(posts[i].getPostAuthor() == post_author)
            postFlag = true;
    }
    
    if(num_posts_stored <= 0 || num_users_stored <= 0)
        return -2;
    else if(!userFlag || !postFlag)
        return -3;
    
    int index;
    
    for(int i = 0; i < num_users_stored; i++) {
        if(users[i].getUsername() == username)
            index = i;
    }
    
    for(int i = 0; i < num_posts_stored; i++) {
        if(posts[i].getPostAuthor() == post_author)
            return users[index].getLikesAt(i);
    }
    
    return -1;
}

void findTagUser(string username_tag, User users[], int num_users_stored) {
    if(num_users_stored <= 0) {
        cout << "No users are stored in the database" << endl;
        return;
    }
    
    string names[num_users_stored];
    int count = 0;
    
    for(int i = 0; i < num_users_stored; i++) {
        
        string username = users[i].getUsername();
        
        for(int j = 0; j < username.length() - username_tag.length() + 1; j++) {
            if(username.substr(j, username_tag.length()) == username_tag) {
                names[count] = users[i].getUsername();
                count++;
            }
        }
    }
    
    if(count == 0) {
        cout << "No matching user found" << endl;
        return;
    }
    cout << "Here are all the usernames that contain " << username_tag << endl;
    for(int i = 0; i < count; i++) {
        cout << names[i] << endl;
    }
}

int main() {
    bool quit = false;
    int posts_stored = 0;
    int users_stored = 0;
    int val = 0;
    int postsLen = 50;
    int usersLen = 50;
    int max_posts = 50;
    Post posts[postsLen];
    User users[usersLen];
    
    while(!quit) {
        cout << "======Main Menu======" << endl;
        cout << "1. Read Posts" << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes" << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Quit" << endl;
        
        string input;
        cin >> input;
        
        switch(stoi(input)) { // switch statement for user input
            case 1: // user entered 1
            {
                string filename;
                cout << "Enter a post file name:" << endl; // prompt user for a filename
                cin >> filename;
                val = readPosts(filename, posts, posts_stored, postsLen); // read the posts from the file
                
                if(val == -1) { // print if file failed to open
                    cout << "File failed to open. No posts saved to the database." << endl;
                    break;
                }
                else if(val == -2) { // print if posts was already full
                    cout << "Database is already full. No posts were added." << endl;
                    break;
                }
                else if(val == postsLen) { // print if posts was filled before the file was fully read
                    posts_stored = val;
                    cout << "Database is full. Some posts may have not been added." << endl;
                    break;
                }
                else if(val >= 0 && val < postsLen) { // prints if posts was not filled by the file
                    posts_stored = val;
                    cout << "Total posts in the database: " << posts_stored << endl;
                    break;
                }
            }
            case 2: // user entered 2
            {
                string year;
                cout << "Enter the year(YY):" << endl; // prompt user for yera
                cin >> year;
                printPostsByYear(posts, year, posts_stored); // print the posts for that year
                break;
            }
            case 3: // user entered 3
            {
                string filename;
                cout << "Enter a user file name:" << endl; // prompt user for filename
                cin >> filename;
                
                val = readLikes(filename, users, users_stored, usersLen, max_posts); // read the likes from the user file
                
                if(val == -1) { // prints if file could not be opened
                    cout << "File failed to open. No users saved to the database." << endl;
                    break;
                }
                else if(val == -2) { // print if users was already full
                    cout << "Database is already full. No users were added." << endl;
                    break;
                }
                else if(val == usersLen) { // prints if users was filled before the file was fully read
                    users_stored = val; // number of users that are stored in users
                    cout << "Database is full. Some users may have not been added." << endl;
                    break;
                }
                else if(val >= 0 && val < usersLen) { // prints if users was not filled up by the file
                    users_stored = val; // number of users that are stored in users
                    cout << "Total users in the database: " << users_stored << endl;
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
                
                val = getLikes(post_author, posts, posts_stored, username, users, users_stored); // get the likes from the user object on inputted post
                
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
                
                findTagUser(tag, users, users_stored); // find the tag in list of users
                break;
            }
            case 6: // user entered 6
            {
                cout << "Good bye!" << endl;
                quit = true; // ends the program
                break;
            }
            default: // user entered invalid input
                cout << "Invalid input." << endl;
                break;
        }
    }
    
    return 0;
}






