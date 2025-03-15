#include "NHANVIEN.h"
using namespace std;

NHANVIEN::NHANVIEN(){
	name = "";
	nams = 2000;
	ngays = 1;
	thangs = 1;
}
NHANVIEN::~NHANVIEN(){}

void NHANVIEN:: Nhap()
{
	cout << "Ten NV: ";
	cin.ignore();
	getline(cin, name);
	cout << "Ngay sinh: ";
	cin >> ngays >> thangs >> nams;
}
int NHANVIEN:: Luong(int,int) {
	return 0;
}
int NHANVIEN:: Luong(int){
	return 0;
}
