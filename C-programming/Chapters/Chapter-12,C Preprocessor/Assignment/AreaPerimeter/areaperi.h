#ifndef AREAPERI_H
#define AREAPERI_H

#include <math.h>


#define TRIANGLE_AREA(a, b, c) ({ \
    double s = ((a) + (b) + (c)) / 2.0; \
    sqrt(s * (s - (a)) * (s - (b)) * (s - (c))); \
})

#define TRIANGLE_PERIMETER(a, b, c) ((a) + (b) + (c))


#define SQUARE_AREA(s) ((s) * (s))
#define SQUARE_PERIMETER(s) (4 * (s))


#define CIRCLE_AREA(r) (M_PI * (r) * (r))
#define CIRCLE_CIRCUMFERENCE(r) (2 * M_PI * (r))

#endif
