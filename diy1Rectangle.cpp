#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;
public:
    Rectangle() : length(0), width(0) {}
    void setLength(double l) { if (l >= 0) length = l; else cout << "Invalid length\n"; }
    void setWidth(double w)  { if (w >= 0) width = w;  else cout << "Invalid width\n"; }
    double area() const { return length * width; }
    double perimeter() const { return 2 * (length + width); }
};

int main() {
    Rectangle r;
    r.setLength(5);
    r.setWidth(3);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    r.setLength(-2);
    return 0;
}