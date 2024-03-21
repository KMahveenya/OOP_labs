#include <iostream>
#include "Test.h"
#include "IQuestion.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"
#include "Admin.h"
#include "TestRepository.h"
#include "StatisticRepository.h"
#include "ConsoleManager.h"
#include <time.h>
#include <windows.h>
#include "Student.h"

#include "TestStatistic.h"
#include "StudentStatistic.h"

TestRepository* TestRepository::testRep = NULL;
StatisticRepository* StatisticRepository::statisticRep = NULL;
ConsoleManager* ConsoleManager::console = NULL;

enum class UserType
{
	Student,
	Admin,
	None
};

int main()
{
    Admin* admin = new Admin();
	Student* student = new Student();

	std::vector<int> v{ 3, 2 };
	std::vector<std::string> vars1{ "2", "3", "4", "5"};
	std::vector<std::string> vars2{ "Birds", "Animals", "Mushrooms", "Spiders" };

	admin->createTest("test1");

	admin->addQuestion("Type of data which store integer numbers?", 100, QuestionType::Open, "int");
	admin->addQuestion("How many principals of OOP?", 200, QuestionType::MonoClose, 3, vars1);
	admin->addQuestion("Choose kingdom of living organisms", 300, QuestionType::MultiClose, v, vars2);

	TestStatistic* teststat = new TestStatistic();
	teststat->setAverageResault(450);
	teststat->setMinTime(20);
	teststat->setQuestionCount(3);
	teststat->setSolvingCount(13);
	StatisticRepository::getInstance()->setTestStatistic(teststat);

	StudentStatistic* studstat = new StudentStatistic();
	studstat->setAverageTime(26);
	studstat->setMaxResault(500);
	studstat->setSolvingTestsCount(72);
	StatisticRepository::getInstance()->setStudentStatistic(studstat);

	int currUser;
	do
	{
		currUser = ConsoleManager::getInstance()->writeStartMenu();
		if (currUser == 1)
		{
			int variant;
			do
			{
				variant = ConsoleManager::getInstance()->writeStudentMenu();
				if (variant == 1)
				{
					student->startTest();
				}
				else if (variant == 2)
				{
					ConsoleManager::getInstance()->writeTestList((std::vector<std::string>&)student->getTestList());
				}
				else if (variant == 3)
				{
					student->getTestStatistic();
				}
				else if (variant == 4)
				{
					student->getStudentStatistic();
				}
			} while (variant != 5);
		}
		else if (currUser == 2)
		{
			int variant;
			do
			{
				variant = ConsoleManager::getInstance()->writeAdminMenu();
				if (variant == 1)
				{
					admin->createTest(ConsoleManager::getInstance()->writeNameAsk());
				}
				else if (variant == 2)
				{
					ConsoleManager::getInstance()->writeTestList((std::vector<std::string>&)admin->getTestList());
				}
				else if (variant == 3)
				{
					admin->getTest(ConsoleManager::getInstance()->writeNameAsk());
				}
				else if (variant == 4)
				{
					admin->removeTest();
					ConsoleManager::getInstance()->writeRemoveTestMess();
				}
				else if (variant == 5)
				{
					std::string questionText = ConsoleManager::getInstance()->writeQuestionTextAsk();
					int intType = ConsoleManager::getInstance()->writeQuestionTypeAsk();
					QuestionType type;
					if (intType == 1)
					{
						type = QuestionType::MonoClose;
					}
					else if (intType == 2)
					{
						type = QuestionType::MultiClose;
					}
					else if (intType == 3)
					{
						type = QuestionType::Open;
					}
					int price = ConsoleManager::getInstance()->writePriceAsk();
					if (type == QuestionType::MonoClose)
					{
						std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
						int ans = ConsoleManager::getInstance()->writeMonoAnswerAsk();
						admin->addQuestion(questionText, price, type, ans, vars);
					}
					else if (type == QuestionType::MultiClose)
					{
						std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
						std::vector<int> anses = ConsoleManager::getInstance()->writeMultiAnswerAsk();
						admin->addQuestion(questionText, price, type, anses, vars);
					}
					else if (type == QuestionType::Open)
					{
						std::string ans = ConsoleManager::getInstance()->writeOpenAnswerAsk();
						admin->addQuestion(questionText, price, type, ans);
					}
				}
				else if (variant == 6)
				{
					int intChangeType = ConsoleManager::getInstance()->writeChangeAsk();
					int questionNumber = ConsoleManager::getInstance()->writeQuestionNumber() - 1;
					if (intChangeType == 1)
					{
						std::string newQuestionText = ConsoleManager::getInstance()->writeQuestionTextAsk();
						admin->changeQuestion(questionNumber, ChangeType::QuestionText, newQuestionText);
					}
					else if (intChangeType == 2)
					{
						int intQType = ConsoleManager::getInstance()->writeQuestionTypeAsk();
						QuestionType qType, currQType;
						currQType = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getQuestionType();
						qType = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getQuestionType();
						if (intQType == 1)
						{
							qType = QuestionType::MonoClose;
							admin->changeQuestion(questionNumber, ChangeType::QuestionType, qType);
							if (currQType == QuestionType::Open)
							{
								std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
								admin->changeQuestion(questionNumber, ChangeType::Variants, vars);
							}
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if(intQType == 2)
						{
							qType = QuestionType::MultiClose;
							admin->changeQuestion(questionNumber, ChangeType::QuestionType, qType);
							if (currQType == QuestionType::Open)
							{
								std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
								admin->changeQuestion(questionNumber, ChangeType::Variants, vars);
							}
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (intQType == 3)
						{
							qType = QuestionType::Open;
							admin->changeQuestion(questionNumber, ChangeType::QuestionType, qType);
							std::string newAns = ConsoleManager::getInstance()->getOpenAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
					}
					else if (intChangeType == 3)
					{
						int newPrice = ConsoleManager::getInstance()->writePriceAsk();
						admin->changeQuestion(questionNumber, ChangeType::Price, newPrice);
					}
					else if (intChangeType == 4)
					{
						QuestionType qType = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getQuestionType();
						if (qType == QuestionType::MonoClose)
						{
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (qType == QuestionType::MultiClose)
						{
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (qType == QuestionType::Open)
						{
							std::string newAns = ConsoleManager::getInstance()->getOpenAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
					}
					else if (intChangeType == 5)
					{
						QuestionType currQType = TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getQuestionType();
						if (currQType == QuestionType::MonoClose)
						{
							std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
							admin->changeQuestion(questionNumber, ChangeType::Variants, vars);
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (currQType == QuestionType::MultiClose)
						{
							std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
							admin->changeQuestion(questionNumber, ChangeType::Variants, vars);
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer();
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if(currQType == QuestionType::Open)
						{
							ConsoleManager::getInstance()->writeChangeQuestionError();
						}
					}
				}
				else if (variant == 7)
				{
					admin->removeQuestion(ConsoleManager::getInstance()->writeQuestionNumber() - 1);
				}
				else if (variant == 8)
				{
					admin->getTestStatistic();
				}
				else if (variant == 9)
				{
					admin->logout();
				}
			} while (variant != 9);
		}
	} while (currUser != 3);

	return 0;
}