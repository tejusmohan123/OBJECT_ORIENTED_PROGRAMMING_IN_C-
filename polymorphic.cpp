#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string& msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string& msg) override {
        cout << "[Console] " << msg << "\n";
    }
};

class FileLogger : public Logger {
    ofstream file;
public:
    FileLogger(const string& name = "log.txt") : file(name, ios::app) {}
    void write(const string& msg) override {
        file << "[File] " << msg << "\n";
    }
    ~FileLogger() { file.close(); }
};

int main() {
    Logger* logger = nullptr;
    int choice;

    do {
        cout << "\nChoose logger: 1) Console  2) File  0) Exit : ";
        cin >> choice;
        if (choice == 0) break;

        delete logger;
        if (choice == 1)      logger = new ConsoleLogger();
        else if (choice == 2) logger = new FileLogger("log.txt");
        else { logger = nullptr; cout << "Invalid choice\n"; continue; }

        logger->write("Hello from the logger!");
        logger->write("Logger switched at run time.");
    } while (true);

    delete logger;
    return 0;
}