#pragma once
#include <string>
#include <vector>
#include "IUser.h"
#include "IQuestion.h"

enum class ChangeType
{
	QuestionText,
	Answer,
	QuestionType,
	Price,
	Variants
};

class Admin : public IUser
{
public:
	Admin();

	void addQuestion(std::string, std::string, int, QuestionType, int, std::vector<std::string>&);
	void addQuestion(std::string, std::string, int, QuestionType, std::vector<int>&, std::vector<std::string>&);
	void addQuestion(std::string, std::string, int, QuestionType, std::string);

	void removeQuestion(std::string, int);

	void changeQuestion(std::string, int, ChangeType, std::string);
	void changeQuestion(std::string, int, ChangeType, int);
	void changeQuestion(std::string, int, ChangeType, std::vector<int>&);
	void changeQuestion(std::string, int, ChangeType, QuestionType);
	void changeQuestion(std::string, int, ChangeType, std::vector<std::string>&);

	void createTest(std::string);

	void removeTest();
};

