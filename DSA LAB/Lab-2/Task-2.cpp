#include <iostream>
using namespace std;

int main()
{
	int rows, cols;
	cout << "Enter Number of Rows and Columns: ";
	cin >> rows >> cols;
	int **style = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		style[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter Element " << i << " " << j << ": ";
			cin >> style[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << style[i][j] << " ";
		}
		cout << endl;
	}
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += style[i][j];
		}
		cout << "Row " << i + 1 << " :" << sum << endl;
		sum = 0;
	}
	sum = 0;
	for (int j = 0; j < cols; j++)
	{

		for (int i = 0; i < cols; i++)
		{
			sum += style[i][j];
		}
		cout << "Column " << j + 1 << " :" << sum << endl;
		sum = 0;
	}
	int **transpose = new int *[cols];
	for (int i = 0; i < cols; i++)
	{
		transpose[i] = new int[rows];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			transpose[j][i] = style[i][j];
		}
	}
	cout << "Transpose " << endl;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << transpose[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		delete style[i];
	}
	delete[] style;
	for (int i = 0; i < cols; i++)
	{
		delete transpose[i];
	}
	delete[] transpose;
}