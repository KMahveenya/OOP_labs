#include "MonoCloseQuestion.h"

MonoCloseQuestion::MonoCloseQuestion()
{
	type = QuestionType::MonoClose;
	answer = 3;
	this->variants;
}

MonoCloseQuestion::MonoCloseQuestion(std::string questionText, int price, QuestionType type, int answer, std::vector<std::string> variants)
{
	this->type = type;
	this->price = price;
	this->textQuestion = questionText;
	this->answer = answer;
	this->variants = variants;
}

bool MonoCloseQuestion::check(int answer)
{
	return answer == this->answer;
}

void MonoCloseQuestion::setAnswer(int answer)
{
	this->answer = answer;
}

std::vector<std::string>& MonoCloseQuestion::getVariants()
{
	return variants;
}

void MonoCloseQuestion::setVariants(std::vector<std::string>& variants)
{
	this->variants = variants;
}