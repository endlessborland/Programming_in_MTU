//
//  main.c
//  lab1
//
//  Created by Денис Скоробогатов on 07.02.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 255

typedef struct
{
    int number;
    char string[MAXLENGTH];
    float othernumber;
} readthing;


int main(int argc, const char * argv[]) {
    readthing *thing = malloc(sizeof(readthing));
    FILE *file;
    if (argc != 2)
    {
        printf("need args\n");
        return 0;
    }
    if ((file = fopen(argv[1], "r+b")) == NULL)
    {
        printf("file does not exist\n");
        return 0;
    }
    /*if ((file = fopen("/Users/denisskorobogatov/Desktop/lab1/lab1/data.dat", "r+b")) == NULL)
    {
        printf("file does not exist\n");
        return 0;
    }*/
    int i = 0;
    while (!feof(file))
    {
        fread(thing, sizeof(readthing), 1, file);
        printf("%d %s %f\n", thing->number, thing->string, thing->othernumber);
        i++;
    }
    fseek(file,0,SEEK_END);
    printf("Количество элементов: %d\n", i-1);
    printf("Размер файла, биты: %ld\n", ftell(file));
    fclose(file);
    return 0;
}
