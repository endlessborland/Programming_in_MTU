//
//  main.c
//  upcoming_sequence
//  Написать программу, которая проверяет, представляют ли элементы введенного с клавиатуры
//  массива возрастающую последовательность. Размер массива задается пользователем в начале работы программы
//  Created by Денис Скоробогатов on 12.11.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int *array; // указатель на динамический массив
    int size; // размер динамического массива
    int i; // счетчик
    printf("Enter the size of an array\n");
    scanf("%d", &size);
    if (size <= 0) // нулевой и отрицательный размер массива
    {
        printf("GIMME AT LEAST SOMETHING\n");
        return 0;
    }
    array = (int*) malloc(size * sizeof(int)); // выделение памяти под массив
    if (array == NULL) // проверка выделения памяти
    {
        free(array);
        printf("Memory not ok\n");
        return 0;
    }
    printf("Enter the array\n");
    scanf("%d", &array[0]); // ввод первого элемента массива
    for (i = 1; i < size; i++)
    {
        scanf("%d", &array[i]); // ввод 1 - size элемента массива
        if (array[i] < array[i-1]) // проверка на убывание
        {
            free(array);
            printf("Array isn't an increasing sequence\n");
            return 0;
        }
    }
    printf("Array is an increasing sequence\n");
    free(array);
    return 0;
}
