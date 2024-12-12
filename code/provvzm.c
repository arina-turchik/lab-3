#include <stdio.h>

int vzm(int a,int b) 
{
    int c;
    if (a<b)
    {
        c = a/2;
    }
    else
    {
        c = b/2;
    }
    if (a==b)
    {
        return 0;
    }
    for (int d=2; d<=c; d++)
    {
        if (a%d==0 && b%d==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a,b,r;
    printf("Input a and b:");
    scanf("%d", &a);
    scanf("%d", &b);
    r=vzm(a,b);
    printf("%d \n", r);
    return 0;
}