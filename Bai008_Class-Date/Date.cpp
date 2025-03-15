#include "Date.h"
#include <iostream>
using namespace std;

void Date::InputDate() {
    int day; int month; int year;
    bool valid = false;

    do {
        cin >> day >> month >> year;
        if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
            cout << "Ngay khong hop le" << endl;
        }
        else {
            valid = true;
        }
    } while (!valid);

    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::OutputDate(){
    cout << day << "/" << month << "/" << year << "\n";
}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year) {
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

Date Date::getNextDate() {
    Date nextDate = *this;
    nextDate.day++;

    if (nextDate.day > daysInMonth(nextDate.month, nextDate.year)) {
        nextDate.day = 1;
        nextDate.month++;

        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }

    return nextDate;
}

Date Date::getnextXDay(const int x) {
    Date nextDate = *this;
    nextDate.day += x;

    while (nextDate.day > daysInMonth(nextDate.month, nextDate.year)) {
        nextDate.day -= daysInMonth(nextDate.month, nextDate.year);
        nextDate.month++;

        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }

    return nextDate;
}