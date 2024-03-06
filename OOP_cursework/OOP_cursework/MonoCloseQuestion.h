#pragma once
#include <string>
#include "IQuestion.h"

class MonoCloseQuestion : public IQuestion
{
private:
	int answer;
public:
	MonoCloseQuestion();

	bool check(int);
};

