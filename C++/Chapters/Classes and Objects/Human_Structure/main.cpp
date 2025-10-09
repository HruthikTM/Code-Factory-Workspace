#include <iostream>
#include "HumanBody.h"

using namespace std;

int main()
{
    HumanBody human;
    human.setGender("Male");
    human.setIsAlive(true);
    cout << "Gender: " << human.getGender() << endl;
    cout << "Is Alive: " << (human.getIsAlive() ? "Yes" : "No") << endl;
    return 0;
}
