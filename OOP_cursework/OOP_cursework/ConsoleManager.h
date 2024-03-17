#pragma once
#include <string>
#include <vector>

class ConsoleManager
{
private:
	static ConsoleManager* console;

	ConsoleManager();
	ConsoleManager(const ConsoleManager&) = delete;
	ConsoleManager& operator=(ConsoleManager&);

public:
	static ConsoleManager* getInstance();

	int getMonoCloseAnswer();
	std::vector<int> getMultiCloseAnswer();
	std::string getOpenAnswer();

	void writeQuestion(std::string);
	void writeVariants(std::vector<std::string>&);
	void correct(bool);
};

