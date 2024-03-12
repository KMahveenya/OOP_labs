#include "Test.h"
#include <string>

Test::Test()
{

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