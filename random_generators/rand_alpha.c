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
        printf("1 to 26: Uppercase letters\t27 to 52: Lowercase letters\n");
        printf("Enter lower and upper intervals: ");
        scanf("%d %d", &lower, &upper);

        if(upper <= lower || upper < 1 || lower < 1 || upper > 52 || lower > 52)
        {
            printf("Invalid arguments\n\n");
            continue;
        }

        int rand_alpha = ((float) rand() * (upper - lower) / (float) RAND_MAX) + lower;

        if(rand_alpha < 27)
            rand_alpha += 64;
        else
        {
            rand_alpha -= 26;
            rand_alpha += 96;
        }
        
        printf("Random character: %c", rand_alpha);
        printf("\n\n");
    }
    return 0;
}