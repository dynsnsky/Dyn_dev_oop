#pragma once
#include "iostream"
#include "cmath"
using namespace std;

class DATHUC {
private:
	int a, b, c;
public:
	DATHUC() : a(0), b(0), c(0) {}
	DATHUC(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
	~DATHUC() {}

	void NhapDT();
	void KTdau(int, int, string);
	DATHUC Tong2DT(DATHUC);
	DATHUC Hieu2DT(DATHUC);
	int getA() const { return a; }
	int getB() const { return b; }
	int getC() const { return c; }
	void XuatDT();
	int Tinh(int);
};

class DATHUCBAC4 : public DATHUC {
public:
	int m, n, p, q, r;
	DATHUCBAC4() : m(0), n(0), p(0), q(0), r(0) {};
	~DATHUCBAC4() {};
	void XuatDTBAC4();
};

void DATHUC::NhapDT() {
	cin >> a >> b >> c;
}

void DATHUC::KTdau(int x, int before, string bien) {
	if (x != 0 && before != 0) {
		if (x < 0 && x != -1) cout << x;
		else if (x > 0 && x != 1) cout << "+" << x;
		else {
			switch (x) {
			case 1:
				cout << "+";
				if (bien.empty()) cout << 1;
				break;
			case -1:
				cout << "-";
				if (bien.empty()) cout << 1;
				break;
			}
		}
		if (!bien.empty()) cout << bien;
	}
	else if (x != 0 && before == 0) {
		if (x < 0 && x != -1 && x != 1) cout << x;
		else {
			switch (x) {
			case 1:
				if (bien.empty()) cout << 1;
				break;
			case -1:
				cout << "-";
				if (bien.empty()) cout << 1;
				break;
			}
		}
		if (!bien.empty()) cout << bien;
	}
}

void DATHUC::XuatDT() {
	if (a != 0) {
		switch (a) {
		case 1: cout << "x^2"; break;
		case -1: cout << "-x^2"; break;
		default: cout << a << "x^2"; break;
		}
	}
	this->KTdau(b, a, "x");
	this->KTdau(c, (a != 0 || b != 0) ? b : 0, "");
	cout << endl;
}

DATHUC DATHUC::Tong2DT(DATHUC x) {
	return DATHUC(a + x.a, b + x.b, c + x.c);
}

DATHUC DATHUC::Hieu2DT(DATHUC x) {
	return DATHUC(a - x.a, b - x.b, c - x.c);
}

int DATHUC::Tinh(int x) {
	return (a * x * x + b * x + c);
}

void DATHUCBAC4::XuatDTBAC4() {
	if (m != 0) {
		switch (m) {
		case 1: cout << "x^4"; break;
		case -1: cout << "-x^4"; break;
		default: cout << m << "x^4"; break;
		}
	}

	this->KTdau(n, m, "x^3");
	this->KTdau(p, n, "x^2");
	this->KTdau(q, p, "x");
	this->KTdau(r, q, "");
	cout << endl;
}

int main() {
	DATHUC x1, x2;
	cout << "Nhap vao da thuc 1 dang (a b c): ";
	x1.NhapDT();
	cout << "f1(x) = ";
	x1.XuatDT();
	cout << "\nNhap vao da thuc 2 dang (a b c): ";
	x2.NhapDT();
	cout << "f2(x) = ";
	x2.XuatDT();

	cout << "\nTong cac da thuc: ";
	DATHUC Tong = x1.Tong2DT(x2);
	Tong.XuatDT();

	cout << "\nHieu cac da thuc: ";
	DATHUC Hieu = x1.Hieu2DT(x2);
	Hieu.XuatDT();

	cout << "\nTich cac da thuc: ";
	DATHUCBAC4 Tich;
	Tich.m = x1.getA() * x2.getA();
	Tich.n = x1.getA() * x2.getB() + x1.getB() * x2.getA();
	Tich.p = x1.getB() * x2.getB() + x1.getA() * x2.getC() + x2.getA() * x1.getC();
	Tich.q = x1.getB() * x2.getC() + x2.getB() * x1.getC();
	Tich.r = x1.getC() * x2.getC();
	Tich.XuatDTBAC4();

	int x;
	cout << "\nGia tri cac da thuc khi x = ";
	cin >> x;
	cout << "f1(" << x << ") = " << x1.Tinh(x) << endl;
	cout << "f2(" << x << ") = " << x2.Tinh(x) << endl;

	return 0;
}
