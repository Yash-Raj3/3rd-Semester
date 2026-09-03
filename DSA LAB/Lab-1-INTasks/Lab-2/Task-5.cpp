
#include <iostream>
using namespace std;

int main()
{
	int rows;
	cout << "Enter Number of Rows: ";
	cin >> rows;
	int **Arr = new int *[rows];
	int size[rows];
	for (int i = 0; i < rows; i++)
	{
		cout << "Enter Length of Row " << i + 1 << " :";
		cin >> size[i];
	}
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new int[size[i]];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			cout << "Enter Element " << i << " " << j << " :";
			cin >> Arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
	float sum = 0;
	float avg;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			sum += Arr[i][j];
		}
		cout << "Sum of Row " << i + 1 << " :" << sum << endl;
		avg = sum / size[i];
		cout << "Average of Row " << i + 1 << " :" << avg << endl;
		sum = 0;
	}
	int most = size[0];
	int mostR = 0;
	int fewR = 0;
	int fewest = size[0];
	for (int i = 1; i < rows; i++)
	{
		if (size[i] > most)
		{
			most = size[i];
			mostR = i;
		}
		if (size[i] < fewest)
		{
			fewest = size[i];
			fewR = i;
		}
	}
	if (most == fewest)
	{
		cout << "Both Rows Equal Number of Elements: " << most << endl;
	}
	else
	{

		cout << "Row with Most Element " << most << " :" << mostR + 1 << endl;
		cout << "Row with Fewest Element " << fewest << " :" << fewR + 1 << endl;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}
