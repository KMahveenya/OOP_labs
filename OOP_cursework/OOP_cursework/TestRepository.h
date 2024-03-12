#pragma once
#include "Test.h"

class TestRepository
{
private:
	static TestRepository* testRep;

	TestRepository() {}
	TestRepository(const TestRepository&) = delete;
	TestRepository& operator=(TestRepository&);

public:
	Test* test = new Test();

	static TestRepository* getInstance() {
		if (!testRep)
			testRep = new TestRepository();
		return testRep;
	}
};

