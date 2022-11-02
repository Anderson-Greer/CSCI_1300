// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Homework 7 - Problem 3

#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    bool jokerFlag = false;
    vector<int> vec;
    int num = 0;
    int count = 0;
    
    while(!jokerFlag) { // while a joker has not been played
        cout << "Please enter a number:" << endl;
        cin >> num;
        while(num <= 0 || num > 14) { // input validation
            cout << "The number should be an integer between 1 and 14." << endl;
            cout << "Please enter a number:" << endl;
            cin >> num;
        }
        
        
        vec.push_back(num); // add the input number to the vector
        
        if(num == 14) { // if the card is a joker, end the game
            jokerFlag = true;
            vec.pop_back();
        }
        else if(num == 11 || num == 12 || num == 13) { // if the card is a face card, remove last two cards from vector and add two to count
            if(vec.size() == 1) { // if there is only one card in vector, remove just that card and add one to count
                vec.pop_back();
                count++;
            }
            else {
                vec.pop_back();
                vec.pop_back();
                count += 2;
            }
        }
        else if(num == 1) { // if the card is an ace, remove first two cards from vector and add two to count
            if(vec.size() == 1) { // if there is only one card in vector, remove just the first card and add one to count
                vec.pop_back();
                count++;
            }
            else {
                vec.erase(vec.begin());
                vec.erase(vec.begin());
                count += 2;
            }
        }
    }
    
    cout << "Your remaining cards are: ";
    for(int i = 0; i < vec.size(); i++) { // print out user's remaining cards
        cout << vec.at(i) << " ";
    }
    
    cout << "\nI have " << count << " card(s)." << endl; // print out how many cards the computer has
    
    // checks to see who won
    if(count > vec.size())
        cout << "I win!" << endl;
    else if(count < vec.size())
        cout << "You win!" << endl;
    else
        cout << "Tie!" << endl;
    
    return 0;
}