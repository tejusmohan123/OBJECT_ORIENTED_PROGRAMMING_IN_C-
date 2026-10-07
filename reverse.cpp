#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    vector<string> words;
    string w;
    while (ss >> w)
        words.push_back(w);

    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    return 0;
}