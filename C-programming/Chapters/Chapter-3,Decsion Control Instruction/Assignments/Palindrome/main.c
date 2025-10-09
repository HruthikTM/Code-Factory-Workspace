#include <stdio.h>

void isPalindrome(int num){
    int d,rev=0,temp=num;
    while(num!=0){
     d=num%10;
     rev= rev*10+d;
     num=num/10;
    }

     if(rev==temp)
         printf("Palindrome\n");
     else
         printf("Not Palindrome\n");
}



int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d",&num);

    isPalindrome(num);

    return 0;
}
