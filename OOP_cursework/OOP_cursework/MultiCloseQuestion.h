#pragma once
#include <string>
#include <vector>
#include "IQuestion.h"

class MultiCloseQuestion : public IQuestion
{
private:
	std::vector<int> answer;
public:
	bool check(std::vector<int>&);
};

