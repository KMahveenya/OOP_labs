#include "MonoCloseQuestion.h"

MonoCloseQuestion::MonoCloseQuestion()
{
	answer = -1;
}

bool MonoCloseQuestion::check(int answer)
{
	return answer == this->answer;
}