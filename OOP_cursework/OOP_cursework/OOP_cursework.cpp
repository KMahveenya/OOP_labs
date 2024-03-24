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
#include "Noname.h"

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
	Noname* noname = new Noname();
	//std::cout << noname->registration("qwe", "pass1", "pass1");
	//std::cout << noname->authentification("user1", "password1");

	Admin* admin = new Admin();
	TestStatistic* teststat = new TestStatistic();
	StudentStatistic* studstat = new StudentStatistic();
	StatisticRepository::getInstance()->setTestStatistic(teststat);
	StatisticRepository::getInstance()->setStudentStatistic(studstat);

	std::vector<int> v{3, 2};
	std::vector<std::string> vars1{ "2", "3", "4", "5"};
	std::vector<std::string> vars2{ "Birds", "Animals", "Mushrooms", "Spiders" };

	admin->createTest("test1");

	admin->addQuestion("Type of data which store integer numbers?", 100, QuestionType::Open, "int");
	admin->addQuestion("How many principals of OOP?", 200, QuestionType::MonoClose, 3, vars1);
	admin->addQuestion("Choose kingdom of living organisms", 300, QuestionType::MultiClose, v, vars2);
	
	teststat->setAverageResault(450);
	teststat->setMinTime(20);
	teststat->setQuestionCount(3);
	teststat->setSolvingCount(7);
	
	studstat->setCommonTime(30);
	studstat->setMaxResault(500);
	studstat->setSolvingTestsCount(5);

	int currUser;
	do
	{
		currUser = ConsoleManager::getInstance()->writeStartMenu();

		if (currUser == 1)
		{
			std::string login;
			int access = ConsoleManager::getInstance()->writeAccessMenu();
			if (access == 1)
			{
				do
				{
					login = ConsoleManager::getInstance()->getLogin();
				} while (!noname->registration(login, ConsoleManager::getInstance()->getPassword(2), ConsoleManager::getInstance()->getPassword(1)));
			}
			else if (access == 2)
			{
				do
				{
					login = ConsoleManager::getInstance()->getLogin();
				} while (!noname->authentification(login, ConsoleManager::getInstance()->getPassword(1)));
			}
			int variant;
			Student* student = new Student(login);
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
				else if (variant == 4)
				{
					delete student;
				}
			} while (variant != 5);
		}
		else if (currUser == 2)
		{
			int variant;
			while (!noname->authentification("admin", ConsoleManager::getInstance()->getPassword(1)))
			{

			}
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
						int ans = ConsoleManager::getInstance()->writeMonoAnswerAsk(vars.size());
						admin->addQuestion(questionText, price, type, ans, vars);
					}
					else if (type == QuestionType::MultiClose)
					{
						std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
						std::vector<int> anses = ConsoleManager::getInstance()->writeMultiAnswerAsk(vars.size());
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
					int questionNumber = ConsoleManager::getInstance()->writeQuestionNumber(TestRepository::getInstance()->getTest()->getQuestionCount()) - 1;
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
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants().size());
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
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants().size());
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
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants().size());
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (qType == QuestionType::MultiClose)
						{
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants().size());
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
							int newAns = ConsoleManager::getInstance()->getMonoCloseAnswer(TestRepository::getInstance()->getTest()->getQuestion(questionNumber)->getVariants().size());
							admin->changeQuestion(questionNumber, ChangeType::Answer, newAns);
						}
						else if (currQType == QuestionType::MultiClose)
						{
							std::vector<std::string> vars = ConsoleManager::getInstance()->writeVariantsAsk();
							admin->changeQuestion(questionNumber, ChangeType::Variants, vars);
							std::vector<int> newAns = ConsoleManager::getInstance()->getMultiCloseAnswer(vars.size());
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
					admin->removeQuestion(ConsoleManager::getInstance()->writeQuestionNumber(TestRepository::getInstance()->getTest()->getQuestionCount()) - 1);
				}
				else if (variant == 8)
				{
					admin->getTestStatistic();
				}
				else if (variant == 9)
				{
					//delete admin;
				}
			} while (variant != 9);
		}
	} while (currUser != 3);

	return 0;
}