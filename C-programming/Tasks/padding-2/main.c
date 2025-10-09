#include <stdio.h>

#pragma pack(1)

struct example{

    char a[10];
    //long num;
    char z;
    //double d;
    //char b[13];
};

#pragma pack;

int main()
{

    //struct example e={1212122, "/*hruthik*/",13.56,"/*goodmorning*/"};

   // struct example e={1111,123.56};

    struct example e={"hruthik",'v'};

    int size=sizeof(struct example);
    printf("structure size %d\n\t",size);

    // printf("\nValue: %ld and Address: %u\n",e.num,&e.num);

    // for(int i =0; i<sizeof(e.a); i++){
    // printf("\nValue : %c and Address : %u\n",e.a[i],&e.a[i]);
    // }


    // printf("\nValue: %c and Address: %d\n",e.z,&e.z);


    //printf("\nValue: %lf and Address: %u\n",e.d,&e.d);


    // for(int i =0; i<sizeof(e.b); i++){
    //     printf("\nValue : %c and Address : %u\n",e.b[i],&e.b[i]);
    // }







    return 0;
}
