#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc Date
struct Date {
	int day;
	int month;
	int year;
};

// 2. Kiểm tra năm nhuận
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 3. Hàm trả về số ngày trong một tháng
int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

// 4. Hàm trả về ngày tiếp theo
Date getNextDay(Date current) {
    Date nextDate = current;
    nextDate.day++;

    if (nextDate.day > daysInMonth(current.month, current.year)) {
        nextDate.day = 1;
        nextDate.month++;

        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }

    return nextDate;
}

// 5. Trả về x ngày tiếp theo
Date getnextXDay(Date current, int x) {
    Date nextXDate = current;
    nextXDate.day+=x;

    if (nextXDate.day > daysInMonth(current.month, current.year)) {  //Dang kiem tra
        nextXDate.day = 1;
        nextXDate.month++;

        if (nextXDate.month > 12) {
            nextXDate.month = x;
            nextXDate.year++;
        }
    }

    return nextDate;
}

int main() {
    Date today;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

    if (today.month < 1 || today.month > 12 || today.day < 1 || today.day > daysInMonth(today.month, today.year)) {
        cout << "Ngay khong hop le" << endl;
        return 1;
    }

    Date nextDay = getNextDay(today);

    cout << "Ngay tiep theo la: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;

    cout << "Ngay chinh xac cua X ngay tiep theo, voi X = ";
    int x; cin >> x; 

    Date nextXDay = getNextXDay(today,x);

    cout << " la: " << nextXDay.day << "/" << nextXDay.month << "/" << nextXDay.year << endl;
    return 0;
}
