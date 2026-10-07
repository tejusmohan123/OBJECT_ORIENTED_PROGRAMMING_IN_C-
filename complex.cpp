#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex() : real(0), imag(0) {}
    void setData(double r, double i) { real = r; imag = i; }
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << (imag >= 0 ? imag : -imag) << "i\n";
    }
};

int main() {
    Complex arr[3];
    arr[0].setData(3, 4);
    arr[1].setData(1.5, -2);
    arr[2].setData(0, 7);
    for (int i = 0; i < 3; i++)
        arr[i].display();
    return 0;
}