// CSCI 1300 Fall 2022
// Author: Anderson Greer
// Recitation 101: Morgan Byers
// Homework 7 - Problem 2

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
 * Algorithm:
 * 1. Take in vector vec as parameter
 * 2. Create a flag boolean, result string, and tag string
 * 3. Loop through the vector and save each tag in the tag string
 * 4. Loop through each tag and if a tag has an incorrect character or not a size of 3, return "Invalid sequence."
 * 5. If the tag is the starting codon, set flag variable to true
 * 6. If flag variable is true, check to see if the tag is an ending codon, if so then return result string
 * 7. If not, add the tag to the result string
 * 8. Exit the for loop and return result if there is no ending codon
*/
string dnaRead(vector<string> vec) {
    bool startFlag = false;
    string result = "";
    string tag;
    
    for(int i = 0; i < vec.size(); i++) {
        tag = vec.at(i); 

        for(int j = 0; j < vec.at(i).size(); j++) {
            if((tag[j] != 'A' && tag[j] != 'C' && tag[j] != 'G' && tag[j] != 'T') || tag.size() != 3) {
                return "Invalid sequence.";
            }
        }
        
        if(tag == "ATG") {
            startFlag = true;
        }
        else if(startFlag) {
            if(tag == "TAA" || tag == "TAG" || tag == "TGA")
                return result;
            else
                result += tag;
        }
    }
    
    return result;
}

int main() {
    // test case 1
    vector<string> dna1{"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    assert(dnaRead(dna1) == "CATACTGAC");

    // test case 2
    vector<string> dna2{"ATG", "CT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    assert(dnaRead(dna2) == "Invalid sequence.");

    // test case 3
    vector<string> dna3{"ATG", "CAT", "ACT", "GAC", "ACL", "TAA", "TAC"};
    assert(dnaRead(dna3) == "Invalid sequence.");

    // test case 4
    vector<string> dna4{"ATG", "CAT", "ACT"};
    assert(dnaRead(dna4) == "CATACT");

    // test case 5
    vector<string> dna5{"CAT", "ACT", "GAC", "TAA", "ACG", "TAC"};
    assert(dnaRead(dna5) == "");

    return 0;
}