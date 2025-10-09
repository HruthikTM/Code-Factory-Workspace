#include "Window.h"

Window::Window()
{
    cout << "Window created" <<endl;
}

Window::~Window()
{
    cout << "Window destroyed" <<endl;
}

void Window :: setWindowType(string windowType)
{
    m_windowType = windowType;
}

string Window :: getWindowType()
{
    return m_windowType;
}

void Window :: openWindow()
{
    cout << "Open Window " <<endl;
}

void Window :: closeWindow()
{
    cout << "Close Window " <<endl;
}
