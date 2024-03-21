#pragma once
#include <string>
#include "Test.h"

class IUser
{
public:
	void getTest(std::string);
	std::vector<std::string> getTestList();
	void getTestStatistic();
	void logout();
};

