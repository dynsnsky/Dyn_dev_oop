#include "PhanSo.h"
#include <iostream>
using namespace std;

void PhanSo::Nhap()
{
	cout << "Nhap tu so, mau so: ";
	cin >> TuSo >> MauSo;
}

void PhanSo::Xuat()
{
	cout << TuSo << "/" << MauSo;
	cout << endl;
}

int findGCD(int a, int b)
{
	while (b != 0) {
		int du = a % b;
		a = b;
		b = du;
	}
	return abs(a);
}

void PhanSo::rutgonPS() {
	int gcd = findGCD(TuSo, MauSo);

	TuSo /= gcd;
	MauSo /= gcd;

	if (MauSo < 0) {
		TuSo = -TuSo;
		MauSo = -MauSo;
	}
}

PhanSo PhanSo::Tong(PhanSo ps)
{
	PhanSo Tong;
	Tong.TuSo = TuSo*ps.MauSo + MauSo*ps.TuSo;
	Tong.MauSo = MauSo*ps.MauSo;
	return Tong;
}

PhanSo PhanSo::Hieu(PhanSo ps)
{
	PhanSo Hieu;
	Hieu.TuSo = TuSo * ps.MauSo - MauSo * ps.TuSo;
	Hieu.MauSo = MauSo * ps.MauSo;
	return Hieu;
}

PhanSo PhanSo::Tich(PhanSo ps)
{
	PhanSo Tich;
	Tich.TuSo = TuSo * ps.TuSo;
	Tich.MauSo = MauSo * ps.MauSo;
	return Tich;
}

PhanSo PhanSo::Thuong(PhanSo ps)
{
	PhanSo Thuong;
	Thuong.TuSo = TuSo * ps.MauSo;
	Thuong.MauSo = MauSo * ps.TuSo;
	return Thuong;
}

float PhanSo::DinhGiaTri()
{
	float GiaTri;
	GiaTri = ((float(TuSo) / MauSo));
	return GiaTri;
}