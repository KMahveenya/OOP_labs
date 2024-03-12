#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "IQuestion.h"

class MultiCloseQuestion : public IQuestion
{
private:
	std::vector<int> answer;
	std::vector<std::string> variants;

public:
	MultiCloseQuestion();
	MultiCloseQuestion(std::string, int, QuestionType, std::vector<int>&, std::vector<std::string>&);

	bool check(int) override { return 0; };
	bool check(std::string) override { return 0; };
	bool check(std::vector<int>&) override;

	void setAnswer(int) override {};
	void setAnswer(std::string) override {};
	void setAnswer(std::vector<int>&) override;

	std::vector<std::string>& getVariants() override;
	void setVariants(std::vector<std::string>&) override;

};

