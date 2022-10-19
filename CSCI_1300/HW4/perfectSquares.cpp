#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // declare all variables
    int number;
    int sum = 0;
    int max_val;
    
    // prompt the user and get their input
    cout << "Enter a non-negative integer:" << endl;
    cin >> number;
    
    // input validation
    if (number < 0)
    { 
        cout << "Invalid input." << endl;
    }
    else
    {
        // compute square root
        max_val = sqrt(number);
        
        // loop to compute sum of perfect squares
        for (int i = 0; i <= max_val; i++)
        {
            sum += pow(i, 2);
        }
        cout << "Sum: " << sum << endl;
    }
    return 0;
}