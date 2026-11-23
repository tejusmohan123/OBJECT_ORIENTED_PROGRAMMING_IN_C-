#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
    int num, den;

    static int gcd(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    void simplify() {
        if (den == 0) throw invalid_argument("Denominator cannot be zero");
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.den == 1) out << f.num;
        else out << f.num << "/" << f.den;
        return out;
    }
    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        int n, d;
        in >> n >> slash >> d;     // input format: n/d
        if (in) f = Fraction(n, d);
        return in;
    }
};

int main() {
    Fraction f1(6, 8), f2(-10, 4), f3(5, -15);
    cout << "6/8   -> " << f1 << "\n";
    cout << "-10/4 -> " << f2 << "\n";
    cout << "5/-15 -> " << f3 << "\n";

    Fraction f;
    cout << "Enter a fraction (n/d): ";
    try {
        cin >> f;
        cout << "Simplified: " << f << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}