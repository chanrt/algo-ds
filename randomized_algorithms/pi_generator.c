#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int inCircle(float x, float y)
{
    return (((x-1)*(x-1) + (y-1)*(y-1)) <= 1);
}

int main()
{
    long iteration = 1, inside = 0, key;
    float x,y;
    double factor;
    srand(time(NULL));
    while(1)
    {
        x = ((float) rand() / (float) RAND_MAX) * 2;
        y = ((float) rand() / (float) RAND_MAX) * 2;
            
        if(inCircle(x,y))
            inside++;

        factor = (double) inside / iteration;
        if(iteration % 100 == 0)
            printf("Iteration: %d\tValue of PI: %lf\n", iteration, factor * 4.0);
        iteration++;

        if(kbhit())
        {
            printf("Proceed: ");
            scanf("%d", &key);
        }
    }
    return 0;
}