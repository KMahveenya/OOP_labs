#include "Student.h"
#include "TestRepository.h"
#include "StatisticRepository.h"
#include "ConsoleManager.h"

#include <iostream>

void Student::startTest()
{
	this->currPrice = 0;
	int sumPrice = 0;
	for (int i = 0; i < TestRepository::getInstance()->getTest()->getQuestionCount(); i++)
	{
		ConsoleManager::getInstance()->writeQuestion(TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionText());
		sumPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();

		if (TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionType() == QuestionType::MonoClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants());
			bool answer = TestRepository::getInstance()->getTest()->getQuestion(i)->check(ConsoleManager::getInstance()->getMonoCloseAnswer());
			ConsoleManager::getInstance()->correct(answer);
			if (answer)
			{
				currPrice += TestRepository::getInstance()->getTest()->getQuestion(i)->getPrice();
			}
		}
		else if (TestRepository::getInstance()->getTest()->getQuestion(i)->getQuestionType() == QuestionType::MultiClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->getQuestion(i)->getVariants());
			bool answer = TestRepository::getInstance()->getTest()->getQuestion(i)->check((std::vector<int>&)(ConsoleManager::getInstance()->getMultiCloseAnswer()));
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
	ConsoleManager::getInstance()->writePrice(this->currPrice, sumPrice);
}

void Student::getStudentStatistic()
{
	int solvCount = StatisticRepository::getInstance()->getStudentStatistic()->getSolvingTestsCount();
	int maxRes = StatisticRepository::getInstance()->getStudentStatistic()->getMaxResault();
	int averTime = StatisticRepository::getInstance()->getStudentStatistic()->getAverageTime();

	ConsoleManager::getInstance()->writeStudentStatistic(this->name, solvCount, maxRes, averTime);
}