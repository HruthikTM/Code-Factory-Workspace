#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
    int m[3][3];


public:
    Matrix();

    void read()
    {
        cout << "Enter the elements in to 3x3 matrix: \n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << "m["<<i<<"]["<<j<<"]=";
                cin >> m[i][j];
            }
        }
    }
        void display()
        {
            for(int i=0;i<3;i++)
            {
                cout<<"\n";
                for (int j = 0; j < 3; ++j)
                {
                    cout << m[i][j] <<"\t";
                }
            }
        }
        friend Matrix trans(Matrix);
};

// Matrix trans(Matrix m1)
// {
//     Matrix m2;

//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             m2.m[i][j] = m1.m[i][j];
//         }
//     }

//     return (m2);
// }

#endif // MATRIX_H
