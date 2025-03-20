#include "TIME.h"
#include "iostream"
using namespace std;

void TIME::Nhap() {
    cout << "Nhap thoi gian hien tai (gio phut giay): ";
    cin >> hours >> minutes >> seconds;

    while (!checkTime()) {
        cout << "Thoi gian khong hop le, vui long nhap lai!\n";
        cout << "Nhap thoi gian hien tai (gio phut giay): ";
        cin >> hours >> minutes >> seconds;
    }
}

bool TIME::checkTime() {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
        return false;
    return true;
}

void TIME::Chuanhoa() {
    minutes += seconds / 60;
    seconds %= 60;

    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }

    hours += minutes / 60;
    minutes %= 60;

    if (minutes < 0) {
        minutes += 60;
        hours--;
    }

    hours %= 24;
    if (hours < 0) hours += 24;
}

TIME TIME::addTime(int x, int y, int z) {
    TIME after = *this;
    after.seconds += z;
    after.minutes += y;
    after.hours += x;
    after.Chuanhoa();
    return after;
}

void TIME::Xuat() {
    cout << hours << " gio, " << minutes << " phut, " << seconds << " giay.\n";
}
