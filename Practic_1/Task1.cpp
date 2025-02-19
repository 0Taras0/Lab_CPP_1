#include "Task1.h"

using namespace std;

int Task1::GetMinElement()
{
	int min = array[0];
	for (int i = 1; i < array.size(); i++)
		if (array[i] < min)
			min = array[i];
	return min;
}

int Task1::GetSumfFirstAndLastPositiveElements()
{
	int firstPositiveIndex = 0, lastPositiveIndex = 0;
	for (int i = 0; i < array.size(); i++) {
		if (array[i] > 0)
		{
			firstPositiveIndex = i;
			break;
		}
	}
	for (int i = array.size() - 1; i > 0; i--)
	{
		if (array[i] > 0)
		{
			lastPositiveIndex = i;
			break;
		}
	}
	return GetSum(firstPositiveIndex, lastPositiveIndex);
}

int Task1::GetSum(int first, int last)
{
	int sum = 0;
	for (int i = first; i <= last; i++)
		sum += array[i];
	return sum;
}

void Task1::TransformArray()
{
	vector<int> newArray(array.size());
	int zeroCount = 0;
	int index = 0;

	for (int i = 0; i < array.size(); i++)
		if (array[i] == 0)
			zeroCount++;

	for (int i = 0; i < zeroCount; i++)
		newArray[index++] = 0;

	for (int i = 0; i < array.size(); i++)
		if (array[i] != 0)
			newArray[index++] = array[i];

	array = newArray;
}


void Task1::GetArray()
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}


void Task1::Execute(vector<int> array)
{
	this->array = array;
	cout << "Min element: " << GetMinElement() << endl;
	cout << "Sum of first and last positive elements: " << GetSumfFirstAndLastPositiveElements() << endl;
	TransformArray();
	cout << "Transformed array: ";
	GetArray();
}
