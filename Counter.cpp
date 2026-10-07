#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}
    void increment() { count++; }
    void reset() { count = 0; }
    int get() const { return count; }
};

int main() {
    Counter c[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j <= i; j++)
            c[i].increment();

    for (int i = 0; i < 3; i++)
        cout << "Counter " << i << " = " << c[i].get() << endl;

    c[1].reset();
    cout << "Counter 1 after reset = " << c[1].get() << endl;
    return 0;
}