#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string name;
    int marks;
public:
    Student() : name(""), marks(0) {}
    Student(string n, int m) : name(n), marks(m) {}
    string getName() const { return name; }
    int getMarks() const { return marks; }
    void display() const { cout << name << " - " << marks << "\n"; }
};

int main() {
    // write name-marks pairs to a file
    ofstream fout("students.txt");
    fout << "Asha 85\n";
    fout << "Ravi 92\n";
    fout << "Meena 78\n";
    fout << "Kiran 88\n";
    fout.close();

    // read them back into an array of Student objects
    ifstream fin("students.txt");
    if (!fin) {
        cout << "Cannot open students.txt\n";
        return 1;
    }

    const int MAX = 100;
    Student students[MAX];
    int n = 0;
    string name;
    int marks;

    while (n < MAX && fin >> name >> marks) {
        students[n++] = Student(name, marks);
    }
    fin.close();

    if (n == 0) {
        cout << "No records found\n";
        return 0;
    }

    cout << "Students read:\n";
    for (int i = 0; i < n; i++) students[i].display();

    int topIdx = 0;
    for (int i = 1; i < n; i++)
        if (students[i].getMarks() > students[topIdx].getMarks()) topIdx = i;

    cout << "\nTopper: ";
    students[topIdx].display();
    return 0;
}