//
//  main.c
//  matrix_multiplication
//
//  Created by Денис Скоробогатов on 15.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, j, k;
    int n1, m1, n2, m2;
    printf("Введите количество строк и столбцов первой матрицы\n");
    scanf("%d%d", &n1, &m1);
    printf("Введите количество строк и столбцов второй матрицы\n");
    scanf("%d%d", &n2, &m2);
    if (m1 != n2)
    {
        printf("Матрицы нельзя уможить\n");
        return 0;
    }
    //Выделяем память под массивы
    float **A = (float**)malloc(n1 * sizeof(float*));
    float **B = (float**)malloc(n2 * sizeof(float*));
    float **C = (float**)malloc(n1 * sizeof(float*));
    for (i = 0; i < n1; i++)
    {
        A[i] = (float*)malloc(m1 * sizeof(float));
        C[i] = (float*)malloc(m2 * sizeof(float));
    }
    for (i = 0; i < n2; i++)
        B[i] = (float*)malloc(m2 * sizeof(float));
    printf("Введите первую матрицу\n");
    for (i = 0; i < n1; i++)
        for (j = 0; j < m1; j++)
        {
            scanf("%f", &A[i][j]);
        }
    printf("Введите вторую матрицу\n");
    for (i = 0; i < n2; i++)
        for (j = 0; j < m2; j++)
        {
            scanf("%f", &B[i][j]);
        }
    //Умножение матриц
    for(i = 0; i < n1; i++)
        for(j = 0; j < m2; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < m1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    //Вывод матриц
    printf("Матрица A\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
            printf("%f ", A[i][j]);
        printf("\n");
    }
    printf("\nМатрица B\n");
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
            printf("%f ", B[i][j]);
        printf("\n");
    }
    printf("\nРезультат умножения\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
            printf("%3f ", C[i][j]);
        printf("\n");
    }
    //Освобождаем память¸
    for (i = 0; i < n1; i++)
    {
        free(A[i]);
        free(C[i]);
    }
    for (i = 0; i < n2; i++)
        free(B[i]);
    free(A);
    free(B);
    free(C);
    
    return 0;
}
