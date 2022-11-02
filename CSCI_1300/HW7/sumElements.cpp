// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Homework 7 - Problem 1

#include <cassert>
#include <vector>

using namespace std;

/*
 * Algorithm:
 * 1. If the size of the array is less than or equal to either the start or end index, return -2
 * 2. If the start index is greater than the end index, return -1
 * 3. Create a total count variable
 * 4. Loop through the vector starting at the start index and finishing at the end index
 * 5. Add each element in this range to the total variable
 * 6. Return the total variable
*/
int sumElements(vector<int> vec, int start, int end) {
    if(start >= vec.size() || end >= vec.size()) {
        return -2;
    }
    else if(start > end) {
        return -1;
    }
    
    int total = 0;
    
    for(int i = start; i <= end; i++) {
        total += vec.at(i);
    }
    
    return total;
}

int main() {
    // test case 1
    vector<int> vect1{10, 20, 30, 40, 50};
    int start_index = 1, end_index = 3;
    assert(sumElements(vect1, start_index, end_index) == 90);

    // test case 2
    vector<int> vect2{10, 20, 30, 40, 50};
    start_index = 0, end_index = 4;
    assert(sumElements(vect2, start_index, end_index) == 150);

    // test case 3
    vector<int> vect3{10, 20, 30, 40, 50};
    start_index = 0, end_index = 0;
    assert(sumElements(vect3, start_index, end_index) == 10);

    // test case 4
    vector<int> vect4{10, 20, 30, 40, 50};
    start_index = 4, end_index = 3;
    assert(sumElements(vect4, start_index, end_index) == -1);

    // test case 5
    vector<int> vect5{10, 20, 30, 40, 50};
    start_index = 1, end_index = 6;
    assert(sumElements(vect5, start_index, end_index) == -2);

    return 0;
}