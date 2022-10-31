#include <iostream>
#include <vector>

using namespace std;

vector<float> storeFloats() {
    vector<float> vec;

    for(int i = 0; i < 15; i++) {
        float num;
        cout << "Enter float " << (i + 1) << ":" << endl;
        cin >> num;
        vec.push_back(num);
    }

    return vec;
}

float averageVal(vector<float> vec) {
    float total = 0.0;

    for(int i = 0; i < vec.size(); i++) {
        total += vec.at(i);
    }

    return total / vec.size();
}

vector<float> removeAboveAverage(vector<float> vec, float average) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec.at(i) > average) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    return vec;
}

int main() {
    vector<float> ex;

    ex = storeFloats();

    cout << "Values in vector:" << endl;
    for(int i = 0; i < ex.size(); i++) {
        cout << ex.at(i) << ", ";
    }

    float average = averageVal(ex);
    cout << "Average value: " << average << endl;

    vector<float> ex1;

    cout << "Vector after removing above average values: " << endl;
    ex1 = removeAboveAverage(ex, average);
    for(int i = 0; i < ex1.size(); i++) {
        cout << ex1.at(i) << ", ";
    }

    cout << endl;

    return 0;
}