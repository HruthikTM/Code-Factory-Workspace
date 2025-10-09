#include <iostream>

using namespace std;

class Pointer_to_Member
{
public:
    int num;

    Pointer_to_Member(int j)
    {
        num = j;
    }

    Pointer_to_Member * operator ->(void)
    {
        return this;
    }
};

int main()
{
    Pointer_to_Member P(5);
    Pointer_to_Member *ptr = &P;

    cout << "P.num = " << P.num;
    cout << "\nptr->num = "<<ptr->num;
    cout<< "\nP->num = " << P->num;
    return 0;
}
