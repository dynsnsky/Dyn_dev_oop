#include "STUDENT.h"
#include <iostream>
#include <string>
#define maxn 1000
using namespace std;

int main() {
    int n;
    cin >> n;
    STUDENT sv[maxn];
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ")" << endl;
        sv[i].Input();
    }
    cout << "DANH SACH SINH VIEN\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        sv[i].Display();
    }
    cout << "\nTong so sinh vien trong lop: " << STUDENT::getStudentCount() << endl;
    return 0;
}