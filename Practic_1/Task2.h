#pragma once
#include <iostream>
#include <vector>

struct Index
{
	int row;
	int column;
};

class Task2
{
private:
	int** matrix;
	int size;

	std::vector<int> GetColumnsWithNegativeElements();
	int GetSumOfColumn(std::vector<int> columns);
	std::vector<Index> GetSaddleElements();
	void PrintSaddleElements(std::vector<Index> saddleElements);
public:
	void Execute(int**& matrix, int size);
	~Task2();
};

