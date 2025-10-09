#include <stdio.h>
#include<math.h>

int main()
{
    float weight,height,bmi;

    printf("Enter Weight(kg) and Height(m): ");
    scanf("%f%f",&weight,&height);

    bmi=weight/pow(height,2);

    if(bmi>=40)
        printf("Morbidy Obese");
    else if(bmi>=30 && bmi<=30.9)
        printf("Obese\n");
    else if(bmi>=25 && bmi<=25.9)
        printf("Over Weight\n");
    else if(bmi>=18.6 && bmi<=24.9)
        printf("Ideal\n");
    else if(bmi>=17.6 && bmi<=18.5)
        printf("Under Weight\n");
    else if(bmi>=15.1 && bmi<=17.5)
        printf("Anorexic\n");
    else if(bmi<15)
        printf("Starvation\n");
    else
        printf("Dead state\n");

    return 0;

}
