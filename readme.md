# Лабораторная работа №3
## Задача:
### Разобрать тему массивы и функции
#### Вариант задания - 9
**"Найти два взаимно простых числа в массиве натуральных чисел, вывести на экран и поменять меньшее из них местами с максимумом, а большее - с минимумом. Если таких чисел нет, обнулить минимум и максимум."**
## Ход работы:
1. Разобрать данный преподавателем код.
2. Найти способ выполнить выбранный вариант задания.
3. Написать и проверить функции, которые смогут выполнить поставленную задачу.
4. Написать обновлённый код, который выполняет поставленную задачу.
5. Переместить всю проделанную работу в репозиторий на `github`.

## Данный изначально код:
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
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
    return 0;
}
```

## Переработанный под задание код
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int vzm(int a,int b)
{
    int t1 = a%b==0 ? 1 : 0;
    if (t1==0)
    {
        t1 = b%a==0 ? 1 : 0;
    }
    if (t1==1)
    {
        return 1;
    }
    int t= a<b ? abs(a) : abs(b);
    int end_i=(int)t/2+1;
    for (int i=2;i<end_i;i++)
    {
        if ((a%i==0)&&(b%i==0))
        {
            return 1;
        }
    }
    return 0;
}

void fill(int n, int a[])
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 101 +1;
}

int main()
{
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    for (int i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
  int max_ind=0;
  int min_ind=0;
  int min=A[0];
  int max=A[0];
  for (int i=0;i<n;i++)
  {
    if(A[i]<A[min_ind])
    {
        min_ind=i;
        min=A[min_ind];
    }
    if (A[i]>A[max_ind])
   {
        max_ind=i;
        max=A[max_ind];
   } 
  }
  printf("min index = %d max index = %d \n", min_ind, max_ind);
  int u=0;
  for (int i=0;i<n-1;i++)
  {
    for (int r=i+1;r<n;r++)
    {
           if (u>0)
        {
            break;
        }
        int t=vzm(A[i],A[r]);
        if (t==0)
        {
            printf("%d,%d \n", A[i], A[r]);
            if (A[i]<A[r])
            {
                A[max_ind]=A[i];
                A[i]= max;
                A[min_ind]=A[r];
                A[r]= min;
            }
            else
            {
                A[max_ind]=A[r];
                A[r]= max;
                A[min_ind]=A[i];
                A[i]= min;
            }
            u=u+1;
        }
    }
  }
  if (u==0)
  {
    A[max_ind]=0;
    A[min_ind]=0;
  }
    for (int i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
}
```
## Скриношот результатов работы программы
 <image src = result.png alt="result">

 ## Источники
 [Функции: вызов функции, возвращаемое значение](https://prog-cpp.ru/c-functions/)  
 [Markdown](https://doka.guide/tools/markdown/)  
 [Evil-teacher](https://evil-teacher.on.fleek.co/prog_pm/term1/lab03/)