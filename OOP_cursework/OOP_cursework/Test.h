#pragma once
#include <string>
#include "IQuestion.h"

class Test
{
public:
	std::string testName;
	int questionCount;
	IQuestion* questions;

public:
	Test();
	std::string getName();
};

