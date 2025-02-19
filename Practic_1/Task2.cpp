#include "Task2.h"

using namespace std;

vector<int> Task2::GetColumnsWithNegativeElements()
{
	vector<int> columns;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[j][i] < 0)
			{
				columns.push_back(i);
				break;
			}
		}
	}
	return columns;
}

int Task2::GetSumOfColumn(vector<int> columns)
{
	int sum = 0;
	for (int col : columns)
	{
		for (int j = 0; j < size; j++)
		{
			sum += matrix[j][col];
		}
	}
	return sum;
}
vector<Index> Task2::GetSaddleElements()
{
    vector<Index> saddleElements;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int current = matrix[i][j];
            bool valid = true;

            for (int k = 0; k < size; k++)
            {
                if (matrix[i][k] < current)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                for (int k = 0; k < size; k++)
                {
                    if (matrix[k][j] > current)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
                saddleElements.push_back({ i, j });
        }
    }

    return saddleElements;
}


void Task2::PrintSaddleElements(vector<Index> saddleElements)
{
	if (saddleElements.empty())
	{
		cout << "No saddle elements found" << endl;
		return;
	}
	for (const auto& elem : saddleElements)
	{
		cout << "Saddle element: " << matrix[elem.row][elem.column] << " at row: " << elem.row << " column: " << elem.column << endl;
	}
}

void Task2::Execute(int**& matrix, int size)
{
	this->matrix = matrix;
	this->size = size;
	cout << "Sum of columns with negative elements: " << GetSumOfColumn(GetColumnsWithNegativeElements()) << endl;
	PrintSaddleElements(GetSaddleElements());
}

Task2::~Task2()
{
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}
