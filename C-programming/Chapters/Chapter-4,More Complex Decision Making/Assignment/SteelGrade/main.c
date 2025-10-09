#include <stdio.h>

    int main() {
    float hardness, carbon_content, tensile_strength;
    int grade;


    printf("Enter hardness: ");
    scanf("%f", &hardness);
    printf("Enter carbon content: ");
    scanf("%f", &carbon_content);
    printf("Enter tensile strength: ");
    scanf("%f", &tensile_strength);

    int cond1 = hardness > 50;
    int cond2 = carbon_content < 0.7;
    int cond3 = tensile_strength > 5600;


    if (cond1 && cond2 && cond3)
        grade = 10;
    else if (cond1 && cond2)
        grade = 9;
    else if (cond2 && cond3)
        grade = 8;
    else if (cond1 && cond3)
        grade = 7;
    else if (cond1 || cond2 || cond3)
        grade = 6;
    else
        grade = 5;


    printf("Grade: %d\n", grade);

    return 0;
}
