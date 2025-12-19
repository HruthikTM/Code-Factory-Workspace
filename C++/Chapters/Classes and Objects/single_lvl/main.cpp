#include <iostream>

using namespace std;

class Base
{
private:
    int m_age;
    //string m_name;

public:
    int getAge()
    {
        return m_age;
    }

    void setAge(int age)
    {
        m_age = age;
    }

    string getName()
    {
        return m_name;
    }

    void setName(string name)
    {
        m_name = name;
    }

    Base()
    {

    }

    Base(int age, string name) : m_age(age) , m_name(name)
    {
        cout << "Base constructor" << endl;
    }

    ~Base()
    {
        cout << "Base destructor" << endl;
    }

    void run()
    {
        cout << "run" << endl;
    }
};

class Derived : public Base
{
private:
    int m_phno;

public:
    int getPhno()
    {
        return m_phno;
    }

    void setPhno(int phno)
    {
        m_phno = phno;
    }

    Derived(int a,string newName):Base(a,newName)
    {
        cout << sizeof(Base) << endl;
        cout << "Derived constructor" << endl;
        // setAge(10);
        // setName("hruthik");


    }

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    Derived d(10,"hruthik");
    // d.setAge(10);
    // d.setName("Hruthik");

    d.setPhno(949494);

    cout << sizeof(d) << endl;

    cout << "Age" << d.getAge() <<  "," << "Name" << d.getName() << "," << "Phno" << d.getPhno() << endl;
    return 0;
}
