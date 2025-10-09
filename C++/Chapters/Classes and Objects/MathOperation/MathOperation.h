#ifndef MATHOPERATION_H
#define MATHOPERATION_H

#include <iostream>
using namespace std;

class MathOperation
{
public:
    MathOperation();
    ~MathOperation();

    MathOperation(int ,int);

    MathOperation operator + (MathOperation &);
    MathOperation operator - (MathOperation &);
    MathOperation operator * (MathOperation &);
    MathOperation operator / (MathOperation &);
    bool operator <  (MathOperation &);
    bool operator >  (MathOperation &);

    void display();

private:
    int a, b;
};

#endif // MATHOPERATION_H
