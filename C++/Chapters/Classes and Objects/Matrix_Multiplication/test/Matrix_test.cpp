#include <gtest/gtest.h>
#include "Matrix.h"

TEST(Matrix, ValidMultiplication)
{
    Matrix m;

    int A[10][10] = {
        {1,2},
        {3,4}
    };

    int B[10][10] = {
        {1,2},
        {3,4}
    };

    m.setMatrixA(2, 2, A);
    m.setMatrixB(2, 2, B);

    EXPECT_TRUE(m.canMultiply());

    m.multiply();

    EXPECT_EQ(m.getResult(0, 0), 7);
    EXPECT_EQ(m.getResult(0, 1), 10);
    EXPECT_EQ(m.getResult(1, 0), 15);
    EXPECT_EQ(m.getResult(1, 1), 22);
}

TEST(Matrix, InvalidMultiplication)
{
    Matrix m;

    int A[10][10] = {1, 2, 3};
    int B[10][10] = {1, 2};

    m.setMatrixA(1, 3, A);
    m.setMatrixB(1, 2, B);

    EXPECT_FALSE(m.canMultiply());
}

TEST(Matrix, ReturnsTrueForEvenNumber)
{
    Matrix m;
    int num = 2;

    EXPECT_TRUE(m.isEven(num));
}

TEST(Matrix, ReturnsFalseForOddNumber)
{
    Matrix m;
    int num = 3;

    EXPECT_FALSE(m.isEven(num));
}

TEST(Matrix, ZeroValue)
{
    Matrix m;
    int num = 0;

    EXPECT_TRUE(m.isEven(num));
}

TEST(Matrix, NegativeEven)
{
    Matrix m;
    int num = -6;

    EXPECT_TRUE(m.isEven(num));
}

TEST(Matrix, NegativeOdd)
{
    Matrix m;
    int num = -5;

    EXPECT_FALSE(m.isEven(num));
}
