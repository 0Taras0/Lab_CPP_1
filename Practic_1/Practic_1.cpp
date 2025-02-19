#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

using namespace std;

#define Task_1

int main()
{
#ifdef Task_1
	Task1 task1;
	vector<int> array = { 1, 2, -3, 4, 0, 6, 0, 8, 9, -10 };
	task1.Execute(array);
#endif

#ifdef Task_2
	Task2 task2;
	int const SIZE = 2;
	int** matrix = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		matrix[i] = new int[SIZE];

	srand(time(0));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = (rand() % 201) - 100;
		}
	}

	cout << "Matrix:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}


	task2.Execute(matrix, SIZE);
#endif

#ifdef Task_3
	Task3 task3;
	//string text = "Hello, World! This is a test text. It contains 5 words. The shortest word is 'a'.";
	string text;
	cout << "Enter text: ";
	getline(cin, text);

	task3.Execute(text);
#endif

#ifdef Task_4
	vector<WORKER> workers;
	int const N = 3;
	Task4 task4(&workers, N);
	task4.InputWorkers();
	task4.SortWorkers();

	cout << "Sorted Workers:" << endl;
	for (const auto& worker : workers)
		cout << "Name: " << worker.NAME << ", Position: " << worker.POS << ", Year: " << worker.YEAR << ", Month: " << worker.MONTH << endl;
	cout << endl;

	int requiredYears, currentYear, currentMonth;
	cout << "Enter required years of experience: ";
	cin >> requiredYears;
	cout << "Enter current year: ";
	cin >> currentYear;
	cout << "Enter current month: ";
	cin >> currentMonth;

	task4.DisplayWorkersWithExperience(requiredYears, currentYear, currentMonth);
#endif
}