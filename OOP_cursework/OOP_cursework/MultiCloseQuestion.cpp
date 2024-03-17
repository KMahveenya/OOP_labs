#include "MultiCloseQuestion.h"
#include <iostream>

MultiCloseQuestion::MultiCloseQuestion()
{

}

MultiCloseQuestion::MultiCloseQuestion(std::string questionText, int price, QuestionType type, std::vector<int>& answer, std::vector<std::string>& variants)
{
	this->type = type;
	this->price = price;
	this->textQuestion = questionText;
	this->answer = answer;
	this->variants = variants;
}

bool MultiCloseQuestion::check(std::vector<int>& answer)
{
	if (answer.size() != this->answer.size())
	{
		return false;
	}
	std::sort(begin(this->answer), end(this->answer));
	std::sort(begin(answer), end(answer));
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] != this->answer[i])
		{
			return false;
		}
	}
	return true;
}

void MultiCloseQuestion::setAnswer(std::vector<int>& answer)
{
	this->answer = answer;
}

std::vector<std::string>& MultiCloseQuestion::getVariants()
{
	return variants;
}

void MultiCloseQuestion::setVariants(std::vector<std::string>& variants)
{
	this->variants = variants;
}