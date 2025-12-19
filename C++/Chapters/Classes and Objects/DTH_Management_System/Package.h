#ifndef PACKAGE_H
#define PACKAGE_H

#include <map>
#include <string>
#include "Channels.h"

using namespace std;

class Package
{
public:
    Package();
    Package(int id, const string& name);

    int getPackageId() const;
    string getPackageName() const;
    double getTotalPrice() const;

    void setPackageId(int id);
    void setPackageName(const string& name);

    void addChannel(Channels* ch);
    void removeChannel(int id);
    void calculateTotalPrice();

    map<int, Channels*>& getChannelMap();

    void setTotalPrice(double newTotalPrice);

private:
    int m_packageId;
    string m_packageName;
    double m_totalPrice;

    map<int, Channels*> m_channelMap;
};

#endif
