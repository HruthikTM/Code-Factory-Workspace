#ifndef ABC_H
#define ABC_H

class XYZ;

class ABC
{
private:
    int data;
public:
    ABC();

    void setValue(int value)
    {
        data = value ;
    }

    friend void add(XYZ, ABC);
};


#endif // ABC_H
