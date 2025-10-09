#include <stdio.h>

int numSum(int num);

int main()
{

    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);

    //printf("%d",numSum(num));
    //return 0;





    int output=numSum(num);
    printf("%d",output);

    return 0;

}

int numSum(int num){
    int sum=num+10;
    //printf("%d",sum);
    return (sum);
}
