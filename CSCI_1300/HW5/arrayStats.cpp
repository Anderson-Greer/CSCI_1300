// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 2

#include <iostream>
#include <cassert>

using namespace std;

// function to test equality of doubles
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

// Algorithm: takes an input array and it's length then calculates the minimum value in the array
// by looping through each value and saving the smallest which it eventually returns
double min(double arr[], int length) {
    double min = arr[0];
    
    for(int i = 1; i < length; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    
    return min;
}

// Algorithm: takes in an input array and it's length and then calculates the sum of all the elements
// in the array, returns the sum
double sum(double arr[], int length) {

    double total = 0;
    
    for(int i = 0; i < length; i++) {
        total += arr[i];
    }
    
    return total;
}

// Algorithm: takes in an input array and it's length and then calculates the average value of the 
// array by taking the sum and dividing it by the length.
double average(double arr[], int length) {   
    if(length <= 0)
        return 0;
     
    return sum(arr, length) / length;
}


int main() {
    // declare arrays and other variables
    double arr1[] = {1.24, 5.68, 3, 456};
    int arr1Length = 4;
    double arr2[] = {-5.67, 10.435, 43.2, 1, 49835};
    int arr2Length = 5;
    double arr3[] = {};
    int arr3Length = 0;
    double arr4[] = {-5.67, -100, -1, 2};
    int arr4Length = 4;

    // 4 test cases for min function
    assert(doublesEqual(min(arr1, arr1Length), 1.24));
    assert(doublesEqual(min(arr2, arr2Length), -5.67));
    assert(doublesEqual(min(arr3, arr3Length), 0));
    assert(doublesEqual(min(arr4, arr4Length), -100));

    // 4 test cases for sum function
    assert(doublesEqual(sum(arr1, arr1Length), 465.92));
    assert(doublesEqual(sum(arr2, arr2Length), 49883.965));
    assert(doublesEqual(sum(arr3, arr3Length), 0));
    assert(doublesEqual(sum(arr4, arr4Length), -104.67));

    // 4 test cases for sum function
    assert(doublesEqual(average(arr1, arr1Length), 116.48));
    assert(doublesEqual(average(arr2, arr2Length), 9976.793));
    assert(doublesEqual(average(arr3, arr3Length), 0.0));
    assert(doublesEqual(average(arr4, arr4Length), -26.1675));

    return 0;   
}
