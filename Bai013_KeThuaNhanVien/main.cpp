#include "NVSanXuat.h"
#include "NVVanPhong.h"
using namespace std;

int main() {
	cout << "1-NHAN VIEN SAN XUAT\n";
	cout << "So luong nhan vien: ";
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		NVSanXuat nvsx;		
		cout << "\nNhan vien san xuat " << i+1<< ":\n"; 
		nvsx.Nhap();
		int canban, sanpham;
		cout << "Nhap LUONG CAN BAN, SO SAN PHAM: ";
		cin >> canban >> sanpham;
		cout << "LUONG NV: " << nvsx.Luong(canban, sanpham);
	}

	cout << "\n\n2-NHAN VIEN VAN PHONG\n";
	cout << "So luong nhan vien: ";
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cout << "\n";
		NVVanPhong nvvp;
		cout << "\nNhan vien van phong " << i+1 << ":\n";
		nvvp.Nhap();
		int ngaylam;
		cout << "Nhap SO NGAY LAM: ";
		cin >> ngaylam;
		cout << "LUONG NV: " << nvvp.Luong(ngaylam);
	}
	return 0;
}