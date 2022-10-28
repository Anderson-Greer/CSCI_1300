// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Project 2 Part 1 - Problem 3

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

/*Algorithm
 * 1. Take in a posts array, year, and number of posts stored in posts array as parameters
 * 2. If the number of posts stored in the posts array is less than or equal to 0, print no posts stored
 * 3. Create a count variable and set it equal to 0
 * 4. Loop through the filled elements of posts array and compare the last two characters of the object's post date to the year parameter
 * 5. If the two strings are the same, increase count by 1 and print the post body
 * 5a. If this is the first post found, print "here is a list of posts for the given year" before the post body is printed
 * 6. If the count variable is never increased, print "no posts stored for given year"
*/
void printPostsByYear(Post posts[], string year, int num_posts_stored) {
    if(num_posts_stored <= 0) {
        cout << "No posts are stored" << endl;
        return;
    }
    
    int count = 0;
    
    for(int i = 1; i < num_posts_stored; i++) {
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

int main() {
    // test case 1
    Post posts[50];
    readPosts("posts.txt", posts, 0, 50);
    // should print:
    // Here is a list of posts for year 22
    // It's National Live Creative Day! What better way to celebrate than showcasing our creative talented and passionate Buffs!
    // We had so much fun yesterday at the Be Involved Fair!
    // Yesterday was such a beautiful start to the new school year
    // Ready for the weekend
    // Welcome to the Buffs fam to all our new students
    // It's been so toasty in Boulder recently! Are you missing the snow tipped Flatirons?
    // John Bally professor emeritus of astrophysical and planetary sciences at CU Boulder comes to @fiskeplanet to take a look at first glimpses of the universe.
    // In honor of tomorrow being #NationalTrailsDay we want to know where your favorite hike is around campus Buffs.
    // It’s 70° and sunny in April… we hope to catch you outside Buffs
    printPostsByYear(posts, "22", 50);

    // test case 2
    // should print:
    // No posts stored for year 32
    printPostsByYear(posts, "32", 50);

    // test case 3
    Post postList[0];
    // should print:
    // No posts stored
    printPostsByYear(postList, "22", 0);

    return 0;
}