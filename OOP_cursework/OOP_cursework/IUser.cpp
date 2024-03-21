#include "IUser.h"
#include "TestRepository.h"
#include "StatisticRepository.h"
#include "ConsoleManager.h"

void IUser::getTest(std::string testId)
{
	TestRepository::getInstance()->setTest(new Test());       //realisation


}

std::vector<std::string> IUser::getTestList()
{
	std::vector<std::string> testNames { "name1", "name2", "name3" };
	return testNames;	//realisation
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