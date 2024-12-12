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

int vzm(int a,int b)
{
    int c;
    if (a < b)
    {
        c = a / 2;
    }
    else
    {
        c = b / 2;
    }
    if (a == b)
    {
        return 0;
    }
    for (int d = 2; d <= c; d++)
    {
        if (a % d == 0 && b % d == 0)
        {
            return 0;
        }
    }
    return 1;
}

void minmax(int A[], int n)
{
    int min = A[0];
    int max = A[0];
    int min_ind = 0;
    int max_ind = 0;
    for (int i = 1; i < n; i++)
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
    if (min_ind != max_ind) 
    {
        A[min_ind] = 0;
        A[max_ind] = 0;
    }
}

void fill(int n, int a[])
{
    for (int i = 0; i < n; i++)
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
    for (int i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
    int B[n];
    int r;
    int t;
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (r = i + 1; r < n; r++)
        {
            t = vzm(A[i], A[r]);
            if (t == 1)
            {
                int z = B[i];
                B[i] = B[r];
                B[r] = z;
                u = u + 1;
            }
        }
    }
    if (u == 0)
    {
        minmax(B, n);
    }
    for (int i = 0; i < n; i++)
        printf("%4d", B[i]);
    printf("\n");
}
```
## Скриношот результатов работы программы
 <image src = result.png alt="result">

 ## Источники
 [Функции: вызов функции, возвращаемое значение](https://prog-cpp.ru/c-functions/)  
 [Markdown](https://doka.guide/tools/markdown/)  
 [Evil-teacher](https://evil-teacher.on.fleek.co/prog_pm/term1/lab03/)