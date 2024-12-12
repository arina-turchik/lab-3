#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minmax(int A[], int n)
{
    int min = A[0];
    int max = A[0];
    int min_ind=0;
    int max_ind=0;
    for (int i = 1; i<n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
            min_ind = i;
        }
        if (A[i] > max)
        {
            max = A[i];
            max_ind = i;
        }
    }
    A[min_ind]=0;
    A[max_ind]=0;
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
    int r;
    for (r=0;r<n;r++)
    {
        B[r]=A[r];
    }
    minmax(B,n);
    for (i = 0; i < n; i++)
    {
        printf("%4d", B[i]);
    }
}
