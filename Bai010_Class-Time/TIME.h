#pragma once
#include "iostream"
#include "cmath"
using namespace std;

class TIME
{
	private: 
		int hours;
		int minutes;
		int seconds;
	public:
		TIME() {
			hours = 0; minutes = 0; seconds = 0;
		}
		~TIME() {};
		void Nhap();
		bool checkTime();
		void Chuanhoa();
		TIME addTime(int, int, int);
		void Xuat();
};

