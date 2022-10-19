// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 5

#include <iostream>
#include <cassert>

using namespace std;

int fullClass(bool classroom[][4], int rows, int waitlist) {
    if(rows == 0) {
        cout << "Remaining Students: " << waitlist << endl;
        return 0;
    }
     
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 4; j++) {
            if(waitlist > 0) {
                if(classroom[i][j] == 0) {
                    classroom[i][j] = 1;
                    waitlist--;
                }
            }
        }
    }
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 4; j++) {
            cout << classroom[i][j];
        }
        cout << "\n";
    }
    
    cout << "Remaining Students: " << waitlist << endl;
    
    return waitlist;
}

int main() {
    // declare arrays and other variables
    bool classroom[4][4] = {{0, 1, 1, 1},
                            {0, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 1}};
    int waitlist = 6;
    /* This test should return:
    1111
    1111
    1110
    0101
    Remaining Students: 0
    */
    int remaining = fullClass(classroom, 4, waitlist);
    assert(remaining == 0);
    
    bool classroom1[4][4] = {{0, 1, 1, 1},
                            {0, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 1}};
    waitlist = 1;
    /* This test should return:
    1111
    0000
    1100
    0101
    Remaining Students: 0
    */
    remaining = fullClass(classroom1, 4, waitlist);
    assert(remaining == 0);

    bool classroom2[4][4] = {{1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1}};
    waitlist = 100;
    /* This test should return:
    1111
    1111
    1111
    1111
    Remaining Students: 100
    */
    remaining = fullClass(classroom2, 4, waitlist);
    assert(remaining == waitlist);

    bool classroom3[4][4] = {{1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 1},
                             {1, 1, 1, 1}};
    waitlist = 0;
    /* This test should return:
    1111
    1111
    1101
    1111
    Remaining Students: 0
    */
    remaining = fullClass(classroom3, 4, waitlist);
    assert(remaining == 0);


    return 0;
}
