#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("nums.txt");
    if (!fin) {
        cout << "Cannot open nums.txt\n";
        return 1;
    }

    int x, count = 0;
    long long sum = 0;
    int mn = 0, mx = 0;

    while (fin >> x) {
        if (count == 0) mn = mx = x;
        else {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }
        sum += x;
        count++;
    }
    fin.close();

    if (count == 0) {
        cout << "File has no numbers\n";
        return 0;
    }

    cout << "Count: " << count << "\n";
    cout << "Sum:   " << sum << "\n";
    cout << "Min:   " << mn << "\n";
    cout << "Max:   " << mx << "\n";
    return 0;
}