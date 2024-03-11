#pragma once
#include <string>
#include "IUser.h"

class Admin : public IUser
{
public:
	Admin();

	void addQuestion(std::string);
	void removeQuestion(std::string);
	void changeQuestion(std::string);
	void createTest(std::string);
	void removeTest(std::string);
};

