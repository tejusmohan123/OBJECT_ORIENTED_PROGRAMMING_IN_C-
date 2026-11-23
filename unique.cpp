#include <iostream>
using namespace std;

class Order {
    int id;
    static int nextID;
public:
    Order() : id(nextID++) {}
    int getID() const { return id; }
};
int Order::nextID = 1001;

int main() {
    Order o1, o2, o3;
    cout << "Order IDs: " << o1.getID() << ", " << o2.getID() << ", " << o3.getID() << "\n";
    return 0;
}