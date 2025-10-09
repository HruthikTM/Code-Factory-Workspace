#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

using namespace std;

class Engine
{
public:
    Engine();

    ~Engine();

    void setEngineType(string engineType);
    string getEngineType();

    void setEngineHP(int engineHP);
    int getEngineHP();

    void engineStart();
    void engineStop();

private:
    string m_engineType;
    int m_engineHP;
};

#endif // ENGINE_H
