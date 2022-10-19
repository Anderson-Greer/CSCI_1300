#include <iostream>
#include <string>

using namespace std;

int main()
{
    // declare variables
    string input;
    string seq;
    bool flag = false;
    int total = 0;
    
    // prompt user and take input
    cout << "Enter the DNA Sequence:" << endl;
    getline(cin, input);
    
    // input validation
    for(int i = 0; i < input.length(); i++) {
        if(input[i] != 'A' && input[i] != 'C' && input[i] != 'G' && input[i] != 'T') {
            cout << "This is not a valid DNA sequence." << endl;
            return 0;
        }
    }
    
    // prompt user and take input
    cout << "Enter the DNA fragment to be searched:" << endl;
    getline(cin, seq);
    
    // check input
    for(int i = 0; i < seq.length(); i++) {
        if(seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'T') {
            cout << "This is not a valid DNA sequence" << endl;
            return 0;
        }
    }
    
    // reuse flag variable
    flag = true;
    
    // loop through input to check for sequence inside of it
    for(int i  = 0; i < input.length() - seq.length() + 1; i++) {
        for(int j = 0; j < seq.length(); j++) { // loops through sequence and compares each char in sequence to input
            if(input[i + j] != seq[j]) {
                flag = false;
            }
            
        }
        if(flag) {
            total++;
        }
        flag = true;
    }
    
    // output answer
    cout << "Number of occurrences: " << total  << endl;
    
    return 0;
}