#include <iostream>
#include <memory>

using namespace std;

// class Test {
// public:
//     Test() {
//         cout << "Constructor called" << endl;
//     }
//     ~Test() {
//         cout << "Destructor called" << endl;
//     }
//     void show() {
//         cout << "Hello from Test class!" << endl;
//     }
// };

// int main() {
//     unique_ptr<Test> p = make_unique<Test>();

//     p->show();

//     return 0;
// }


int main() {
    unique_ptr<int> p1 = make_unique<int>(50);

    cout << "p1 value = " << *p1 << endl;

    unique_ptr<int> p2 = move(p1);

    if (!p1)
        cout << "p1 is now NULL (empty)" << endl;

    cout << "p2 value = " << *p2 << endl;

    return 0;
}
