#include <stdio.h>

int main()
{
    int classObtained,failedSubjects,graceMarks=0;

    printf("Enter the Class Obtained (1 for Firstclass,2 for Secondclass,3 for Thirdclass): ");
    scanf("%d",&classObtained);

    printf("Enter Number of subjects failed: ");
    scanf("%d",&failedSubjects);

    switch(classObtained){

    case 1:
        if(failedSubjects<=3)
            graceMarks=5*failedSubjects;
        else
            graceMarks=0;
        break;

    case 2:
        if(failedSubjects<=2)
            graceMarks=4*failedSubjects;
        else
            graceMarks=0;
        break;

    case 3:
        if(failedSubjects<=1)
            graceMarks=5;
        else
            graceMarks=0;
        break;

    default:
        printf("Invalid class entered.\n");
        return 1;
    }

    printf("Grace marks awarded: %d\n", graceMarks);
    return 0;
}
