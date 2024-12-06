#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<long> Trim(const string& str) {
    istringstream iss(str);
    long tmp;
    vector<long> trimmed;

    while (iss >> tmp) {
        trimmed.push_back(tmp);
    }

    return trimmed;
}

bool IsValidSequence(const vector<long>& values, int offset) {
    if (values.size() < 2) {
        return false; 
    }

    bool increasing = values[0] < values[1];

    for (size_t i = 1; i < values.size(); i++) {
        int diff = abs(values[i - 1] - values[i]);
        if (diff > offset || diff == 0) {
            return false;
        }

        if (increasing && values[i - 1] > values[i]) {
            return false; 
        }

        if (!increasing && values[i - 1] < values[i]) {
            return false; 
        }
    }

    return true;
}

int SolvePt1(const string& path) {
    ifstream file(path);
    string line;
    vector<long> values;

    long curr;
    long prev;
    int total = 0;
    int offset = 3;

    while (getline(file, line)) {
        values = Trim(line);
        if (IsValidSequence(values, offset)) total++;
    }
    
    return total;
}

int main() {
    int res1 = SolvePt1("daytwo.txt");
    return EXIT_SUCCESS;
}