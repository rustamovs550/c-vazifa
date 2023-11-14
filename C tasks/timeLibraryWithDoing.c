#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber()
{
    return 999 +rand() % 10000;
}

int main()
{
    int randomNumber;
    srand(time(NULL));

    randomNumber = generateRandomNumber();
    printf("Generatsiya qilingan son: %d\n", randomNumber);

    // if (randomNumber > 1000 && randomNumber < 10000)
    // {
    //     printf("Generatsiya qilingan son 1000 va 10000 oraligidadir.\n");
    // }
    // else
    // {
    //     printf("Generatsiya qilingan son 1000 va 10000 oraligida emas.\n");
    // }

    return 0;
}