#pragma once
#include "iostream"
#include "cmath"
#include "string"
using namespace std;
class NHANVIEN{
	private:
		string name;
		//ngaysinh
		int ngays;
		int thangs;
		int nams;
	public:
		NHANVIEN();
		~NHANVIEN();
		void Nhap();
		int Luong(int);
		int Luong(int,int);

};

