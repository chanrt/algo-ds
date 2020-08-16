#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    while(1)
    {
        int upper, lower;
        printf("Enter lower and upper limit of random number generator: ");
        scanf("%d %d", &lower, &upper);

        if(upper <= lower)
        {
            printf("Invalid arguments\n\n");
            continue;
        }

        int rand_int = ((float) rand() * (upper - lower) / (float) RAND_MAX) + lower;
        printf("Random integer: %d", rand_int);
        printf("\n\n");
    }
    return 0;
}