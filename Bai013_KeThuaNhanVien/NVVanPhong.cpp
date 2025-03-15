#include "NVVanPhong.h"
NVVanPhong::NVVanPhong() {
	canban = 0;
	sanpham = 0;

}
NVVanPhong::~NVVanPhong() {}
int NVVanPhong::Luong(int ngaylam) {
	return (ngaylam * 100 000);
}