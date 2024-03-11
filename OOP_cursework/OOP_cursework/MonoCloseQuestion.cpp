#include "MonoCloseQuestion.h"

MonoCloseQuestion::MonoCloseQuestion()
{
	type = QuestionType::MonoClose;
	answer = 3;
}

bool MonoCloseQuestion::check(int answer)
{
	return answer == this->answer;
}