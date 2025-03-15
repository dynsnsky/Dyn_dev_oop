#include "Cuu.h"

Cuu::Cuu() {}
Cuu::~Cuu() {}
int Cuu::SinhCon() {
	return rand() % 7;
}
int Cuu::ChoSua() {
	return rand() % 5;
}
void Cuu::Keu() {
	cout << "BAAAA ";
}