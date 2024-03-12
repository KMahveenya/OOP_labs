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
	OpenQuestion(std::string, int, QuestionType, std::string);

	bool check(int) override { return 0; };
	bool check(std::string) override;
	bool check(std::vector<int>&) override { return 0; };

	void setAnswer(int) override {};
	void setAnswer(std::string) override;
	void setAnswer(std::vector<int>&) override {};

	std::vector<std::string>& getVariants() override { std::vector<std::string> v; return v; };
	void setVariants(std::vector<std::string>&) override {};
};