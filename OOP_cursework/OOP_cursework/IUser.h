#pragma once
#include <string>
#include "Test.h"

class IUser
{
public:
	//std::vector<Test*> tests; //delete

	void getTest(std::string);
	void saveTest();
	std::vector<std::string> getTestList();
	void getTestStatistic();
	void logout();
};

