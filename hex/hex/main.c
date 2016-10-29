//
//  main.c
//  hex
//
//  Created by Денис Скоробогатов on 29.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>

int checkhex(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'f')
        return 1;
    if (c >= 'A' && c <= 'F')
        return 1;
    if (c == '\n')
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    char c;
    int a = 0;
    while ((c = getchar()) != '\n')
    {
        if (a == 0 && c != '0')
        {
            printf("WOW, hex must start with '0x'\n");
            return 0;
        }
        if (a == 1 && c != 'x')
        {
            printf("WOW, hex must start with '0x'\n");
            return 0;
        }
        if (checkhex(c) == 0 && a > 1)
        {
            printf("WOW, it's not hex!\n");
            return 0;
        }
        if (a != 2)
            a++;
    }
    if (a)
        printf("That looks like hex\n");
    else
        printf("Gimme at least something\n");
    return 0;
}
