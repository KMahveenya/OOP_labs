#include "Student.h"
#include "TestRepository.h"
#include "StatisticRepository.h"
#include "ConsoleManager.h"

#include <iostream>

Student::Student(std::string name)
{
	this->name = name;
}

void Student::startTest()
{
	this->currPrice = 0;
	int sumPrice = 0;
	clock_t start = clock();
	for (int i = 0; i < TestRepository::getInstance()->getTest()->getQuestionCount(); i++)
	{
		ConsoleManager::getInstance()->writeQuestion(TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionText());
		sumPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();

		if (TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionType() == QuestionType::MonoClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants());
			bool answer = TestRepository::getInstance()->getTest()->getQuestion(i)->check(ConsoleManager::getInstance()->getMonoCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants().size()));
			ConsoleManager::getInstance()->correct(answer);
			if (answer)
			{
				currPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();
			}
		}
		else if (TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionType() == QuestionType::MultiClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants());
			bool answer = TestRepository::getInstance()->getTest()->getQuestion(i)->check((std::vector<int>&)(ConsoleManager::getInstance()->getMultiCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants().size())));
			ConsoleManager::getInstance()->correct(answer);
			if (answer)
			{
				currPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();
			}
		}
		else if (TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionType() == QuestionType::Open)
		{
			bool answer = TestRepository::getInstance()->getTest()->getQuestion(i)->check(ConsoleManager::getInstance()->getOpenAnswer());
			ConsoleManager::getInstance()->correct(answer);
			if (answer)
			{
				currPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();
			}
		}
	}

	clock_t end = clock();
	int seconds = (int)(end - start) / CLOCKS_PER_SEC;

	ConsoleManager::getInstance()->writePrice(this->currPrice, sumPrice);

	int newResault = (StatisticRepository::getInstance()->getTestStatistic()->getAverageResault() * StatisticRepository::getInstance()->getTestStatistic()->getSolvingCount() + this->currPrice) / (StatisticRepository::getInstance()->getTestStatistic()->getSolvingCount() + 1);
	StatisticRepository::getInstance()->getTestStatistic()->setAverageResault(newResault);
	StatisticRepository::getInstance()->getTestStatistic()->setSolvingCount(StatisticRepository::getInstance()->getTestStatistic()->getSolvingCount() + 1);
	if (StatisticRepository::getInstance()->getTestStatistic()->getMinTime() > seconds)
	{
		StatisticRepository::getInstance()->getTestStatistic()->setMinTime(seconds);
	}

	StatisticRepository::getInstance()->getStudentStatistic()->setSolvingTestsCount(StatisticRepository::getInstance()->getStudentStatistic()->getSolvingTestsCount() + 1);
	StatisticRepository::getInstance()->getStudentStatistic()->setCommonTime(StatisticRepository::getInstance()->getStudentStatistic()->getCommonTime() + seconds);
	if (StatisticRepository::getInstance()->getStudentStatistic()->getMaxResault() < this->currPrice)
	{
		StatisticRepository::getInstance()->getStudentStatistic()->setMaxResault(this->currPrice);
	}
}

void Student::getStudentStatistic()
{
	int solvCount = StatisticRepository::getInstance()->getStudentStatistic()->getSolvingTestsCount();
	int maxRes = StatisticRepository::getInstance()->getStudentStatistic()->getMaxResault();
	int averTime = StatisticRepository::getInstance()->getStudentStatistic()->getCommonTime();

	ConsoleManager::getInstance()->writeStudentStatistic(this->name, solvCount, maxRes, averTime);
}