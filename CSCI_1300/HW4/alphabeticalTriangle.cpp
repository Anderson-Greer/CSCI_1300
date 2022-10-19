#include <iostream>

using namespace std;

int main()
{
    // declare variables
    int heightInput;
    int length = 1;
    char letter = 'a';
    
    // prompt user and take input
    cout << "Enter the height:" << endl;
    cin >> heightInput;
    
    // input validation
    if(heightInput <= 0) {
        cout << "Invalid input." << endl;
    }
    
    // nested for loop to loop until the height has been reached and loop through each line
    for(int i = 0; i < heightInput; i++) {
        for(int j = 0; j < length; j++) {
            cout << letter;
            
            if(letter == 'z') // reset the alphabet when z is reached
                letter -= 25;
            else
                letter++;
        }
        cout << "\n"; // start a new line at the end of each line
        length += 2; // increase the length of the next line by 2

    }
    
    return 0;
}