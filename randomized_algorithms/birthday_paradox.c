#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkRepeats(int *birthdays, int n)
{
    int repeats = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(birthdays[i] == birthdays[j])
                repeats++;
        }
    }
    return repeats;
}

int main()
{
    srand(time(NULL));
    while(1)
    {
        int num;
        printf("Enter number of people in the room: ");
        scanf("%d", &num);

        int *birthdays = (int *) malloc(num*sizeof(int));
        for(int i = 0; i < num; i++)
            birthdays[i] = (rand() % 365) + 1;

        int repeats = checkRepeats(birthdays, num);

        printf("There is a %f percent probability that two people share the same birthday", (float) repeats * 100.0 / (float) num);
        printf("\n\n");
    }
    return 0;
}