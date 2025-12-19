#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <map>
#include <string>
#include "Languages.h"
#include "Channels.h"


using namespace std;

class Package
{
public:
    Package(int id, const string& name);
    ~Package();


    int getPackageId() const;
    string getPackageName() const;
    void setPackageName(const string &newPackageName);

    double getTotalPrice() const;
    void setTotalPrice(double newTotalPrice);

    map<int, Channels *> getChannelMap() const;
    void addChannel(Channels* channel);
    void removeChannel(int channelId);
    double calculateTotalPrice();

private:
    int m_packageId;
    string m_packageName;
    double m_totalPrice;
    map<int, Channels*> m_channelMap;


};

#endif // PACKAGE_H
