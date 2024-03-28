#include <stdio.h>
#include <string.h>

//use typedef will come in handy to reduce boilerplate code
typedef struct Struct
{
    char name[15];
    int number;
}Player;

int main(){

    //different definition
    Player player1;
    Player player2= {"Gilmore",2};

    strcpy(player1.name,"Drax");
    player1.number=1;

    //printf("Player n.%d is %s\n",player1.number,player1.name);

    Player players[] = {player1,player2};

    int size = sizeof(players)/sizeof(player1);

    for (size_t i = 0; i < size; i++)
    {
       printf("Player n.%d is %s\n",players[i].number,players[i].name); 
    }
    

    return 0;
}