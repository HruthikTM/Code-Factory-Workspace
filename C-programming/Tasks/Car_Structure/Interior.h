#ifndef INTERIOR_H
#define INTERIOR_H

#include "Seat.h"
#include "Dashboard.h"
#include "Steering.h"
#include "Gearbox.h"

struct CarInterior {
    struct Seat seats;
    struct Dashboard dashboard;
    struct SteeringWheel steering;
    struct Gearbox gearBox;

};

#endif // INTERIOR_H
