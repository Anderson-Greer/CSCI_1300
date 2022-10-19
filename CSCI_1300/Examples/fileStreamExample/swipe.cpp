#include <fstream>
#include <iostream>

using namespace std;

int countSwipes(string list_of_swipes) {
    int swipes = 1;
    for(int i = 0; i < list_of_swipes.length(); i++) {
        if(list_of_swipes[i] == ',') {
            swipes++;
        }
    }

    return swipes;
}

string findBusiest(string filepath) {
    ifstream in_file(filepath);

    if(in_file.fail()) {
        return "";
    }

    int highest_swipes = 0;
    string busiest_day;

    while(!in_file.eof()) {
        string day, list_of_swipes;
        in_file >> day >> list_of_swipes;

        int current_swipes = countSwipes(list_of_swipes);

        if(current_swipes > highest_swipes) {
            highest_swipes = current_swipes;
            busiest_day = day;
        }
    }

    in_file.close();

    return busiest_day;
}

int main() {

    cout << findBusiest("card_swipes.txt") << " is the busiest day of the week at the lab." << endl;

    return 0;
}