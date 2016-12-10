//
//  main.c
//  name
//
//  Created by Денис Скоробогатов on 10.12.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, const char * argv[]) {
    srand((int)time(NULL));
    int **array;
    int **easy;
    char c[255];
    int l;
    int res = 0;
    int a;
    int n = 4 + rand() % 5;
    int m = 3 + rand() % 5;
    int i, j;
    int i2, j2;
    int min = 1001;
    int minx = 0, miny = 0;
    array = (int**) malloc(n*sizeof(int*));
    for (i = 0; i < n; i++)
        array[i] = (int*) malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            array[i][j] = 100 + rand() % 900;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        swap(&array[0][i], &array[n-1][i]);
    }
    printf("Поменял строки местами\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    // индекс наименьшего элемента
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < m; j++)
        {
            if (array[i][j] < min)
            {
                min = array[i][j];
                minx = i;
                miny = j;
            }
        }
    }
    easy = (int**) malloc((n-1)*sizeof(int*));
    for (i = 0; i < n; i++)
        easy[i] = (int*) malloc((m-1) * sizeof(int));
    for (i = 0, i2 = 0; i < n; i++)
    {
        if (i != minx)
        {
            for (j = 0, j2 = 0; j < m; j++)
            {
                if (j != miny)
                {
                    easy[i2][j2] = array[i][j];
                    j2++;
                }
            }
            i2++;
        }
    }
    printf("Удалил?\n");
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < m-1; j++)
        {
            printf("%d ", easy[i][j]);
        }
        printf("\n");
    };
    int n1 = n-1 , m1 = m-1, n2 = m1, m2;
    int k;
    scanf("%d", &m2);
    if (m1 != n2)
    {
        printf("Матрицы нельзя уможить\n");
        return 0;
    }
    //Выделяем память под массивы
    int **B = (int**)malloc(n2 * sizeof(int*));
    int **C = (int**)malloc(n1 * sizeof(int*));
    for (i = 0; i < n1; i++)
    {
        C[i] = (int*)malloc(m2 * sizeof(int));
    }
    for (i = 0; i < n2; i++)
        B[i] = (int*)malloc(m2 * sizeof(int));
    printf("Введите вторую матрицу\n");
    
    // SIZE - N*M - n2 * m2;
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2 - 1; j++)
            scanf("%d", &B[i][j]);
        scanf("%s", c);
        l = strlen(c);
        c[l-1] = '\0';
        B[i][m2-1] = atoi(c);
    }
    
    
    //Умножение матриц
    for(i = 0; i < n1; i++)
        for(j = 0; j < m2; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < m1; k++)
                C[i][j] += easy[i][k] * B[k][j];
        }
    printf("\nРезультат умножения\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    //Освобождаем память¸
    free(easy);
    free(array);
    free(B);
    free(C);
    
    return 0;
}
