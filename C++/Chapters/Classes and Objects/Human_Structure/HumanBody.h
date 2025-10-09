#ifndef HUMANBODY_H
#define HUMANBODY_H

#include <iostream>
#include <string>
using namespace std;

#include "HeadArea.h"
#include "ChestArea.h"
#include "LeftHand.h"
#include "RightHand.h"
#include "LeftLeg.h"
#include "RightLeg.h"



using namespace std;

class HumanBody
{
public:
    HumanBody();
    ~HumanBody();

    void setGender(string gender);
    string getGender();

    void setIsAlive(bool isAlive);
    bool getIsAlive();

private:
    string m_gender;
    bool m_isAlive;

    HeadArea headArea;
    ChestArea chestArea;
    LeftHand leftHand;
    RightHand rightHand;
    LeftLeg leftLeg;
    RightLeg rightLeg;

};

#endif // HUMANBODY_H
