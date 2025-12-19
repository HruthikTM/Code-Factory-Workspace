#include <iostream>
#include <memory>
using namespace std;

void doSomething()
{
    throw runtime_error("Something went wrong!");
}

class Test
{
public:
    Test()
    {
        cout << "Constructor\n";
    }
    ~Test()
    {
        cout << "Destructor\n";
    }
};

int main()
{
    try
    {
        unique_ptr<Test> p(new Test());
        //shared_ptr<Test> p = make_shared<Test>();

        doSomething();

        cout << "hell0" << endl;

    }
    catch (const exception& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
