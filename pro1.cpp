#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
        void setName(string name) {
        this->name = name;  
    }

       void setMarks(int marks) {
        if (marks >= 0 && marks <= 100) {
            this->marks = marks;
        } else {
            cout << "Invalid marks! Must be between 0 and 100." << endl;
            this->marks = 0; 
        }
    }

        string getName() {
        return name;
    }

        int getMarks() {
        return marks;
    }

        char getGrade() {
        if (marks >= 90)
            return 'A';
        else if (marks >= 80)
            return 'B';
        else if (marks >= 70)
            return 'C';
        else if (marks >= 60)
            return 'D';
        else
            return 'F';
    }

        void displayInfo() {
        cout << "Name: " << getName() << endl;
        cout << "Marks: " << getMarks() << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main() {
    Student s1;

    string nameInput;
    int marksInput;

    cout << "Enter student name: ";
    getline(cin, nameInput);

    cout << "Enter marks (0 - 100): ";
    cin >> marksInput;

    s1.setName(nameInput);
    s1.setMarks(marksInput);

    cout << "\n--- Student Report ---" << endl;
    s1.displayInfo();

    return 0;
}
