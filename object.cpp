#include <iostream>
using namespace std;

class Counter {
    int value;
    static int totalCreated;
    static int aliveCount;
public:
    Counter(int v = 0) : value(v) { ++totalCreated; ++aliveCount; }
    Counter(const Counter& other) : value(other.value) { ++totalCreated; ++aliveCount; }
    ~Counter() { --aliveCount; }

    void increment() { ++value; }
    void decrement() { --value; }
    int getValue() const { return value; }

    static int getTotalCreated() { return totalCreated; }
    static int getAliveCount() { return aliveCount; }
};
int Counter::totalCreated = 0;
int Counter::aliveCount = 0;

int main() {
    {
        Counter c1, c2;
        {
            Counter c3(5);
            cout << "Created: " << Counter::getTotalCreated()
                 << ", Alive: " << Counter::getAliveCount() << "\n";
        }
        cout << "Created: " << Counter::getTotalCreated()
             << ", Alive: " << Counter::getAliveCount() << "\n";
    }
    cout << "Created: " << Counter::getTotalCreated()
         << ", Alive: " << Counter::getAliveCount() << "\n";
    return 0;
}