#include "Point.h"
using namespace std;

int main() {
	Point a,b;
	cout << "Nhap hoanh do (x), tung do (y) dang (x;y): ";
	a.InputPoint();
	cout << "Nhap tung do di chuyen (dx), hoanh do di chuyen (dy) dang (x+dx;y+dy): ";
	b.InputPoint();
	cout << "Sau khi di chuyen:\n";
	b.Move(a);
	b.Display();
	a.Distance(b);
}