#include <iostream>

using namespace std;

int main()
{
    // declare all variables
    int input;
    int honeycomb;
    int dandelion;
    int coal;
    int toadstool;
    int totalMana = 0;
    int totalHealth = 0;
    
    // prompt user for input and store in var
    cout << "Select a potion crafting priority:\n1. Minor Mana\n2. Minor Healing" << endl;
    cin >> input;
    while(input < 1 || input > 2) { // input validation
        cout << "Invalid input." << endl;
        cout << "Select a potion crafting priority:\n1. Minor Mana\n2. Minor Healing" << endl;
        cin >> input;
    }
    
    // prompt user for input and store in var
    cout << "How many Honeycombs do you have?" << endl;
    cin >> honeycomb;
    while(honeycomb < 0) { // input validation
        cout << "Invalid input. ";
        cout << "How many Honeycombs do you have?" << endl;
        cin >> honeycomb;
    }
    
    // prompt user for input and store in var
    cout << "How many Dandelions do you have?" << endl;
    cin >> dandelion;
    while(dandelion < 0) { // input validation
        cout << "Invalid input. ";
        cout << "How many Dandelions do you have?" << endl;
        cin >> dandelion;
    }
    
    // prompt user for input and store in var
    cout << "How many Coal do you have?" << endl;
    cin >> coal;
    while(coal < 0) { // input validation
        cout << "Invalid input. ";
        cout << "How many Coal do you have?" << endl;
        cin >> coal;
    }
    
    // prompt user for input and store in var
    cout << "How many Toadstools do you have?" << endl;
    cin >> toadstool;
    while(toadstool < 0) { // input validation
        cout << "Invalid input. ";
        cout << "How many Toadstools do you have?" << endl;
        cin >> toadstool;
    }
    // switch input variable which is user choice for potion
    switch(input) {
        case 1: // user chose mana potion
            while(honeycomb / 5 >= 1 && dandelion / 3 >= 1 && coal >= 1) { // loops while user can afford to make another mana potion
                totalMana++;
                honeycomb -= 5;
                dandelion -= 3;
                coal--;
            }
            while(honeycomb / 5 >= 1 && coal / 2 >= 1 && toadstool >= 3) { // loops while user can afford to make another health potion
                totalHealth++;
                honeycomb -= 5;
                coal -= 2;
                toadstool -= 3;
            }

            // output answer
            cout << "You can make " << totalMana << " Mana potion(s) and " << totalHealth << " Healing potion(s)." << endl;
            break;
        case 2: // user chose health potion
            while(honeycomb / 5 >= 1 && coal / 2 >= 1 && toadstool >= 3) { // loops while user can afford to make another health potion
                totalHealth++;
                honeycomb -= 5;
                coal -= 2;
                toadstool -= 3;
            }
            while(honeycomb / 5 >= 1 && dandelion / 3 >= 1 && coal >= 1) { // loops while user can afford to make another mana potion
                totalMana++;
                honeycomb -= 5;
                dandelion -= 3;
                coal--;
            }

            // output answer
            cout << "You can make " << totalHealth << " Healing potion(s) and " << totalMana << " Mana potion(s)." << endl;
            break;
    }
    
    return 0;
}