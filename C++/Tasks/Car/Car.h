#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

#include "Door.h"
#include "Seat.h"
#include "Wheel.h"
#include "Engine.h"
#include "Staring.h"
#include "Light.h"
#include "AlloyWheel.h"
#include "WindShield.h"
#include "ManualTransmission.h"
#include "DashBoard.h"
#include "Headlight.h"
#include "TailLight.h"

using namespace std;

class Car
{

public:
    Car(string brand, string model, string fuelType, double price, float milage);

    ~Car();

    void setBrand(string brand);
    string getBrand();

    void setModel(string model);
    string getModel();

    void setFuelType(string fuelType);
    string getFuelType();

    void setPrice(double price);
    double getPrice();

    void setMilage(float milage);
    float getMilage();

    void start();

    void drive();

    void stop();


private:

    string m_brand;
    string m_model;
    string m_fuelType;
    double m_price;
    float m_milage;

    Door m_myDoor[4];
    Seat m_mySeat[4];
    AlloyWheel m_myWheel[4];
    Engine m_myEngine;
    Staring m_myStaring;
    HeadLight m_myHeadLight;
    TailLight m_myTailLight;
    WindShield m_myWindShield;
    ManualTransmission m_myGear;
    DashBoard m_myDashboard;


};



#endif // CAR_H
