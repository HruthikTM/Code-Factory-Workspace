#include "Service_Provider.h"
int main()
{
    ServiceProvider *sp = new ServiceProvider;
    sp->setupChannels();
    delete sp;
    return 0;
}


