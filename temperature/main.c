//
//  main.c
//  temperature
//
//  Created by Денис Скоробогатов on 15.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//
#define ABSOLUTE_ZERO 273.15
#define KELVIN 'K'
#define CELSIUS 'C'
#define FAHRENHEIT 'F'

#include <stdio.h>

float toCel(char from, float value)
{
    if (from == KELVIN)
        return value - ABSOLUTE_ZERO;
    if (from == FAHRENHEIT)
        return (value - 32) / 1.8;
    return 0;
}

float toKel(char from, float value)
{
    if (from == CELSIUS)
        return value + ABSOLUTE_ZERO;
    if (from == FAHRENHEIT)
        return toKel(CELSIUS, toCel(FAHRENHEIT, value));
    return 0;
}

float toFar(char from, float value)
{
    if (from == CELSIUS)
        return (value * 1.8) + 32;
    if (from == KELVIN)
        return toFar(CELSIUS, toCel(KELVIN, value));
    return 0;
}

int main(int argc, const char * argv[]) {
    char scale;
    float value;
    printf("Введите единицы измерения температуры\n");
    printf("C - Цельсий\n");
    printf("F - Фаренгейт\n");
    printf("K - Кельвин\n");
    scale = getchar();
    printf("Введите значение температуры\n");
    scanf("%f", &value);
    switch (scale) {
        case KELVIN:
        {
            printf("Градусы по Цельсию: %f\n", toCel(KELVIN, value));
            printf("Градусы по Фаренгейту: %f\n", toFar(KELVIN, value));
            break;
        }
        case CELSIUS:
        {
            printf("Градусы по Кельвину: %f\n", toKel(CELSIUS, value));
            printf("Градусы по Фаренгейту: %f\n", toFar(CELSIUS, value));
            break;
        }
        case FAHRENHEIT:
        {
            printf("Градусы по Цельсию: %f\n", toCel(FAHRENHEIT, value));
            printf("Градусы по Кельвину: %f\n", toKel(FAHRENHEIT, value));
            break;
        }
        default:
        {
            printf("Я знаю, что надо было сказать раньше, но единциы измерения не распознаны, попробуй еще раз\n");
            break;
        }
    }
    return 0;
}
