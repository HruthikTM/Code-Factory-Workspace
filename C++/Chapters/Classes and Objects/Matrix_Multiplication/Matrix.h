#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
public:
    int r1, c1, r2, c2;
    int a[10][10], b[10][10], c[10][10];

    Matrix();
    ~Matrix();

    void setMatrixA(int rows, int cols, int data[10][10]);
    void setMatrixB(int rows, int cols, int data[10][10]);

    bool canMultiply() const;
    void multiply();

    int getResult(int i, int j) const;

    bool isEven(int num);
};

#endif
