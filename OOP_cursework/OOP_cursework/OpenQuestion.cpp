#include "OpenQuestion.h"

OpenQuestion::OpenQuestion()
{
	type = QuestionType::Open;
}

bool OpenQuestion::check(std::string answer)
{
	std::transform(answer.begin(), answer.end(), answer.begin(), tolower);
	return answer == this->answer;
}