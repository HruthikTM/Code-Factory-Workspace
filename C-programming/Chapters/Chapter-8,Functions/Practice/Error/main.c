#include <stdio.h>


// int addmult(int,int);

// int main()
// {
//     int i=4,j=4,k,l;
//     k=addmult(i,j);
//     l=addmult(i,j);
//     printf("%d%d\n",k,l);
//     return 0;
// }

// int addmult(int a,int b){
//     int c,d;
//     c=a+b;
//     d=a*b;
//     return(c,d);
// }

//int printit(float,char);

int printit(float a,char ch)
{
    printf("%f%c\n",a,ch);

    return 0;
}

int main(){
    float a=15.5;
    char ch='C';
    printit(a,ch);
    return 0;
}




// void message();
// int main()
// {
//     message(message());
//     return 0;
// }

// void message()
// {
//     printf("Hello world\n");
// }
