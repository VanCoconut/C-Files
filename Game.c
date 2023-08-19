#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
int cPoints = 0;
int pPoints = 0;
const char PLAYER = 'X';
const char COMPUTER = 'O';

void loadResults();
void saveResults();
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
void displayResults();

int main()
{

    char winner;
    char response;
    do
    {
        response = ' ';
        winner = ' ';

        printf("\nLet's play\n");
        loadResults();
        displayResults();
        resetBoard();

        while (winner = ' ' && checkFreeSpaces != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);
        saveResults();
        printf("\nWould you like to play again? (Y/N): ");
        // non capisco perchè bisogna farlo due volte o non funziona
        scanf("%c", &response);
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("\nThanks for playing! See you soon");

    return 0;
}

void resetBoard()
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    for (size_t i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i == 2)
        {
            continue;
        }

        printf("---|---|---\n");
    }
}
int checkFreeSpaces()
{

    int freeSpace = 9;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpace--;
            }
        }
    }
    return freeSpace;
}
void playerMove()
{

    int x, y;

    printf("Player turn\n");

    do
    {
        printf("choose the row from 1 to 3\n");
        scanf("%d", &x);
        if (x < 1 || x > 3)
        {
            printf("Invalid number for rows\n");
            return playerMove();
        }
        x--;
        printf("choose the column from 1 to 3\n");
        scanf("%d", &y);
        if (y < 1 || y > 3)
        {
            printf("Invalid number for columns\n");
            return playerMove();
        }
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move, this space is already taken\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
void computerMove()
{
    srand(time(0));
    int x, y;

    printf("Computer turn\n");

    do
    {
        x = rand() % 3;
        y = rand() % 3;

    } while (board[x][y] != ' ');

    board[x][y] = COMPUTER;

    printf("The computer turn ends succefully\n");
}
char checkWinner()
{

    // check the rows for a winning match
    for (size_t i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // check columns for a winnign match
    for (size_t i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // check diagonals

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[3][0])
    {
        return board[0][2];
    }

    return ' ';
}
void printWinner(char winner)
{

    if (winner == PLAYER)
    {
        pPoints++;
        printf("You win!\n");
    }
    else if (winner == COMPUTER)
    {
        cPoints++;
        printf("You lose, Computer win!\n");
    }
    else
    {
        printf("Draw\n");
    }
}
void loadResults()
{
    FILE *pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\saves.txt", "r");

    if (pF == NULL)
    {
        puts("no such file to load");
    }
    else
    {
        fseek(pF, 10, SEEK_SET); // set file pointer to 2nd position (0-indexed)
        char part[2] = {0};      // array for 9 characters plus terminating 0
        fread(part, 1, 1, pF);   // read 9 members of size 1 (characters) from f into part
        pPoints = atoi(part);
        fseek(pF, 23, SEEK_SET); // set file pointer to 2nd position (0-indexed)
        char part1[2] = {0};     // array for 9 characters plus terminating 0
        fread(part1, 1, 1, pF);  // read 1 members of size 1 (characters) from pF into part
        cPoints = atoi(part1);
    }
    fclose(pF);
}
void saveResults()
{
    FILE *pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\saves.txt", "w");

    fprintf(pF, "P POINTS: %d\n", pPoints);
    fprintf(pF, "C POINTS: %d\n", cPoints);

    fclose(pF);
}

void displayResults()
{
    printf("PLAYER POINTS: %d\n", pPoints);
    printf("COMPUTER POINTS: %d\n", cPoints);
}