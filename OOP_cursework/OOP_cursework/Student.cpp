#include "Student.h"
#include "TestRepository.h"
#include "ConsoleManager.h"

#include <iostream>

void Student::startTest()
{
	for (int i = 0; i < TestRepository::getInstance()->getTest()->getQuestionCount(); i++)
	{
		ConsoleManager::getInstance()->writeQuestion(TestRepository::getInstance()->getTest()->questions[i]->getQuestionText());

		if (TestRepository::getInstance()->getTest()->questions[i]->getQuestionType() == QuestionType::MonoClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->questions[i]->getVariants());
			ConsoleManager::getInstance()->correct(TestRepository::getInstance()->getTest()->questions[i]->check(ConsoleManager::getInstance()->getMonoCloseAnswer()));
		}
		else if (TestRepository::getInstance()->getTest()->questions[i]->getQuestionType() == QuestionType::MultiClose)
		{
			ConsoleManager::getInstance()->writeVariants(TestRepository::getInstance()->getTest()->questions[i]->getVariants());
			ConsoleManager::getInstance()->correct(TestRepository::getInstance()->getTest()->questions[i]->check((std::vector<int>&)(ConsoleManager::getInstance()->getMultiCloseAnswer())));
		}
		else if (TestRepository::getInstance()->getTest()->questions[i]->getQuestionType() == QuestionType::Open)
		{
			ConsoleManager::getInstance()->correct(TestRepository::getInstance()->getTest()->questions[i]->check(ConsoleManager::getInstance()->getOpenAnswer()));
		}
	}
}