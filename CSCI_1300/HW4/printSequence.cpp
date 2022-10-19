#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // declare all variables
    int input;
    
    // prompt user for input and store in var
    cout << "Enter  a value between 1 and 1000:" << endl;
    cin >> input;
    
    // input validation
    while(input <= 1 || input >= 1000)
    {
        cout << "Invalid input." << endl;;
        cout << "Enter  a value between 1 and 1000:" << endl;
        cin >> input;
    }
    
    // loop to compute answer
    while(input != 1)
    {
        cout << input << endl;
        
        if(input % 2 == 0)
        {
            input = floor(input / 2);
        }
        else
        {
            input = 3 * input + 1;
        }
    }
    
    // print answer
    cout << input << endl;
    
    return 0;
}