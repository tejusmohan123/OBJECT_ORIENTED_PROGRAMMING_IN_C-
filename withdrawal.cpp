#include <iostream>
#include <string>
using namespace std;

class InsufficientFunds {
    double balance, requested;
public:
    InsufficientFunds(double bal, double req) : balance(bal), requested(req) {}
    void show() const {
        cout << "InsufficientFunds: balance = " << balance
             << ", requested = " << requested
             << ", short by " << (requested - balance) << "\n";
    }
};

class BankAccount {
    string owner;
    double balance;
public:
    BankAccount(string o, double b) : owner(o), balance(b) {}

    void deposit(double amt) { balance += amt; }

    void withdraw(double amt) {
        if (amt > balance)
            throw InsufficientFunds(balance, amt);
        balance -= amt;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Ravi", 5000);

    try {
        acc.withdraw(2000);
        cout << "Withdrew 2000. Balance: " << acc.getBalance() << "\n";
        acc.withdraw(4000);
        cout << "Withdrew 4000. Balance: " << acc.getBalance() << "\n";
    } catch (const InsufficientFunds& e) {
        e.show();
    }

    cout << "Final balance: " << acc.getBalance() << "\n";
    return 0;
}