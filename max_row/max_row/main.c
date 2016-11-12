//
//  main.c
//  max_row
//  Найти номер строки произвольной вещественной матрицы, сумма элементов которой максимальна
//  Размер массива задаетяс пользователем в начале работы программы
//  Created by Денис Скоробогатов on 12.11.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    float **array; // двумерный массив
    float max_row = 0; // максимальная сумма элементов строки
    int max_row_number = 0; // индекс строки с максимальной суммой элементов
    float current_row; // сумма элементов текущей строки
    int row_size, column_size; // размер матрицы
    int i, j; // счетчики
    printf("Enter the number of rows\n");
    scanf("%d", &row_size);
    printf("Enter the number of columns\n");
    scanf("%d", &column_size);
    if (row_size <= 0 || column_size <= 0) // проверка размера массива
    {
        printf("GIMME AT LEAST SOMETHING\n");
        return 0;
    }
    array = (float **) malloc(row_size * sizeof(float*)); // выделение памяти
    if (array == NULL) // проверка выделения памяти
    {
        free(array);
        printf("Memory not ok\n");
        return 0;
    }
    for (i = 0; i < row_size; i++)
    {
        array[i] = (float *) malloc(column_size * sizeof(float));
        if (array[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(array[j]);
            free(array);
            printf("Memory not ok\n");
            return 0;
        }
    }
    printf("Enter the array\n");
    for (j = 0; j < column_size; j++) // ввод первой строки
    {
        scanf("%f", &array[0][j]);
        max_row += array[0][j]; // на данном этапе, сумма эл-ов первой строки является единственной и максимальной
        max_row_number = 0;
    }
    for (i = 1; i < row_size; i++) // ввод остального массива
    {
        current_row = 0;
        for (j = 0; j < column_size; j++)
        {
            scanf("%f", &array[i][j]);
            current_row += array[i][j];
        }
        if (current_row > max_row) // поиск максимальной строки
        {
            max_row = current_row;
            max_row_number = i;
        }
    }
    printf("The number of the largest row is: %d\n", max_row_number + 1); // вывод результата
    for (j = 0; j < row_size; j++) // освобождение памяти
        free(array[j]);
    free(array);
    return 0;
}
