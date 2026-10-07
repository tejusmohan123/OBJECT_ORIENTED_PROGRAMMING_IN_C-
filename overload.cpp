#include <iostream>
using namespace std;

const double PI = 3.14159265;

double volume(double side) {                           
    return side * side * side;
}

double volume(double l, double w, double h) {          
    return l * w * h;
}

double volume(double radius, double height) {          
    return PI * radius * radius * height;
}

int main() {
    cout << "Cube (3): " << volume(3.0) << endl;
    cout << "Cuboid (2, 3, 4): " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder (r=2, h=5): " << volume(2.0, 5.0) << endl;
    return 0;
}