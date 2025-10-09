#include <stdio.h>

int main()
{
    // int i=0;
    // for(;i;){
    //     printf("Hi\n");
    // }
    // return 0;



    for(;;){
         int i=1,j=1;
        if(i>5)
            break;

        else
            j+=i;

        printf("%d\n",j);
        i+=j;

    }
    return 0;
}
