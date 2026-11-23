#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Asha", 85},
        {"Ravi", 92},
        {"Meena", 78},
        {"Kiran", 88},
        {"Divya", 70}
    };

    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;   // ascending by second field
    });

    for (const auto& p : v)
        cout << p.first << " : " << p.second << "\n";
    return 0;
}