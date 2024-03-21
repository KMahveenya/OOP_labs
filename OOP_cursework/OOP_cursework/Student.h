#pragma once
#include "IUser.h"

class Student : public IUser
{
private:
	std::string name;
	int currPrice;

public:
	void startTest();
	//void getTestStatistic();
	void getStudentStatistic();

	/*void setName(std::string);

	std::string getName();*/

};

