#include <iostream>
using namespace std;
void Display()
{
	cout << "----Operation Display----\n";
	cout << "1.Add\n"
		 << "2.Multiply\n"
		 << "3.Exit\n";
}
void print(int **matrix, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int choice = 0;
	int r1, c1, r2, c2;
	cout << "Enter Row and Column Size for Matrix 1: ";
	cin >> r1 >> c1;
	cout << "Enter Row and Column Size for Matrix 2: ";
	cin >> r2 >> c2;

	int **Matrix1 = new int *[r1];
	int **Matrix2 = new int *[r2];
	cout << "----Matrix 1----\n";
	for (int i = 0; i < r1; i++)
	{
		Matrix1[i] = new int[c1];
		for (int j = 0; j < c1; j++)
		{
			cout << "Enter Element " << i << " " << j << " :";
			cin >> Matrix1[i][j];
		}
	}
	cout << "----Matrix 2----\n";

	for (int i = 0; i < r2; i++)
	{
		Matrix2[i] = new int[c2];
		for (int j = 0; j < c2; j++)
		{
			cout << "Enter Element " << i << " " << j << " :";
			cin >> Matrix2[i][j];
		}
	}
	while (choice != 3)
	{

		Display();
		cout << "Enter Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			if (r1 == r2 && c1 == c2)
			{
				int **add = new int *[r1];
				for (int i = 0; i < r1; i++)
				{
					add[i] = new int[c1];
				}
				for (int i = 0; i < r1; i++)
				{
					for (int j = 0; j < c1; j++)
					{
						add[i][j] = Matrix1[i][j] + Matrix2[i][j];
					}
				}
				cout << "----Addition Product----\n";
				print(add, r1, c1);

				for (int i = 0; i < r1; i++)
				{
					delete[] add[i];
				}
				delete[] add;
			}
			else
			{
				cout << "Incompatible Addition!" << endl;
			}
		}
		else if (choice == 2)
		{
			if (c1 == r2)
			{
				int **multiply = new int *[r1];
				for (int i = 0; i < r1; i++)
				{
					multiply[i] = new int[c2];
				}
				for (int i = 0; i < r1; i++)
				{
					for (int j = 0; j < c2; j++)
					{
						multiply[i][j] = 0;
						for (int k = 0; k < r2; k++)
						{
							multiply[i][j] += Matrix1[i][k] * Matrix2[k][j];
						}
					}
				}
				cout << "----Multiplication Product----\n";
				print(multiply, r1, c2);
				for (int i = 0; i < r1; i++)
				{
					delete[] multiply[i];
				}
				delete[] multiply;
			}
			else
			{
				cout << "Incompatible Multiplication!" << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Exiting System..." << endl;
			for (int i = 0; i < r1; i++)
			{
				delete[] Matrix1[i];
			}
			delete[] Matrix1;

			for (int i = 0; i < r2; i++)
			{
				delete[] Matrix2[i];
			}
			delete[] Matrix2;
			return 0;
		}
		else
		{
			cout << "Invalid Choice!" << endl;
		}
	}
}
