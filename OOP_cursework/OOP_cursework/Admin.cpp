#include "Admin.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"
#include "OpenQuestion.h"
#include "TestRepository.h"
#include <iostream>

Admin::Admin()
{

}

void Admin::testing()
{	
	std::vector<int> v{ 3, 10, 5 };
	std::vector<std::string> vars{ "var1", "var2", "var3" };

	this->addQuestion("id123451", "what1?", 100, QuestionType::Open, "bebra1");
	this->addQuestion("id123452", "what2?", 200, QuestionType::MonoClose, 2, vars);
	this->addQuestion("id123453", "what3?", 300, QuestionType::MultiClose, v, vars);

	std::cout << TestRepository::getInstance()->test->getQuestionCount() << '\n';

	std::cout << TestRepository::getInstance()->test->questions[1]->getQuestionText() << '\n';
	this->changeQuestion("123123", 1, ChangeType::QuestionText, "who?");
	std::cout << TestRepository::getInstance()->test->questions[1]->getQuestionText() << '\n';

	std::vector<int> v2{ 3, 10, 12 };
	std::cout << TestRepository::getInstance()->test->questions[2]->check(v2) << '\n';
	this->changeQuestion("123123", 2, ChangeType::Answer, v2);
	std::cout << TestRepository::getInstance()->test->questions[2]->check(v2) << '\n';

	std::cout << TestRepository::getInstance()->test->questions[1]->check(2) << '\n';
	this->changeQuestion("123123", 1, ChangeType::QuestionType, QuestionType::Open);
	this->changeQuestion("123123", 1, ChangeType::Answer, "someText");

	std::cout << TestRepository::getInstance()->test->questions[1]->check("someText") << '\n';

	std::vector<std::string> vars2{ "new1", "new2", "new3" };

	std::cout << TestRepository::getInstance()->test->questions[2]->getVariants()[2] << '\n';
	this->changeQuestion("123123", 2, ChangeType::Variants, vars2);
	std::cout << TestRepository::getInstance()->test->questions[2]->getVariants()[2] << '\n';

}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, int answer, std::vector<std::string>& variants)
{
	TestRepository::getInstance()->test->questions.push_back(new MonoCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->test->incQuestionCount();
}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, std::vector<int>& answer, std::vector<std::string>& variants)
{
	TestRepository::getInstance()->test->questions.push_back(new MultiCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->test->incQuestionCount();
}

void Admin::addQuestion(std::string testId, std::string questionText, int price, QuestionType type, std::string answer)
{
	TestRepository::getInstance()->test->questions.push_back(new OpenQuestion(questionText, price, type, answer));
	TestRepository::getInstance()->test->incQuestionCount();
}

void Admin::removeQuestion(std::string testId, int questionNumber)
{
	auto iter = TestRepository::getInstance()->test->questions.cbegin();
	TestRepository::getInstance()->test->questions.erase(iter + questionNumber);
	TestRepository::getInstance()->test->decQuestionCount();
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::string str)
{
	if (type == ChangeType::QuestionText)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setQuestionText(str);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setAnswer(str);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, int num)
{
	if (type == ChangeType::Price)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setPrice(num);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setAnswer(num);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::vector<int>& nums)
{
	if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setAnswer(nums);
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, QuestionType qtype)
{
	if (type == ChangeType::QuestionType)
	{
		std::string tempText = TestRepository::getInstance()->test->questions[questionNumber]->getQuestionText();
		int tempPrice = TestRepository::getInstance()->test->questions[questionNumber]->getPrice();
		std::vector<std::string> variants = TestRepository::getInstance()->test->questions[questionNumber]->getVariants();
		
		this->removeQuestion(testId, questionNumber);

		if (qtype == QuestionType::MonoClose)
		{
			auto iter = TestRepository::getInstance()->test->questions.cbegin();
			TestRepository::getInstance()->test->questions.insert(iter + questionNumber, new MonoCloseQuestion(tempText, tempPrice, QuestionType::MonoClose, 0, variants));
			TestRepository::getInstance()->test->incQuestionCount();
		}
		else if (qtype == QuestionType::MultiClose)
		{
			auto iter = TestRepository::getInstance()->test->questions.cbegin();
			std::vector<int> v;
			TestRepository::getInstance()->test->questions.insert(iter + questionNumber, new MultiCloseQuestion(tempText, tempPrice, QuestionType::MultiClose, v, variants));
			TestRepository::getInstance()->test->incQuestionCount();
		}
		else if (qtype == QuestionType::Open)
		{
			auto iter = TestRepository::getInstance()->test->questions.cbegin();
			TestRepository::getInstance()->test->questions.insert(iter + questionNumber, new OpenQuestion(tempText, tempPrice, QuestionType::MultiClose, ""));
			TestRepository::getInstance()->test->incQuestionCount();
		}
	}
}

void Admin::changeQuestion(std::string testId, int questionNumber, ChangeType type, std::vector<std::string>& vars)
{
	if (type == ChangeType::Variants)
	{
		TestRepository::getInstance()->test->questions[questionNumber]->setVariants(vars);
	}
}