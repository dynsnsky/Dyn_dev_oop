#include "SOPHUC.h"
#include <iostream>
using namespace std;

int main() {
    SOPHUC sp1, sp2, Tong, Hieu, Tich, Thuong;

    cout << "Nhap vao so phuc thu nhat\n";
    sp1.Nhap();

    cout << "Nhap vao so phuc thu hai\n";
    sp2.Nhap();

    cout << "\nSo phuc thu nhat: ";
    sp1.Xuat();

    cout << "So phuc thu hai: ";
    sp2.Xuat();

    Tong = sp1.Cong(sp2);
    cout << "\nTong hai so phuc: ";
    Tong.Xuat();

    Hieu = sp1.Tru(sp2);
    cout << "Hieu hai so phuc: ";
    Hieu.Xuat();

    Tich = sp1.Nhan(sp2);
    cout << "Tich hai so phuc: ";
    Tich.Xuat();

    Thuong = sp1.Chia(sp2);
    cout << "Thuong hai so phuc: ";
    Thuong.Xuat();

    return 0;
}
