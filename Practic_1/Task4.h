#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct WORKER {
    std::string NAME;
    std::string POS;
    int YEAR;
    int MONTH;
};

class Task4
{
private:
	std::vector<WORKER>* workers;
    int n;
public:
    Task4(std::vector<WORKER>* workers, int n);
	void InputWorkers();
	void SortWorkers();
	void DisplayWorkersWithExperience(int requiredYears, int currentYear, int currentMonth);
};

