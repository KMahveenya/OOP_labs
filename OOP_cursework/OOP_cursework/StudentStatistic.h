#pragma once
class StudentStatistic
{
private:
	int solvingTestsCount;
	int maxResault;
	int averageTime;

public:
	void setSolvingTestsCount(int);
	void setMaxResault(int);
	void setAverageTime(int);

	int getSolvingTestsCount();
	int getMaxResault();
	int getAverageTime();
};

