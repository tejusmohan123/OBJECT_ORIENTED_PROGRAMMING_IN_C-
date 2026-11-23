#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    // min-heap of size 3: holds the 3 largest numbers seen so far
    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() > 3) pq.pop();   // drop the smallest
    }

    vector<int> top;
    while (!pq.empty()) {
        top.push_back(pq.top());
        pq.pop();
    }

    cout << "Top " << top.size() << " largest: ";
    for (int i = (int)top.size() - 1; i >= 0; i--)
        cout << top[i] << " ";
    cout << "\n";
    return 0;
}