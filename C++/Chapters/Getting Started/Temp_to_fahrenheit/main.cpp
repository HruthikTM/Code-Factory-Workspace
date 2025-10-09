#include <iostream>

using namespace std;

class Temp
{
private:
    int temp;

    void convertToFahrenheit()
    {
        float fahrenheit = (temp * 9.0 / 5) + 32;
        cout << temp << " Celsius is " << fahrenheit << " Fahrenheit" << endl;
    }

public:
    void inputAndConvert()
    {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        convertToFahrenheit();
    }
};

int main()
{
    Temp t;
    t.inputAndConvert();

    return 0;
}
