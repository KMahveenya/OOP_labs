#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "IQuestion.h"

class MultiCloseQuestion : public IQuestion
{
private:
	std::vector<int> answer;
public:
	MultiCloseQuestion();

	bool check(int) override { return 0; };
	bool check(std::string) override { return 0; };
	bool check(std::vector<int>&) override;
};

