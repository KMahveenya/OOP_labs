#pragma once
#include <string>
#include <vector>
#include "IUser.h"
#include "IQuestion.h"
#include "StatisticRepository.h"

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

	void addQuestion(std::string, int, QuestionType, int, std::vector<std::string>);
	void addQuestion(std::string, int, QuestionType, std::vector<int>&, std::vector<std::string>);
	void addQuestion(std::string, int, QuestionType, std::string);

	void removeQuestion(int);

	void changeQuestion(int, ChangeType, std::string);
	void changeQuestion(int, ChangeType, int);
	void changeQuestion(int, ChangeType, std::vector<int>&);
	void changeQuestion(int, ChangeType, QuestionType);
	void changeQuestion(int, ChangeType, std::vector<std::string>);

	void createTest(std::string);

	void removeTest();
};

