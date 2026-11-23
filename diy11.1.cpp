#include <iostream>
using namespace std;

template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

int main() {
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << "\n";
    swapVals(a, b);
    cout << "After swap:  a = " << a << ", b = " << b << "\n";

    double x = 1.5, y = 2.75;
    cout << "Before swap: x = " << x << ", y = " << y << "\n";
    swapVals(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << "\n";

    int iarr[] = {4, 17, 9, 25, 3};
    double darr[] = {2.5, 9.75, 1.25, 6.5};

    cout << "Max of int array:    " << findMax(iarr, 5) << "\n";
    cout << "Max of double array: " << findMax(darr, 4) << "\n";
    return 0;
}