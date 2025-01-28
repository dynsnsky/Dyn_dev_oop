#include <bits/stdc++.h>
using namespace std;

struct Time{
	int hours,minutes,seconds;
};

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
	cout << "Nhap thoi gian hien tai (gio phut giay): \n";
    cin >> current.hours >> current.minutes >> current.seconds;
    int x,y,z;
    cout << "Nhap so gio, phut, giay can cong them: \n"; 
    cin >> x>> y >> z;
    after = addTime (x,y,z,current);
    cout << "Thoi gian sau khi cong them la: \n";
    cout << after.hours << " gio, " << after.minutes << " phut, " << after.seconds << " giay.\n";
	return 0;
}
