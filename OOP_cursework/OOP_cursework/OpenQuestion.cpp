#include "OpenQuestion.h"

OpenQuestion::OpenQuestion()
{
	type = QuestionType::Open;
}

OpenQuestion::OpenQuestion(std::string questionText, int price, QuestionType type, std::string answer)
{
	this->type = type;
	this->price = price;
	this->textQuestion = questionText;
	this->answer = answer;
}

bool OpenQuestion::check(std::string answer)
{
	std::transform(answer.begin(), answer.end(), answer.begin(), tolower);
	std::transform(this->answer.begin(), this->answer.end(), this->answer.begin(), tolower);
	return answer == this->answer;
}

void OpenQuestion::setAnswer(std::string answer)
{
	this->answer = answer;
}