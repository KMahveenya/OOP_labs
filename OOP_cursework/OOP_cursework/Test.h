#pragma once
#include <string>
#include "IQuestion.h"

class Test
{
private:
	std::string testName;
	int questionCount;
	std::vector<IQuestion*> questions;

public:
	Test();
	Test(std::string);

	~Test();

	std::string getName();
	int getQuestionCount();
	IQuestion* getQuestion(int);
	std::vector<IQuestion*>& getQuestions();

	void setName(std::string);
	void incQuestionCount();
	void decQuestionCount();
};

