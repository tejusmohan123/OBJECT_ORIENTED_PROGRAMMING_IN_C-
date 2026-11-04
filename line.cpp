#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin) {
        cout << "Cannot open in.txt\n";
        return 1;
    }
    if (!fout) {
        cout << "Cannot create out.txt\n";
        return 1;
    }

    string line;
    int lineNo = 1;
    while (getline(fin, line)) {
        fout << lineNo << ": " << line << "\n";
        lineNo++;
    }

    fin.close();
    fout.close();
    cout << "Copied " << (lineNo - 1) << " lines to out.txt\n";
    return 0;
}