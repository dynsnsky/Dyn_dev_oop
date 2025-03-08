#include "STUDENT.h"
#include <iostream>
#include <string>

int STUDENT::studentCount = 0;

STUDENT::STUDENT() {
    studentCount++;
}
void STUDENT::Input() {
    cout << "Ho ten sinh vien: ";
    cin.ignore();
    getline(cin, name);
    cout << "ID sinh vien: ";
    cin >> id;
}
void STUDENT::Display() {
    cout << "Ho ten: " << name << "\tID: " << id << endl;
}

int STUDENT::getStudentCount() {
    return studentCount;
}