#include "TestStatistic.h"

void TestStatistic::setQuestionCount(int questionCount)
{
	this->questionsCount = questionCount;
}

void TestStatistic::setMinTime(int minTime)
{
	this->minTime = minTime;
}

void TestStatistic::setAverageResault(int evarageResault)
{
	this->averageResault = evarageResault;
}

void TestStatistic::setSolvingCount(int solvingCount)
{
	this->solvingCount = solvingCount;
}

int TestStatistic::getQuestionCount()
{
	return this->questionsCount;
}

int TestStatistic::getMinTime()
{
	return this->minTime;
}

int TestStatistic::getAverageResault()
{
	return this->averageResault;
}

int TestStatistic::getSolvingCount()
{
	return this->solvingCount;
}