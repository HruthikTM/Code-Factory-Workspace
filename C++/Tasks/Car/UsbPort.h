#ifndef USBPORT_H
#define USBPORT_H

#include <iostream>
#include <string>

using namespace std;

class UsbPort
{
public:
    UsbPort();

    ~UsbPort();

    void connectDevice();
};

#endif // USBPORT_H
