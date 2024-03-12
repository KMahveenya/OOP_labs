#pragma once
#include <string>
#include "IQuestion.h"

class Test
{
private:
	std::string testName;
	int questionCount;
	

public:
	std::vector<IQuestion*> questions;
	Test();

	std::string getName();
	int getQuestionCount();

	void setName(std::string);
	void incQuestionCount();
	void decQuestionCount();
};

