// Without lock (wrong totals):  g++ -std=c++14 -pthread q3.cpp -o q3 && ./q3
// With lock (always 200000):    g++ -std=c++14 -pthread -DUSE_LOCK q3.cpp -o q3 && ./q3
// Run several times:            for i in 1 2 3 4 5; do ./q3; done
// Optional detector:            g++ -std=c++14 -pthread -fsanitize=thread -g q3.cpp -o q3
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void work() {
    for (int i = 0; i < 100000; i++) {
#ifdef USE_LOCK
        lock_guard<mutex> lock(m);
#endif
        counter++;
    }
}

int main() {
    thread t1(work);
    thread t2(work);
    t1.join();
    t2.join();

    cout << "Total = " << counter << " (expected 200000)\n";
    return 0;
}