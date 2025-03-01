#include "PhanSo.h"
void main() {
	PhanSo a, b;
	a.Nhap();
	b.Nhap();
	PhanSo tong = a.Tong(b);
	PhanSo hieu = a.Hieu(b);
	PhanSo tich = a.Tich(b);
	PhanSo thuong = a.Thuong(b);
	cout << "Phan so thu nhat: ";
	a.Xuat();
	cout << "Phan so thu hai: ";
	b.Xuat();
	cout << "Tong la ";
	tong.rutgonPS();
	tong.Xuat();
	cout << endl;
	cout << "Hieu la ";
	hieu.rutgonPS();
	hieu.Xuat();
	cout << endl;
	cout << "Tich la ";
	tich.rutgonPS();
	tich.Xuat();
	cout << endl;
	cout << "Thuong la ";
	thuong.rutgonPS();
	thuong.Xuat();
	cout << endl;
	cout << "Phan so thu nhat dinh gia tri la " << a.DinhGiaTri() << endl;
	cout << "Phan so thu hai dinh gia tri la " << b.DinhGiaTri() << endl;
}