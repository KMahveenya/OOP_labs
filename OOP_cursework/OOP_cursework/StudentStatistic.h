#pragma once
class StudentStatistic
{
private:
	int solvingTestsCount;
	int maxResault;
	int commonTime;

public:
	void setSolvingTestsCount(int);
	void setMaxResault(int);
	void setCommonTime(int);

	int getSolvingTestsCount();
	int getMaxResault();
	int getCommonTime();
};

