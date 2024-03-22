#pragma once
#include "IUser.h"
#include <time.h>
#include <windows.h>

class Student : public IUser
{
private:
	std::string name;
	int currPrice;

public:
	Student(std::string);

	void startTest();
	void getStudentStatistic();
};

