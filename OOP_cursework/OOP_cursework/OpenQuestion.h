#pragma once
#include <algorithm>
#include <string>
#include "IQuestion.h"

class OpenQuestion : public IQuestion
{
private:
	std::string answer;
public:
	bool check(std::string);
};