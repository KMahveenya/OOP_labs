#include "Test.h"
#include <string>

Test::Test()
{

}

Test::Test(std::string testName)
{
	this->setName(testName);
}

Test::~Test()
{
	for (std::vector<IQuestion*>::const_iterator iter = questions.begin(); iter != questions.end(); iter++)
	{
		delete* iter;
	}
}

std::string Test::getName()
{
	return this->testName;
}

int Test::getQuestionCount()
{
	return this->questionCount;
}

void Test::incQuestionCount()
{
	this->questionCount++;
}

void Test::decQuestionCount()
{
	this->questionCount--;
}

void Test::setName(std::string name)
{
	this->testName = name;
}