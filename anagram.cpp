#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string a, b;
    cout << "Enter first word: ";
    cin >> a;
    cout << "Enter second word: ";
    cin >> b;

    // Make comparison case-insensitive
    for (char &c : a) c = tolower(c);
    for (char &c : b) c = tolower(c);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
        cout << "The words are anagrams." << endl;
    else
        cout << "The words are not anagrams." << endl;
    return 0;
}