#pragma once
#include <string>
#include "IQuestion.h"

class MonoCloseQuestion : public IQuestion
{
private:
	int answer;
public:
	MonoCloseQuestion();

	bool check(int) override;
	bool check(std::string) override { return 0; };
	bool check(std::vector<int>&) override { return 0; };
};