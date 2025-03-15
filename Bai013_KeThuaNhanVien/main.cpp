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
		NVSanXuat nvsx;		
		cout << "Nhan vien thu " << i+1<< ":\n"; 
		nvsx.Nhap();
		int canban, sanpham;
		cout << "Nhap LUONG CAN BAN, SO SAN PHAM: " << ":\n";
		cin >> canban >> sanpham;
		cout << "LUONG NV: " << nvsx.Luong(canban, sanpham);
	}

	cout << "2-NHAN VIEN VAN PHONG\n";
	cout << "So luong nhan vien: ";
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		NVVanPhong nvvp;
		cout << "Nhan vien thu " << i+1 << ":\n";
		nvvp.Nhap();
		int ngaylam;
		cout << "Nhap SO NGAY LAM: " << ":\n";
		cin >> ngaylam;
		cout << "LUONG NV: " << nvvp.Luong(ngaylam);
	}
	return 0;
}