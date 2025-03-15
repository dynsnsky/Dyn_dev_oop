#pragma once
#include "NHANVIEN.h"

class NVSanXuat : public NHANVIEN {
private:
	int canban;
	int sanpham;
public:
	NVSanXuat();
	~NVSanXuat();
	int Luong(int,int);
};

