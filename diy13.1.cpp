// g++ -std=c++14 q1.cpp -o q1
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Stack {
    unique_ptr<int[]> data;   // was: int* data; new int[]; delete[] in destructor
    int top;
    int capacity;
public:
    Stack(int cap = 5) : data(make_unique<int[]>(cap)), top(-1), capacity(cap) {}

    void push(int x) {
        if (top == capacity - 1) throw overflow_error("Stack overflow");
        data[++top] = x;
    }
    int pop() {
        if (top == -1) throw underflow_error("Stack underflow");
        return data[top--];
    }
    bool isEmpty() const { return top == -1; }
    // no destructor needed: unique_ptr frees the memory automatically
};

int main() {
    auto s = make_unique<Stack>(3);   // was: Stack* s = new Stack(3); delete s;

    try {
        s->push(10);
        s->push(20);
        s->push(30);
        s->push(40);   // overflow
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    try {
        while (true) cout << "Popped: " << s->pop() << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}