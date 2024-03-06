#include "MultiCloseQuestion.h"

bool MultiCloseQuestion::check(std::vector<int>& answer)
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] != this->answer[i])
		{
			return false;
		}
	}
	return true;
}