#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
	private:
		int TuSo;
		int MauSo;
	public:
		PhanSo() { TuSo = 1; MauSo = 1; }
		PhanSo(int tu) {
			this->TuSo = tu;
			this->MauSo = 1;
		}
		PhanSo(int tu, int mau) {
			this->TuSo = tu;
			this->MauSo = mau;
		}
		~PhanSo() {};
		void Nhap();
		void Xuat();
		void rutgonPS();
		PhanSo Tong(PhanSo ps);
		PhanSo Hieu(PhanSo ps);
		PhanSo Tich(PhanSo ps);
		PhanSo Thuong(PhanSo ps);
		float DinhGiaTri();
};

