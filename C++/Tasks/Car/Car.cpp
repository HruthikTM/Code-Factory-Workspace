#include "Car.h"

Car :: Car(string brand, string model, string fuelType, double price, float milage)
{
    m_brand = brand;
    m_model = model;
    m_fuelType = fuelType;
    m_price = price;
    m_milage = milage;

    cout << "Car object created " << endl;

    m_myDoor->setDoorMaterial("Steel");
    m_myDoor->setDoorColor("Red");

    for(int i=0; i < 4; i++)
    {
    m_myDoor->getDoorMaterial();

    m_myDoor->getDoorMaterial();
    }
    m_myDoor->openDoor();


    m_mySeat->setSeatType("Leather");
    m_mySeat->setSeatLength(3);

    for(int i=0; i < 4; i++)
    {
    m_mySeat->getSeatType();
    m_mySeat->getSeatLength();
    }

    m_mySeat->seatIncline();
    m_mySeat->seatDecline();

    m_myDoor->closeDoor();

    m_myWheel->setWheelPrice(1500);
    m_myWheel->setWheelRadius(3.5);

    for(int i=0; i < 4; i++)
    {
        m_myWheel->getWheelPrice();
        m_myWheel->getWheelRadius();
    }
    m_myWheel->move();
    m_myWheel->turn();

    m_myEngine.setEngineType("V10");
    m_myEngine.setEngineHP(520);

    m_myEngine.engineStart();
    m_myEngine.engineStop();

    m_myStaring.setHandleType("Auto");
    m_myStaring.getHandleType();

    m_myStaring.turnLeft();
    m_myStaring.turnRight();
    m_myStaring.horn();

    m_myHeadLight.lightON();

    m_myTailLight.lightOFF();

    m_myWindShield.clearView();
    m_myWindShield.disturbedView();

    m_myGear.transmitMotion();
    m_myGear.controlSpeed();

    m_myDashboard.operate();

}

Car :: ~Car()
{
    cout << "Car object deleted " << endl;
}


void Car :: setBrand(string brand)
{
    m_brand = brand;
}

string Car :: getBrand()
{
    return m_brand;
}

void Car :: setModel(string model)
{
    m_model = model;
}

string Car :: getModel()
{
    return m_model;
}

void Car :: setFuelType(string fuelType)
{
    m_fuelType = fuelType;
}

string Car :: getFuelType()
{
    return m_fuelType;
}

void Car :: setPrice(double price)
{
    m_price = price;
}

double Car :: getPrice()
{
    return m_price;
}

void Car :: setMilage(float milage)
{
    m_milage = milage;
}

float Car :: getMilage()
{
    return m_milage;
}

void Car :: start()
{
    cout << m_brand << " Car is started " << endl;
}

void Car :: drive()
{
    cout << m_brand << " Car is moving " << endl;
}

void Car :: stop()
{
    cout << m_brand << " Car is stopped " << endl;
}
