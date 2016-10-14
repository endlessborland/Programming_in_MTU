//
//  main.c
//  bin_to_dec
//
//  Created by Денис Скоробогатов on 14.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void f(int *i, unsigned long int *result)
{
    char c = getchar();
    if (c == '\n')
        return;
    f(i, result);
    *result += (c - '0') * pow(2, *i);
    *i += 1;
}

int main(int argc, const char * argv[]) {
    int i = 0;
    unsigned long int result = 0;
    f(&i, &result);
    printf("%ld\n", result);
    return 0;
}
