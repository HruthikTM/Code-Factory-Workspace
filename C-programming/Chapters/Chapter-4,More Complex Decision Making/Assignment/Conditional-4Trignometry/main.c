#include <stdio.h>
#include <math.h>

int main()
{
    float sin_angle_radian,cos_angle_radian;
    float angles_sum, sum_expected = 1.0;

    printf("Enter Sin angles in radinus: ");
    scanf("%f",&sin_angle_radian);

    printf("Enter Cos angles in radinus: ");
    scanf("%f",&cos_angle_radian);

    angles_sum = pow(sin(sin_angle_radian), 2) + pow(cos(cos_angle_radian), 2);

    if (fabs(angles_sum - sum_expected) < 0.0001)
        printf("Sum of squares of sin and cos = 1 (approximately)\n");
    else
        printf("Sum of squares of sin and cos != 1\n");

    return 0;
}
