#include "Admin.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"
#include "OpenQuestion.h"
#include "TestRepository.h"
#include <iostream>

Admin::Admin()
{

}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, int answer, std::vector<std::string>& variants)
{
	TestRepository::getInstance()->getTest()->questions.push_back(new MonoCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->getTest()->incQuestionCount();
}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, std::vector<int>& answer, std::vector<std::string>& variants)
{
	TestRepository::getInstance()->getTest()->questions.push_back(new MultiCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->getTest()->incQuestionCount();
}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, std::string answer)
{
	TestRepository::getInstance()->getTest()->questions.push_back(new OpenQuestion(questionText, price, type, answer));
	TestRepository::getInstance()->getTest()->incQuestionCount();
}

void Admin::removeQuestion(std::string testId, int questionNumber)
{
	auto iter = TestRepository::getInstance()->getTest()->questions.cbegin();
	TestRepository::getInstance()->getTest()->questions.erase(iter + questionNumber);
	TestRepository::getInstance()->getTest()->decQuestionCount();
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::string str)
{
	if (type == ChangeType::QuestionText)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setQuestionText(str);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setAnswer(str);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, int num)
{
	if (type == ChangeType::Price)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setPrice(num);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setAnswer(num);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::vector<int>& nums)
{
	if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setAnswer(nums);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, QuestionType qtype)
{
	if (type == ChangeType::QuestionType)
	{
		std::string tempText = TestRepository::getInstance()->getTest()->questions[questionNumber]->getQuestionText();
		int tempPrice = TestRepository::getInstance()->getTest()->questions[questionNumber]->getPrice();
		std::vector<std::string> variants = TestRepository::getInstance()->getTest()->questions[questionNumber]->getVariants();
		
		this->removeQuestion(testId, questionNumber);

		if (qtype == QuestionType::MonoClose)
		{
			auto iter = TestRepository::getInstance()->getTest()->questions.cbegin();
			TestRepository::getInstance()->getTest()->questions.insert(iter + questionNumber, new MonoCloseQuestion(tempText, tempPrice, QuestionType::MonoClose, 0, variants));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
		else if (qtype == QuestionType::MultiClose)
		{
			auto iter = TestRepository::getInstance()->getTest()->questions.cbegin();
			std::vector<int> v;
			TestRepository::getInstance()->getTest()->questions.insert(iter + questionNumber, new MultiCloseQuestion(tempText, tempPrice, QuestionType::MultiClose, v, variants));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
		else if (qtype == QuestionType::Open)
		{
			auto iter = TestRepository::getInstance()->getTest()->questions.cbegin();
			TestRepository::getInstance()->getTest()->questions.insert(iter + questionNumber, new OpenQuestion(tempText, tempPrice, QuestionType::MultiClose, ""));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::vector<std::string>& vars)
{
	if (type == ChangeType::Variants)
	{
		TestRepository::getInstance()->getTest()->questions[questionNumber]->setVariants(vars);
	}
}

void Admin::createTest(std::string testName)
{
	TestRepository::getInstance()->setTest(new Test(testName));
}

void Admin::removeTest()
{
	delete TestRepository::getInstance()->getTest();
}