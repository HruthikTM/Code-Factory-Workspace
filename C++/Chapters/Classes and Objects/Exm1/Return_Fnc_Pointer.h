#ifndef RETURN_FNC_POINTER_H
#define RETURN_FNC_POINTER_H

class TEST
{
public:
    int *p;

    int *fun()
    {
        int i = 20;
        return (&i);
    }
}


#endif // RETURN_FNC_POINTER_H
