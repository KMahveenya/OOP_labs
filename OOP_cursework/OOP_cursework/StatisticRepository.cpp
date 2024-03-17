#include "StatisticRepository.h"

void StatisticRepository::setTestStatistic(TestStatistic* testStatistic)
{
	this->testStatistic = testStatistic;
}

TestStatistic* StatisticRepository::getTestStatistic()
{
	return this->testStatistic;
}

void StatisticRepository::setStudentStatistic(StudentStatistic* studentStatistic)
{
	this->studentStatistic = studentStatistic;
}

StudentStatistic* StatisticRepository::getStudentStatistic()
{
	return this->studentStatistic;
}

StatisticRepository* StatisticRepository::getInstance()
{
	if (!statisticRep)
	{
		statisticRep = new StatisticRepository();
	}
	return statisticRep;
}