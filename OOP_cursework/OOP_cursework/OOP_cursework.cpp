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

TestRepository* TestRepository::testRep = NULL;
StatisticRepository* StatisticRepository::statisticRep = NULL;
ConsoleManager* ConsoleManager::console = NULL;

int main()
{
    Admin* admin = new Admin();

	std::vector<int> v{ 3, 10, 5 };
	std::vector<std::string> vars{ "var1", "var2", "var3" };

	admin->createTest("test1");

	admin->addQuestion("id123451", "what1?", 100, QuestionType::Open, "bebra1");
	admin->addQuestion("id123452", "what2?", 200, QuestionType::MonoClose, 2, vars);
	admin->addQuestion("id123453", "what3?", 300, QuestionType::MultiClose, v, vars);

	/*std::cout << TestRepository::getInstance()->getTest()->getQuestionCount() << '\n';

	std::cout << TestRepository::getInstance()->getTest()->questions[1]->getQuestionText() << '\n';
	admin->changeQuestion("123123", 1, ChangeType::QuestionText, "who?");
	std::cout << TestRepository::getInstance()->getTest()->questions[1]->getQuestionText() << '\n';

	std::vector<int> v2{ 3, 10, 12 };
	std::cout << TestRepository::getInstance()->getTest()->questions[2]->check(v2) << '\n';
	admin->changeQuestion("123123", 2, ChangeType::Answer, v2);
	std::cout << TestRepository::getInstance()->getTest()->questions[2]->check(v2) << '\n';

	std::cout << TestRepository::getInstance()->getTest()->questions[1]->check(2) << '\n';
	admin->changeQuestion("123123", 1, ChangeType::QuestionType, QuestionType::Open);
	admin->changeQuestion("123123", 1, ChangeType::Answer, "someText");

	std::cout << TestRepository::getInstance()->getTest()->questions[1]->check("someText") << '\n';

	std::vector<std::string> vars2{ "new1", "new2", "new3" };

	std::cout << TestRepository::getInstance()->getTest()->questions[2]->getVariants()[2] << '\n';
	admin->changeQuestion("123123", 2, ChangeType::Variants, vars2);
	std::cout << TestRepository::getInstance()->getTest()->questions[2]->getVariants()[2] << '\n';

	//admin->removeTest();

	clock_t start = clock();
	Sleep(3500);
	clock_t end = clock();
	std::cout << (end - start) / CLOCKS_PER_SEC << '\n';


	StatisticRepository::getInstance()->setTestStatistic(new TestStatistic());
	StatisticRepository::getInstance()->setStudentStatistic(new StudentStatistic());
	StatisticRepository::getInstance()->getTestStatistic()->setMinTime(45);
	std::cout << StatisticRepository::getInstance()->getTestStatistic()->getMinTime() << '\n';*/

	Student* student = new Student();
	student->startTest();
}