#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

using namespace std;


class Window
{
public:
    Window();

    ~Window();

    void setWindowType(string windowType);
    string getWindowType();

    void openWindow();
    void closeWindow();

private:
    string m_windowType;

};

#endif // WINDOW_H
