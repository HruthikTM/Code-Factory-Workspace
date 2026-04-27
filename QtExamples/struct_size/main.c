#include <stdio.h>

struct v
{
int a[200];
float b[300];
char g;
}s;

struct a
{

char c;
double d;
int r;
char i;
float z;

struct v a;

}op;

int main()
{
    printf("%d",sizeof(op));
    return 0;
}
