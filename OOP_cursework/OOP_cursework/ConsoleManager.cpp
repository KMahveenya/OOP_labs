#include "ConsoleManager.h"
#include <iostream>

ConsoleManager::ConsoleManager()
{
	
}

void ConsoleManager::writeQuestion(std::string question)
{
	std::cout << '\n' << question << "\n\n";
}

void ConsoleManager::writeChangeQuestionError()
{
	std::cout << "\nThis question is open. You can`t change variants\n";
}

ConsoleManager* ConsoleManager::getInstance()
{
	if (!console)
	{
		console = new ConsoleManager();
	}
	return console;
}

int ConsoleManager::getMonoCloseAnswer()
{
	int ans = 0;
	std::cout << "\nYour answer: \n";
	std::string str;
	std::getline(std::cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] > '0' && str[i] < '9')
		{
			ans = ans * 10 + str[i] - 48;
		}
	}
	return ans;
}

std::vector<int> ConsoleManager::getMultiCloseAnswer()
{
	std::vector<int> ans;
	std::string str;
	std::cout << "\nYour answer: \n";
	std::getline(std::cin, str);
	int a = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			a = a * 10 + (str[i] - 48);
		}
		else
		{
			ans.push_back(a);
			a = 0;
		}
	}
	ans.push_back(a);
	return ans;
}

std::string ConsoleManager::getOpenAnswer()
{
	std::string ans;
	std::cout << "\nYour answer: \n";
	std::getline(std::cin, ans);
	return ans;
}

void ConsoleManager::correct(bool ans)
{
	if (ans)
	{
		std::cout << "\nCorrect answer!\n";
	}
	else
	{
		std::cout << "\nIncorrect answer!\n";
	}
}

void ConsoleManager::writeVariants(std::vector<std::string>& vars)
{
	for (int i = 0; i < vars.size(); i++)
	{
		std::cout << i + 1 << ". " << vars[i] << '\n';
	}
}

void ConsoleManager::writePrice(int price, int sumPrice)
{
	std::cout << "\nYour points: " << price << '/' << sumPrice;
}

void ConsoleManager::writeTestStatistic(std::string name, int averRes, int minTime, int questionCount, int solveCount)
{
	std::cout << "\n\n---------------------------------------------------------------------\n";
	std::cout << "Test name: " << name;
	std::cout << "\nAverage resault: " << averRes;
	std::cout << "\nMinimum time to solve test: " << minTime;
	std::cout << "\nCount of questions in test: " << questionCount;
	std::cout << "\nCount of solves test: " << solveCount;
	std::cout << "\n---------------------------------------------------------------------\n\n";
}

void ConsoleManager::writeStudentStatistic(std::string name, int solvCount, int maxRes, int averTime)
{
	std::cout << "\n\n---------------------------------------------------------------------\n";
	std::cout << "User name: " << name;
	std::cout << "\nCount of solving tests: " << solvCount;
	std::cout << "\nMaximum resault of user: " << maxRes;
	std::cout << "\nAverage time of solvings: " << averTime;
	std::cout << "\n---------------------------------------------------------------------\n\n";
}

int ConsoleManager::writeStudentMenu()
{
	std::cout << "\n***---Menu---***\n";
	std::cout << "1. Start test\n";
	std::cout << "2. List of tests\n";
	std::cout << "3. Check test statistic\n";
	std::cout << "4. Check student statistic\n";
	std::cout << "5. Logout\n";
	std::cout << "\nYou choose: ";
	int a;
	std::string str;
	std::cin >> a;
	std::getline(std::cin, str);
	return a;
}

int ConsoleManager::writeAdminMenu()
{
	std::cout << "\n***---Menu---***\n";
	std::cout << "1. Create new test\n";
	std::cout << "2. List of tests\n";
	std::cout << "3. Get test by name\n";
	std::cout << "4. Remove test\n";
	std::cout << "5. Add question to test\n";
	std::cout << "6. Change question in test\n";
	std::cout << "7. Remove question in test\n";
	std::cout << "8. Check test statistic\n";
	std::cout << "9. Logout\n";
	std::cout << "\nYou choose: ";
	int a;
	std::string str;
	std::cin >> a;
	std::getline(std::cin, str);
	return a;
}

void ConsoleManager::writeTestList(std::vector<std::string>& names)
{
	std::cout << "\nTests:\n";
	for (int i = 0; i < names.size(); i++)
	{
		std::cout << names[i] << '\n';
	}
}

std::string ConsoleManager::writeNameAsk()
{
	std::cout << "\nEnter test name:\n";
	std::string str;
	std::getline(std::cin, str);
	return str;
}

void ConsoleManager::writeRemoveTestMess()
{
	std::cout << "\nTest removed:\n";
}

std::string ConsoleManager::writeQuestionTextAsk()
{
	std::cout << "\nEnter question text: \n";
	std::string str;
	std::getline(std::cin, str);
	return str;
}

int ConsoleManager::writePriceAsk()
{
	std::cout << "\nEnter cost of question: \n";
	int num;
	std::string str;
	std::cin >> num;
	std::getline(std::cin, str);
	return num;
}

int ConsoleManager::writeQuestionTypeAsk()
{
	std::cout << "\nChoose type of question:\n1. close/1 variant\n2. close/many variants\n3. open\n\nYou choose: \n";
	int num;
	std::string str;
	std::cin >> num;
	std::getline(std::cin, str);
	return num;
}

int ConsoleManager::writeMonoAnswerAsk()
{
	std::cout << "\nEnter num of correct variant: \n";
	int num;
	std::string str;
	std::cin >> num;
	std::getline(std::cin, str);
	return num;
}

std::vector<int> ConsoleManager::writeMultiAnswerAsk()
{
	std::cout << "\nEnter nums of correct variants: \n";
	std::vector<int> ans;
	std::string str;
	std::getline(std::cin, str);
	int a = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			a = a * 10 + (str[i] - 48);
		}
		else
		{
			ans.push_back(a);
			a = 0;
		}
	}
	ans.push_back(a);
	return ans;
}

std::string ConsoleManager::writeOpenAnswerAsk()
{
	std::cout << "\nEnter correct answer: \n";
	std::string str;
	std::getline(std::cin, str);
	return str;
}

std::vector<std::string> ConsoleManager::writeVariantsAsk()
{
	std::cout << "\nHow many variants you want to add: \n";
	int count;
	std::string str;
	std::cin >> count;
	std::getline(std::cin, str);
	std::vector<std::string> vars;
	std::cout << "\nEnter variants: \n";
	for (int i = 0; i < count; i++)
	{
		std::getline(std::cin, str);
		vars.push_back(str);
	}
	return vars;
}

int ConsoleManager::writeStartMenu()
{
	std::cout << "\n***---Menu---***\n";
	std::cout << "1. Enter like student\n";
	std::cout << "2. Enter like admin\n";
	std::cout << "3. Exit\n";
	std::cout << "\nYou choose: ";
	int a;
	std::string str;
	std::cin >> a;
	std::getline(std::cin, str);
	return a;
}

int ConsoleManager::writeChangeAsk()
{
	std::cout << "\nChoose type of choosing:\n1. Text of question\n2. Type of question\n3. Cost of question\n4. Answer of question\n5. Variants of question\n\nYou choose: \n";
	int num;
	std::string str;
	std::cin >> num;
	std::getline(std::cin, str);
	return num;
}

int ConsoleManager::writeQuestionNumber()
{
	std::cout << "\nEnter number of question: \n";
	int num;
	std::string str;
	std::cin >> num;
	std::getline(std::cin, str);
	return num;
}