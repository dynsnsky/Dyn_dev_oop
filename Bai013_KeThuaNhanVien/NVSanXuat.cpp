#include "NVSanXuat.h"
NVSanXuat::NVSanXuat(){}
NVSanXuat::~NVSanXuat() {}
int NVSanXuat::Luong(int canban, int sanpham) {
	return ((canban + sanpham) * 5000);
}