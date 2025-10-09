#include <stdio.h>

int x=21;

void fun();

int main()
{
    extern int y;
    printf("%d %d",x,y);
    fun();
    return 0;
}


int y=31;

void fun()
{
    printf("%d ",y);

}
