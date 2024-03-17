#include "StudentStatistic.h"

void StudentStatistic::setAverageTime(int averageTime)
{
	this->averageTime = averageTime;
}

void StudentStatistic::setMaxResault(int maxResault)
{
	this->maxResault = maxResault;
}

void StudentStatistic::setSolvingTestsCount(int solvingTestsCount)
{
	this->solvingTestsCount = solvingTestsCount;
}

int StudentStatistic::getAverageTime()
{
	return this->averageTime;
}

int StudentStatistic::getMaxResault()
{
	return this->maxResault;
}

int StudentStatistic::getSolvingTestsCount()
{
	return this->solvingTestsCount;
}