#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <string>

#include "Window.h"

using namespace std;

class Door
{
public:
    Door();

    ~Door();

    void setDoorMaterial(string doorMaterial);
    string getDoorMaterial();

    void setDoorColor(string doorColor);
    string getDoorColor();

    void openDoor();

    void closeDoor();

private:
    string m_doorMaterial;
    string m_doorColor;

    Window myWindow;
};

#endif // DOOR_H
