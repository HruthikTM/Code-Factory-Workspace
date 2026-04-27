#include "Matrix.h"

Matrix::Matrix() {}
Matrix::~Matrix() {}

void Matrix::setMatrixA(int rows, int cols, int data[10][10])
{
    r1 = rows;
    c1 = cols;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            a[i][j] = data[i][j];
        }
    }
}

void Matrix::setMatrixB(int rows, int cols, int data[10][10])
{
    r2 = rows;
    c2 = cols;

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            b[i][j] = data[i][j];
        }
    }
}

bool Matrix::canMultiply() const
{
    return c1 == r2;
}

void Matrix::multiply()
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int Matrix::getResult(int i, int j) const
{
    return c[i][j];
}

bool Matrix::isEven(int num)
{
    if(num%2==0)
        return true;
    else
        return false;
}
