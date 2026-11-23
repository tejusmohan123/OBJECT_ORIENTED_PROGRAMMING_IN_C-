#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string word;

    cout << "Enter words (Ctrl+D on Linux/Mac, Ctrl+Z then Enter on Windows to finish):\n";
    while (cin >> word)
        freq[word]++;

    if (freq.empty()) {
        cout << "No words entered\n";
        return 0;
    }

    cout << "\nWord counts:\n";
    for (const auto& p : freq)
        cout << p.first << " : " << p.second << "\n";

    string best;
    int bestCount = 0;
    for (const auto& p : freq) {
        if (p.second > bestCount) {
            best = p.first;
            bestCount = p.second;
        }
    }

    cout << "\nMost frequent word: " << best << " (" << bestCount << " times)\n";
    return 0;
}