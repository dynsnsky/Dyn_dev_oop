#include "Bo.h"

Bo::Bo(){}
Bo::~Bo(){}
int Bo::SinhCon() {
	return rand() % 7;
}
int Bo::ChoSua() {
	return rand() % 20;
}
void Bo::Keu() {
	cout << "BO ";
}