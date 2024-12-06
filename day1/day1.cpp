#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
template <typename ...Args> using umap = unordered_map<Args...>

vector<long> Trim(const string& str) {
    vector<long> trimmed;
    istringstream iss(str);
    long tmp;

    while (iss >> tmp) {
        trimmed.push_back(tmp);
    }

    return trimmed;
}

long SolvePt1(const string& path) {
    ifstream file(path);
    string line;
    vector<long> line_nums, list1, list2;
    while (getline(file, line)) {
        line_nums = Trim(line);
        list1.push_back(line_nums[0]);
        list2.push_back(line_nums[1]);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int size = list1.size();

    long dist = 0, total = 0;
    for (int i = 0; i < size; i++) {
        dist = abs(list1[i] - list2[i]);
        total += dist;
    }

    return total;
}

long SolvePt2(const string& path) {
    ifstream file(path);
    string line;
    vector<long> line_nums;
    umap<long, int> freq1, freq2;

    while (getline(file, line)) {
        line_nums = Trim(line);
        int num1 = line_nums[0], num2 = line_nums[1];
        freq1[num1]++;
        freq2[num2]++;
    }

    long total = 0;
    for (const auto& pair : freq1) {
        long key = pair.first;
        int freq = pair.second;
        if (freq2.find(key) != freq2.end()) {
            total += key * freq2[key];
        }
    }

    return total;
}

int main() {
    long res1 = SolvePt1("dayone.txt");
    long res2 = SolvePt2("dayone.txt");

    cout << "Solution Pt.1: " << res1 << endl;
    cout << "Solution Pt.2: " << res2 << endl;
    return EXIT_SUCCESS;
}