#include <iostream>

using namespace std;

#include "matrix.h"

Matrix trans(Matrix m1)
{
    Matrix m2;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m2.m[i][j] = m1.m[j][i];
        }
    }

    return (m2);
}

int main()
{

    Matrix m1,m2;
    m1.read();
    cout << "You entered the following matrix:" << endl;
    m1.display();

    m2 = trans(m1);
    cout << "\nTransposed Matrix: " ;
    m2.display();

    return 0;
}
