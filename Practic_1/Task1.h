#pragma once
#include <iostream>
#include <vector>
class Task1
{
private:
	std::vector<int> array;
	int GetMinElement();
	int GetSumfFirstAndLastPositiveElements();
	int GetSum(int first, int last);
	void TransformArray();
	void GetArray();
public:
	void Execute(std::vector<int> array);
};

