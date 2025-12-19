#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> p1 = make_shared<int>(100);

    cout << "p1 value = " << *p1 << endl;

    shared_ptr<int> p2 = p1;

    //shared_ptr<int> p3 = p1;
    shared_ptr<int> p3 = move(p1);

    shared_ptr<int> p4 = p2;

    cout << "use count = " << p1.use_count() << endl;
    cout << "use count = " << p3.use_count() << endl;
    return 0;
}
