#pragma once
#include "Test.h"

class TestRepository
{
private:
	static TestRepository* testRep;
	Test* test;

	TestRepository() {}
	TestRepository(const TestRepository&) = delete;
	TestRepository& operator=(TestRepository&);

public:
	static TestRepository* getInstance();

	Test* getTest();
	void setTest(Test*);
};