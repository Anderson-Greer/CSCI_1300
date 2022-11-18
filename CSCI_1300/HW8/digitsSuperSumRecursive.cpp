// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Homework 8 - Problem 1

#include <cassert>

using namespace std;

int digitsSuperSumRecursive(int num) {
    if(num / 10 == 0) // checks to see if it's the final digit
        return num;
    return digitsSuperSumRecursive((num % 10) + digitsSuperSumRecursive(num / 10)); // returns the super sum of each digit
}

int main() {
    // test cases
    assert(digitsSuperSumRecursive(4567) == 4);
    assert(digitsSuperSumRecursive(0) == 0);
    assert(digitsSuperSumRecursive(26) == 8);
    assert(digitsSuperSumRecursive(-5) == -5);

    return 0;
}