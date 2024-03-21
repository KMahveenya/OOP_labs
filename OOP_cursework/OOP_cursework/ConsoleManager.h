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

	void writeTestStatistic(std::string, int, int, int, int);
	void writeStudentStatistic(std::string, int, int, int);

	void writeQuestion(std::string);
	void writeTestList(std::vector<std::string>&);
	void writeVariants(std::vector<std::string>&);
	void writePrice(int, int);
	void writeRemoveTestMess();
	void writeChangeQuestionError();
	
	std::string writeQuestionTextAsk();
	std::string writeNameAsk();
	int writePriceAsk();
	int writeQuestionTypeAsk();
	int writeMonoAnswerAsk();
	std::vector<int> writeMultiAnswerAsk();
	std::string writeOpenAnswerAsk();
	std::vector<std::string> writeVariantsAsk();
	int writeQuestionNumber();

	int writeStartMenu();
	int writeStudentMenu();
	int writeAdminMenu();
	int writeChangeAsk();

	void correct(bool);
};

