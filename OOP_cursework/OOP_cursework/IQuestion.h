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

	virtual void setAnswer(int) = 0;
	virtual void setAnswer(std::string) = 0;
	virtual void setAnswer(std::vector<int>&) = 0;

	virtual std::vector<std::string>& getVariants() = 0;
	virtual void setVariants(std::vector<std::string>&) = 0;

	void setQuestionText(std::string);
	void setPrice(int);

	std::string getQuestionText();
	int getPrice();
};

