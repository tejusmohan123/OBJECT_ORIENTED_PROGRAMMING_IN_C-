#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    long long product = accumulate(v.begin(), v.end(), 1LL,
        [](long long acc, int x) { return acc * x; });

    int evenSum = accumulate(v.begin(), v.end(), 0,
        [](int acc, int x) { return (x % 2 == 0) ? acc + x : acc; });

    cout << "Product of all elements: " << product << "\n";
    cout << "Sum of even elements:    " << evenSum << "\n";
    return 0;
}