#include <stdio.h>
#include "areaperi.h"

int main() {

    double a = 3, b = 4, c = 5;
    printf("Triangle (a=3, b=4, c=5):\n");
    printf("Area = %.2f\n", TRIANGLE_AREA(a, b, c));
    printf("Perimeter = %.2f\n\n", TRIANGLE_PERIMETER(a, b, c));


    double side = 6;
    printf("Square (side=6):\n");
    printf("Area = %.2f\n", SQUARE_AREA(side));
    printf("Perimeter = %.2f\n\n", SQUARE_PERIMETER(side));


    double radius = 7;
    printf("Circle (radius=7):\n");
    printf("Area = %.2f\n", CIRCLE_AREA(radius));
    printf("Circumference = %.2f\n", CIRCLE_CIRCUMFERENCE(radius));

    return 0;
}
