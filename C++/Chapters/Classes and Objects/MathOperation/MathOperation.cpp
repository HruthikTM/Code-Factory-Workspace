#include "MathOperation.h"


MathOperation::MathOperation()
{
    cout << "Math operation Const is called" << endl;
}

MathOperation::MathOperation(int x, int y)
{
    cout << "Math operation Para Const is called" << endl;
    a = x;
    b = y;
}

MathOperation::~MathOperation()
{
    cout << "Math operation Dest is called" << endl;
}

MathOperation MathOperation :: operator +(MathOperation &o)
{
    MathOperation add;
    add.a = a + o.a;
    add.b = b + o.b;
    return add;
}

MathOperation MathOperation :: operator -(MathOperation &o)
{
    MathOperation sub;
    sub.a = a - o.a;
    sub.b = b - o.b;
    return sub;
}

MathOperation MathOperation :: operator *(MathOperation &o)
{
    MathOperation mul;
    mul.a = a * o.a;
    mul.b = b * o.b;
    return mul;
}

MathOperation MathOperation :: operator /(MathOperation &o)
{
    MathOperation div;
    div.a = a / o.a;
    div.b = b / o.b;
    return div;
}

bool MathOperation::operator<(MathOperation &o)
{
    return (a + b) < (o.a + o.b);
}

bool MathOperation::operator>(MathOperation &o)
{
    return (a + b) > (o.a + o.b);
}

void MathOperation::display()
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
