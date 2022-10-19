#include <fstream>
#include <iostream>

using namespace std;

int main() {

    cout << "Enter the input filenames: " << endl;
    string filepath1, filepath2;
    cin >> filepath1 >> filepath2;

    cout << "Enter the output filename: " << endl;
    string outputpath;
    cin >> outputpath;

    ifstream in_file1(filepath1);
    ifstream in_file2(filepath2);

    if(in_file1.fail() || in_file2.fail()) {
        return 0;
    }

    string input1 = "";
    string input2 = "";

    getline(in_file1, input1);
    getline(in_file2, input2);

    string newInput = input1 + input2;

    in_file1.close();
    in_file2.close();

    ofstream out_file(outputpath);

    out_file << newInput << endl;

    out_file.close();

    cout << "Files concatenated successfully." << endl;

    return 0;
}