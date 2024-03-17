#include "IUser.h"
#include "TestRepository.h"

void IUser::getTest(std::string testId)
{
	TestRepository::getInstance()->setTest(new Test());       //realisation
}

std::string* IUser::getTestList()
{
	std::string* testNames = new std::string[3]{ "name1", "name2", "name3" };
	return testNames;	//realisation
}