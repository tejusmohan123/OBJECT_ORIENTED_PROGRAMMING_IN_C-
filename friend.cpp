#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hh, mm;
public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}
    void display() const {
        cout << setfill('0') << setw(2) << hh << ":" << setw(2) << mm << setfill(' ');
    }
    friend Time laterOf(Time a, Time b);
};

Time laterOf(Time a, Time b) {
    if (a.hh > b.hh) return a;
    if (a.hh < b.hh) return b;
    return (a.mm >= b.mm) ? a : b;
}

int main() {
    Time t1(9, 45), t2(14, 5);
    Time later = laterOf(t1, t2);

    cout << "Later of "; t1.display();
    cout << " and ";     t2.display();
    cout << " is ";      later.display();
    cout << "\n";
    return 0;
}