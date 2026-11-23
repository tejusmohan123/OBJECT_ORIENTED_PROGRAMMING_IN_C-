#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
    T* data;
    int capacity;
    int frontIdx;
    int count;
public:
    Queue(int cap = 10) : capacity(cap), frontIdx(0), count(0) {
        data = new T[capacity];
    }
    ~Queue() { delete[] data; }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    void enqueue(const T& item) {
        if (isFull()) throw overflow_error("Queue is full");
        data[(frontIdx + count) % capacity] = item;
        count++;
    }

    T dequeue() {
        if (isEmpty()) throw underflow_error("Queue is empty");
        T item = data[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return item;
    }

    T& front() {
        if (isEmpty()) throw underflow_error("Queue is empty");
        return data[frontIdx];
    }
};

int main() {
    Queue<string> q(5);

    q.enqueue("Asha");
    q.enqueue("Ravi");
    q.enqueue("Meena");

    cout << "Front: " << q.front() << "\n";
    cout << "Size:  " << q.size() << "\n";

    while (!q.isEmpty())
        cout << "Dequeued: " << q.dequeue() << "\n";

    try {
        q.dequeue();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}