#include <iostream>
#include "DthServiceProvider.h"

using namespace std;

int main() {
    cout << "==============================" << endl;
    cout << "   Welcome to DTH Management  " << endl;
    cout << "==============================" << endl;

    DthServiceProvider *provider = new DthServiceProvider();

    provider->startService();

    delete provider;


    return 0;
}

