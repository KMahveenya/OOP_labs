#include "TestRepository.h"

void TestRepository::setTest(Test* test)
{
	this->test = test;
}

Test* TestRepository::getTest()
{
	return this->test;
}

TestRepository* TestRepository::getInstance()
{
	if (!testRep)
	{
		testRep = new TestRepository();
	}
	return testRep;
}