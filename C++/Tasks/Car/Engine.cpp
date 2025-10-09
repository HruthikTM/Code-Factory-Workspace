#include "Engine.h"

Engine::Engine()
{
    cout << "Engine object created" << endl;
}

Engine::~Engine()
{
    cout << "Engine object destroyed" << endl;
}

void Engine:: setEngineType(string engineType)
{
    m_engineType = engineType;
}

string Engine :: getEngineType()
{
    return m_engineType;
}

void Engine:: setEngineHP(int engineHP)
{
    m_engineHP = engineHP;
}

int Engine :: getEngineHP()
{
    return m_engineHP;
}

void Engine :: engineStart()
{
    cout << "Engine stated" << endl;
}

void Engine :: engineStop()
{
    cout << "Engine stopped" << endl;
}
