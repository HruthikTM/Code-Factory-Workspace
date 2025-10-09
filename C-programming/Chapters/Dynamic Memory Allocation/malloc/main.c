#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of elements:");
    scanf("%d",&n);

    int *ptr=(int *)malloc(n*sizeof(int));

    if(ptr==NULL){
        printf("Memory Not Avaliable");
        exit(1);
    }

    for(int i=0;i<n;i++)
    {
        printf("Enter an interger: ");
        scanf("%d",ptr+i);
    }

    for(int i=0;i<n;i++){
        printf("%d",*(ptr+i));
    }
    return 0;
}
