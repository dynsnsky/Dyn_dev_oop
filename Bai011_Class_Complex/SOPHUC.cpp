#include "SOPHUC.h"
#include <iostream>
using namespace std;

// Constructors
SOPHUC::SOPHUC() : thuc(0), ao(0) {}

SOPHUC::SOPHUC(double thuc, double ao) : thuc(thuc), ao(ao) {}

void SOPHUC::Nhap() {
    cout << "\tNhap phan thuc: ";
    cin >> thuc;
    cout << "\tNhap phan ao: ";
    cin >> ao;
}

void SOPHUC::Xuat() const {
    if (thuc != 0)
        cout << thuc;
    if (ao > 0) {
        if (thuc != 0) cout << "+";
        cout << ao << "i";
    }
    else if (ao < 0) {
        cout << ao << "i";
    }
    else if (thuc == 0) {
        cout << 0;
    }
    cout << endl;
}

SOPHUC SOPHUC::Cong(const SOPHUC& sp) const {
    return SOPHUC(thuc + sp.thuc, ao + sp.ao);
}

SOPHUC SOPHUC::Tru(const SOPHUC& sp) const {
    return SOPHUC(thuc - sp.thuc, ao - sp.ao);
}

SOPHUC SOPHUC::Nhan(const SOPHUC& sp) const {
    double thucMoi = thuc * sp.thuc - ao * sp.ao;
    double aoMoi = thuc * sp.ao + ao * sp.thuc;
    return SOPHUC(thucMoi, aoMoi);
}

SOPHUC SOPHUC::Chia(const SOPHUC& sp) const {
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
    if (mau == 0) {
        cerr << "Loi: Khong the chia cho 0!" << endl;
        return SOPHUC();
    }
    double thucMoi = (thuc * sp.thuc + ao * sp.ao) / mau;
    double aoMoi = (ao * sp.thuc - thuc * sp.ao) / mau;
    return SOPHUC(thucMoi, aoMoi);
}
