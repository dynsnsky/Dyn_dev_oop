#include "Date.h"

int main() {
	Date current, nextdate;
	cout << "Nhap ngay (dd mm yyyy): ";
	current.InputDate();
	nextdate = current.getNextDate(); 
	cout << "Ngay tiep theo la: ";
	nextdate.OutputDate();
	cout << "Ngay chinh xac cua X ngay tiep theo: ";
	int x; 
	cin >> x;
	Date nextXDay = current.getnextXDay(x);
	cout << "Vay " << x << " ngay tiep theo se la: ";
	nextXDay.OutputDate();
	return 0;
}