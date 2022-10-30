// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 1

#include <string>
#include <fstream>
#include <iostream>
#include "Post.cpp"
#include "User.cpp"
#include "Buffchat.h"

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

int Buffchat::split(string input_string, char separator, string arr[], int arr_size) {
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

    num_posts_ = count;
    return count;
}

/*Algorithm
 * 1. Take in a posts array, year, and number of posts stored in posts array as parameters
 * 2. If the number of posts stored in the posts array is less than or equal to 0, print no posts stored
 * 3. Create a count variable and set it equal to 0
 * 4. Loop through the filled elements of posts array and compare the last two characters of the object's post date to the year parameter
 * 5. If the two strings are the same, increase count by 1 and print the post body
 * 5a. If this is the first post found, print "here is a list of posts for the given year" before the post body is printed
 * 6. If the count variable is never increased, print "no posts stored for given year"
*/
void Buffchat::printPostsByYear(string year) {
    if(num_posts_ <= 0) {
        cout << "No posts are stored" << endl;
        return;
    }
    
    int count = 0;
    
    for(int i = 1; i < num_posts_; i++) {
        if(posts_[i].getPostDate().substr(6, 2) == year) {
            count++;
            if(count == 1)
                cout << "Here is a list of posts for year " << year << endl;
            cout << posts_[i].getPostBody() << endl;
        }
    }
    
    if(count == 0)
        cout << "No posts stored for year " << year << endl;
}

/* Algorithm
 * 1. Take in a filename, users array, number of users in the array, the size of the array, and the max posts for each file line as parameters
 * 2. If number of users stored is the same as the size of the array, return -2 because the array is already full
 * 3. Return -1 if the file cannot be opened
 * 4. While there is still room in the array, loop through each line of the text file and split each line into an array
 * 4a. If the line is empty, reduce the for loop conditional variable by one
 * 5. Create a user object with the username from the file line and an array of likes that follows the username
 * 6. Increase a count variable for number of users added
 * 7. Return the count variable once the loop ends
*/
int Buffchat::readLikes(string filename) {
    ifstream fin(filename); // open file for reading
    
    if(num_users_ == users_size_) // if array is already full, return -2
        return -2;
    else if(fin.fail()) // if file does not exist or will not open, return -1
        return -1;
    
    int count = 0;
    int lineLen;
    int max_posts = 50;
    string line;
    
    for(int i = num_users_; i < users_size_; i++) { // loop through each available space in the users array
        
        if(getline(fin, line)) { // check if there is a readable line and store it in the string line
            string splitArr[max_posts + 1];
            lineLen = split(line, ',', splitArr, max_posts + 1); // use split function to split the line from the file into an array
            
            if(splitArr[0] != users_[i - 1].getUsername() && lineLen != 0) { // if the user is not repeated or not an empty line, execute the rest of code
                int likes[lineLen];
                
                for(int j = 0; j < lineLen - 1; j++) { // loop through the array from split function and store every value but the first in a likes array
                    likes[j] = stoi(splitArr[j + 1]);
                }
                User user(splitArr[0], likes, lineLen); // create a user object to store with given username and likes from file line
                users_[i] = user; // store user object in array
                
                count++; // increase count variable by one
            }
            else { // if the line is skipped, the for loop should be set back an iteration because the available space in the users array was not used
                i--;
            }
        }
    }

    fin.close(); // close the file

    num_users_ += count;
    return num_users_; // return the new number of elements in the users array
}

/* Algorithm
 * 1. Take in post_author, posts list, number of posts stored, username, users list, and number of users stored as parameters
 * 2. Check if the username is in the users list and the post_author is in the posts list
 * 3. Return -2 if there are 0 elements in either users or posts lists
 * 4. Return -3 if either username or post_author are not present in their respective lists
 * 5. Search the users list for the desired username and save it's index
 * 6. Loop through the posts list to find the post author and return the number of likes from the user at the post author's index
*/
int Buffchat::getLikes(string post_author, string username) {
    bool userFlag = false; // flags to ensure username and post_author exist
    bool postFlag = false;
    
    for(int i = 0; i < num_users_; i++) { // checks to see if username exists in users array
        if(users_[i].getUsername() == username)
            userFlag = true;
    }
    for(int i = 0; i < num_posts_; i++) { // checks to see if post_author exists in posts array
        if(posts_[i].getPostAuthor() == post_author)
            postFlag = true;
    }
    
    if(num_posts_ <= 0 || num_users_ <= 0) // if either posts or users arrays are empty, return -2
        return -2;
    else if(!userFlag || !postFlag) // if username or post_author do not exist in respective arrays, return -3
        return -3;
    
    int index;
    
    for(int i = 0; i < num_users_; i++) { // find the index of the username in users array
        if(users_[i].getUsername() == username)
            index = i;
    }
    
    for(int i = 0; i < num_posts_; i++) { // find the index of post_author in posts array
        if(posts_[i].getPostAuthor() == post_author)
            return users_[index].getLikesAt(i); // return the number of likes the user with given username has given the desired post
    }
    
    return -1;
}

/* Algorithm
 * 1. Take the username_tag, users array, and number of users in the array as parameters
 * 2. If the number of users in the array is less than or equal to 0, print no users in database
 * 3. Loop through each user in the users array and compare each possible substring in that username to the username_tag
 * 4. If any substring is equal to the username_tag, add that username to a separate array and increase a count variable by 1
 * 5. Once the loop is finished, if the count variable is greater than one print out each username in the separate array
 * 6. If count is equal to 0, print no users found
*/
void Buffchat::findTagUser(string username_tag) {
    if(num_users_ <= 0) { // input validation
        cout << "No users are stored in the database" << endl;
        return;
    }
    
    string names[num_users_]; // array for usernames with the tag
    int count = 0; // count variable
    
    for(int i = 0; i < num_users_; i++) { // loops through users array to look at each user
        
        string username = users_[i].getUsername(); // stores the username of the user object
        
        for(int j = 0; j < username.length() - username_tag.length() + 1; j++) { // compares each possible substring in the username to the tag
            if(username.substr(j, username_tag.length()) == username_tag) {
                names[count] = users_[i].getUsername(); // store matching username
                count++; // increase count variable by one
            }
        }
    }
    
    if(count == 0) { // no usernames matched the tag
        cout << "No matching user found" << endl;
        return;
    }
    cout << "Here are all the usernames that contain " << username_tag << endl;
    for(int i = 0; i < count; i++) { // print out all usernames with the tag
        cout << names[i] << endl;
    }
}

bool Buffchat::addPost(string post_body, string post_author, string date) {
    if(num_posts_ == posts_size_)
        return false;
    
    Post post(post_body, post_author, 0, date);
    posts_[num_posts_] = post;
    num_posts_++;
    return true;
}

void Buffchat::printPopularPosts(int count, string year) {

}

User Buffchat::findLeastActiveUser() {
    User user;
    return user;
}

int Buffchat::countUniqueLikes(string post_author) {
    return 0;
}
