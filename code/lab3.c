#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b)
{
    int m;
    int min;
    if (a<b)
    {
        int min = a/2;
        for (m=2;m<=min;m++)
        {
            if (a%m==0 & b%m==0)
                return -1;
        }
    }
    else
    {
        if (b<a)
        {int min = b/2;}
        if (a==b)
        {return -1;}
        for (m=2;m<=min;m++)
        {
            if (a%m==0 & b%m==0)
                return -1;
        }
    }
}

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
}


int main()
{
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    int i;
    for (i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
    int B[n];
    int r,q,t;
    for (r=0;r<n;r++)
    {
        for (q=1;q<n;q++)
        {
            t=gcd(A[r],A[q]);
            if (t==1)
            {
                if(A[r]<A[q])
                {
                    B[r]=A[q];
                    B[q]=A[r];
                }
                else
                {
                    B[r]=A[r];
                    B[q]=A[q];
                }
            }
        }
    }
        for (i = 0; i < n; i++)
        printf("%4d", B[i]);
    printf("\n");
}

