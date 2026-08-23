#include <iostream>
using namespace std;

class Matrix
{
    int rows, cols;
    int **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
        cout << "Parameterized constructor" << endl;
    }
    Matrix(const Matrix &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "Copy constructor" << endl;
    }
    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;
            data = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        cout << " Copy Assignment operator" << endl;
        return *this;
    }
    Matrix operator+(const Matrix &other)
    {
        Matrix m3(rows, cols);
        if (rows == other.rows && cols == other.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    m3.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
        }
        return m3;
    }
    void set(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }
    int get(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            return data[r][c];
        }
        return -1;
    }
    void intialize()
    {
        cout << "Matrix Initialization" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter Element " << i << " " << j << ": ";
                cin >> data[i][j];
            }
        }
    }
    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
        cout << "Destructor" << endl;
    }
};
int main()
{
    Matrix m1(2, 3);
    m1.intialize();
    Matrix m2(2, 3);
    m2.intialize();
    Matrix m3 = m1 + m2;
    Matrix m4(2, 3);
    m4 = m1;
    Matrix m5(m2);

    cout << "Matrix 1" << endl;
    m1.display();
    cout << "Matrix 2" << endl;
    m2.display();
    cout << "Matrix 3 (m1+m2)" << endl;
    m3.display();
    cout << "Matrix 4" << endl;
    m4.display();
    cout << "Matrix 5" << endl;
    m5.display();

    m2.set(1, 1, 200);
    m4.set(0, 1, 10);
    cout << "After modifying m2 and m4" << endl;
    cout << "Matrix 1" << endl;
    m1.display();
    cout << "Matrix 2" << endl;
    m2.display();
    cout << "Matrix 3" << endl;
    m3.display();
    cout << "Matrix 4" << endl;
    m4.display();
    cout << "Matrix 5" << endl;
    m5.display();
}
