//
//  main.c
//  array
//
//  Created by Денис Скоробогатов on 15.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>

#define ARRAY_LENGTH 256

int main(int argc, const char * argv[]) {
    float array[ARRAY_LENGTH];
    int i;
    int counter = 0;
    float average = 0;
    int array_length;
    scanf("%d", &array_length);
    for (i = 0; i < array_length; i++)
    {
        scanf("%f", &array[i]);
        if (array[i] > 0)
        {
            counter++;
            average += array[i];
        }
    }
    printf("Положительных чисел: %d\n", counter);
    if (counter)
        average/=array_length;
    printf("Среднее арифметическое положительных чисел %f\n", average);
    return 0;
}
