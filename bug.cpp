
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructed\n"; }
#ifdef FIX
    virtual ~Base() { cout << "Base destroyed\n"; }
#else
    ~Base() { cout << "Base destroyed\n"; }
#endif
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[100];
        cout << "Derived constructed\n";
    }
    ~Derived() {
        delete[] data;
        cout << "Derived destroyed\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}