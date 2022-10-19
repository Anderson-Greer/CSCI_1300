// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation: 101 – Morgan Byers
// Homework 5 - Problem 6

#include <iostream>
#include <cassert>

using namespace std;

// function from github
int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    		arr[i] = 5;
			count++;
		}
	}
	return count;
}

int main() {
    // declare arrays and variables
    int size = 2;
    int arr1[size] = {0, 0};
    int count = zeroesToFives(arr1, size);
    // test case 1
    assert(arr1[0] == 5);
    assert(arr1[1] == 5);
    assert(count == 2);

    size = 3;
    int arr2[size] = {0, 0, 5};
    count = zeroesToFives(arr2, size);
    // test case 2
    assert(arr2[0] == 5);
    assert(arr2[1] == 5);
    assert(arr2[2] == 5);
    assert(count == 2);

    size = 0;
    int arr3[size] = {};
    count = zeroesToFives(arr3, size);
    // test case 3
    assert(count == 0);

    size = 5;
    int arr4[size] = {1, 2, 3, 4, 5};
    count = zeroesToFives(arr4, size);
    // test case 4
    assert(arr4[0] == 1);
    assert(arr4[1] == 2);
    assert(arr4[2] == 3);
    assert(arr4[3] == 4);
    assert(arr4[4] == 5);
    assert(count == 0);

    return 0;
}

