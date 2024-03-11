#pragma once
#include <string>
#include <vector>

enum class QuestionType
{
	MonoClose,
	MultiClose,
	Open
};

class IQuestion
{
protected:
	std::string textQuestion;
	int price;
	QuestionType type;

public:
	virtual bool check(int) = 0;
	virtual bool check(std::string) = 0;
	virtual bool check(std::vector<int>&) = 0;
};

