#include "AirConditioner.h"

AirConditioner::AirConditioner()
{
    cout << "Air conditioner obj created" << endl;
}


AirConditioner::~AirConditioner()
{
    cout << "Air conditioner obj destroyed" << endl;
}

void AirConditioner :: cool()
{
    cout << "Cool air breeze" << endl;
}

void AirConditioner :: warm()
{
    cout << "Warm air breeze" << endl;
}
