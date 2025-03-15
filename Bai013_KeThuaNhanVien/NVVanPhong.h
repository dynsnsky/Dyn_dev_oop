#pragma once
#include "NHANVIEN.h"

class NVVanPhong : public NHANVIEN {
private: 
	int ngaylam;
public:
	NVVanPhong();
	~NVVanPhong();
	int Luong(int);
};
