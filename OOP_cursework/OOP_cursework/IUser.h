#pragma once
#include <string>
#include "Test.h"

class IUser
{
protected:
	Test getTest(std::string);
	std::string* getTestList();
};

