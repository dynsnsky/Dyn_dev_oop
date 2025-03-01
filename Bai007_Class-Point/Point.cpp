#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

void Point::InputPoint()
{
	cin >> x >> y;
}
void Point::Set(int xx, int yy)
{
	x = xx;
	y = yy;
}

void Point::Move(Point a)
{
	x += a.x;
	y += a.y;
}

void Point::Display()
{
	cout << "Toa do: (" << x << ";" << y << ")" << endl;
}

void Point::Distance(Point d)
{
	cout << "Khoang cach 2 diem la " << sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
