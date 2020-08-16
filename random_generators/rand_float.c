#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    while(1)
    {
        float upper, lower;
        printf("Enter lower and upper limit of random number generator: ");
        scanf("%f %f", &lower, &upper);

        if(upper <= lower)
        {
            printf("Invalid arguments\n\n");
            continue;
        }

        float rand_float = ((float) rand() * (upper - lower) / (float) RAND_MAX) + lower;
        printf("Random integer: %f", rand_float);
        printf("\n\n");
    }
    return 0;
}