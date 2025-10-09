#include <iostream>

using namespace std;

#include "account.h"

const int count = 10;

int main()
{
    Account holder[count];

    for (int i = 0; i < count; i++)
    {
        holder[i].enterDetails();
    }

    return 0;
}
