#include "Admin.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"
#include "OpenQuestion.h"
#include "TestRepository.h"

Admin::Admin()
{

}

void Admin::addQuestion(std::string questionText, int price, QuestionType type, int answer, std::vector<std::string> variants)
{
	TestRepository::getInstance()->getTest()->getQuestions().push_back(new MonoCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->getTest()->incQuestionCount();

	StatisticRepository::getInstance()->getTestStatistic()->setQuestionCount(TestRepository::getInstance()->getTest()->getQuestionCount());
}

void Admin::addQuestion(std::string questionText, int price, QuestionType type, std::vector<int>& answer, std::vector<std::string> variants)
{
	TestRepository::getInstance()->getTest()->getQuestions().push_back(new MultiCloseQuestion(questionText, price, type, answer, variants));
	TestRepository::getInstance()->getTest()->incQuestionCount();

	StatisticRepository::getInstance()->getTestStatistic()->setQuestionCount(TestRepository::getInstance()->getTest()->getQuestionCount());
}

void Admin::addQuestion(std::string questionText, int price, QuestionType type, std::string answer)
{
	TestRepository::getInstance()->getTest()->getQuestions().push_back(new OpenQuestion(questionText, price, type, answer));
	TestRepository::getInstance()->getTest()->incQuestionCount();

	StatisticRepository::getInstance()->getTestStatistic()->setQuestionCount(TestRepository::getInstance()->getTest()->getQuestionCount());
}

void Admin::removeQuestion(int questionNumber)
{
	auto iter = TestRepository::getInstance()->getTest()->getQuestions().cbegin();
	TestRepository::getInstance()->getTest()->getQuestions().erase(iter + questionNumber);
	TestRepository::getInstance()->getTest()->decQuestionCount();

	StatisticRepository::getInstance()->getTestStatistic()->setQuestionCount(TestRepository::getInstance()->getTest()->getQuestionCount());
}

void Admin::changeQuestion(int questionNumber, ChangeType type, std::string str)
{
	if (type == ChangeType::QuestionText)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setQuestionText(str);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setAnswer(str);
	}
}

void Admin::changeQuestion(int questionNumber, ChangeType type, int num)
{
	if (type == ChangeType::Price)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setPrice(num);
	}
	else if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setAnswer(num);
	}
}

void Admin::changeQuestion(int questionNumber, ChangeType type, std::vector<int>& nums)
{
	if (type == ChangeType::Answer)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setAnswer(nums);
	}
}

void Admin::changeQuestion(int questionNumber, ChangeType type, QuestionType qtype)
{
	if (type == ChangeType::QuestionType)
	{
		std::string tempText = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getQuestionText();
		int tempPrice = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getPrice();
		std::vector<std::string> variants;
		if (qtype != QuestionType::Open)
		{
			variants = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants();
		}
		
		this->removeQuestion(questionNumber);

		if (qtype == QuestionType::MonoClose)
		{
			auto iter = TestRepository::getInstance()->getTest()->getQuestions().cbegin();
			TestRepository::getInstance()->getTest()->getQuestions().insert(iter + questionNumber, new MonoCloseQuestion(tempText, tempPrice, QuestionType::MonoClose, 0, variants));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
		else if (qtype == QuestionType::MultiClose)
		{
			auto iter = TestRepository::getInstance()->getTest()->getQuestions().cbegin();
			std::vector<int> v;
			TestRepository::getInstance()->getTest()->getQuestions().insert(iter + questionNumber, new MultiCloseQuestion(tempText, tempPrice, QuestionType::MultiClose, v, variants));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
		else if (qtype == QuestionType::Open)
		{
			auto iter = TestRepository::getInstance()->getTest()->getQuestions().cbegin();
			TestRepository::getInstance()->getTest()->getQuestions().insert(iter + questionNumber, new OpenQuestion(tempText, tempPrice, QuestionType::Open, ""));
			TestRepository::getInstance()->getTest()->incQuestionCount();
		}
	}
}

void Admin::changeQuestion(int questionNumber, ChangeType type, std::vector<std::string> vars)
{
	if (type == ChangeType::Variants)
	{
		TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->setVariants(vars);
	}
}

void Admin::createTest(std::string testName)
{
	if (TestRepository::getInstance() != nullptr)
	{
		this->saveTest();
	}
	TestRepository::getInstance()->setTest(new Test(testName));
}

void Admin::removeTest()
{
	delete TestRepository::getInstance()->getTest();	//realisation (delete in db and testStatistic)
}