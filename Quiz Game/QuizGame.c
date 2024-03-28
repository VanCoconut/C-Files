#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char guess;
    int score = 0;

    char questions[][100] = {"What is 1+1?",
                             "What come after the 2000?",
                             "Wich century do we live in?"};

    char options[][100] = {"A. 2 ", "B. -2", "C. 5", "D. 10",
                           "A. 1999", "B. 3000", "C. 2001", "D. 2100",
                           "A. XX", "B. XXI", "C. XXX", "D. XIX"};

    char answers[] = {'A', 'C', 'B'};

    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    for (size_t i = 0; i < numberOfQuestions; i++)
    {
        printf("\n****************");
        printf("\n%s", questions[i]);

        for (size_t j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("\n%s", options[j]);
        }

        printf("\nGuess: ");
        scanf("%c", &guess);
        /* 
            clear \n from imput buffer, so in the next iteration scan
            will work fine instead of skipping, DO REMEBER THE *
        */
         scanf("%*c");
        printf("Guess is %c", guess);

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("\nCORRECT");
            score++;
        }
        else
        {
            printf("\nWRONG");
        }
    }

    // printf("\nthe answer is: %d", answer);
    printf("\nYour score is %d/%d", score, numberOfQuestions);
    return 0;
}