#include <iostream>
using namespace std;

class Overflow {
public:
    void show() const { cout << "Overflow: stack is full\n"; }
};

class Underflow {
public:
    void show() const { cout << "Underflow: stack is empty\n"; }
};

class Stack {
    int* data;
    int top;
    int capacity;
public:
    Stack(int cap = 3) : top(-1), capacity(cap) { data = new int[capacity]; }
    ~Stack() { delete[] data; }

    void push(int x) {
        if (top == capacity - 1) throw Overflow();
        data[++top] = x;
    }
    int pop() {
        if (top == -1) throw Underflow();
        return data[top--];
    }
};

int main() {
    Stack s(3);

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Pushed 3 items\n";
        s.push(40);   // overflow
    } catch (const Overflow& e) {
        e.show();
    } catch (const Underflow& e) {
        e.show();
    }

    try {
        for (int i = 0; i < 4; i++)
            cout << "Popped: " << s.pop() << "\n";   // 4th pop underflows
    } catch (const Overflow& e) {
        e.show();
    } catch (const Underflow& e) {
        e.show();
    }

    return 0;
}