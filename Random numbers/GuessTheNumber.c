#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100;
    int answer;
    int guess;
    int guesses = 0;

    // define a seed for the rand function
    srand(time(0));
    // set the rand funct to choice from 1 to 100
    answer = rand() % MAX + MIN;

    printf("\nthe answer is: %d", answer);

    do
    {
        printf("\nGuess the number from 1 to 100\n");
        scanf("%d",&guess);
        if (guess<answer)
        {
            printf("\nToo low");
        }
        else if (guess>answer)
        {
            printf("\nToo hight");
        }
        else
        {
            printf("\nCORRECT YOU WIN");
        }

        guesses++;
        
    } while (guess!=answer);
    
    printf("\nthe answer is: %d", answer);
    printf("\nTo find the correct number you took: %d times", guesses);
    return 0;
}