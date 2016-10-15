//
//  main.c
//  random_number
//
//  Created by Денис Скоробогатов on 15.10.16.
//  Copyright © 2016 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 100;

int main(int argc, const char * argv[]) {
    int a, i, p;
    srand(time(NULL));
    a = rand();
    // printf("%d\n", a);
    for (i = 0; i < N; i ++)
    {
        scanf("%d", &p);
        if (!(p-a))
        {
            printf("Угадал!\n"); //Как тут вообще можно угадать?!
            break;
        } else
            printf("Не угадал, пробуй еще\n");
    }
    return 0;
}
