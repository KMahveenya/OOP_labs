#include "IUser.h"
#include "TestRepository.h"
#include "StatisticRepository.h"
#include "ConsoleManager.h"

#include <iostream>

void IUser::getTest(std::string testId)
{
	//realisation
	
	/*this->saveTest();
	for (int i = 0; i < tests.size(); i++)
	{
		if (tests[i]->getName() == testId)
		{
			TestRepository::getInstance()->setTest(new Test());
			break;
		}
	}*/
}

void IUser::saveTest()
{
	//realisation
	
	//std::cout << tests.size();
	/*for (int i = 0; i < tests.size(); i++)
	{
		if (tests[i]->getName() == TestRepository::getInstance()->getTest()->getName())
		{
			tests[i] = TestRepository::getInstance()->getTest();
			return;
		}
	}*/
	//tests.push_back(TestRepository::getInstance()->getTest());
}

std::vector<std::string> IUser::getTestList()
{
	//realisation

	std::vector<std::string> testNames{ "name1", "name2", "name3" };


	/*for (int i = 0; i < tests.size(); i++)
	{
		testNames.push_back(tests[i]->getName());
	}*/
	return testNames;
}

void IUser::logout()
{
	//realisation
}

void IUser::getTestStatistic()
{
	std::string name = TestRepository::getInstance()->getTest()->getName();
	int averRes = StatisticRepository::getInstance()->getTestStatistic()->getAverageResault();
	int minTime = StatisticRepository::getInstance()->getTestStatistic()->getMinTime();
	int questionCount = StatisticRepository::getInstance()->getTestStatistic()->getQuestionCount();
	int solvCount = StatisticRepository::getInstance()->getTestStatistic()->getSolvingCount();

	ConsoleManager::getInstance()->writeTestStatistic(name, averRes, minTime, questionCount, solvCount);
}