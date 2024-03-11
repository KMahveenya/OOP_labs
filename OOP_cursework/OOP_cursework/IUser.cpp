#include "IUser.h"

Test IUser::getTest(std::string testName)
{
	return Test();	//realisation
}

std::string* IUser::getTestList()
{
	std::string* testNames = new std::string[3]{ "name1", "name2", "name3" };
	return testNames;	//realisation
}