#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <string>

using namespace std;

class Camera
{
    string brand;
    int resolution;

public:
    Camera(string b, int r)
    {
        brand = b;
        resolution = r;

        cout << "Camera created: " << brand << endl;
    }

    ~Camera()
    {
        cout << "Camera destroyed: " << brand << endl;
    }

    void click()
    {
        cout << "Photo taken at " << resolution << "MP" << endl;
    }

    void record()
    {
        cout << "Recording video.." << endl;
    }
};

#endif // CAMERA_H
