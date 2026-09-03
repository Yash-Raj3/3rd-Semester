#include <iostream>
using namespace std;
bool insertSubject(int **marks, int *courses, int Total, int Sindex, int Marks)
{
	if (Sindex >= Total || Sindex < 0)
	{
		cout << "Invalid Student Index!" << endl;
		return false;
	}
	int *temp = new int[courses[Sindex] + 1];
	for (int i = 0; i < courses[Sindex]; i++)
	{
		temp[i] = marks[Sindex][i];
	}

	temp[courses[Sindex]] = Marks;
	delete[] marks[Sindex];
	courses[Sindex] += 1;
	marks[Sindex] = temp;
	return true;
}

int main()
{
	int n;
	cout << "Enter Number of Students: ";
	cin >> n;
	int **Marks = new int *[n];
	int *Courses = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << " Number of Courses: ";
		cin >> Courses[i];
		Marks[i] = new int[Courses[i]];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << " " << endl;
		for (int j = 0; j < Courses[i]; j++)
		{
			cout << "Course " << j + 1 << " Marks: ";
			cin >> Marks[i][j];
		}
	}

	double *avg = new double[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << " Marks " << endl;
		for (int j = 0; j < Courses[i]; j++)
		{
			cout << Marks[i][j] << " ";
			sum += Marks[i][j];
		}
		cout << endl;
		avg[i] = (double)sum / (double)Courses[i];
		cout << "Average: " << avg[i] << endl;
		sum = 0;
	}
	int h = 1, l = 1;
	double Havg = avg[0], Lavg = avg[0];
	for (int i = 1; i < n; i++)
	{
		if (avg[i] > Havg)
		{
			Havg = avg[i];
			h = i + 1;
		}
		if (avg[i] < Lavg)
		{
			Lavg = avg[i];
			l = i + 1;
		}
	}
	cout << "Highest Average " << Havg << " : Student: " << h << endl;
	cout << "Lowest Average " << Lavg << " : Student: " << l << endl;
	int choice = 0;
	cout << "--Add Another Subject--" << endl;
	cout << "1.Yes\n"
		 << "2.No\n";
	cout << "Enter Choice: ";
	cin >> choice;
	if (choice == 1)
	{
		int nMarks, index;
		cout << "Enter Student Index: ";
		cin >> index;
		cout << "Enter Marks: ";
		cin >> nMarks;

		if (insertSubject(Marks, Courses, n, index, nMarks))
		{
			cout << "Subject Added Successfully!" << endl;
			cout << "Student " << index + 1 << " Marks: ";
			for (int i = 0; i < Courses[index]; i++)
			{
				cout << Marks[index][i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "Failed to Add Subject!" << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Program Ending...." << endl;
		return 0;
	}
	else
	{
		cout << "Invalid Choice!" << endl;
	}

	delete[] Courses;
	delete[] avg;
	for (int i = 0; i < n; i++)
	{
		delete[] Marks[i];
	}
	delete[] Marks;
}
