#include <iostream>
using namespace std;

inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(8, 3) = " << minVal(8, 3) << endl;
    cout << "minVal(8, 3, 5) = " << minVal(8, 3, 5) << endl;
    return 0;
}