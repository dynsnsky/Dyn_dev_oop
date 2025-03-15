#pragma once
#include <iostream>
using namespace std;
class Date {
	private:
		int day;
		int month;
		int year;
	public:
		Date() { day = 1; month = 1; year = 2000; }
		~Date() {};
		void InputDate();
		void OutputDate();
		bool isLeapYear(int);
		int daysInMonth(int, int);
		Date getNextDate();
		Date getnextXDay(const int);

};


