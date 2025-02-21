#include <bits/stdc++.h>
using namespace std;

struct Time{
	int hours,minutes,seconds;
};

bool checktime(Time current){
	if (current.hours > 23 || current.minutes > 60 || current.seconds > 60)
	 	return false;
	return true;
}
void Chuanhoa(Time &x){
	x.minutes += x.seconds / 60; //quy doi giay -> phut
    x.seconds %= 60; 

    if (x.seconds < 0) {
        x.seconds += 60;
        x.minutes--;
    }

    x.hours += x.minutes / 60; //quy doi phut -> gio
    x.minutes %= 60;

    if (x.minutes < 0) {
        x.minutes += 60;
        x.hours--;
    }

    x.hours %= 24;			 // chuan hoa gio
    if (x.hours < 0) {
        x.hours += 24;
    }
}

Time addTime(int x, int y, int z, Time current){
	Time after=current;
	after.seconds += z;
    after.minutes += y;
    after.hours += x;
    Chuanhoa(after);
	return after;	
}

int main(){
	Time current,after;
	cout << "Nhap thoi gian hien tai (gio phut giay): ";
    cin >> current.hours >> current.minutes >> current.seconds;
    while (!checktime(current)){
    	cout << "Thoi gian khong hop le, vui long nhap lai!\n";
    	cout << "\nNhap thoi gian hien tai (gio phut giay): ";
    	cin >> current.hours >> current.minutes >> current.seconds;
	}
    int hours,minutes,seconds;
    cout << "Nhap so gio, phut, giay can cong them: \n"; 
    cin >> hours >> minutes >> seconds;
    after = addTime (hours,  minutes, seconds, current);
    cout << "Thoi gian sau khi cong them la: \n";
    cout << after.hours << " gio, " << after.minutes << " phut, " << after.seconds << " giay.\n";
	return 0;
}
