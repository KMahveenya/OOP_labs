#include "ConsoleManager.h"
#include <iostream>

ConsoleManager::ConsoleManager()
{
	
}

void ConsoleManager::writeQuestion(std::string question)
{
	std::cout << '\n' << question << "\n\n";
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
	int ans;
	std::cin >> ans;
	return ans;
}

std::vector<int> ConsoleManager::getMultiCloseAnswer()
{
	std::vector<int> ans;
	std::string str;
	std::getline(std::cin, str);
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
	std::cin >> ans;
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