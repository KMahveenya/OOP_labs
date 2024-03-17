#pragma once
#include "TestStatistic.h"
#include "StudentStatistic.h"

class StatisticRepository
{
private:
	static StatisticRepository* statisticRep;
	TestStatistic* testStatistic;
	StudentStatistic* studentStatistic;

	StatisticRepository() {}
	StatisticRepository(const StatisticRepository&) = delete;
	StatisticRepository& operator=(StatisticRepository&);

public:
	static StatisticRepository* getInstance();

	TestStatistic* getTestStatistic();
	StudentStatistic* getStudentStatistic();
	void setTestStatistic(TestStatistic*);
	void setStudentStatistic(StudentStatistic*);
};
