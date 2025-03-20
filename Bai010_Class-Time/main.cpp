#include "TIME.h"
#include "iostream"
using namespace std;
int main() {
    TIME current, after;
    current.Nhap();
    current.Xuat();
    int hours, minutes, seconds;
    cout << "Nhap so gio, phut, giay can cong them (tuong ung gio phut giay): ";
    cin >> hours >> minutes >> seconds;
    after = current.addTime(hours, minutes, seconds);
    cout << "\nThoi gian sau khi cong them la: \n";
    after.Xuat();
    return 0;
}