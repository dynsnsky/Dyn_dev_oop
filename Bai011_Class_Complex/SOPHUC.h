#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SOPHUC {
private:
    double thuc;
    double ao;

public:
    // Constructors
    SOPHUC();
    SOPHUC(double thuc, double ao);

    // Nhập và xuất
    void Nhap();
    void Xuat() const;

    // Các phép toán
    SOPHUC Cong(const SOPHUC& sp) const;
    SOPHUC Tru(const SOPHUC& sp) const;
    SOPHUC Nhan(const SOPHUC& sp) const;
    SOPHUC Chia(const SOPHUC& sp) const;
};

#endif
