#include "MultiCloseQuestion.h"

MultiCloseQuestion::MultiCloseQuestion()
{
	type = QuestionType::MultiClose;
	answer = { 6, 1, 3 };
}

bool MultiCloseQuestion::check(std::vector<int>& answer)
{
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