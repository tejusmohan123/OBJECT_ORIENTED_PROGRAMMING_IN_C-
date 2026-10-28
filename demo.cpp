#include <iostream>
using namespace std;

class MathError {
public:
    virtual const char* what() const { return "MathError"; }
    virtual ~MathError() {}
};

class DivideByZero : public MathError {
public:
    const char* what() const override { return "DivideByZero"; }
};

double divide(double a, double b) {
    if (b == 0) throw DivideByZero();
    return a / b;
}

int main() {
    cout << "--- WRONG order (base first) ---\n";
    try {
        divide(10, 0);
    } catch (const MathError& e) {
        cout << "Caught by MathError handler: " << e.what() << "\n";
    } catch (const DivideByZero& e) {
        cout << "Caught by DivideByZero handler: " << e.what() << "\n";   // never runs
    }

    cout << "\n--- CORRECT order (derived first) ---\n";
    try {
        divide(10, 0);
    } catch (const DivideByZero& e) {
        cout << "Caught by DivideByZero handler: " << e.what() << "\n";
    } catch (const MathError& e) {
        cout << "Caught by MathError handler: " << e.what() << "\n";
    }

    return 0;
}