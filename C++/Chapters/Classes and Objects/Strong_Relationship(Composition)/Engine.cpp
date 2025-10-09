#include "Engine.h"

Engine::Engine()
{
    cout << "Engine Constructor" << endl;
}

Engine::~Engine()
{
    cout << "Engine Destructor" << endl;
}

void Engine :: start()
{
    cout << "Engine started" << endl;
}
