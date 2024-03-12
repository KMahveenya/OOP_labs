#pragma once
#include <string>
#include "IQuestion.h"

class MonoCloseQuestion : public IQuestion
{
private:
	int answer;
	std::vector<std::string> variants;

public:
	MonoCloseQuestion();
	MonoCloseQuestion(std::string, int, QuestionType, int, std::vector<std::string>&);

	bool check(int) override;
	bool check(std::string) override { return 0; };
	bool check(std::vector<int>&) override { return 0; };

	void setAnswer(int) override;
	void setAnswer(std::string) override {};
	void setAnswer(std::vector<int>&) override {};

	std::vector<std::string>& getVariants() override;
	void setVariants(std::vector<std::string>&) override;

};