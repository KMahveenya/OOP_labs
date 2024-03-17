#pragma once

class TestStatistic
{
private:
	int questionsCount;
	int averageResault;
	int solvingCount;
	int minTime;

public:
	void setQuestionCount(int);
	void setAverageResault(int);
	void setSolvingCount(int);
	void setMinTime(int);

	int getQuestionCount();
	int getAverageResault();
	int getSolvingCount();
	int getMinTime();

};

