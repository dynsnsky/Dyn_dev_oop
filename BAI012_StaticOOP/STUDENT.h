#pragma once
#include <iostream>
using namespace std;

class STUDENT
{
	private:
		string name;
		int id;
		static int studentCount;
	public:
		STUDENT();
		void Input();
		void Display();
		static int getStudentCount();
};

