#include "IQuestion.h"

void IQuestion::setQuestionText(std::string questionText)
{
	this->textQuestion = questionText;
}

void IQuestion::setPrice(int price)
{
	this->price = price;
}

std::string IQuestion::getQuestionText()
{
	return this->textQuestion;
}

int IQuestion::getPrice()
{
	return this->price;
}

QuestionType IQuestion::getQuestionType()
{
	return type;
}