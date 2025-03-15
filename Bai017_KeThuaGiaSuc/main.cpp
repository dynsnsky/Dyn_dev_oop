#include "De.h"
#include "Bo.h"
#include "Cuu.h"

int main() {
	int TongBo = 0;
	int litSuaBo = 0;
	int TongDe = 0;
	int litSuaDe = 0;
	int TongCuu = 0;
	int litSuaCuu = 0;
	Bo b[15];
	De d[15];
	Cuu c[15];
	int soBo;
	int soDe;
	int soCuu;

	cout << "Nhap so luong Bo: ";
	cin >> soBo;
	for (int i = 0; i < soBo; i++) {
		TongBo += i + b[i].SinhCon();
		litSuaBo += b[i].ChoSua(); \
			b[i].Keu();
		//cout << "\n";
	}
	cout << "\nTong so con Bo: " << TongBo << "\n";
	cout << "Tong so lit sua Bo: " << litSuaBo << "\n";
	
	cout << "Nhap so luong De: ";
	cin >> soDe;
	for (int i = 0; i < soDe; i++) {
		TongDe += i + d[i].SinhCon();
		litSuaDe += d[i].ChoSua(); \
			d[i].Keu();
		//cout << "\n";
	}
	cout << "\nTong so con De: " << TongDe << "\n";
	cout << "Tong so lit sua De: " << litSuaDe << "\n";

	cout << "Nhap so luong Cuu: ";
	cin >> soCuu;
	for (int i = 0; i < soCuu; i++) {
		TongCuu += i + c[i].SinhCon();
		litSuaCuu += c[i].ChoSua(); \
			c[i].Keu();
		//cout << "\n";
	}
	cout << "\nTong so con Cuu: " << TongCuu << "\n";
	cout << "Tong so lit sua Cuu: " << litSuaCuu << "\n";
	system("pause");
	return 0;
}