#pragma once
#include <iostream>
using namespace std;

class Point
{
	private:
		int x;
		int y;

	public:
		void InputPoint();
		void Set(int xx, int yy);
		void Move(Point a);
		void Display();
		void Distance(Point d);
};


