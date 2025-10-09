#include "HeadArea.h"

HeadArea::HeadArea()
{
    cout << "Head Area Constructor" << endl;
    m_face = new Face;
    m_hair = new Hair;
}


HeadArea::~HeadArea()
{
    cout << "Head Area Destructor" << endl;
}
