#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual double calculateInterest() const = 0;
    virtual const char* type() const = 0;
    double getBalance() const { return balance; }
    virtual ~Account() {}
};

class Savings : public Account {
    static const double RATE;
public:
    Savings(double b) : Account(b) {}
    double calculateInterest() const override { return balance * RATE / 100; }
    const char* type() const override { return "Savings"; }
};
const double Savings::RATE = 4.0;

class Current : public Account {
    static const double RATE;
public:
    Current(double b) : Account(b) {}
    double calculateInterest() const override { return balance * RATE / 100; }
    const char* type() const override { return "Current"; }
};
const double Current::RATE = 1.0;

int main() {
    Account* accounts[4];
    accounts[0] = new Savings(10000);
    accounts[1] = new Current(25000);
    accounts[2] = new Savings(50000);
    accounts[3] = new Current(8000);

    cout << fixed << setprecision(2);
    for (int i = 0; i < 4; i++) {
        cout << accounts[i]->type() << " | Balance: " << accounts[i]->getBalance()
             << " | Interest: " << accounts[i]->calculateInterest() << "\n";
    }

    for (int i = 0; i < 4; i++) delete accounts[i];
    return 0;
}
