#include "Door.h"

Door::Door()
{
    // cout << "Door object is created of material: " << m_doorMaterial << " and Color: " << m_doorColor << endl;

    cout << "Door object is created" << endl;

    myWindow.setWindowType("Glass");

    myWindow.openWindow();
    myWindow.closeWindow();

}

Door :: ~Door()
{
    //cout << "Door object is destroyed of material: " << m_doorMaterial << " and Color: " << m_doorColor << endl;

    cout << "Door object is destroyed" << endl;
}

void Door :: setDoorMaterial(string doorMaterial)
{
    m_doorMaterial = doorMaterial;
}

string Door :: getDoorMaterial()
{
    return m_doorMaterial;
}

void Door :: setDoorColor(string doorColor)
{
    m_doorColor = doorColor;
}

string Door :: getDoorColor()
{
    return m_doorColor;
}

void Door :: openDoor()
{
    cout << "Door opend " << endl;
}

void Door :: closeDoor()
{
    cout << "Door closed " << endl;
}
