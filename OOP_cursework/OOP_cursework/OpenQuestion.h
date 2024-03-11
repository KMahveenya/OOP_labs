#pragma once
#include <algorithm>
#include <string>
#include "IQuestion.h"

class OpenQuestion : public IQuestion
{
private:
	std::string answer;
public:
	OpenQuestion();

	bool check(int) override { return 0; };
	bool check(std::string) override;
	bool check(std::vector<int>&) override { return 0; };
};