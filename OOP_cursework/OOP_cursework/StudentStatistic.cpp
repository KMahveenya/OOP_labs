#include "StudentStatistic.h"

void StudentStatistic::setCommonTime(int averageTime)
{
	this->commonTime = averageTime;
}

void StudentStatistic::setMaxResault(int maxResault)
{
	this->maxResault = maxResault;
}

void StudentStatistic::setSolvingTestsCount(int solvingTestsCount)
{
	this->solvingTestsCount = solvingTestsCount;
}

int StudentStatistic::getCommonTime()
{
	return this->commonTime;
}

int StudentStatistic::getMaxResault()
{
	return this->maxResault;
}

int StudentStatistic::getSolvingTestsCount()
{
	return this->solvingTestsCount;
}