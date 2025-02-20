#include "Task4.h"

using namespace std;

Task4::Task4(vector<WORKER>* workers, int n)
{
	this->workers = workers;
	this->n = n;
}

void Task4::InputWorkers()
{
	for (int i = 0; i < n; i++)
	{
		WORKER worker;
		cout << i + 1 << ". " << "Enter worker's name: ";
		getline(cin, worker.NAME);
		cout << i + 1 << ". " << "Enter worker's position: ";
		getline(cin, worker.POS);
		cout << i + 1 << ". " << "Enter worker's year of employment: ";
		cin >> worker.YEAR;
		cin.ignore();
		cout << i + 1 << ". " << "Enter worker's month of employment: ";
		cin >> worker.MONTH;
		cin.ignore();
		workers->push_back(worker);
		cout << endl;
	}
}


void Task4::SortWorkers()
{
	bool swapped;
	int n = workers->size();

	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (workers->at(j).NAME > workers->at(j + 1).NAME) {
				swap(workers->at(j), workers->at(j + 1));
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void Task4::DisplayWorkersWithExperience(int requiredYears, int currentYear, int currentMonth)
{
	bool isFound = false;
	cout << "Workers with experience of " << requiredYears << " years or more:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (currentYear - workers->at(i).YEAR > requiredYears)
		{
			isFound = true;
			cout << i + 1 << ". " << workers->at(i).NAME << " - " << workers->at(i).POS << endl;
		}
		else if (currentYear - workers->at(i).YEAR == requiredYears && currentMonth >= workers->at(i).MONTH)
		{
			isFound = true;
			cout << i + 1 << ". " << workers->at(i).NAME << " - " << workers->at(i).POS << endl;
		}
	}
	if (!isFound)
		cout << "No workers found." << endl;
}
