#include <iostream>
using namespace std;

class SafeMatrix
{
	int rows;
	int cols;
	int **Style;

public:
	SafeMatrix(int r, int c)
	{
		rows = r;
		cols = c;
		Style = new int *[rows];
		for (int i = 0; i < rows; i++)
		{
			Style[i] = new int[cols];
		}
	}
	void set(int r, int c, int val)
	{
		if (r < 0 || r >= rows || c < 0 || c >= cols)
		{
			cout << "Boundary Error!" << endl;
			return;
		}
		Style[r][c] = val;
	}

	int get(int r, int c)
	{
		if (r < 0 || r > (rows - 1) || c < 0 || c > (cols - 1))
		{
			cout << "Boundary Error!" << endl;
			return -1;
		}
		return Style[r][c];
	}

	void display()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << Style[i][j] << " ";
			}
			cout << endl;
		}
	}
	~SafeMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] Style[i];
		}
		delete[] Style;
	}
};
int main()
{
	SafeMatrix Sfa(4, 4);
	Sfa.set(0, 0, 1);
	Sfa.set(0, 1, 2);
	Sfa.set(0, 2, 3);
	Sfa.set(0, 3, 4);
	Sfa.set(1, 0, 5);
	Sfa.set(1, 1, 6);
	Sfa.set(1, 2, 7);
	Sfa.set(1, 3, 8);
	Sfa.set(2, 0, 9);
	Sfa.set(2, 1, 10);
	Sfa.set(2, 2, 11);
	Sfa.set(2, 3, 12);
	Sfa.set(3, 0, 14);
	Sfa.set(3, 1, 15);
	Sfa.set(3, 2, 16);
	Sfa.set(3, 3, 17);
	Sfa.display();

	// Three Invalid Cases
	cout << "Invalid  Cases" << endl;
	cout << Sfa.get(-1, 0) << endl;
	cout << Sfa.get(0, 10) << endl;
	cout << Sfa.get(4, 4) << endl;
}
