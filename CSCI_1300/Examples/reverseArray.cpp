#include <iostream>

using namespace std;

void swap(int myArray[], int startIndex, int endIndex) {
    int temp = myArray[startIndex];
    myArray[startIndex] = myArray[endIndex];
    myArray[endIndex] = temp;
    return;
}

void reverseArray(int myArray[], int myArrayLength) {
    for(int i = 0; i < myArrayLength / 2; i++) {
        swap(myArray, i, myArrayLength - 1 - i);
    }
    return;
}

int main() {

    int length;
    cout << "Please enter the size of the array: " << endl;
    cin >> length;

    int array[length];

    cout << "Please enter the elements of the array: " << endl;
    for(int i = 0; i < length; i++) {
        cin >> array[i];
    }

    reverseArray(array, length);

    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}