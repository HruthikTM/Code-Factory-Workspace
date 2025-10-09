#include <stdio.h>
#include "stdio.h"
#include <string.h>
#define PI 3.14

void stringReverse(char *);

int main() {

    float area,r=3;

    char str[] = "naman";



    char originalStr[strlen(str) + 1];

    strcpy(originalStr, str);
    printf("Original string: %s\n", str);

    stringReverse(str);
    printf("Reversed string: %s\n", str);

    if (strcmp(originalStr, str)==0) {
        printf("Strings are Equal\n");
    } else {
        printf("Strings are not Equal\n");
    }


    //Hello hi kjkjkjek

    area=PI*r*r;

    printf("Area=%f\n",area);

    return 100;


}


void stringReverse(char* str) {
    // int length = 0;
    // while (str[length] != '\0') {
    //     length++;
    // }

    int length;


    for (length = 0; str[length] != '\0'; length++);

    int first = 0, last = length - 1;
    char temp;

    /*while (first < last)*/
        for(;first < last;first++,last--){
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;

         // first++;
         // last--;
    }

}
