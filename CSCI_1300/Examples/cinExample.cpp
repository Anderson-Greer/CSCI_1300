#include <iostream>

using namespace std;

int main() 
{
    cout << "Enter a sentence: ";
    string input;
    getline(cin, input);
    cout << input << endl;
    int inputLength = input.length();

    for(int i = 0; i < inputLength; i++) 
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] -= 32;
        }
    }

    cout << input << endl;

    return 0;
}